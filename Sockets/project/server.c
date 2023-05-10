#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// socket programming header files 

#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8881

int main()
{

	printf("\n THIS IS A TEST MESSAGE \n");

	int server_fd, new_socket, valread;
	struct sockaddr_in address;

	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = { 0 };
	char* myMessage = "Hello this is a test message";

	// creating socket file descriptor 


	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket Failed !");
		exit(EXIT_FAILURE);

	}

	// Forcefully attaching socket to the port 8881
	
	if ((setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) < 0)
	{
		perror("Setsockopt");
		exit(EXIT_FAILURE);

	}

	// Forecefully attaching socket to the port 8881

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if ((bind(server_fd, (struct sockaddr *)&address, sizeof(address))) < 0)
	{
		perror("Bind Failed !");
		exit(EXIT_FAILURE);

	}

	if ((listen(server_fd, 3)) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);	

	}
	
	if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0)
	{

		perror("ACCEPT");
		exit(EXIT_FAILURE);

	}	

	while (1) 
	{

		valread = read(new_socket, buffer, 1024);
		printf("%s\n", buffer);
		send(new_socket, buffer, strlen(buffer), 0);
		printf("\n Hello message send to the client \n");
	}

	close(new_socket);

		// shutdown(server_fd, SHUT_RDWR);

	return 0;

}
