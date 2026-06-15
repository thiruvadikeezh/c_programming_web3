#include <stdio.h>

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

	printf("socket creation successful");

	struct sockaddr_in addr;

	addr.sin_family = AF_INET;

	addr.sin_port = htons(6969);

	addr.sin_addr.s_addr = INADDR_ANY;



	int rc = bind(tcp_socket, (const struct sockaddr *)&addr, sizeof(addr));


	if (rc == -1)
	{
		perror("bind( ()");

		return -1;
	}
	printf("port accurately bindned\n");


	return 0;

}




