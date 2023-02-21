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


void padLeft(uint8* buffer, const uint8 finalLength)
{
    // int     bufferSize = sizeof(*buffer); /* wrong implement no usage */
    int lengh_fix;
    int 	bufferLen = strlen((const char*)buffer);      /** buffer lenght */
    uint8	finalBuf[22] = "0000000000000000000000";
    
    if (finalLength >= 22) // Babak Hajizadeh 
    {
        //lengh_fix = 21;
        //padLeft(buffer, lengh_fix); // const finalLengh could not be modified recursively

        /* buffer length mismatch */
        /* TODO: showlog propper error */
        return;
    }
    finalBuf[finalLength] = 0; 
    memmove(&finalBuf[finalLength - bufferLen], buffer, bufferLen); 
    memcpy(buffer, finalBuf, finalLength + 1/* +1 babak*/);
    /* Babak: in order to explicitly null - terminate the outter buffer
    for more safety however buffers are often nullt-erminated */
}

int main()
{

    uint8 buffer[1000] = { 0 };
    strcpy(buffer, "abcd");
    padLeft(buffer, 22);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

