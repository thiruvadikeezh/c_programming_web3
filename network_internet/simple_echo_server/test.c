#include <stdio.h>

#include <sys/socket.h>

int main(){

	int server_fd;

	server_fd= socket(AF_INET, SOCK_STREAM, 0);

	printf("Socket FD = %d\n", server_fd);

	return 0;

}

