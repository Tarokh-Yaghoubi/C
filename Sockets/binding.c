/*
*
*	Tarokh (Jacob) Yaghoubi
*	Socket Programming in C
*	How to use bind() and socket()	
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Windows Socket Header files, 

#include <Windows.h>
#include <ws2def.h>
#include <WS2tcpip.h>
#include <WinSock2.h>


int main(int argc, char* argv[])
{

	struct addrinfo hints, * res;
	int sockfd;

	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		fprintf(stderr, "Startup failed due to some reason \n");
		exit(1);
	}
	if (LOBYTE(wsaData.wVersion) != 2 ||
		HIBYTE(wsaData.wVersion) != 2)
	{
		fprintf(stderr, "version 2.2 of WinSock is not available \n");
		exit(2);
	}
	else
		fprintf(stdout, "\n Everything is working fine ... \n");

	
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, "3490", &hints, &res);

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

	// bind the socket with the port we passed to getaddrinfo()

	bind(sockfd, res->ai_addr, res->ai_addrlen);

}


