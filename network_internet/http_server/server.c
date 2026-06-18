#include <stdio.h>

#include <unistd.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main()
{
	int tcp_socket = socket(
		AF_INET, /*ipv4*/
		SOCK_STREAM, /*tcp*/
		0
	);

	if (tcp_socket == -1)
	{
		perror("socket()");

		return 1;
	}

	printf("socket creation successful\n");

	struct sockaddr_in addr;

	addr.sin_family = AF_INET;

	addr.sin_port = htons(6969);

	addr.sin_addr.s_addr = INADDR_ANY;



	int bind_rc = bind(tcp_socket, (const struct sockaddr *)&addr, sizeof(addr));


	if (bind_rc == -1)
	{
		perror("bind( ()");

		return -1;
	}
	printf("port accurately bindned\n");


	int listen_rc = listen(tcp_socket, 5);

	if (listen_rc == -1)
	{
		perror("liten failed");

		return -1;
	}

	printf("we are listening\n");




	int client_fd = accept(tcp_socket, NULL, NULL);

	if (client_fd == -1)
	{
		perror("accept failed");

		return -1;
	}

	printf(" we are accepting\n");

	char buffer[1024];
	while(1)
	{


		ssize_t bytes_recv = recv(client_fd, buffer, sizeof(buffer), 0);

		if ( bytes_recv == -1)
		{
			perror("recv failed");
			break;
		}

		if (bytes_recv == 0)
		{
			printf("The Client Disconencted \n");
			break;
		}



		if (bytes_recv > 0)
		{
			
			buffer[bytes_recv] = '\0';

		}

		printf(" now the recv function is working\n");

		printf("%s\n", buffer);

		ssize_t bytes_send = send(client_fd, buffer, bytes_recv, 0);

		if (bytes_send == -1)
		{
			perror("send faile");

			break;
		}



		printf("The send function is working\n");
	}

	
	close(tcp_socket);
	close(client_fd);

	printf(" didi i came here \n");




	return 0;

}




