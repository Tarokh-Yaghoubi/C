/*

	Tarokh (Jacob) Yaghoubi , A program to Fill zero from the 
	left-side of a character array that contains numbers 
	The Buffer must be 12 characters maximum which is the numbers 
	that you inject in the buffer , plus the zeros .

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char uint8;

int main(int argc, char* argv[])
{
	// defined unsigned char 
	int size = 0;
	int max = 12;
	char zero[13];
	char buffer[12] = "12345678";
	if (strlen(buffer) > 12)
		return;
	//char zero[12] = "000000000000";
	int len = strlen(buffer);
	max = max - len;
	for (int i = 0; i < max; i++)
	{
		zero[i] = '0';
	}
	//memcpy(&buffer[0], '0', max);
	for (int i = 0, j = max; i < strlen(buffer) && j <= 12; i++, j++)
	{
		zero[j] = buffer[i];
	}
	zero[12] = '\0';

	for (int i = 0; i < 12; i++)
		printf("%c", zero[i]);

	return 0;
}