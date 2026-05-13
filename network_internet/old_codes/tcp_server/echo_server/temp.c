#include <stdio.h>          // Standard C library for input/output functions like printf(), perror()
#include <stdlib.h>         // Standard library for exit(), EXIT_FAILURE, memory utilities
#include <string.h>         // Provides memset(), strlen(), and other string functions
#include <unistd.h>         // POSIX API for read(), close(), and other Unix system calls
#include <arpa/inet.h>      // Networking utilities: sockaddr_in, htons(), inet functions

#define PORT 65432          // Preprocessor macro defining the port number the server will listen on
#define BUFFER_SIZE 1024    // Size of the buffer used to store received data

int main() {                // Program entry point
    int server_fd, new_socket; // server_fd = listening socket, new_socket = client communication socket
    struct sockaddr_in address; // Structure that holds IPv4 address and port information
    int opt = 1;                // Option value used for setsockopt()
    int addrlen = sizeof(address); // Size of the address structure (needed for accept())
    char buffer[BUFFER_SIZE] = {0}; // Buffer to store incoming data, initialized to zero

    // 1. Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { // socket() creates a TCP socket
        perror("socket failed"); // Prints error message if socket creation fails
        exit(EXIT_FAILURE);      // Terminates program with failure status
    }

    // 2. Forcefully attaching socket to the port 65432
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)); 
    // setsockopt() configures socket options
    // SOL_SOCKET = operate at socket layer
    // SO_REUSEADDR = allows reusing the port immediately after program restart

    address.sin_family = AF_INET;          // Specifies IPv4 address family
    address.sin_addr.s_addr = INADDR_ANY;  // Server listens on all network interfaces
    address.sin_port = htons(PORT);        // Converts port number from host byte order to network byte order

    // 3. Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) { 
        // bind() assigns IP address and port to the socket
        // cast to (struct sockaddr *) because socket API uses a generic address structure
        perror("bind failed");  // Print error if binding fails
        exit(EXIT_FAILURE);     // Exit program
    }

    // 4. Listen for incoming connections (Queue size of 3)
    if (listen(server_fd, 3) < 0) { // listen() marks socket as passive (waiting for client connections)
        perror("listen");           // Print error message
        exit(EXIT_SUCCESS);         // Exit program
    }

    printf("C Echo Server is live on port %d\n", PORT); // Inform user that server started

    // 5. Accept a connection (This blocks until a device connects)
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        // accept() waits for a client connection
        // returns a new socket descriptor for communication with that client
        perror("accept"); // Print error if connection fails
        exit(EXIT_FAILURE);
    }

    // 6. Echo Loop
    while (1) { // Infinite loop to continuously read client data
        int valread = read(new_socket, buffer, BUFFER_SIZE); 
        // read() reads data sent by the client into buffer

        if (valread <= 0) break; // If client disconnects or error occurs, exit loop

        printf("Received: %s", buffer); // Print the received message on server terminal

        send(new_socket, buffer, valread, 0); 
        // send() sends the same data back to the client (echo functionality)
        
        memset(buffer, 0, BUFFER_SIZE); 
        // memset() clears the buffer to prevent leftover data from previous messages
    }

    close(new_socket); // Close the client communication socket
    close(server_fd);  // Close the listening socket

    return 0; // Program finished successfully
}
