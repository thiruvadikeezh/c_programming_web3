#include <stdio.h>

#include <string.h>

#include <sys/socket.h>

#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int server_fd, new_socket;

    struct sockaddr_in address;
    
    int opt = 1;

    int addrlen = sizeof(address);

    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    printf(" the server fd is : %d\n", server_fd);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    listen(server_fd, 3);
    printf("server is listening on port 8080.....\n");

    while(1)
    {

        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        if (new_socket < 0)
        {
            perror(" the accept failed!");
            continue;
        }

        while(1)
        {


            memset(buffer, 0, 1024);

            int check = read(new_socket, buffer, 1024);

            if (check <= 0)
            {
                break;
            }

            buffer[check] = '\0';


            printf("The Client Sent: %s\n", buffer);


        }


        close(new_socket);

        printf("Client Disconnected.....\n");
    
    }

    close(server_fd);

    return 0;
}


    



