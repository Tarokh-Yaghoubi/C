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


//void padLeft(uint8* buffer, const uint8 finalLength)
//{
//    // int     bufferSize = sizeof(*buffer); /* wrong implement no usage */
//    int lengh_fix;
//    int 	bufferLen = strlen((const char*)buffer);      /** buffer lenght */
//    uint8	finalBuf[22] = "0000000000000000000000";
//    
//    if (finalLength >= 22) // Babak Hajizadeh 
//    {
//        //lengh_fix = 21;
//        //padLeft(buffer, lengh_fix); // const finalLengh could not be modified recursively
//
//        /* buffer length mismatch */
//        /* TODO: showlog propper error */
//        return;
//    }
//    finalBuf[finalLength] = 0; //gpt: this line sets the null terminator at a wrong index , it shoud be set at finalBuf[funalLength - 1]
//    
//
//
//    memmove(&finalBuf[finalLength - bufferLen], buffer, bufferLen); 
//    memcpy(buffer, finalBuf, finalLength + 1/* +1 babak*/);
//    /* Babak: in order to explicitly null - terminate the outter buffer
//    for more safety however buffers are often nullt-erminated */
//}

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


    finalBuf[finalLength] = '\0'; // gpt : this line sets the null-terminator in a wrong place , use funalBuf[finalLKength] = 0
    // memmove(&finalBuf[finalLength - bufferLen], buffer, bufferLen);
    memcpy(buffer, finalBuf, finalLength);

    /* showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "PAD LEFT");
     comportHexShow(buffer, finalLength); */
}

