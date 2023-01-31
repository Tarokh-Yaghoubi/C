#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* #include <stdio.h>

#include <string.h>

int is_in(const char* str);

int main()
{
	char* str = "tarokh is a boy";

	is_in(str);

}

int is_in(const char* str)
{
	while (*str)
	{
		if (*str == ' ') printf("%c", '-');
		else printf("%c", *str);
		str++;
	}
}

*/

typedef unsigned char uint8;


void PadLeft(uint8* buffer, const uint8 finalLength);

int main(int argc, char* argv[])
{
	// Write your code here
	uint8 buffer[10 + 1] = { 0 };
	strcpy(buffer, "12");
	PadLeft(buffer, 10);
	
	return 0;
}

void PadLeft(uint8* buffer, const uint8 finalLength)
{
	int 	bufferLen = strlen((const char*)buffer);      /** buffer lenght */
	uint8	finalBuf[22] = "0000000000000000000000";

	finalBuf[finalLength] = 0;
	memmove(&finalBuf[finalLength - bufferLen], buffer, bufferLen);
	memcpy(buffer, finalBuf, finalLength);

}
