
#define WIN32_LEAN_AND_MEAN // say this if you included windows.h and WinSock2.h

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* You need to make a call to WSAStartup() before doing anyting else with the socket library */
/* You pass in the WinSock version you desire to this library (e.g version 2.2) And then you can
   Check the result to make sure that version is available */

int main()
{
	WSADATA wsaData;

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
	
	// In windows you can not use close() to close a socket , you need to use closesocket() instead
}