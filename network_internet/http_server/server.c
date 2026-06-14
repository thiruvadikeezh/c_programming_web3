#include <sys/socket.h>

#include <arpa/inet.h>


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

	struct sockaddr_in bind_addr;

	bind_addr.sin_port = htons(6969);
	bind_addr.sin_family = AF_INET;

	bind_addr.sin_addr

	int rc = bind(tcp_socket, 

	return 0;


}




