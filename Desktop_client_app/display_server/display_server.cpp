#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <string>

#define BUFFER_SIZE 4096

using namespace std;

class DisplayServer {
public:
    DisplayServer(int port) : port_(port) {}

    void run() {
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd < 0) {
            perror("socket");
            return;
        }

        sockaddr_in server_addr{};
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(port_);

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

        cout << "[DisplayServer] Listening on port " << port_ << "...\n";

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
            if (bytes_read > 0) {
                string message(buffer);
                cout << "[DisplayServer] Received: " << message << "\n";
            }

            close(client_fd);
        }

        close(server_fd);
    }

private:
    int port_;
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: ./display_server <port>\n";
        return 1;
    }

    int port = stoi(argv[1]);
    DisplayServer server(port);
    server.run();

    return 0;
}

