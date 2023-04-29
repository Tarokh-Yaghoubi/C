// Tarokh (Jacob) Yaghoubi , Sockets  
#define WIN32_LEAN_AND_MEAN	  // say this if you included windows.h and WinSock2.h

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>

#include <ws2def.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* You need to make a call to WSAStartup() before doing anyting else with the socket library */
/* You pass in the WinSock version you desire to this library (e.g version 2.2) And then you can
   Check the result to make sure that version is available */

int main()
{

	WSADATA wsaData;
	// getaddrinfo();
	
//	struct sockaddr_in sa;		//	IpV4
//	struct sockaddr_in6 sa6;	//	IpV6

	
	struct addrinfo address_info;	// addrinfo struct 
	struct sockaddr socket_Address;	// sockaddr struct , ai_addr points to sockaddr in addrinfo
	struct sockaddr_in sa;	// Socket Address Internet , a parallel structure to deal with the struct sockaddr 
	struct sockaddr_in6 sa6;
	struct sockaddr_storage socketaddress_storage;	// This structure is designed large enough  to hold both IpV4 and IpV6 structures 
	// It is very similar to struct sockaddr except it is larger .
	// addrinfo.ai_family;
	// socket_Address.sa_family;
	// inet_pton() pton -> presentation to network , convert IpV4 and IpV6 Addresses from text to binary form 
	// It converts an IP address "10.12.110.57" in to struct in_addr or struct in6_addr depending 
	// On whether you specify AF_INET or AF_INET6
	// pton can be also read as printable to network .
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		// fprintf(stderr, "WSAStartup Failed \n");
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
		printf("everything is ok");
	}

	// The Conversion from text to binary can be made as follow using the inet_pton() method .

	inet_pton(AF_INET, "192.168.1.55", &(sa.sin_addr));	// IpV4
	inet_pton(AF_INET6, "2001:db8:63b3 : 1::3490", &(sa6.sin6_addr));	// IpV6

	// the old way of doing this is using the functions inet_addr() and inet_aton() , these are Obsolete and 
	// do not work with IPV6 

	// In windows you can not use close() to close a socket , you need to use closesocket() instead
	// a Socket descriptor has the following type 

//	inet_ntop(); // Network to Printable , Convert IpV4 and IpV6 addresses from Binary to text form

	// Example : 

	
}
