#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define IP_ADDR "192.168.1.3"


int main()
{

    int clientSocket;

    struct sockaddr_in serverAddr;
    char buffer[1024] = {0};

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(clientSocket < 0)
    {
        printf("Socket Creation Failed\n");
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);

    if (inet_pton(AF_INET, IP_ADDR, &serverAddr.sin_addr) <= 0) {

        printf("invalid address or address not supported\n");

        return -1;
    }


    printf("connecting to windows server\n");


    if(connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        printf("Connection failed! is the server running? is the ip correct? \n");
        return -1;
    }


    read(clientSocket, buffer, 1024);
    printf("mesage from server: %s\n", buffer);

    close(clientSocket);
    return 0;
}

