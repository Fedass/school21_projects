#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>


using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: ./client_app <server_ip> <port>\n";
        return 1;
    }

    string server_ip = argv[1];
    int port = stoi(argv[2]);

    while (true) {
        string input;
        cout << "Write something > ";
        getline(cin, input);

        if (input.empty()) continue;

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            cerr << "Socket creation error\n";
            return 1;
        }

        sockaddr_in serv_addr{};
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);

        if (inet_pton(AF_INET, server_ip.c_str(), &serv_addr.sin_addr) <= 0) {
            cerr << "Invalid address or address not supported\n";
            close(sock);
            continue;
        }

        if (connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
            cerr << "Connection failed\n";
            close(sock);
            continue;
        }

        send(sock, input.c_str(), input.size(), 0);

        char buffer[1024] = {0};
        int valread = read(sock, buffer, sizeof(buffer));
        if (valread > 0) {
            cout << "Server response: " << buffer << "\n";
        } else {
            cout << "⚠️ No response from server.\n";
        }

        close(sock);
    }

    return 0;
}