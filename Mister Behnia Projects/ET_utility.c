
/*! \file    utility.c
 *  \author  Hamidreza.Zandieh
 *  \version 1.0
 *  \date    1388/02 - 1388/08
 */
#include <string.h> //mgh
#include <stdio.h> //mgh
#include <stdlib.h> //mgh
#include <ctype.h> //mgh

#include "debug.h"

#include "ET_common.h"
#include "ET_dateTime.h"
#include "ET_binaryTree.h"
#include "ET_menu.h"

#include "ET_cardSpec.h"
#include "ET_terminalSpec.h" //mgh
#include "ET_POSSpecific.h"
#include "ET_initialize.h"
#include "ET_utility.h"
#include "ET_log.h" //mgh
#include "ET_printerWrapper.h"
#include "ET_keyManagerWrapper.h"


/**
 * get input digits number.
 * @param   input input integer.
 * @return  num of input digits.
 */
//int digitNum(int input)
//{
//    int output = 0;            /** num of input digits */
//    
//    if (input == 0) 
//        return 1;
//    
//    while (input > 0) 
//    {
//        input /= 10;
//        output++;
//    }
//    
//    return output;
//}


/**
 * convert IP to string.
 * @param   IP IP in IP format.
 * @param   strIP string format.
 */
void ipToString(uint8* mIP, uint8* strIP)
{
    sprintf(strIP, "%d.%d.%d.%d", mIP[0], mIP[1], mIP[2], mIP[3]);

    showLog(JUST_NEWLAND, __FILE__, __LINE__, DEBUG, "", "strIP is : %s", strIP);		

    //int   ipPartNum         = 0;        /** IP part number, 0-3 */
    //int   ipPartDigitNum	= 0;        /** IP part digits number, 0-2 */
    //uint8 ipPatVal          = 0;        /** IP part value */
    //uint8 quotient          = 0;        /** quotient of divison */
    //uint8 divisionRes		= 0;        /** division result */
    //int   strIpLen          = 0;        /** string IP lenght */
    //int   isFirstInPart		= 1;        /** set if this digit is first in part */
    //
    //for (ipPartNum = 0; ipPartNum < 4; ipPartNum++) 
    //{
    //    if (ipPartNum) 
    //        strIP[strIpLen++] = '.';
    //    
    //    ipPatVal = IP[ipPartNum];
    //    isFirstInPart = 1;
    //    quotient = 100;
    //    
    //    for (ipPartDigitNum = 0; ipPartDigitNum < 3; ipPartDigitNum++) 
    //    {
    //        divisionRes = ipPatVal / quotient;
    //        
    //        if (divisionRes != 0 || !isFirstInPart || ipPartDigitNum == 2) 
    //        {
    //            strIP[strIpLen++] = divisionRes + (uint8)'0';
    //            
    //            if (divisionRes != 0) 
    //                isFirstInPart=0;
    //        }
    //        
    //        ipPatVal %= quotient;
    //        quotient /= 10;
    //    }
    //}
    //strIP[strIpLen] = 0;
}


/*
 * convert string input to string with comma.
 * @param   input input value without comma.
 * @param   output output value with comma.
 */
void makeValueWithCommaStr(uint8* input, uint8* output)
{
    int counter		= 0;                            /** loop counter */
    int outputLen	= 0;                            /** output string lenght */
    int commaPart	= 0;                            /** comma index in output */
    int index		= 0;                            /** index in output */
    int inputLen	= strlen((const char*)input);   /** input value lenght */
    
    if (inputLen == 0)
    {
        output[0] = '0';
        output[1] = 0;
        return;
    }
    
    outputLen = (inputLen % 3 == 0) ? (inputLen + (inputLen / 3) - 1) : 
                                      (inputLen + (inputLen / 3));
    commaPart = inputLen % 3;
    if (commaPart == 0) 
        commaPart += 3;
    
    for (counter = 0, index = 0; index < outputLen, counter < inputLen; counter++, index++)
    {
        if (counter == commaPart)
        {
            output[index] = ',';
            index++;
            commaPart += 3;
        }
        
        output[index] =  input[counter];

    }
    
    output[outputLen] = 0;
}


/**
 * convert uint32 input to string with comma.
 * @param   value input value without comma ant uint32 form.
 * @param   valueWithCommaStr output value with comma.
 * @see     makeValueWithCommaStr()
 */
void makeValueWithCommaInt(uint32 value, uint8* valueWithCommaStr)
{
    uint8 valueStr[50] = {0};              /** input value in string form */

    sprintf(valueStr, "%lu", value);
    
	showLog(JUST_NEWLAND, __FILE__, __LINE__, DEBUG, "", "value is : %lu", value);
	showLog(JUST_NEWLAND, __FILE__, __LINE__, DEBUG, "", "valueStr is : %s", valueStr);
	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "value is : %lu", value);
	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "valueStr is : %s", valueStr);

    //mgh showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "value is : %lu", value);
    //mgh showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "valueStr is : %s", valueStr);

    if (strlen((const char*)valueStr) == 0)
    {
        valueWithCommaStr[0] = '0';
        valueWithCommaStr[1] = 0;
    }
    else
        makeValueWithCommaStr(valueStr, valueWithCommaStr);
}


/**
 * make card ID for display on LCD.
 * @param   cardIdStr card Id.
 * @param   result card Id for display on LCD.
 * @return  TRUE or FALSE.
 */
void maskCardId(uint8* cardIdStr, uint8* result)
{
    int   counter       = 0;            /** loop counter */
    uint8 cardID[18]	= {0};          /** card ID */

    strncpy(cardID, cardIdStr, 17);
    cardID[17] = 0;

    ////FKH 130627 : commented because of SHAPARAK
//#ifdef SEPAH
//    for (counter = 0; counter < 12; counter++) 
//        cardID[counter] = '*';    //Star
//#else
    for (counter = 6; counter < 12; counter++) 
        cardID[counter] = '*';    //Star
//#endif
////////////////////////////
	for (counter = 9; counter < 13; counter++)
        cardID[counter] = cardID[counter + 3];    //Star
    
	cardID[13] = 0;
///////////////////////////
    strcpy((char*)result, cardID);
}


/**
 * convert number string to int
 * @param   inputStr input string.
 * @param   size size of input string.
 * @return  number.
 */
int zeroPadStrToInt(uint8* inputStr, int size)
{
    int   counter	= 0;                /** loop counter */
    int   value		= 0;                /** number, return value */
    int   sign		= 1;                /** number sign */
    uint8 nonZero	= FALSE;            /** set if escape all zeros */
    
    for (counter = 0; counter < size; counter++) 
    {
        if (inputStr[counter] == '-') 
        {
            if (!nonZero) 
            {
                nonZero = TRUE;
                sign = -1;
                continue;
            }
            else 
                return 0;
        }
        else if (inputStr[counter] > '0' && inputStr[counter] <='9') 
            nonZero = TRUE;
        
        if (inputStr[counter] >= '0' && inputStr[counter] <='9') 
            value = value * 10 + (inputStr[counter] - '0');
    }
    
    return (sign * value);
}


/**
 * compact string, in input chars have 8 bit but in output chars will have 4 bit.
 * @param   input input string.
 * @param   output output string.
 * @param   index index in output.
 * @param   inputLen input string lenght.
 * @param   padElement pad element.          
 * @param   padDir pad direction.
 */
void asciiToBCD(uint8* input, uint8* output, int inputLen, 
                       uint8 padElement, uint8 padDir) 
{
    int		counter         = 0;	/** loop counter */
    int		index           = 0;
    uint8	secondMid       = 0;    /** second mid */ 
    uint8   firstMid        = 0;    /** first mid */
        
    for (counter = 0; counter < inputLen; counter++, index++) 
    {
        if ((input[counter] == '='))
            firstMid = 13;
        else if (input[counter] >= '0' && input[counter] <= '9')
            firstMid = input[counter] - '0';
        else if (input[counter] >= 'A' && input[counter] <= 'F')
            firstMid = input[counter] - 'A' + 10;
        else
            firstMid = input[counter] - 'a' + 10;
                                         
        if (inputLen % 2 != 0)
        {
            if (padDir == 0 && counter == 0) 
            {
                output[index] = padElement * 16 + firstMid;
                continue;
            }
            else if (padDir == 1 && counter == inputLen - 1) 
            {
                output[index] = firstMid * 16 + padElement;
                continue;
            }
        }
                 
        counter++;
        
        if ((input[counter] == '='))
            secondMid = 13;
        else if (input[counter] >= '0' && input[counter] <= '9')
            secondMid = input[counter] - '0';
        else if (input[counter] >= 'A' && input[counter] <= 'F')
            secondMid = input[counter] - 'A' + 10;
        else
            secondMid = input[counter] - 'a' + 10;
                                                    
        output[index] = firstMid * 16 + secondMid;
    }
}


/**
 * convert HEX character to binary.
 * @param   input hex character. 
 * @return  binary value.
 */
uint8 hexCharToBin(uint8 input) 
{
    if (input >= '0' && input <= '9') 
        return input - '0';
    else if (input >= 'a' && input <= 'f')
        return input - 'a' + 10;
    else if (input >= 'A' && input <= 'F') 
        return input - 'A' + 10;
    else 
        return 0;
}


/**
 * convert bin character to HEX.
 * @param   input ninary character. 
 * @return  HEX value.
 */
uint8 binCharToHex(uint8 input) 
{
    if (input < 10)
        return input + '0';
    else
        return input - 10 + 'A';
}


uint64 StrToUInt64(uint8* inputStr, int size)
{
    int		counter = 0;		/** loop counter */
    uint64	value	= 0;            /** number, return value */
    
    for (counter = 0; counter < size; counter++) 
    {
        if (inputStr[counter] >= '0' && inputStr[counter] <= '9') 
            value = value * 10 + (inputStr[counter] - '0');
    }
    
    return value;
}


/**
 * convert binary string to HEX string.
 * @param   binStr input array in binary form.
 * @param   hexStr output array in hex form. 
 * @param   binLen lenght. 
 * @see     binCharToHex()  
 */
void binStrToHex(uint8* binStr, uint8* hexStr, int binLen) 
{
    uint8 HexChar = 0;               /** HEX character */

    while (binLen)
    {
        HexChar = binStr[--binLen];
        hexStr[2 * binLen + 1] = binCharToHex(HexChar % 16);
        hexStr[2 * binLen] = binCharToHex(HexChar / 16);
    }
}


/**
 * calculate XOR with two string.
 * @param   firstOperand first operand.
 * @param   secondOperand second input.
 * @param   result operation result.
 * @param   len lenght.
 */
//void XOR1(uint8* firstOperand, uint8* secondOperand, uint8* result, int len) 
//{
//    int counter = 0;                            /** loop counter */
//    
//    for (counter = 0; counter < len; counter++) 
//        result[counter] = firstOperand[counter] ^ secondOperand[counter];
//}


/**
 * check each bit set or not in uint8 type variable.
 * @param   index index in byte bits.
 * @param   input input byte.
 * @return  TRUE or FALSE.
 */
uint8 isBitSet(int index, uint8 input)
{
    input = input << (7 - index);
    input = input >> 7;
    return (uint8)input;
}

/**
 * show the hex log data in serial port
 * @param	ucDataToPrint	data to show
 * @param	iLen			length of data
 */
void comportHexShow(uint8* ucDataToPrint, uint16 iLen)
{
    int		i           = 0;
    int		k           = 0;
    char	szTemp[6]   = {0};
    char	szLine[51]  = {0};

    memset(szLine, 0x00, sizeof(szLine));
    for (i = 0; i < iLen; i++)
    {
    	if (k == 7)
            sprintf(szTemp, "%02X   ", ucDataToPrint[i]);
    	else
        sprintf(szTemp, "%02X ", ucDataToPrint[i]);
        strcat(szLine, szTemp);
        k++;
        if (k == HEX_COUNT_SHOW)
        {
			showLog(ALL_POS, __FILE__, __LINE__, TRACE, "", "%s", szLine);
            memset(szLine, 0x00, sizeof(szLine));
            k = 0;
            //delay(50, JUST_NEWLAND);
        }
    }
    if (k)
    {
		showLog(ALL_POS, __FILE__, __LINE__, TRACE, "",  "%s", szLine);
    }
}


//uint32 ulBcdToLong ( uint8* src, int32 l_src )
//{
//	int32 i, high, low;
//
//	uint32 dst = 0;
//
//	for (i = 0; i < l_src; i++)
//	{
//		low    = 0x0F & src[i];
//		high   = (0xF0 & src[i]) >> 4;
//		dst *= 10;
//		dst += high;
//		dst *= 10;
//		dst += low;
//	}
//	return dst;
//}

/**
 * wrap farsi words
 * @param	str				the input string
 * @param	separatedStr	the output string separated
 * @param	maxInLine		the maximum character can be displayed in a line
 * @return	the count of separated string	
 */
//int wordWrapFarsi(uint8* str, uint8 separatedStr[10][50], uint8 maxInLine)
//{
//    int     lengh		= 0;
//    int     loop		= 0;
//    uint8   cpyStr[200] = {0};
//
//    strcpy(cpyStr, str);
//    lengh = strlen(cpyStr);
//
//    while (lengh > maxInLine)
//    {
//        lengh -= maxInLine;
//        if ((cpyStr[lengh] == ' ') || (cpyStr[lengh - 1] == ' '))
//        {
//            strcpy(separatedStr[loop], &cpyStr[lengh]);
//            loop++;
//            if (cpyStr[lengh] == ' ')
//                cpyStr[lengh] = '\0';
//            else
//                cpyStr[lengh - 1] = '\0';
//        }
//        else
//        {
//            while (TRUE)
//            {
//                lengh++;
//                if (cpyStr[lengh] == '\0')
//                {
//                    lengh -= maxInLine;
//                    break;
//                }
//                if (cpyStr[lengh] == ' ')
//                    break;
//            }
//            strcpy(separatedStr[loop], &cpyStr[lengh]);
//            loop++;
//            cpyStr[lengh] = '\0';
//        }
//    }
//    strcpy(separatedStr[loop], &cpyStr[0]);
//    return loop;
//}

void strToToken_2(uint8* str, uint8* token, uint8 * delimiter);
int wordWrapFarsi_1(uint8* str, uint8 separatedStr[10][200], uint16 maxInLine, uint8 scrOrPrn)
{
    int     lengh		= 0;  
    int     loop		= 0;
    uint8   cpyStr[350] = {0};
    
    uint8	tok[100] = {0};
    uint8	token[350] = {0};
    uint8   singleWord[20][100];
    uint8	cnt = 0;

    memset(cpyStr,0x00, sizeof(cpyStr));

    //TRACE_HEX((str, strlen(str), "wordWrapFarsi lengh: %d, token:", strlen(str)));

    strcpy(token, str);

    //TRACE(("wordWrapFarsi"));

    if (scrOrPrn == 0)
    	iNDK_ScrGetTrueTypeFontSize(token, strlen(token), &lengh, NULL);
    else
    	iNDK_PrnGetTrueTypeFontSize(token, strlen(token), &lengh, NULL);

    //TRACE_HEX((token, strlen(token), "wordWrapFarsi lengh: %d, token:", lengh));

    if (lengh <= maxInLine)
    {
    	strcpy(separatedStr[0], token);
    	return 0;
    }

    strToToken(token, tok, " ");

    while (tok[0] != 0)
	{

    	strcat(cpyStr, tok);
    	strcat(cpyStr, " ");

    	if (scrOrPrn == 0)
    		iNDK_ScrGetTrueTypeFontSize(cpyStr, strlen(cpyStr), &lengh, NULL);
    	else
    	    iNDK_PrnGetTrueTypeFontSize(cpyStr, strlen(cpyStr), &lengh, NULL);

//    	TRACE_HEX((cpyStr, strlen(cpyStr), "wordWrapFarsi lengh: %d, cpyStr:", lengh));

//    	//TRACE(("cpyStr len: %d", strlen(cpyStr)));
//    	//TRACE(("separatedStr[cnt: %d] len: %d", cnt, strlen(separatedStr[cnt])));
//    	//TRACE(("singleWord[cnt: %d] len: %d", cnt, strlen(singleWord[cnt])));
//    	//TRACE(("tok len: %d", strlen(tok)));
//    	//TRACE(("token len: %d", strlen(token)));
//    	//TRACE(("lengh: %d, maxInLine: %d", lengh, maxInLine));
//

    	if (lengh <= maxInLine)
    	{
    		strcpy(singleWord[cnt], cpyStr);
    	}
    	else
    	{
    		strcpy(separatedStr[cnt], singleWord[cnt]);
    		cnt++;
    		strcpy(singleWord[cnt], tok);
    		memset(cpyStr,0x00, sizeof(cpyStr));
    		strcpy(cpyStr, tok);
    		strcat(cpyStr, " ");
    	}

    	strToToken(token, tok, " ");
	}

    strcpy(separatedStr[cnt], cpyStr);

    return cnt;

//
//    strcpy(cpyStr, str);
//    lengh = strlen(cpyStr);
//
//    while (lengh > maxInLine)
//    {
//        lengh -= maxInLine;
//        if ((cpyStr[lengh] == ' ') || (cpyStr[lengh - 1] == ' '))
//        {
//            strcpy(separatedStr[loop], &cpyStr[lengh]);
//            loop++;
//            if (cpyStr[lengh] == ' ')
//                cpyStr[lengh] = '\0';
//            else
//                cpyStr[lengh - 1] = '\0';
//        }
//        else
//        {
//            while (TRUE)
//            {
//                lengh++;
//                if (cpyStr[lengh] == '\0')
//                {
//                    lengh -= maxInLine;
//                    break;
//                }
//                if (cpyStr[lengh] == ' ')
//                    break;
//            }
//            strcpy(separatedStr[loop], &cpyStr[lengh]);
//            loop++;
//            cpyStr[lengh] = '\0';
//        }
//    }
//    strcpy(separatedStr[loop], &cpyStr[0]);
//    return loop;
}

#if (0) // KB [14010228]
int wordWrapFarsi_2(uint8* str, uint8 separatedStr[10][200], uint16 maxInLine, uint8 scrOrPrn)
{
    int     lengh		= 0;
    int     loop		= 0;
    uint8   cpyStr[350] = {0};

    uint8	tok[100] = {0};
    uint8	token[350] = {0};
    uint8   singleWord[20][100];
    uint8	cnt = 0;

    memset(cpyStr,0x00, sizeof(cpyStr));

    //TRACE_HEX((str, strlen(str), "wordWrapFarsi lengh: %d, token:", strlen(str)));

    strcpy(token, str);

    //TRACE(("wordWrapFarsi"));

    if (scrOrPrn == 0)
    	iNDK_ScrGetTrueTypeFontSize(token, strlen(token), &lengh, NULL);
    else
    	iNDK_PrnGetTrueTypeFontSize(token, strlen(token), &lengh, NULL);

    //TRACE_HEX((token, strlen(token), "wordWrapFarsi lengh: %d, token:", lengh));

    if (lengh <= maxInLine)
    {
    	strcpy(separatedStr[0], token);
    	return 0;
    }

    //strToToken(token, tok, " ");
    strToToken_2(token, tok, " ");

    while (tok[0] != 0)
	{

    	strcat(cpyStr, tok);
    	strcat(cpyStr, " ");

    	if (scrOrPrn == 0)
    		iNDK_ScrGetTrueTypeFontSize(cpyStr, strlen(cpyStr), &lengh, NULL);
    	else
    	    iNDK_PrnGetTrueTypeFontSize(cpyStr, strlen(cpyStr), &lengh, NULL);

//    	TRACE_HEX((cpyStr, strlen(cpyStr), "wordWrapFarsi lengh: %d, cpyStr:", lengh));

//    	//TRACE(("cpyStr len: %d", strlen(cpyStr)));
//    	//TRACE(("separatedStr[cnt: %d] len: %d", cnt, strlen(separatedStr[cnt])));
//    	//TRACE(("singleWord[cnt: %d] len: %d", cnt, strlen(singleWord[cnt])));
//    	//TRACE(("tok len: %d", strlen(tok)));
//    	//TRACE(("token len: %d", strlen(token)));
//    	//TRACE(("lengh: %d, maxInLine: %d", lengh, maxInLine));
//

    	if (lengh <= maxInLine)
    	{
    		strcpy(singleWord[cnt], cpyStr);
    	}
    	else
    	{
    		strcpy(separatedStr[cnt], singleWord[cnt]);
    		cnt++;
    		strcpy(singleWord[cnt], tok);
    		memset(cpyStr,0x00, sizeof(cpyStr));
    		strcpy(cpyStr, tok);
    		strcat(cpyStr, " ");
    	}

    	//strToToken(token, tok, " ");
    	strToToken_2(token, tok, " ");
	}

    strcpy(separatedStr[cnt], cpyStr);

    return cnt;

//
//    strcpy(cpyStr, str);
//    lengh = strlen(cpyStr);
//
//    while (lengh > maxInLine)
//    {
//        lengh -= maxInLine;
//        if ((cpyStr[lengh] == ' ') || (cpyStr[lengh - 1] == ' '))
//        {
//            strcpy(separatedStr[loop], &cpyStr[lengh]);
//            loop++;
//            if (cpyStr[lengh] == ' ')
//                cpyStr[lengh] = '\0';
//            else
//                cpyStr[lengh - 1] = '\0';
//        }
//        else
//        {
//            while (TRUE)
//            {
//                lengh++;
//                if (cpyStr[lengh] == '\0')
//                {
//                    lengh -= maxInLine;
//                    break;
//                }
//                if (cpyStr[lengh] == ' ')
//                    break;
//            }
//            strcpy(separatedStr[loop], &cpyStr[lengh]);
//            loop++;
//            cpyStr[lengh] = '\0';
//        }
//    }
//    strcpy(separatedStr[loop], &cpyStr[0]);
//    return loop;
}
#endif
int wordWrapFarsi_3(uint8* str, uint8 separatedStr[10][200], uint16 maxInLine, uint8 scrOrPrn)
{
//    int     lengh		= 0;
//    int     loop		= 0;
//    uint8   cpyStr[350] = {0};

    uint8	tok[100] = { 0 };
    uint8	token[350] = { 0 };
//  uint8   singleWord[20][100];
    uint8	cnt = 0;
    uint8   idx = 0;
    uint8   i = 0;

    uint8 localSeparatedStr[10][200];

//    memset(cpyStr,0x00, sizeof(cpyStr));

    memset(localSeparatedStr, 0x00, sizeof(localSeparatedStr));

    //TRACE_HEX((str, strlen(str), "wordWrapFarsi lengh: %d, token:", strlen(str)));

    if (strstr((const char* )str, "\n") == 0)
    {
        return wordWrapFarsi_1(str, separatedStr, maxInLine, scrOrPrn);
    }

    strcpy((char*)token, (const char*)str);

    strToToken((char*)token, (char*)tok, "\n");

    while (tok[0] != 0)
    {
        memset(localSeparatedStr, 0x00, sizeof(localSeparatedStr));

        cnt = wordWrapFarsi_1(tok, localSeparatedStr, maxInLine, scrOrPrn);

        for (i = 0; i <= cnt; ++i)
        {
            strcpy((char*)separatedStr[idx++], (const char*)localSeparatedStr[i]);
        }

        strToToken((char*)token, (char*)tok, "\n");
    }

    if (idx == 0 )
    {
    	return 0;
    }

    return idx - 1;
}

int wordWrapFarsi(uint8* str, uint8 separatedStr[10][200], uint16 maxInLine, uint8 scrOrPrn)
{
//	return wordWrapFarsi_1(str, separatedStr, maxInLine, scrOrPrn);
//	return wordWrapFarsi_2(str, separatedStr, maxInLine, scrOrPrn);
	return wordWrapFarsi_3(str, separatedStr, maxInLine, scrOrPrn);
}
/**
 * wrap english words
 * @param	str				the input string
 * @param	separatedStr	the output string separated
 * @param	maxInLine		the maximum character can be displayed in a line
 * @return	the count of separated string	
 */
int wordWrapEnglish(uint8 str[200], uint8 separatedStr[10][200], uint8 maxInLine) // KB 1401-03-03
{
    int     lengh           = 0;  
    int     currentIndex	= 0; 
    int     preIndex		= 0;
    int     loop            = 0;
    uint8   cpyStr[200]     = {0};
    
    strcpy(cpyStr, str);
    lengh = strlen(cpyStr);
    while ((lengh - currentIndex) > maxInLine)
    {
        currentIndex = preIndex + maxInLine;
        if ((cpyStr[currentIndex] == ' ') || (cpyStr[currentIndex + 1] == ' '))
        {
            if (cpyStr[currentIndex] == ' ')
                cpyStr[currentIndex] = '\0';
            else
                cpyStr[++currentIndex] = '\0'; 
            strcpy(separatedStr[loop++], &cpyStr[preIndex]);
            preIndex = currentIndex + 1;
        }
        else
        {
            while (TRUE)
            {
                currentIndex--;
                if ((cpyStr[currentIndex] == '\0') || (currentIndex == 0))
                { 
                    currentIndex = preIndex + maxInLine;
                    break;
                }
                if (cpyStr[currentIndex] == ' ')
                    break;
            }
            if (cpyStr[currentIndex] == ' ')
            {
                cpyStr[currentIndex] = '\0';
                strcpy(separatedStr[loop++], &cpyStr[preIndex]);
                preIndex = currentIndex + 1;
            }
            else
            {
                memmove(cpyStr + currentIndex + 1, cpyStr + currentIndex, (lengh - currentIndex));
                cpyStr[currentIndex] = '\0';
                strcpy(separatedStr[loop++], &cpyStr[preIndex]);
                preIndex = currentIndex + 1;
            }
        }
    }
    strcpy(separatedStr[loop], &cpyStr[preIndex]);
    
    return loop;
}

/**
 * convert long to BCD form
 * @param	src		the input number in long form
 * @param	dst		the output in BCD code
 * @param	len		length of input
 */
void longToBCD(uint32 src, uint8* dst, int32 len)
{
	int32	i       = 0;
	int32	high    = 0;
	int32	low     = 0;

	for (i = len - 1; i >= 0; i--)
	{
		low  = (int)(src % 10);
		src /= 10;
		high = (int)(src % 10);
		src /= 10;
		dst[i] = (unsigned char)((high << 4) | low);
	}
}


//void vLongToBcdLH ( uint32 src, uint8* dst, int32 l_dst )
//{
//	int32 i, high, low;
//	uint8 tmp;
//
//	for (i = l_dst - 1; i >= 0; i--)
//	{
//		low  = (int)(src % 10);
//		src /= 10;
//		high = (int)(src % 10);
//		src /= 10;
//		dst[i] = (unsigned char)((high << 4) | low);
//	}
//
//	tmp = dst[0];
//	dst[0] = dst[1];
//	dst[1] = tmp;
//}

/**
 * convert string to integer number
 * @param	inputStr	the input string
 * @return	the integer number
 */
int32 strToInt(uint8* inputStr) 
{
    uint8 buffer[50]	= {0};
    uint8 counter       = 0;                /** loop counter */
    int32 value         = 0;                /** number, return value */
    int8  sign          = 1;                /** number sign */

    strcpy(buffer, inputStr);
    removePadLeft(buffer, '0');

    if (buffer[0] == '-') 
    {
        sign = -1;
        counter++;
    }
    
    for (counter; counter < strlen(buffer); counter++) 
    {
        if (buffer[counter] >= '0' && buffer[counter] <= '9') 
            value = value * 10 + (buffer[counter] - '0');
        else
            return 0;
    }

    return (sign * value);
}


/**
 * convert HEX string to binary string.
 * @param   hexStr input string in hex form.
 * @param   binStr output strng in binary form. 
 * @param   hexLen lenght. 
 * @see     hexCharToBin()  
 */
void hex2bin(uint8* hexStr, uint8* binStr, int hexLen) 
{
    int counter = 0;                    /** loop counter */
    
    if (hexLen % 2 != 0) 
        return;
    
    for (counter = 0; counter < hexLen / 2; counter++) 
        binStr[counter] = hexCharToBin(hexStr[counter * 2]) * 
                          16 + hexCharToBin(hexStr[counter * 2 + 1]);
}


/**
 * remove specified charcter from left side of string.
 * @param   buffer input/output string.
 * @param   ch charcter.
 */
void removePadLeft(uint8* buffer, uint8 pad)
{
    int index		= 0;								/** index in buffer */
    int bufferLen	= strlen(buffer);      /** buffer lenght */
    
    while (buffer[index] == pad)
        index++;
    
    if (index == 0)
    	return;
    
    memmove(buffer, &buffer[index], bufferLen - index);
    buffer[bufferLen - index] = 0;
}


/**
 * pad buffer string with '0'
 * @param   buffer input/output string.
 * @param   final length.
 */
void padLeft(uint8* buffer, const uint8 finalLength)
{
    int 	bufferLen		= strlen((const char*)buffer);      /** buffer lenght */
    uint8	finalBuf[22]	= "0000000000000000000000";
    
    finalBuf[finalLength] = 0;
    memmove(&finalBuf[finalLength - bufferLen], buffer, bufferLen);
    memcpy(buffer, finalBuf, finalLength);
    showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "PAD LEFT");
    comportHexShow(buffer, finalLength);
}


/**
 * remove specified charcter from right side of string.
 * @param   buffer	 input/output string.
 * @param   pad		 the charcter to remove
 */
void removePadRight(uint8* buffer, uint8 pad)
{
    int index = strlen(buffer) - 1;         /** index in buffer */
    
    while (buffer[index] == pad)  
        index--;
    buffer[index+1] = 0;
}

void padRight(uint8* buffer, const uint8 finalLength, uint8 character)
{
    int 	bufferLen		= strlen((const char*)buffer);      /** buffer lenght */
	uint8	finalBuf[22]	= {0};

	memset(finalBuf, character, finalLength - bufferLen);

    //finalBuf[finalLength - bufferLen] = 0;
    //memmove(&finalBuf[finalLength - bufferLen], buffer, bufferLen);
    memcpy(&buffer[bufferLen], finalBuf, finalLength - bufferLen);

	buffer[finalLength] = 0x00;

    //showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "PAD LEFT");
    //comportHexShow(buffer, finalLength);
}


/**
 * remove specified charcter from both left and right side of string.
 * @param   buffer	 input/output string.
 * @param   pad		 the charcter to remove
 */
void removePad(uint8* buffer, uint8 pad)
{
    removePadLeft(buffer, pad);
    removePadRight(buffer, pad);
}

/**
 * set bits of a byte
 * @param	bit0	bit 0 of the byte
 * @param	bit1	bit 1 of the byte
 * @param	bit2	bit 2 of the byte
 * @param	bit3	bit 3 of the byte
 * @param	bit4	bit 4 of the byte
 * @param	bit5	bit 5 of the byte
 * @param	bit6	bit 6 of the byte
 * @param	bit7	bit 7 of the byte
 * @return the result byte 
 */
uint8 setBits(uint8 bit0, uint8 bit1, uint8 bit2, uint8 bit3, uint8 bit4, 
              uint8 bit5, uint8 bit6, uint8 bit7) 
{
    uint8 bitmap = 0;                       /** result byte */
    
    if (bit7) 
        bitmap = bitmap + 128;
    
    if (bit6) 
        bitmap = bitmap + 64;
    
    if (bit5) 
        bitmap = bitmap + 32;
    
    if (bit4) 
        bitmap = bitmap + 16;
    
    if (bit3) 
        bitmap = bitmap + 8; 
    
    if (bit2) 
        bitmap = bitmap + 4;
    
    if (bit1) 
        bitmap = bitmap + 2; 
    
    if (bit0) 
        bitmap = bitmap + 1;

    return bitmap;
}


/* @function convertCp1256ToIransystem
 * converts windows codepage 1256 to Iran System font codepage
 * @param strBuff input string to convert it cannot to exeed 256 bytes
 * @return length of converted string
 * @return strBuff converted string
 */ 
int16 convertCp1256ToIransystem(uint8* strBuff)
{
    uint8   buff[256]   = {0};
    int     len         = strlen(strBuff);
    int     curpos      = 0;
    int     i           = 0;
    int     c           = 0;
    int     prev        = 0;
    int     prev1       = 0;
    int     k           = 0;

    struct k_farsi
    {
        uint8   chr;
        uint8   to_prev;// : 1;
        uint8   to_next;// : 1;
        int     last   ;// : 3;
        int     first  ;// : 3;
    }f_chr[128]={0,0,0,0,0};

    f_chr[ 1].chr = 149; 	/* '' */
    f_chr[ 1].last = -1;
    f_chr[ 1].to_prev = 1;
    f_chr[ 1].to_next = 1;

    f_chr[ 13].chr = 157; 	/* '?' */
    f_chr[ 13].to_prev = 1;
    f_chr[ 13].to_next = 1;
    f_chr[ 13].last = -1;

    f_chr[ 14].chr = 166; 	/* 'Ž' */
    f_chr[ 14].to_prev = 1;

    f_chr[ 16].chr = 240; 	/* '' */
    f_chr[ 16].to_prev = 1;
    f_chr[ 16].to_next = 1;
    f_chr[ 16].last = -1;

    f_chr[ 24].chr = 238; 	/* '˜' */
    f_chr[ 24].to_prev = 1;
    f_chr[ 24].to_next = 1;
    f_chr[ 24].last = -1;

    f_chr[ 42].chr = 249; 	/* 'å' */
    f_chr[ 42].to_next = 1;
    f_chr[ 42].to_prev = 1;
    f_chr[ 42].first = 1;
    f_chr[ 42].last = -1;

    f_chr[ 63].chr = 140; 	/* '¿' */

    f_chr[ 64].chr = 249; 	/* 'å' */
    f_chr[ 64].to_next = 1;
    f_chr[ 64].to_prev = 1;
    f_chr[ 64].first = 1;
    f_chr[ 64].last = -1;

    f_chr[ 65].chr = 143; 	/* '??Á' */

    f_chr[ 66].chr = 141; 	/* '?HÂ' */

    f_chr[ 70].chr = 142; 	/* 'Æ' */
    f_chr[ 70].to_next = 1;
    f_chr[ 70].to_prev = 1;
    f_chr[ 70].last = 1;

    f_chr[ 71].chr = 145; 	/* 'Ç' */
    f_chr[ 71].to_prev = 1;
    f_chr[ 71].first = -1;

    f_chr[ 72].chr = 147; 	/* 'È' */
    f_chr[ 72].to_prev = 1;
    f_chr[ 72].to_next = 1;
    f_chr[ 72].last = -1;

    f_chr[ 74].chr = 151; 	/* 'Ê' */
    f_chr[ 74].to_prev = 1;
    f_chr[ 74].to_next = 1;
    f_chr[ 74].last = -1;

    f_chr[ 75].chr = 153; 	/* 'Ë' */
    f_chr[ 75].to_prev = 1;
    f_chr[ 75].to_next = 1;
    f_chr[ 75].last = -1;

    f_chr[ 76].chr = 155; 	/* 'Ì' */
    f_chr[ 76].to_prev = 1;
    f_chr[ 76].to_next = 1;
    f_chr[ 76].last = -1;

    f_chr[ 77].chr = 159; 	/* 'Í' */
    f_chr[ 77].to_prev = 1;
    f_chr[ 77].to_next = 1;
    f_chr[ 77].last = -1;

    f_chr[ 78].chr = 161; 	/* 'Î' */
    f_chr[ 78].to_prev = 1;
    f_chr[ 78].to_next = 1;
    f_chr[ 78].last = -1;

    f_chr[ 79].chr = 162; 	/* 'Ï' */
    f_chr[ 79].to_prev = 1;

    f_chr[ 80].chr = 163; 	/* 'Ð' */
    f_chr[ 80].to_prev = 1;

    f_chr[ 81].chr = 164; 	/* 'Ñ' */
    f_chr[ 81].to_prev = 1;

    f_chr[ 82].chr = 165; 	/* 'Ò' */
    f_chr[ 82].to_prev = 1;

    f_chr[ 83].chr = 168; 	/* 'Ó' */
    f_chr[ 83].to_prev = 1;
    f_chr[ 83].to_next = 1;
    f_chr[ 83].last = -1;

    f_chr[ 84].chr = 170; 	/* 'Ô' */
    f_chr[ 84].to_prev = 1;
    f_chr[ 84].to_next = 1;
    f_chr[ 84].last = -1;

    f_chr[ 85].chr = 172; 	/* 'Õ' */
    f_chr[ 85].to_prev = 1;
    f_chr[ 85].to_next = 1;
    f_chr[ 85].last = -1;

    f_chr[ 86].chr = 174; 	/* 'Ö' */
    f_chr[ 86].to_prev = 1;
    f_chr[ 86].to_next = 1;
    f_chr[ 86].last = -1;

    f_chr[ 88].chr = 175; 	/* 'Ø' */
    f_chr[ 88].to_prev = 1;
    f_chr[ 88].to_next = 1;

    f_chr[ 89].chr = 224; 	/* 'Ù' */
    f_chr[ 89].to_prev = 1;
    f_chr[ 89].to_next = 1;

    f_chr[ 90].chr = 227; 	/* 'Ú' */
    f_chr[ 90].to_prev = 1;
    f_chr[ 90].to_next = 1;
    f_chr[ 90].first = 1;
    f_chr[ 90].last = -1;

    f_chr[ 91].chr = 231; 	/* 'Û' */
    f_chr[ 91].to_prev = 1;
    f_chr[ 91].to_next = 1;
    f_chr[ 91].last = -1;
    f_chr[ 91].first = 1;

    f_chr[ 92].chr = 139; 	/* '_' */
    f_chr[ 92].to_prev = 1;
    f_chr[ 92].to_next = 1;

    f_chr[ 93].chr = 234; 	/* 'Ý' */
    f_chr[ 93].to_prev = 1;
    f_chr[ 93].to_next = 1;
    f_chr[ 93].last = -1;

    f_chr[ 94].chr = 236; 	/* 'Þ' */
    f_chr[ 94].to_prev = 1;
    f_chr[ 94].to_next = 1;
    f_chr[ 94].last = -1;

    f_chr[ 95].chr = 238; 	/* '˜' */
    f_chr[ 95].to_prev = 1;
    f_chr[ 95].to_next = 1;
    f_chr[ 95].last = -1;

    f_chr[ 97].chr = 243; 	/* 'á' */
    f_chr[ 97].to_prev = 1;
    f_chr[ 97].to_next = 1;
    f_chr[ 97].last = -2;

    f_chr[ 99].chr = 245; 	/* 'ã' */
    f_chr[ 99].to_prev = 1;
    f_chr[ 99].to_next = 1;
    f_chr[ 99].last = -1;

    f_chr[ 100].chr = 247; 	/* 'ä' */
    f_chr[ 100].to_prev = 1;
    f_chr[ 100].to_next = 1;
    f_chr[ 100].last = -1;

    f_chr[ 101].chr = 250; 	/* 'å' */
    f_chr[ 101].to_next = 1;
    f_chr[ 101].to_prev = 1;
    f_chr[ 101].first = 1;
    f_chr[ 101].last = -1;

    f_chr[ 102].chr = 248; 	/* 'æ' */
    f_chr[ 102].to_prev = 1;

    f_chr[ 108].chr = 254; 	/* '?' */
    f_chr[ 108].to_prev = 1;
    f_chr[ 108].to_next = 1;
    f_chr[ 108].last = -2;

    f_chr[ 109].chr = 254; 	/* '?' */
    f_chr[ 109].to_prev = 1;
    f_chr[ 109].to_next = 1;
    f_chr[ 109].last = -2;

    for (curpos = 0, i = 0; i <= len; i++)
    {
		if ( strBuff[i] >= 128 && f_chr[strBuff[i] - 128].chr == 0 )
            continue; 
        prev1 = prev;
        prev = c;
        c = (strBuff[i] > 127) ? strBuff[i] - 128 : 0;
        if (!f_chr[c].to_prev)
        {
            if (f_chr[prev].to_next)
            {
	          	if (buff[curpos - 1] != f_chr[prev].chr && f_chr[prev].chr <= 0xE8) // 'Û'
	            	buff[curpos - 1] = f_chr[prev].chr + f_chr[prev].last - f_chr[prev].first;
                else
                    if (f_chr[prev].chr == 0xFE && !f_chr[prev1].to_next) /* '?' */
	              		buff[curpos - 1] = f_chr[prev].chr - 1;
                    else
	              		buff[curpos - 1] = f_chr[prev].chr + f_chr[prev].last;
            }
            buff[curpos] = (f_chr[c].chr) ? f_chr[c].chr : strBuff[i];
         }
         else
         {
            if (!f_chr[prev].to_next)
	          	buff[curpos]= (f_chr[c].chr) ? f_chr[c].chr + f_chr[c].first : strBuff[i];
            else /*  'Ç'                   'á' */
                if (f_chr[prev].chr != 0xF3 || f_chr[c].chr != 0x91)
                    buff[curpos] = (f_chr[c].chr) ? f_chr[c].chr : strBuff[i];
                else
                {
                    buff[--curpos] = 0xF2; /*'áÇ'*/
                }
         }
         curpos++;
    }
    
	curpos -= 2;
    for (i = 0, k = 0; i <= curpos; i++)
    {
            if ((buff[curpos-i] < 128 && buff[curpos-i] != ' ') || (buff[curpos-i] == ' ' && k > 0))
            {
                if (k == 0)
                    c = i;
                k++;
                if (buff[curpos - i] >= '0' && buff[curpos - i] <= '9')
                    buff[curpos - i] += 0x50;
            }
            else
            {
                if (k > 0)
                {
                    strncpy(strBuff + c, buff + curpos - i + 1, k);
                    k = 0;
                }
                strBuff[i] = buff[curpos - i];
            }
    }
    if (k > 0)
        strncpy(strBuff + c, buff + curpos - i + 1, k);
    
    strBuff[curpos + 1] = 0;	 
    return (curpos + 1);
}

uint16 convertUTF8Cp1256(uint8* strBuff, uint8 * OutBuf)
{
	int     inpLen		    = strlen(strBuff);
    int     currInpPos      = 0;
	int     currOutPos      = 0;
	uint8   f_chr		    = 0;

	UTF8ToCP1256_TableST UTFCharsC3[16]  	= {{151, 215},{160, 224},{162, 226},{167, 231},{168, 232},{169, 233},{170, 234},{171, 235},{174, 238},{175, 239},{180, 244},{183, 247},{185, 249},{187, 251},{188, 252}};
	UTF8ToCP1256_TableST UTFCharsD8[30]     = {{140, 161},{155, 186},{159, 191},{161, 193},{162, 194},{163, 195},{164, 196},{165, 197},{166, 198},{167, 199},{168, 200},{169, 201},{170, 202},{171, 203},{172, 204},{173, 205},{174, 206},{175, 207},{176, 208},{177, 209},{178, 210},{179, 211},{180, 212},{181, 213},{182, 214},{183, 216},{184, 217},{185, 218},{186, 219}};
	UTF8ToCP1256_TableST UTFCharsD9[22]     = {{128, 220},{129, 221},{130, 222},{131, 223},{132, 225},{133, 227},{134, 228},{135, 229},{136, 230},{137, 236},{138, 237},{139, 240},{140, 241},{141, 242},{142, 243},{143, 245},{144, 246},{145, 248},{146, 250},{185, 138},{190, 129}};
	UTF8ToCP1256_TableST UTFCharsDA[9]      = {{134, 141},{136, 143},{145, 154},{152, 142},{169, 152},{175, 144},{186, 159},{190, 170}};
	UTF8ToCP1256_TableST UTFCharsDB[5]		= {{129, 192},{146, 255},{140, 237},{149, 192}};
	UTF8ToCP1256_TableST UTFCharsE280[21]	= {{140, 157},{141, 158},{142, 253},{143, 254},{147, 150},{148, 151},{152, 145},{153, 146},{154, 130},{156, 147},{157, 148},{158, 132},{160, 134},{161, 135},{162, 149},{166, 133},{172, 128},{176, 137},{185, 139},{186, 155}};


	while (currInpPos < inpLen)
	{

		f_chr = strBuff[currInpPos];

		//showLog(JUST_VERIFONE, __FILE__, __LINE__, DEBUG, "", "convertUTF8Cp1256 currInpPos: %d, f_chr: %d, f_chr+1: %d", currInpPos, f_chr, strBuff[currInpPos + 1]);

		if (f_chr >= 32 && f_chr <= 126) {	//if english char return same code
			OutBuf[currOutPos++] = f_chr;
		}
		else
		{
			switch (f_chr)
			{
				case 194:
					if (strBuff[currInpPos+1] >= 160 && strBuff[currInpPos+1] <= 190 && strBuff[currInpPos+1] != 161 && strBuff[currInpPos+1] != 170 && strBuff[currInpPos+1] != 186) {
						OutBuf[currOutPos++] = strBuff[currInpPos+1];
					}
					break;
				case 195:
					currOutPos = UTF8ToCP1256_Finder(UTFCharsC3, 15, strBuff[currInpPos+1], OutBuf, currOutPos);
					break;
				case 197:
					if (strBuff[currInpPos+1] == 146)
						OutBuf[currOutPos++] = 140;
					else if (strBuff[currInpPos+1] == 147)
						OutBuf[currOutPos++] = 156;
					break;
				case 198:
					if (strBuff[currInpPos+1] == 146)
						OutBuf[currOutPos++] = 131;
					break;
				case 203:
					if (strBuff[currInpPos+1] == 134)
						OutBuf[currOutPos++] = 136;
					break;
				case 216:
					currOutPos = UTF8ToCP1256_Finder(UTFCharsD8, 29, strBuff[currInpPos+1], OutBuf, currOutPos);
					break;
				case 217:
					currOutPos = UTF8ToCP1256_Finder(UTFCharsD9, 21, strBuff[currInpPos+1], OutBuf, currOutPos);
					break;
				case 218:
					currOutPos = UTF8ToCP1256_Finder(UTFCharsDA, 8, strBuff[currInpPos+1], OutBuf, currOutPos);
					break;
				case 219:
					currOutPos = UTF8ToCP1256_Finder(UTFCharsDB, 4, strBuff[currInpPos+1], OutBuf, currOutPos);
					break;
				case 226:
					if (strBuff[currInpPos+1] == 128)
						currOutPos = UTF8ToCP1256_Finder(UTFCharsE280, 20, strBuff[currInpPos+2], OutBuf, currOutPos);
					else if (strBuff[currInpPos+1] == 132) {
						if (strBuff[currInpPos+2] == 162)
							OutBuf[currOutPos++] = 153;
						else if (strBuff[currInpPos+2] == 172)
							OutBuf[currOutPos++] = 128;
					}
					currInpPos++;
					break;
			}
			currInpPos++;
		}

		//showLog(JUST_VERIFONE, __FILE__, __LINE__, DEBUG, "", "convertUTF8Cp1256 currOutPos: %d, OutBuf[currOutPos]: %d", currOutPos-1, OutBuf[currOutPos-1]);

		currInpPos++;
	}

	OutBuf[currOutPos] = 0;

	return currOutPos;
}

uint8 UTF8ToCP1256_Finder(UTF8ToCP1256_TableST convertTable[], int8 TableLen, uint8 CharToFind, uint8 * outputBuffer, uint8 outPosition)
{
	int	i = 0;
	uint8 o_chr = 0;
	uint8 len = strlen(outputBuffer);

	for (i = 0; i < TableLen; i++) {
		if (CharToFind == convertTable[i].utf8Char) {
			o_chr = convertTable[i].cp1256Char;
			break;
		}
	}

	if (o_chr)
		outputBuffer[outPosition++] = o_chr;
	else
		outputBuffer[outPosition++] = 191;	//Question Mark if char not found in array

	return outPosition;
}

/* @function convertCp1256ToUtf8
 * converts windows codepage 1256 to UTF8 font codepage
 * @param	 OutBuffer	output string
 * @param	 inBuffer	input string
 * @return length of converted string
 */
uint16 convertCp1256ToUtf8(uint8* OutBuffer, uint8* inBuffer)
{
    uint16 len = 0;
    uint16  i  = 0;
    typedef struct
    {    
        uint8   cp1256Char;
        uint8   utf8[10];
    }convertTableST;

    convertTableST cp1265Table[128] = 
    {
        {128	,{226,     130,    172}},
        {129	,{217,     190        }},            
        {130	,{226,     128,    154}},
        {131	,{198,     146        }}, 
        {132	,{226,     128,    158}},
        {133	,{226,     128,    166}},
        {134	,{226,     128,    160}},
        {135	,{226,     128,    161}},
        {136	,{203,     134        }},
        {137	,{226,     128,    176}},
        {138	,{217,     185        }},
        {139	,{226,     128,    185}},
        {140	,{197,     146        }},
        {141	,{218,     134        }},
        {142	,{218,     152        }},
        {143	,{218,     136        }},
        {144	,{218,     175        }},
        {145	,{226,     128,    152}},
        {146	,{226,     128,    153}},
        {147	,{226,     128,    156}},
        {148	,{226,     128,    157}},
        {149	,{226,     128,    162}},
        {150	,{226,     128,    147}},
        {151	,{226,     128,    148}},
        {152	,{218,     169        }},
        {153	,{226,     132,    162}},
        {154	,{218,     145        }},
        {155	,{226,     128,    186}},
        {156	,{197,     147        }},
        {157	,{226,     128,    140}},
        {158	,{226,     128,    141}},
        {159	,{218,     186        }},
        {160	,{194,     160        }},
        {161	,{216,     140        }}, 
        {162	,{194,     162        }},
        {163	,{194,     163        }}, 
        {164	,{194,     164        }},
        {165	,{194,     165        }},
        {166	,{194,     166        }},
        {167	,{194,     167        }},
        {168	,{194,     168        }},
        {169	,{194,     169        }},
        {170	,{218,     190        }},
        {171	,{194,     171        }},
        {172	,{194,     172        }},
        {173	,{194,     173        }},
        {174	,{194,     174        }},
        {175	,{194,     175        }},
        {176	,{194,     176        }},
        {177	,{194,     177        }},
        {178	,{194,     178        }},
        {179	,{194,     179        }},
        {180	,{194,     180        }},
        {181	,{194,     181        }},
        {182	,{194,     182        }},
        {183	,{194,     183        }},
        {184	,{194,     184        }},
        {185	,{194,     185        }},
        {186	,{216,     155        }},
        {187	,{194,     187        }},
        {188	,{194,     188        }},
        {189	,{194,     189        }},
        {190	,{194,     190        }},
        {191	,{216,     159        }},
        {192	,{219,     129        }},
        {193	,{216,     161        }}, 
        {194	,{216,     162        }},
        {195	,{216,     163        }}, 
        {196	,{216,     164        }},
        {197	,{216,     165        }},
        {198	,{216,     166        }},
        {199	,{216,     167        }},
        {200	,{216,     168        }},
        {201	,{216,     169        }},
        {202	,{216,     170        }},
        {203	,{216,     171        }},
        {204	,{216,     172        }},
        {205	,{216,     173        }},
        {206	,{216,     174        }},
        {207	,{216,     175        }},
        {208	,{216,     176        }},
        {209	,{216,     177        }},
        {210	,{216,     178        }},
        {211	,{216,     179        }},
        {212	,{216,     180        }},
        {213	,{216,     181        }},
        {214	,{216,     182        }},
        {215	,{195,     151        }},
        {216	,{216,     183        }},
        {217	,{216,     184        }},
        {218	,{216,     185        }},
        {219	,{216,     186        }},
        {220	,{217,     128        }},
        {221	,{217,     129        }},
        {222	,{217,     130        }},
        {223	,{217,     131        }},
        {224	,{195,     160        }},
        {225	,{217,     132        }}, 
        {226	,{195,     162        }},
        {227	,{217,     133        }}, 
        {228	,{217,     134        }},
        {229	,{217,     135        }},
        {230	,{217,     136        }},
        {231	,{195,     167        }},
        {232	,{195,     168        }},
        {233	,{195,     169        }},
        {234	,{195,     170        }},
        {235	,{195,     171        }},
        {236	,{217,     137        }},
        {237	,{217,     138        }},
        {238	,{195,     174        }},
        {239	,{195,     175        }},
        {240	,{217,     139        }},
        {241	,{217,     140        }},
        {242	,{217,     141        }},
        {243	,{217,     142        }},
        {244	,{195,     180        }},
        {245	,{217,     143        }},
        {246	,{217,     144        }},
        {247	,{195,     183        }},
        {248	,{217,     145        }},
        {249	,{195,     185        }},
        {250	,{217,     146        }},
        {251	,{195,     187        }},
        {252	,{195,     188        }},
        {253	,{226,     128,    142}},
        {254	,{226,     128,    143}},
        {255	,{219,     146        }}  
    };

    memset(OutBuffer, 0, strlen(inBuffer));
    for (i = 0; i < strlen(inBuffer); i++)
    {
        if (inBuffer[i] >= 128 /*&& inBuffer[i] <= 255 --> check for larger than uint8*/)
        {
            strncat(&OutBuffer[len], cp1265Table[inBuffer[i] - 128].utf8, strlen(cp1265Table[inBuffer[i] - 128].utf8));
            len += strlen(cp1265Table[inBuffer[i] - 128].utf8);
        }
        else if (inBuffer[i] >= 48 && inBuffer[i] <= 57)
        {
        	OutBuffer[len++] = 217;
        	OutBuffer[len++] = 112 + inBuffer[i];
        }
        else
        {
            OutBuffer[len] = inBuffer[i];
            len++;
        }
    }

    OutBuffer[len] = 0; // KB 1401-02-26

    return len;
}


int convertCp1256ToUnicode(uint8* input, uint8* output, int inputLen)
{
    int cnt = 0;
    int len = 0;

    typedef struct
    {
        uint8   cp1256Char;
        uint8   unicode[2];
    } convertTableST;

    convertTableST cp1265Table[128] =
    {
        {128 ,{0x20, 0xac}},
        {129 ,{0x06, 0x7e}},
        {130 ,{0x20, 0x1a}},
        {131 ,{0x01, 0x92}},
        {132 ,{0x20, 0x1e}},
        {133 ,{0x20, 0x26}},
        {134 ,{0x20, 0x20}},
        {135 ,{0x20, 0x21}},
        {136 ,{0x02, 0xc6}},
        {137 ,{0x20, 0x30}},
        {138 ,{0x06, 0x79}},
        {139 ,{0x20, 0x39}},
        {140 ,{0x01, 0x52}},
        {141 ,{0x06, 0x86}},
        {142 ,{0x06, 0x98}},
        {143 ,{0x06, 0x88}},
        {144 ,{0x06, 0xaf}},
        {145 ,{0x20, 0x18}},
        {146 ,{0x20, 0x19}},
        {147 ,{0x20, 0x1c}},
        {148 ,{0x20, 0x1d}},
        {149 ,{0x20, 0x22}},
        {150 ,{0x20, 0x13}},
        {151 ,{0x20, 0x14}},
        {152 ,{0x06, 0xA9}},
        {153 ,{0x21, 0x22}},
        {154 ,{0x06, 0x91}},
        {155 ,{0x20, 0x3A}},
        {156 ,{0x01, 0x53}},
        {157 ,{0x20, 0x0C}},
        {158 ,{0x20, 0x0D}},
        {159 ,{0x06, 0xBA}},
        {160 ,{0x00, 0xA0}},
        {161 ,{0x06, 0x0C}},
        {162 ,{0x00, 0xA2}},
        {163 ,{0x00, 0xA3}},
        {164 ,{0x00, 0xA4}},
        {165 ,{0x00, 0xA5}},
        {166 ,{0x00, 0xA6}},
        {167 ,{0x00, 0xA7}},
        {168 ,{0x00, 0xA8}},
        {169 ,{0x00, 0xA9}},
        {170 ,{0x06, 0xBE}},
        {171 ,{0x00, 0xAB}},
        {172 ,{0x00, 0xAC}},
        {173 ,{0x00, 0xAD}},
        {174 ,{0x00, 0xAE}},
        {175 ,{0x00, 0xAF}},
        {176 ,{0x00, 0xB0}},
        {177 ,{0x00, 0xB1}},
        {178 ,{0x00, 0xB2}},
        {179 ,{0x00, 0xB3}},
        {180 ,{0x00, 0xB4}},
        {181 ,{0x00, 0xB5}},
        {182 ,{0x00, 0xB6}},
        {183 ,{0x00, 0xB7}},
        {184 ,{0x00, 0xB8}},
        {185 ,{0x00, 0xB9}},
        {186 ,{0x06, 0x1B}},
        {187 ,{0x00, 0xBB}},
        {188 ,{0x00, 0xBC}},
        {189 ,{0x00, 0xBD}},
        {190 ,{0x00, 0xBE}},
        {191 ,{0x06, 0x1F}},
        {192 ,{0x06, 0xC1}},
        {193 ,{0x06, 0x21}},
        {194 ,{0x06, 0x22}},
        {195 ,{0x06, 0x23}},
        {196 ,{0x06, 0x24}},
        {197 ,{0x06, 0x25}},
        {198 ,{0x06, 0x26}},
        {199 ,{0x06, 0x27}},
        {200 ,{0x06, 0x28}},
        {201 ,{0x06, 0x29}},
        {202 ,{0x06, 0x2A}},
        {203 ,{0x06, 0x2B}},
        {204 ,{0x06, 0x2C}},
        {205 ,{0x06, 0x2D}},
        {206 ,{0x06, 0x2E}},
        {207 ,{0x06, 0x2F}},
        {208 ,{0x06, 0x30}},
        {209 ,{0x06, 0x31}},
        {210 ,{0x06, 0x32}},
        {211 ,{0x06, 0x33}},
        {212 ,{0x06, 0x34}},
        {213 ,{0x06, 0x35}},
        {214 ,{0x06, 0x36}},
        {215 ,{0x00, 0xD7}},
        {216 ,{0x06, 0x37}},
        {217 ,{0x06, 0x38}},
        {218 ,{0x06, 0x39}},
        {219 ,{0x06, 0x3A}},
        {220 ,{0x06, 0x40}},
        {221 ,{0x06, 0x41}},
        {222 ,{0x06, 0x42}},
        {223 ,{0x06, 0x43}},
        {224 ,{0x00, 0xE0}},
        {225 ,{0x06, 0x44}},
        {226 ,{0x00, 0xE2}},
        {227 ,{0x06, 0x45}},
        {228 ,{0x06, 0x46}},
        {229 ,{0x06, 0x47}},
        {230 ,{0x06, 0x48}},
        {231 ,{0x00, 0xE7}},
        {232 ,{0x00, 0xE8}},
        {233 ,{0x00, 0xE9}},
        {234 ,{0x00, 0xEA}},
        {235 ,{0x00, 0xEB}},
        {236 ,{0x06, 0x49}},
        {237 ,{0x06, 0x4A}},
        {238 ,{0x00, 0xEE}},
        {239 ,{0x00, 0xEF}},
        {240 ,{0x06, 0x4B}},
        {241 ,{0x06, 0x4C}},
        {242 ,{0x06, 0x4D}},
        {243 ,{0x06, 0x4E}},
        {244 ,{0x00, 0xF4}},
        {245 ,{0x06, 0x4F}},
        {246 ,{0x06, 0x50}},
        {247 ,{0x00, 0xF7}},
        {248 ,{0x06, 0x51}},
        {249 ,{0x00, 0xF9}},
        {250 ,{0x06, 0x52}},
        {251 ,{0x00, 0xFB}},
        {252 ,{0x00, 0xFC}},
        {253 ,{0x20, 0x0E}},
        {254 ,{0x20, 0x0F}},
        {255 ,{0x06, 0xD2}}
    };


    memset(output, 0x00, inputLen * 2);

    while(cnt < inputLen)
    {
        if (input[cnt] > 0x7f)
        {
            output[len++] = cp1265Table[input[cnt] - 128].unicode[1];
            output[len++] = cp1265Table[input[cnt] - 128].unicode[0];
        }
        else
        {
            output[len++] = input[cnt];
            output[len++] = 0x00;
        }

        cnt++;
    }

    return len;

}

int16 convertPepToCP1256(uint8* strBuff, uint8 * OutBuf)
{
	int     inpLen		    = strlen(strBuff);
    int     currInpPos      = 0;
	int     currOutPos      = 0;
	uint8   f_chr		    = 0;

	uint8 numFlag = 0;
	uint8 numStr[25] = {0};
	uint8 numPos = 0;
	uint8 numCnt = 0;

	//showLog(JUST_VERIFONE, __FILE__, __LINE__, TRACE, "convPepToIransys ", "inpLen: %d", inpLen);

	while (currOutPos < inpLen)
	{

		f_chr = strBuff[currOutPos];

		//showLog(JUST_VERIFONE, __FILE__, __LINE__, TRACE, "convPepToIransys ", "f_chr: %d", f_chr);

		if (f_chr > 186 && f_chr < 213)
		{
			OutBuf[currOutPos++] = f_chr - 90;
		}
		else if (f_chr > 212 && f_chr < 239)
		{
			OutBuf[currOutPos++] = f_chr - 148;
		}
		else
		{
			switch (f_chr)
			{
			case	0:
				OutBuf[currOutPos++] = 0;
				break;
		// 0, NULL
			case	1:
				OutBuf[currOutPos++] = 32;
				break;
		// 1, SPACE
			case	2:
				OutBuf[currOutPos++] = 32;
				break;
		// 2, SINGLESPACE
			case	3:
				OutBuf[currOutPos++] = 63;
				break;
		// 3, QUESTION_EN
			case	4:
				OutBuf[currOutPos++] = 62;
				break;
		// 4, BIGGER
			case	5:
				OutBuf[currOutPos++] = 60;
				break;
		// 5, LITTLE
			case	6:
				OutBuf[currOutPos++] = 61;
				break;
		// 6, EQUAL
			case	7:
				OutBuf[currOutPos++] = 45;
				break;
		// 7, MINUS
			case	8:
				OutBuf[currOutPos++] = 43;
				break;
		// 8, PLUS
			case	9:
				OutBuf[currOutPos++] = 42;
				break;
		// 9, MULTIPLY
			case	10:
				OutBuf[currOutPos++] = 47;
				break;
		// 10, SLASH
			case	11:
				OutBuf[currOutPos++] = 33;
				break;
		// 11, NOT
			case	12:
				OutBuf[currOutPos++] = 126;
				break;
		// 12, TILDA
			case	13:
				OutBuf[currOutPos++] = 64;
				break;
		// 13, AT
			case	14:
				OutBuf[currOutPos++] = 35;
				break;
		// 14, SHARP
			case	15:
				OutBuf[currOutPos++] = 37;
				break;
		// 15, PERCENT
			case	16:
				OutBuf[currOutPos++] = 94;
				break;
		// 16, HAT
			case	17:
				OutBuf[currOutPos++] = 124;
				break;
		// 17, OR
			case	18:
				OutBuf[currOutPos++] = 38;
				break;
		// 18, AMPERSAND
			case	19:
				OutBuf[currOutPos++] = 95;
				break;
		// 19, UNDER_LINE
			case	20:
				OutBuf[currOutPos++] = 40;
				break;
		// 20, PARENTHESE_LEFT_EN
			case	21:
				OutBuf[currOutPos++] = 41;
				break;
		// 21, PARENTHESE_RIGHT_EN
			case	22:
				OutBuf[currOutPos++] = 39;
				break;
		// 22, SINGLE_QOUTA
			case	23:
				OutBuf[currOutPos++] = 34;
				break;
		// 23, DOUBLE_QOUTA
			case	24:
				OutBuf[currOutPos++] = 44;
				break;
		// 24, COMMA_EN
			case	25:
				OutBuf[currOutPos++] = 58;
				break;
		// 25, COLON
			case	26:
				OutBuf[currOutPos++] = 59;
				break;
		// 26, SEMI_COLON
			case	27:
				OutBuf[currOutPos++] = 46;
				break;
		// 27, DOT

		// 28, GOLABI_28

		// 29, GOLABI_29

		// 30, GOLABI_30

		// 31, GOLABI_31
			case	32:
				OutBuf[currOutPos++] = 63;
				break;
		// 32, QUESTION_FA
			case	33:
				OutBuf[currOutPos++] = 123;
				break;
		// 33, GIUME_LEFT
			case	34:
				OutBuf[currOutPos++] = 125;
				break;
		// 34, GIUME_RIGHT
			case	35:
				OutBuf[currOutPos++] = 128;
				break;
		// 35, COMMA_FA
			case	36:
				OutBuf[currOutPos++] = 46;
				break;
		// 36, IP_DOT

		// 37, TICK

		// 38, CROSS

		// 39, PASSWORD

		// 40, CHECKBOX_FALSE

		// 41, CHECKBOX_TRUE

		// 42, ENTER

		// 43, RIGHT_ALIGNMENT

		// 44, CENTER_ALIGNMENT

		// 45, LEFT_ALIGNMENT
			case	46:
				OutBuf[currOutPos++] = 48;
				break;
		// 46, ZERO_EN
			case	47:
				OutBuf[currOutPos++] = 49;
				break;
		// 47, ONE_EN
			case	48:
				OutBuf[currOutPos++] = 50;
				break;
		// 48, TWO_EN
			case	49:
				OutBuf[currOutPos++] = 51;
				break;
		// 49, THREE_EN
			case	50:
				OutBuf[currOutPos++] = 52;
				break;
		// 50, FOUR_EN
			case	51:
				OutBuf[currOutPos++] = 53;
				break;
		// 51, FIVE_EN
			case	52:
				OutBuf[currOutPos++] = 54;
				break;
		// 52, SIX_EN
			case	53:
				OutBuf[currOutPos++] = 55;
				break;
		// 53, SEVEN_EN
			case	54:
				OutBuf[currOutPos++] = 56;
				break;
		// 54, EIGHT_EN
			case	55:
				OutBuf[currOutPos++] = 57;
				break;
		// 55, NINE_EN
			case	56:
				OutBuf[currOutPos++] = 48;
				break;
		// 56, ZERO_FA
 			case	57:
				OutBuf[currOutPos++] = 49;
				break;
		// 57, ONE_FA
 			case	58:
				OutBuf[currOutPos++] = 50;
				break;
		// 58, TWO_FA
			case	59:
				OutBuf[currOutPos++] = 51;
				break;
		// 59, THREE_FA
			case	60:
				OutBuf[currOutPos++] = 52;
				break;
		// 60, FOUR_FA
			case	61:
				OutBuf[currOutPos++] = 53;
				break;
		// 61, FIVE_FA
			case	62:
				OutBuf[currOutPos++] = 54;
				break;
		// 62, SIX_FA
			case	63:
				OutBuf[currOutPos++] = 55;
				break;
		// 63, SEVEN_FA
			case	64:
				OutBuf[currOutPos++] = 56;
				break;
		// 64, EIGHT_FA
			case	65:
				OutBuf[currOutPos++] = 57;
				break;
		// 65, NINE_FA
			case	66:
				OutBuf[currOutPos++] = 195;
				break;
		// 66, ALEF_HAMZE_F
			case	67:
				OutBuf[currOutPos++] = 195;
				break;
		// 67, ALEF_HAMZE_M
			case	68:
				OutBuf[currOutPos++] = 199;
				break;
		// 68, ALEF_F
			case	69:
				OutBuf[currOutPos++] = 199;
				break;
		// 69, ALEF_M
			case	70:
				OutBuf[currOutPos++] = 194;
				break;
		// 70, ALEF_AA_F
			case	71:
				OutBuf[currOutPos++] = 199;
				break;
		// 71, ALEF_AA_M
			case	72:
				OutBuf[currOutPos++] = 200;
				break;
		// 72, BE_F
			case	73:
				OutBuf[currOutPos++] = 200;
				break;
		// 73, BE_M
			case	74:
				OutBuf[currOutPos++] = 200;
				break;
		// 74, BE_L
			case	75:
				OutBuf[currOutPos++] = 200;
				break;
		// 75, BE_A
			case	76:
				OutBuf[currOutPos++] = 129;
				break;
		// 76, PE_F
			case	77:
				OutBuf[currOutPos++] = 129;
				break;
		// 77, PE_M
			case	78:
				OutBuf[currOutPos++] = 129;
				break;
		// 78, PE_L
			case	79:
				OutBuf[currOutPos++] = 129;
				break;
		// 79, PE_A
			case	80:
				OutBuf[currOutPos++] = 202;
				break;
		// 80, TE_F
			case	81:
				OutBuf[currOutPos++] = 202;
				break;
		// 81, TE_M
			case	82:
				OutBuf[currOutPos++] = 202;
				break;
		// 82, TE_L
			case	83:
				OutBuf[currOutPos++] = 202;
				break;
		// 83, TE_A
			case	84:
				OutBuf[currOutPos++] = 203;
				break;
		// 84, SE_F
			case	85:
				OutBuf[currOutPos++] = 203;
				break;
		// 85, SE_M
			case	86:
				OutBuf[currOutPos++] = 203;
				break;
		// 86, SE_L
			case	87:
				OutBuf[currOutPos++] = 203;
				break;
		// 87, SE_A
			case	88:
				OutBuf[currOutPos++] = 204;
				break;
		// 88, JIM_F
			case	89:
				OutBuf[currOutPos++] = 204;
				break;
		// 89, JIM_M
			case	90:
				OutBuf[currOutPos++] = 204;
				break;
		// 90, JIM_L
			case	91:
				OutBuf[currOutPos++] = 204;
				break;
		// 91, JIM_A
			case	92:
				OutBuf[currOutPos++] = 141;
				break;
		// 92, CHE_F
			case	93:
				OutBuf[currOutPos++] = 141;
				break;
		// 93, CHE_M
			case	94:
				OutBuf[currOutPos++] = 141;
				break;
		// 94, CHE_L
			case	95:
				OutBuf[currOutPos++] = 141;
				break;
		// 95, CHE_A
			case	96:
				OutBuf[currOutPos++] = 205;
				break;
		// 96, HE_JIMI_F
			case	97:
				OutBuf[currOutPos++] = 205;
				break;
		// 97, HE_JIMI_M
			case	98:
				OutBuf[currOutPos++] = 205;
				break;
		// 98, HE_JIMI_L
			case	99:
				OutBuf[currOutPos++] = 205;
				break;
		// 99, HE_JIMI_A
			case	100:
				OutBuf[currOutPos++] = 206;
				break;
		// 100, KHE_F
			case	101:
				OutBuf[currOutPos++] = 206;
				break;
		// 101, KHE_M
			case	102:
				OutBuf[currOutPos++] = 206;
				break;
		// 102, KHE_L
			case	103:
				OutBuf[currOutPos++] = 206;
				break;
		// 103, KHE_A
			case	104:
				OutBuf[currOutPos++] = 207;
				break;
		// 104, DAAL_F
			case	105:
				OutBuf[currOutPos++] = 207;
				break;
		// 105, DAAL_M
			case	106:
				OutBuf[currOutPos++] = 208;
				break;
		// 106, ZAAL_F
			case	107:
				OutBuf[currOutPos++] = 208;
				break;
		// 107, ZAAL_M
			case	108:
				OutBuf[currOutPos++] = 209;
				break;
		// 108, RE_F
			case	109:
				OutBuf[currOutPos++] = 209;
				break;
		// 109, RE_M
			case	110:
				OutBuf[currOutPos++] = 210;
				break;
		// 110, ZE_F
			case	111:
				OutBuf[currOutPos++] = 210;
				break;
		// 111, ZE_M
			case	112:
				OutBuf[currOutPos++] = 142;
				break;
		// 112, JHE_F
			case	113:
				OutBuf[currOutPos++] = 142;
				break;
		// 113, JHE_M
			case	114:
				OutBuf[currOutPos++] = 211;
				break;
		// 114, SIN_F
			case	115:
				OutBuf[currOutPos++] = 211;
				break;
		// 115, SIN_M
			case	116:
				OutBuf[currOutPos++] = 211;
				break;
		// 116, SIN_L
			case	117:
				OutBuf[currOutPos++] = 211;
				break;
		// 117, SIN_A
			case	118:
				OutBuf[currOutPos++] = 212;
				break;
		// 118, SHIN_F
			case	119:
				OutBuf[currOutPos++] = 212;
				break;
		// 119, SHIN_M
			case	120:
				OutBuf[currOutPos++] = 212;
				break;
		// 120, SHIN_L
			case	121:
				OutBuf[currOutPos++] = 212;
				break;
		// 121, SHIN_A
			case	122:
				OutBuf[currOutPos++] = 213;
				break;
		// 122, SAAD_F
			case	123:
				OutBuf[currOutPos++] = 213;
				break;
		// 123, SAAD_M
			case	124:
				OutBuf[currOutPos++] = 213;
				break;
		// 124, SAAD_L
			case	125:
				OutBuf[currOutPos++] = 213;
				break;
		// 125, SAAD_A
			case	126:
				OutBuf[currOutPos++] = 214;
				break;
		// 126, ZAAD_F
			case	127:
				OutBuf[currOutPos++] = 214;
				break;
		// 127, ZAAD_M
			case	128:
				OutBuf[currOutPos++] = 214;
				break;
		// 128, ZAAD_L
			case	129:
				OutBuf[currOutPos++] = 214;
				break;
		// 129, ZAAD_A
			case	130:
				OutBuf[currOutPos++] = 216;
				break;
		// 130, TAA_F
			case	131:
				OutBuf[currOutPos++] = 216;
				break;
		// 131, TAA_M
			case	132:
				OutBuf[currOutPos++] = 216;
				break;
		// 132, TAA_L
			case	133:
				OutBuf[currOutPos++] = 216;
				break;
		// 133, TAA_A
			case	134:
				OutBuf[currOutPos++] = 217;
				break;
		// 134, ZAA_F
			case	135:
				OutBuf[currOutPos++] = 217;
				break;
		// 135, ZAA_M
			case	136:
				OutBuf[currOutPos++] = 217;
				break;
		// 136, ZAA_L
			case	137:
				OutBuf[currOutPos++] = 217;
				break;
		// 137, ZAA_A
			case	138:
				OutBuf[currOutPos++] = 218;
				break;
		// 138, EYN_F
			case	139:
				OutBuf[currOutPos++] = 218;
				break;
		// 139, EYN_M
			case	140:
				OutBuf[currOutPos++] = 218;
				break;
		// 140, EYN_L
			case	141:
				OutBuf[currOutPos++] = 218;
				break;
		// 141, EYN_A
			case	142:
				OutBuf[currOutPos++] = 219;
				break;
		// 142, GHEYN_F
			case	143:
				OutBuf[currOutPos++] = 219;
				break;
		// 143, GHEYN_M
			case	144:
				OutBuf[currOutPos++] = 219;
				break;
		// 144, GHEYN_L
			case	145:
				OutBuf[currOutPos++] = 219;
				break;
		// 145, GHEYN_A
			case	146:
				OutBuf[currOutPos++] = 221;
				break;
		// 146, FE_F
			case	147:
				OutBuf[currOutPos++] = 221;
				break;
		// 147, FE_M
			case	148:
				OutBuf[currOutPos++] = 221;
				break;
		// 148, FE_L
			case	149:
				OutBuf[currOutPos++] = 221;
				break;
		// 149, FE_A
			case	150:
				OutBuf[currOutPos++] = 222;
				break;
		// 150, GHAAF_F
			case	151:
				OutBuf[currOutPos++] = 222;
				break;
		// 151, GHAAF_M
			case	152:
				OutBuf[currOutPos++] = 222;
				break;
		// 152, GHAAF_L
			case	153:
				OutBuf[currOutPos++] = 222;
				break;
		// 153, GHAAF_A
			case	154:
				OutBuf[currOutPos++] = 223;
				break;
		// 154, KAAF_F
			case	155:
				OutBuf[currOutPos++] = 223;
				break;
		// 155, KAAF_M
			case	156:
				OutBuf[currOutPos++] = 223;
				break;
		// 156, KAAF_L
			case	157:
				OutBuf[currOutPos++] = 223;
				break;
		// 157, KAAF_A
			case	158:
				OutBuf[currOutPos++] = 144;
				break;
		// 158, GAAF_F
			case	159:
				OutBuf[currOutPos++] = 144;
				break;
		// 159, GAAF_M
			case	160:
				OutBuf[currOutPos++] = 144;
				break;
		// 160, GAAF_L
			case	161:
				OutBuf[currOutPos++] = 144;
				break;
		// 161, GAAF_A
			case	162:
				OutBuf[currOutPos++] = 225;
				break;
		// 162, LAAM_F
			case	163:
				OutBuf[currOutPos++] = 225;
				break;
		// 163, LAAM_M
			case	164:
				OutBuf[currOutPos++] = 225;
				break;
		// 164, LAAM_L
			case	165:
				OutBuf[currOutPos++] = 225;
				break;
		// 165, LAAM_A
			case	166:
				OutBuf[currOutPos++] = 227;
				break;
		// 166, MIM_F
			case	167:
				OutBuf[currOutPos++] = 227;
				break;
		// 167, MIM_M
			case	168:
				OutBuf[currOutPos++] = 227;
				break;
		// 168, MIM_L
			case	169:
				OutBuf[currOutPos++] = 228;
				break;
		// 169, NOON_F
			case	170:
				OutBuf[currOutPos++] = 228;
				break;
		// 170, NOON_M
			case	171:
				OutBuf[currOutPos++] = 228;
				break;
		// 171, NOON_L
			case	172:
				OutBuf[currOutPos++] = 228;
				break;
		// 172, NOON_A
			case	173:
				OutBuf[currOutPos++] = 230;
				break;
		// 173, VAAV_F
			case	174:
				OutBuf[currOutPos++] = 230;
				break;
		// 174, VAAV_M
			case	175:
				OutBuf[currOutPos++] = 229;
				break;
		// 175, HE_2CH_F
			case	176:
				OutBuf[currOutPos++] = 229;
				break;
		// 176, HE_2CH_M
			case	177:
				OutBuf[currOutPos++] = 229;
				break;
		// 177, HE_2CH_L
			case	178:
				OutBuf[currOutPos++] = 229;
				break;
		// 178, HE_2CH_A
			case	179:
				OutBuf[currOutPos++] = 236;
				break;
		// 179, YE_F
			case	180:
				OutBuf[currOutPos++] = 236;
				break;
		// 180, YE_M
			case	181:
				OutBuf[currOutPos++] = 236;
				break;
		// 181, YE_L
			case	182:
				OutBuf[currOutPos++] = 236;
				break;
		// 182, YE_A
			case	183:
				OutBuf[currOutPos++] = 193;
				break;
		// 183, HAMZE_F
			case	184:
				OutBuf[currOutPos++] = 193;
				break;
		// 184, HAMZE_M
			case	185:
				OutBuf[currOutPos++] = 193;
				break;
		// 185, HAMZE_L
			case	186:
				OutBuf[currOutPos++] = 193;
				break;
		// 186, HAMZE_A
			default:
				OutBuf[currOutPos++] = 63;
				break;
			}

		}

		//showLog(JUST_VERIFONE, __FILE__, __LINE__, TRACE, "convPepToIransys ", "OutBuf[%d]: %d", currOutPos - 1, OutBuf[currOutPos - 1]);


		if ((OutBuf[currOutPos - 1] > 47 && OutBuf[currOutPos - 1] < 58) || OutBuf[currOutPos - 1] == 45)
		{
			if (numCnt > 0)
			{
				numPos = OutBuf[currOutPos - 1];

				memmove(&OutBuf[currOutPos - numCnt], &OutBuf[currOutPos - 1 - numCnt], numCnt);
				OutBuf[currOutPos - 1 - numCnt] = numPos;
			}

			numCnt++;

			//showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "convPepToIransys ", "numCnt: %d, numPos: %d", numCnt, numPos);

		}
		else
		{
			if (numCnt > 0)
			{
				numCnt = 0;
				numPos = 0;
			}
		}


	}

	OutBuf[currOutPos] = 0;

	return currOutPos;

}

//mgh
/**
 * power x to y
 * @param	x	the number
 * @param	y	the power
 * @return x ^ y
 */
int power(int x, int y) 
{
	if (y == 0) 
        return 1;
	if (y < 0) 
        return 0;
    
	return x * power(x, y - 1);
}

/**
 * reverse a string
 * @param	str		the string to be reversed
 */
void reverseString(uint8* str)
{
    int     i       = 0;
    int     j       = 0;
    uint8   temp    = 0;
    
    for (i = 0, j = strlen(str) - 1; i <= j; i++, j--)
	{
		temp    = str[i];
		str[i]  = str[j];
		str[j]  = temp;
	}
}


//mgh: 111117
/**
 * add a string number to another one
 * @param	X		the first number in string form
 * @param	Y		the second number in string form
 * @param	result	sum of two numbers
 */
void sumStringNumbers(uint8* X, uint8* Y, uint8* result)
{
    int     maxLen                  = 0;
    int     i                       = 0;
    int     R                       = 0;
    int     tempResult[15 + 1]      = {0};
    uint8   reverseX[15 + 1]        = {0};
    uint8   reverseY[15 + 1]        = {0};
    uint8   tempX[2]                = {0};
    uint8   tempY[2]                = {0};
    
    //showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "X= %s", X);
    //showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "Y= %s", Y);
    
    maxLen = strlen(X) > strlen(Y) ? strlen(X) : strlen(Y);
  
    strcpy(reverseX, X);
    reverseString(reverseX);
    strcpy(reverseY, Y);
    reverseString(reverseY);
    //showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "reverseX= %s", reverseX);
    //showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "reverseY= %s", reverseY);
    
    for (i = 0; i < maxLen; i++)
    {
        tempX[0] = reverseX[i];
        tempY[0] = reverseY[i];
        tempResult[i] = atoi(tempX) + atoi(tempY) + R;

        if (tempResult[i] > 9) 
            R = 1;                                      /* We keep the surplus in mind :)*/
        else
            R = 0;
        tempResult[i] %= 10;                                /* if the number is bigger than 10 we keep only the last digit */
        result[i] = (char)(tempResult[i] + '0');
        
        //showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "tempX: %s", tempX);
        //showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "atoi(tempX): %d", atoi(tempX));
        //showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "tempY: %s", tempY);
        //showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "atoi(tempY): %d", atoi(tempY));
        //showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "tempResult[i]: %d", tempResult[i]);
    }

    if (R != 0) 
    {
        tempResult[maxLen] = R;
        result[maxLen] = (char)(tempResult[maxLen] + '0');
    }
    
    reverseString(result);
}


//mgh: 111117
/**
 * compare two string numbers
 * @param	X	the first string number 
 * @param	Y	the second string number
 * @return   -1 if X < Y, 0 if X = Y and 1 if X > Y
 */ 
int compareStringNumbers(uint8* X, uint8* Y)
{
    int i = 0;
/*
    showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "X: %s", X);
    showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "strlen(X): %d", strlen(X));
    showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "Y: %s", Y);
    showLog(JUST_CASTLES, __FILE__, __LINE__, TRACE, "", "strlen(Y): %d", strlen(Y));
*/
    if (strlen(X) < strlen(Y)) 
        return -1;          // if Y has more digits than X then it is bigger than X
    else if (strlen(X) > strlen(Y)) 
        return 1; 
    else
    {
/*
        if (atoi(&X[0]) < atoi(&Y[0]))
            return -1;
        else if (atoi(&X[0]) > atoi(&Y[0]))
            return 1;
        else
            return 0;
*/
        for (i = 0; i < strlen(Y); i++)
        {
            if (Y[i] > X[i]) 
                return -1;
            else if (Y[i] < X[i]) 
                return 1;
        }
        return 0;
    }
}

/**
 * sutract two numbers
 * @param	X	the first number
 * @param	Y	the second number
 */
void sub(uint8* X, uint8* Y)
{
	/* We assume that X is bigger than Y */
	int 	i   			= 0;
    int 	j   			= 0;
    int 	len 			= 0;
    uint8	tempY[12 + 1] 	= {0};
    
    strcpy(tempY, Y);
    padLeft(tempY, strlen(X));
	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "X: %s, Y: %s", X, tempY);
	for (i = strlen(tempY) - 1; i >= 0; i--)
    {
    	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "i = %d", i);
    	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "X[i]: %c, Y[i]: %c", X[i], tempY[i]);
        if ((tempY[i] -  '0') > (X[i] - '0'))
		{
        	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "Y[i] > X[i]");
            j = i; 
            while (X[--j] == '0');
            
            X[j]--; 
            j++;
            
            while (j < i)
            {
                X[j] = '9';
                j++;
            }
            X[i] += '0' + 10;//58; //10;   
            X[i] -= tempY[i]; 

        	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "X: %s, Y: %s", X, tempY);
		}
        else
		{
            X[i] -= (tempY[i] - '0'); 
        	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "X: %s, Y: %s", X, tempY);
		} 
    }

	removePadLeft(tempY, '0');
	strcpy(Y, tempY);
	
    len = strlen(X);
	while ((X[len] == 0) && (len > 0))
        len--;
	removePadLeft(X, '0');
	if (strlen(X) <= 0)
		strcpy(X, "0");
}

/**
 * subtract two string numbers
 * @param	X	the first string number
 * @param	Y	the second string number
 * @param	result	the result of subtraction
 */
void SubStringNumbers(uint8* X, uint8* Y, uint8* result)
{ 
    int a = compareStringNumbers(X, Y);
    //int i = 0;
    
    showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "sub %s from %s", Y, X);
    if ((a == 1) || (a == 0)) /// if X >= Y 
    {
    	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "X >= Y");
//        for (i = 0; i <= strlen(X); i++) 
//            result[i] = X[i]; 
    	strcpy(result, X);
        sub(result, Y);
        showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "result: %s", result);
    }
    else /// if X < Y 
    { 
    	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "X < Y");
//        for (i = 0; i <= strlen(Y); i++) 
//            result[i] = Y[i]; 
    	strcpy(result, Y);
        sub(result, X);
        showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "result: %s", result);
    }
}


//mgh 111127
/**
 * change string to upper case
 * @param	str		the input string
 */
void strToUpper(uint8* str)
{
	if (str != NULL)
	{
		while (*str++ != ASCII_NULL)
		{
			*str = (uint8)toupper((int)*str);
		}
	}
}

/**
 * parse field data
 * @param	fieldData		the field data
 * @param	fieldDataLen	the data length
 * @param	fieldDataParsed	the data parsed
 * @param	separator		the separating character
 */
void parseFieldData(uint8* fieldData, uint32 fieldDataLen, uint8 fieldDataParsed[16][100], uint8 separator)
{
    int i = 0;
    int j = 0;
    int k = 0;

    showLog(ALL_POS, __FILE__, __LINE__, TRACE, "", "fieldDataLen is : %d", fieldDataLen);
    comportHexShow(fieldData, fieldDataLen);

    for (k = 0, j = 0; k < fieldDataLen; k++, j++)
    {
      if (fieldData[k] == separator)
      {
        i++;
        j = 0;
        //                k++;
        if (fieldData[k + 1] == separator)
            continue;
        else
            k++;
      }
      fieldDataParsed[i][j] = fieldData[k];
    }
}

void create3ByteKVC(uint8* input, uint8* output)
{
	uint8	data[16 + 1] 			= {0};
	uint8 	encryptedData[16 + 1]	= {0};

	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "Create KVC 3 Byte");
	encryptData(input, KEY_LEN, data, 16, encryptedData);
//	encryptData(data, input, 16, encryptedData);
	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "input:");
	comportHexShow(input, 16);

	memcpy(output, encryptedData, 3);
	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "output:");
	comportHexShow(output, 3);
}


void create7ByteKVC(uint8* input, uint8* output)
{
	uint8	KVC[6 + 1]		= {0};
	uint8	KVCHex[6 + 1]	= {0};
	int32	decimalKVC		= 0;
	int		i 				= 0;

	create3ByteKVC(input, KVC);
	binStrToHex(KVC, KVCHex, 3);
	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "hex KVC: %s", KVCHex);
	for (i = 0; i < 6; i++)
	{
		decimalKVC += hexCharToBin(KVCHex[i]) * power(16, 5 - i);
	}
	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "decimal KVC: ", "%ld", decimalKVC);

	sprintf(output, "%ld", decimalKVC); //TODO: check correction
	padLeft(output, 14);
	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "create KVC 7 Byte:", "%s", output);
//	binStrToHex(encryptedData, encryptedDataHex, 8);
//	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "hex output");
//	comportHexShow(encryptedDataHex, 8);
}



uint8 verifyKVC(uint8* encryptionKeyFile, uint8* key, uint8* KVC, uint8* decryptedKey)
{
	uint8	keyKVC3[3 + 1]			= {0};
	uint8	keyKVC6[6 + 1]			= {0};
	uint8 	encryptionKey[16]	= {0};
	uint8	binKey[16]			= {0};
//	uint8	str[33] = {0};
	if (!loadSecurityKey(encryptionKeyFile, ENIAC_GENERAL_KEY, encryptionKey, 16))
		return FALSE;

	hex2bin(key, binKey, 32);
	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "received key:");
	comportHexShow(binKey, 16);

	//decrypt received factory key
	if (!decryptData(encryptionKey, KEY_LEN, binKey, 16, decryptedKey))
		return FALSE;

//	printOneStringEnglish("-------------------", PRN_NORM, ALIGN_LEFT);
//	binStrToHex(encryptionKey, str, 16);
//	printOneStringEnglish(str, PRN_NORM, ALIGN_LEFT);
//	binStrToHex(decryptedKey, str, 16);
//	printOneStringEnglish(str, PRN_NORM, ALIGN_LEFT);

	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "decrypt received key:");
	comportHexShow(decryptedKey, 16);

	create3ByteKVC(decryptedKey, keyKVC3);
	binStrToHex(keyKVC3, keyKVC6, 3);

//	printOneStringEnglish(keyKVC6, PRN_NORM, ALIGN_LEFT);
//	printOneStringEnglish(KVC, PRN_NORM, ALIGN_LEFT);

	showLog(JUST_INGENICO, __FILE__, __LINE__, TRACE, "", "keyKVC6");
	comportHexShow(keyKVC6, 6);

	if (strcmp(keyKVC6, KVC) == 0)
		return TRUE;
	else
		return FALSE;
}

 

uint8 cardToBank(uint8* cardStr, uint8* BankName)
{
	uint8 cardID[7] = {0};

	strncpy(cardID, cardStr, 6);
    cardID[6] = 0;

    if ((strcmp(cardID, "603799") == 0) || (strcmp(cardID, "170019") == 0))
     	strcpy(BankName, "ãáí");
    else if ((strcmp(cardID, "991975") == 0) || (strcmp(cardID, "610433") == 0))
     	strcpy(BankName, "ãáÊ");
    else if ((strcmp(cardID, "627884") == 0) || (strcmp(cardID, "622106") == 0))
     	strcpy(BankName, "ÇÑÓíÇä");
    else if (strcmp(cardID, "628023") == 0)
     	strcpy(BankName, "ãÓ˜ä");
    else if (strcmp(cardID, "606373") == 0)
     	strcpy(BankName, "ãåÑ");
    else if ((strcmp(cardID, "627353") == 0) || (strcmp(cardID, "585983") == 0))
     	strcpy(BankName, "ÊÌÇÑÊ");
    else if (strcmp(cardID, "505416") == 0)
     	strcpy(BankName, "ÑÏÔÑí");
    else if (strcmp(cardID, "627412") == 0)
     	strcpy(BankName, "ÇÞÊÕÇÏ äæíä");
    else if ((strcmp(cardID, "639217") == 0) || (strcmp(cardID, "603770") == 0))
     	strcpy(BankName, "˜ÔÇæÑÒí");
    else if (strcmp(cardID, "636795") == 0)
     	strcpy(BankName, "ãÑ˜Òí");
    else if ((strcmp(cardID, "639347") == 0) || (strcmp(cardID, "502229") == 0))
     	strcpy(BankName, "ÇÓÇÑÇÏ");
    else if ((strcmp(cardID, "627488") == 0) || (strcmp(cardID, "502910") == 0))
     	strcpy(BankName, "˜ÇÑÂÝÑíä");
    else if (strcmp(cardID, "627961") == 0)
     	strcpy(BankName, "ÕäÚÊ æ ãÚÏä");
    else if (strcmp(cardID, "603769") == 0)
     	strcpy(BankName, "ÕÇÏÑÇÊ");
    else if ((strcmp(cardID, "504706") == 0) || (strcmp(cardID, "502806") == 0))
     	strcpy(BankName, "ÔåÑ");
    else if (strcmp(cardID, "639346") == 0)
     	strcpy(BankName, "ÓíäÇ");
    else if (strcmp(cardID, "639607") == 0)
     	strcpy(BankName, "ÓÑãÇíå");
    else if (strcmp(cardID, "589210") == 0)
     	strcpy(BankName, "Óå");
    else if (strcmp(cardID, "589463") == 0)
     	strcpy(BankName, "ÑÝÇå");
    else if (strcmp(cardID, "627381") == 0)
     	strcpy(BankName, "ÇäÕÇÑ");
    else if (strcmp(cardID, "621986") == 0)
     	strcpy(BankName, "ÓÇãÇä");
    else if (strcmp(cardID, "502938") == 0)
     	strcpy(BankName, "Ïí");
    else if (strcmp(cardID, "636949") == 0)
     	strcpy(BankName, "Í˜ãÊ ÇíÑÇäíÇä");
    else if (strcmp(cardID, "502908") == 0)
     	strcpy(BankName, "ÊæÓÚå ÊÚÇæä");
    else if (strcmp(cardID, "628157") == 0)
     	strcpy(BankName, "ÊæÓÚå ÇÚÊÈÇÑí");
    else if (strcmp(cardID, "636214") == 0)
     	strcpy(BankName, "ÂíäÏå");
    else if ((strcmp(cardID, "627648") == 0) || (strcmp(cardID, "207177") == 0))
     	strcpy(BankName, "ÊæÓÚå ÕÇÏÑÇÊ");
    else if (strcmp(cardID, "627760") == 0)
     	strcpy(BankName, "ÓÊ ÈÇä˜");
    else if (strcmp(cardID, "189956") == 0)
     	strcpy(BankName, "ÇÚÊÈÇÑí ÔåÑ");
    else if (strcmp(cardID, "505785") == 0)
     	strcpy(BankName, "ÇíÑÇä Òãíä");
	else if (strcmp(cardID, "585947") == 0)
     	strcpy(BankName, "ÎÇæÑãíÇäå");
	else if (strcmp(cardID, "606256") == 0)
     	strcpy(BankName, "ã.Ç.ãáá");
	else if (strcmp(cardID, "639599") == 0)
     	strcpy(BankName, "ÞæÇãíä");
	else if (strcmp(cardID, "505801") == 0)
     	strcpy(BankName, "˜æËÑ");
	else if (strcmp(cardID, "504172") == 0)
     	strcpy(BankName, "ÑÓÇáÊ");
    else
     	strcpy(BankName, "äÇãÔÎÕ");
}

int hexToDec(uint8* buff, uint8 hexLen)
{
	unsigned int result = 0;

	while (hexLen--)
	{
		result <<= 8;
		result += *buff;
		buff++;
	}
	return result;
}

int16 BCD2ASCII(uint8 *BCD, uint32 BCDLen, uint8 *ASCII, uint32 asciiLen, uint8 zerounpad)
{
	uint8 binChar;
	uint8 ascChar;
	uint8 binCnt = 0;
	uint8 ascCnt = 0;

	while (binCnt < BCDLen)
	{
		binChar = BCD[binCnt];
		ascChar = (binChar >> 4) & 0xf;
		ASCII[ascCnt++] = ascChar + '0';

		binChar = BCD[binCnt];
		ascChar = binChar & 0xf;
		ASCII[ascCnt++] = ascChar + '0';

		binCnt++;
	}

	ASCII[ascCnt] = 0x00;

	if (zerounpad)
	{
		removePadLeft(ASCII, '0');
		ascCnt = strlen(ASCII);
	}

	return ascCnt;
}

int ShowAndPrintQR(char *pszAscInfo, char printFlag)
{
	DataInfo stDataInfo;
	BmpInfo stBmpInfo;
	BmpInfo BmpBuff;

	memset(&stDataInfo,0,sizeof(DataInfo));
	memset(&stBmpInfo,0,sizeof(BmpInfo));

	stDataInfo.nLevel = 3;
	stDataInfo.nMask = -1;
	stDataInfo.nVersion = 8;
	strcpy(stDataInfo.szInputData,pszAscInfo);
	stDataInfo.nLen = strlen(stDataInfo.szInputData);


	if(APP_SUCC != PubEncodeDataAndGenerateBmp(&stDataInfo, &BmpBuff))
	{
		//PubMsgDlg(NULL, "Generate failed", 3, 60);
		return APP_FAIL;

	}


	/*Show QR Code*/
	PubClearAll();
	NDK_ScrDrawBitmap((320 - BmpBuff.xsize) / 2, 2, BmpBuff.xsize, BmpBuff.ysize, BmpBuff.bmpbuff);
	PubUpdateWindow();
	PubBeep(1);

	/*Print QR Code*/
	if (printFlag)
	{
		ASSERT_QUIT(ProConfirm());
		PubPrintImage(BmpBuff.xsize, BmpBuff.ysize, 10, BmpBuff.bmpbuff);
		NDK_PrnStart();
	}

	return APP_SUCC;
}


uint8 calcQRCode_check_digit(uint8* data, uint8 len)
{
    uint16 total = 0;
    uint8 i = 0;
    uint8 cd = 0;
    uint8 str[15] = { 0 };



    for (i = 0; i < len; i = i + 2)
    {
        strncpy(str, &data[i], 1);
        str[1] = 0x00;
        total += atoi(str);
    }

    total *= 3;

    for (i = 1; i < len; i = i + 2)
    {
        strncpy(str, &data[i], 1);
        str[1] = 0x00;
        total += atoi(str);
    }

    cd = 10 - (total % 10);
    cd = cd % 10;

    strcpy(str, data);

    memset(data, 0x00, len + 2);

    sprintf(data, "%s%d", str, cd);

    return cd;
}

uint8 generateQRCode(uint8* mAmount, uint8* mInvoice, uint8* TerminalId)
{
	uint8   qrData[100] = { 0 };
	uint8   qrBase[41];
	uint8   qrVer[3];
	uint8   qrTerm[11] = { 0 };
	uint8 chDig1 = 0;
	uint8 chDig2 = 0;

	if (strlen(mAmount) == 0 || strlen(mInvoice) == 0)
	{
		return FALSE;
	}

	memset(qrData, 0x00, sizeof(qrData));

	strcpy(qrBase, "http://www.ln.shetac.com/");
	strcpy(qrVer, "2");
	strcpy(qrTerm, TerminalId);

	chDig1 = calcQRCode_check_digit(qrTerm, strlen(qrTerm));
	chDig2 = calcQRCode_check_digit(qrTerm, strlen(qrTerm));

	sprintf(&qrTerm[strlen(qrTerm) - 2], "%d%d", chDig2, chDig1);

	sprintf(qrData, "%s?v=%s&t=%s&a=%s&i=%s", qrBase, qrVer, qrTerm, mAmount, mInvoice);

	//TRACE(("qrData: %s", qrData));

	if (ShowAndPrintQR(qrData, FALSE) != APP_SUCC)
		return FALSE;

	return TRUE;
}

uint8 getStringByModel(uint8* strInput, uint8* strOutput)
{
	unsigned int len = 0;
	char model[64] = {0};
	uint8   cpyStr[250] = {0};

	memset(model, 0x00, sizeof(model));

	strcpy(model, (char*)PubGetPosTypeStr());

	//NDK_SysGetPosInfo(SYS_HWINFO_GET_POS_TYPE, &len, model);

//	if (!strcmp(model, "SP830"))
//	{
		createMixedString(strInput, cpyStr);
		convertCp1256ToUtf8(strOutput, cpyStr);
//	}
//	else
//	{
//		convertCp1256ToUtf8(strOutput, strInput);
//	}


}


uint8 createMixedString(uint8* strInput, uint8* strOutput)
{
	typedef struct
	{
		uint8	Type;
		uint8   subString[100];
	} mixedStringST;

	mixedStringST mixedString[20];

	uint8	Start = 0;
	uint8	Length = 0;
	uint8 	i = 0;
	uint8 	lenCnt = 1;
	uint8 	mode = 0;
	uint8 	mxsCnt = 0;
	uint8 	hasFa = 0;
	uint8 	TotalLen = 0;
	uint8 	k = 0;
	uint8   cpyStr[250] = {0};

	uint8   preCloseMode = 0;

	memset(mixedString, 0x00, sizeof(mixedStringST));

	strcpy(cpyStr, strInput);

	*strOutput = 0;

	for (i = 0; i < strlen(cpyStr); i++)
	{
		if (cpyStr[i] > 127 || (cpyStr[i] > 47 && cpyStr[i] < 58))
		{
			hasFa = 1;
			break;
		}

//		if (cpyStr[i] == 40)
//		{
//			if (cpyStr[i + 1] > 127 && i < strlen(cpyStr) - 1)
//			{
//				preCloseMode = 1;
//				cpyStr[i] = 41;
//			}
//		}
//		else if (cpyStr[i] == 41)
//		{
//			if (preCloseMode == 1)
//			{
//				cpyStr[i] = 40;
//				preCloseMode = 0;
//			}
//		}
	}

	lenCnt = 1;
	mode = 0;
	mxsCnt = 0;
	i = 0;
	TotalLen = 0;
	Start = 0;
	Length = 0;

	while (i <= strlen(cpyStr))
	{
		if (cpyStr[i] < 127)
		{
			if ((cpyStr[i] == 32 || cpyStr[i] == 46) && mixedString[mxsCnt].Type != 1) // 46 == '.'
			{
				mode = mixedString[mxsCnt].Type;

				if (cpyStr[i] == 46 && mixedString[mxsCnt].Type == 3)
					mode = 3;

			}
			else if ((cpyStr[i] == 32 || cpyStr[i] == 47) && mixedString[mxsCnt].Type != 1) // 47 == '/' Behnia 1401-01-31 add
			{
				mode = mixedString[mxsCnt].Type;

				if (cpyStr[i] == 46 && mixedString[mxsCnt].Type == 3)
					mode = 3;
			}
			/*else if ((cpyStr[i] == 32 || cpyStr[i] == 58) && mixedString[mxsCnt].Type != 1) // 58 == ':' Behnia 1401-01-31 add
			{
				mode = mixedString[mxsCnt].Type;

				if (cpyStr[i] == 46 && mixedString[mxsCnt].Type == 3)
					mode = 3;
			}*/
			else
			{
				mode = 1;

				if ( (cpyStr[i] > 39  && cpyStr[i] < 58))
				{
					mode = 3;
				}

				if (cpyStr[i] == 58 || cpyStr[i] == 46 || cpyStr[i] == 47)
				{
					mode = mixedString[mxsCnt].Type;
				}
			}
		}
		else
		{
			mode = 2;
		}

		//showLog(JUST_VERIFONE, __FILE__, __LINE__, DEBUG, "printMixedString", " mode: %d", mode);

		if (lenCnt == 1)
		{
			mixedString[mxsCnt].Type = mode;
		}

		if (mode == mixedString[mxsCnt].Type && i < strlen(cpyStr))
		{
			Length = lenCnt++;
		}
		else
		{

			if (mixedString[mxsCnt].Type == 1)
			{
				memset(mixedString[mxsCnt].subString, 0x00, sizeof(mixedString[mxsCnt].subString));
				//showLog(JUST_VERIFONE, __FILE__, __LINE__, DEBUG, "", "Length: %d, c: %d", Length, cpyStr[Start + Length - 1]);
				if (hasFa == 1)
				{
					while(cpyStr[Start + Length - 1] == ' ')
					{
						//showLog(JUST_VERIFONE, __FILE__, __LINE__, DEBUG, "", "in while");
						memmove(&cpyStr[Start + 1], &cpyStr[Start], Length - 1);
						cpyStr[Start] = ' ';
					}
				}
				memcpy(mixedString[mxsCnt].subString, &cpyStr[Start], Length);
			}
			else
			{
				memset(mixedString[mxsCnt].subString, 0x00, sizeof(mixedString[mxsCnt].subString));
				memcpy(mixedString[mxsCnt].subString, &cpyStr[Start], Length);

				//convert2PrinterFontFormat(mixedString[mxsCnt].subString);
			}

			TotalLen = TotalLen + strlen(mixedString[mxsCnt].subString);

			lenCnt = 1;
			mxsCnt++;
			mixedString[mxsCnt].Type = mode;
			Start = i;
			Length = lenCnt++;
		}

		i++;
	}


	for (k = 0; k < mxsCnt; k++)
	{
		//TRACE(("createMixedString mixedString[%d] type: %d, subString: %s", k, mixedString[k].Type, mixedString[k].subString));

		if (hasFa && (mixedString[k].Type == 1 || mixedString[k].Type == 3))
		{
			reverseChars(mixedString[k].subString, strlen(mixedString[k].subString));
		}

		//TRACE(("createMixedString mixedString[%d] type: %d, subString: %s", k, mixedString[k].Type, mixedString[k].subString));

		strcat(strOutput, mixedString[k].subString);

	}

	//convert2PrinterFontFormat(strOutput);

	//TRACE(("createMixedString strOutput: %s", strOutput));
}

uint8 reverseChars(uint8* strInput, uint8 len)
{
	uint8	tempbuff[100] = {0};
	uint8   cnt = 0;

	memset(tempbuff, 0x00, sizeof(tempbuff));

	if (strInput[0] == 0x20 && strInput[len - 1] != 0x20)
	{
		memmove(&strInput[0], &strInput[1], len);
		strInput[len - 1] = 0x20;
	}

	if (strInput[0] != 0x20 && strInput[len - 1] == 0x20)
	{
		memmove(&strInput[1], &strInput[0], len);
		strInput[0] = 0x20;
	}

	//TRACE_HEX((strInput, len, "strInput: "));

	for (cnt = 0; cnt < len; cnt++)
	{
		tempbuff[cnt] = strInput[len - cnt - 1];
		//TRACE(("tempbuff[%d]: %d, strInput[%d]: %d", cnt, tempbuff[cnt], len - cnt, strInput[len - cnt]));
	}

	//TRACE_HEX((tempbuff, len, "tempbuff: "));

	memcpy(strInput, tempbuff, len);
	strInput[len] = 0x00;

}
