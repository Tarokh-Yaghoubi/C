/*

	Show IP addresses for a host given in the command line , Tarokh (Jacob) Yaghoubi

*/


// You have to call WSAStartup before working with the socket library in windows 
// This is not essential in linux .


#define WIN32_LEAN_AND_MEAN	  // say this if you included windows.h and WinSock2.h

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>

#include <ws2def.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{

	// Making an Instance from WSADATA
	int status;
	char ipstr[INET6_ADDRSTRLEN];
	char* test;

	struct addrinfo hints, * res, * p;


	WSADATA wsaData;



	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		//		fprintf(stderr, "WSAStartup Failed \n");
		printf("WSAStartup Failed \n");

		exit(1);
	}

	if (LOBYTE(wsaData.wVersion) != 2 ||
		HIBYTE(wsaData.wVersion) != 2)
	{
		//		fprintf(stderr, "Version 2.2 of WinSock is not Available \n");
		printf("Version 2.2 of WinSock is not available \n");
		WSACleanup();		// This is the function that you want to call when you are done with the WinSock Library
		exit(2);
	}

	else
	{
		printf("everything is ok \n");
	}


	if (argc != 2)
	{
		fprintf(stderr, "usage: showip hostname");
		return 1;
	}
	else
	{
		printf("the arg is : %s \n", argv[1]);
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if (status = getaddrinfo(argv[1], NULL, &hints, &res) != 0)
	{
		fprintf(stderr, "getaddrinfo error : %s\n", gai_strerror(status));
		return 2;
	}

	printf("Ip addresses for : %s \n\n", argv[1]);
	for (p = res; p != NULL; p = p->ai_next)
	{

		void* addr;
		char* ipver;


		if (p->ai_family == AF_INET)	//	ip version four
		{ 
			struct sockaddr_in* ipv4 = (struct sockaddr_in*)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPV4";

		}
		else {		// Ip version six 

			struct sockaddr_in6* ipv6 = (struct sockaddr_in6*)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPV6";

		}

		//		Convert the IP to a string and print it 

		test = inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
		inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
		printf(" %s : %s \n", ipver, ipstr);
	}

	freeaddrinfo(res);
	return 0;
}

