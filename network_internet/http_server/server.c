#include <stdio.h>

#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int handle_client(int client_socket)
{

	ssize_t n = 0;
	char buffer[1024];

	for(;;)
	{	
		memset(buffer, 0, sizeof(buffer));
		n = read(client_socket, buffer, sizeof(buffer)-1);
		if( n < 0)
		{
			perror("read faild");
			return -1;
		}

		if ( n == 0 )
		{
			printf("conenction closed successful\n");
			break;
		}
		printf("-> %s\n", buffer);
	}
	return 0;
}

int main()
{
	int rc = 0;
	struct sockaddr_in addr = {0};
	int tcp_socket = 0;
	int client_fd = 0;
	int ret = 0;
	char buffer[1024];
	int enabled = true;

	tcp_socket = socket(
		AF_INET, /*ipv4*/
		SOCK_STREAM, /*tcp*/
		0
	);

	if (tcp_socket < 1)
	{
		perror("socket()");
		return 1;
	}
	printf("socket creation successful\n");

	(void)setsockopt(tcp_socket, SOL_SOCKET, SO_REUSEADDR, &enabled, sizeof(enabled));

	addr.sin_family = AF_INET;
	addr.sin_port = htons(6969);
	addr.sin_addr.s_addr = INADDR_ANY;

	rc = bind(tcp_socket, (const struct sockaddr *)&addr, sizeof(addr));
	if (rc < 0)
	{
		perror("bind( ()");
		ret = 1;
		goto exit;
	}
	printf("port accurately bindned\n");


	rc = listen(tcp_socket, 5);
	if (rc < 0)
	{
		perror("listen failed");
		ret = 1;
		goto exit;
	}
	printf("lISTEN SUCCESSFULL\n");
	
	for(;;)
	{
		printf("Waiting for conenctions\n");
		client_fd = accept(tcp_socket, NULL, NULL);
		printf("got an conenction\n");

		rc = handle_client(client_fd);

	}

exit:
	close(tcp_socket);
	return ret;
}




