#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


#define PORT 65432
#define BUFFER_SIZE 1024

int main(){
	int server_fd, new_socket;
	struct sockaddr_in address; // this structure holds teh ipv4 addresses
				    //
	int opt = 1;

	int addrlen = sizeof(address); // size of the address structure (needed for accept())
	
	char buffer[BUFFER_SIZE] = {0}; //buffer to store incomin data, initialized to zero
	

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {

		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	
	
