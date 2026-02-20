#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>


int main()
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(8008);
	server.sin_addr.s_addr = INADDR_ANY;

	bind(sock, (struct sockaddr*)&server, sizeof(server));
	listen(sock, 2);
	
	printf("waiting for connection....\n");
	int client = accept(sock, NULL, NULL);
	printf("Client connected!\n");


	char msg[] = "Hello from TCP Server";
	send(client, msg, strlen(msg), 0);


	close(client);
	close(sock);
}



