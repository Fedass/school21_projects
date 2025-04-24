#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

#define BUFFER_SIZE 4096

using namespace std;

string removeDuplicates(const string& input) {
    istringstream iss(input);
    set<string> words;
    string word, result;

    while (iss >> word) {
        if (words.insert(word).second) {
            result += word + " ";
        }
    }

    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

class ProcessorServer {
public:
    ProcessorServer(int listen_port, const string& display_ip, int display_port)
        : listen_port_(listen_port), display_ip_(display_ip), display_port_(display_port) {}

    void run() {
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd < 0) {
            perror("socket");
            return;
        }

        sockaddr_in server_addr{};
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(listen_port_);

        if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("bind");
            close(server_fd);
            return;
        }

        if (listen(server_fd, 5) < 0) {
            perror("listen");
            close(server_fd);
            return;
        }

        cout << "[ProcessorServer] Listening on port " << listen_port_ << "...\n";

        while (true) {
            sockaddr_in client_addr{};
            socklen_t client_len = sizeof(client_addr);
            int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
            if (client_fd < 0) {
                perror("accept");
                continue;
            }

            char buffer[BUFFER_SIZE] = {0};
            int bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1);
            if (bytes_read <= 0) {
                close(client_fd);
                continue;
            }

            string input(buffer);
            string processed = removeDuplicates(input);

            send(client_fd, "OK\n", 3, 0);
            close(client_fd);

            sendToDisplayServer(processed);
        }

        close(server_fd);
    }

private:
    void sendToDisplayServer(const string& data) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket (to display)");
            return;
        }

        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(display_port_);
        inet_pton(AF_INET, display_ip_.c_str(), &addr.sin_addr);

        if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
            perror("connect (to display)");
            close(sock);
            return;
        }

        send(sock, data.c_str(), data.length(), 0);
        close(sock);
    }

    int listen_port_;
    string display_ip_;
    int display_port_;
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: ./processor_server <listen_port> <display_ip> <display_port>\n";
        return 1;
    }

    int listen_port = stoi(argv[1]);
    string display_ip = argv[2];
    int display_port = stoi(argv[3]);

    ProcessorServer server(listen_port, display_ip, display_port);
    server.run();

    return 0;
}

