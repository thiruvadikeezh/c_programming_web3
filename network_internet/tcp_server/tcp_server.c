#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8008

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket Creation Failed");
        return -1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Bind Failed");
        return -1;
    }

    if (listen(sock, 5) < 0) {
        perror("Listen Failed");
        return -1;
    }

    printf("TCP Server Running On Port %d\n", PORT);
    printf("Waiting for connection...\n");

    int client = accept(sock, NULL, NULL);
    if (client < 0) {
        perror("Accept Failed");
        return -1;
    }

    printf("Client connected!\n");

    while (1) {
        char buffer[1025];  // 🔥 1 extra byte for null
        int len = read(client, buffer, 1024);

        if (len <= 0) {
            printf("Client Disconnected\n");
            break;
        }

        buffer[len] = '\0';

        printf("Received from Pico: %s\n", buffer);

        const char *reply = "Reply From PC Server\n";
        send(client, reply, strlen(reply), 0);
    }

    close(client);
    close(sock);

    return 0;
}
