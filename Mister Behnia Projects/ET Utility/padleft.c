#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h>
#include <windows.h>

typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned long   uint32;
typedef long int 		uint64;
typedef long long int  	int64;
typedef signed char    	int8;
typedef signed short   	int16;
typedef signed long    	int32;

int main()
{

    uint8 buffer[12] = { 0 };
    strcpy(buffer, "abcd");
    padLeft(buffer, 5);
    return 0;
}

void padLeft(uint8* buffer, const uint8 finalLength)
{
    int     bufferLen = strlen((const char*)buffer);      /** buffer lenght */

    if (bufferLen >= finalLength)
        return;

    uint8 finalBuf[22 + 1];
    memset(finalBuf, '0', finalLength - bufferLen);
    memcpy(finalBuf + (finalLength - bufferLen), buffer, bufferLen);


    finalBuf[finalLength] = '\0'; // This line sets the null-terminator in a wrong place , use funalBuf[finalLength] = '\0'
    memcpy(buffer, finalBuf, finalLength);

    /* showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "PAD LEFT");
     comportHexShow(buffer, finalLength); */
}

