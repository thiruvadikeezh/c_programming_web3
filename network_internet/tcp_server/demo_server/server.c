#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 3);

    printf("Server listening on port 8080...\n");

    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, buffer, 1024);
    printf("Client says: %s\n", buffer);

    send(client_fd, "Hello from server", 17, 0);

    close(client_fd);
    close(server_fd);
}
