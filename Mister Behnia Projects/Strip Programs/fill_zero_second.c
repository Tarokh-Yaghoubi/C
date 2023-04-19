/*

	Tarokh (Jacob) Yaghoubi , Fill zero from left 
	second version . (test)

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	int len, max = 12;
	int new_len = 0;
	char number[12] = "12";
	char result[13] = "000000000000";
	
	//for (int i = 0; i < sizeof(result) / sizeof(result[0]); i++)
	//	result[i] = '0';

	len = strlen(&number[0]);
	new_len = max - len;
	strcpy(&result[new_len], &number[0]);	
	result[12] = '\0';

	//if (sizeof(result) / sizeof(result[0]) > 12)
	//	return -1;
	
	for (int i = 0; i < sizeof(result) / sizeof(result[0]); i++)
		printf("%c", result[i]);
	
	return 0;

}
