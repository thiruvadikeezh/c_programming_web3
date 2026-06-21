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

		buffer[n] = '\0';
		printf("-----------\n");
		printf("Raw Request:\n%s\n", buffer);

		char method[32];
		char path[256];
		char version[32];

		sscanf(buffer, "%31s %255s %31s", method, path, version);

		printf("Method   : %s\n", method);
		printf("Path     : %s\n", path);
		printf("Version  : %s\n", version);

		printf("-------\n");
		
		if(strcmp(path, "/") == 0)
		{
			printf("HOME\n");
			const char *response =
				"HTTP/1.1 200 OK\r\n"
				"Content-Type: text/html\r\n"
				"\r\n"
				"<h1>HOME</h1>";

			n = write(client_socket, response, strlen(response));
			if ( n < 0)
			{
				perror("write()");
			}

			break;
		}
		else
		{
			printf("404 NOT FOUND\n");
		}


	}
	close(client_socket);
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

	if (tcp_socket < 0)
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

		if (client_fd < 0)
		{
			perror("acept()");

			ret = 1;
			goto exit;
		}

		printf("got an conenction\n");

		rc = handle_client(client_fd);

		if ( rc < 0)
		{
			perror("read failed");
			ret = 1;
			goto exit;
		}

	}

exit:
	close(tcp_socket);
	close(client_fd);
	return ret;
}




