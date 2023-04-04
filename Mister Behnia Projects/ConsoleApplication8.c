// ConsoleApplication8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char* s;

	int n = 0;
	printf("Enter the size of the string : ");
	scanf("%d", &n);
	printf("the size of string is : %d \n", n);

	s = malloc(n * sizeof(char));
	printf("\n%d\n", strlen(s));

	if (s == NULL)
	{
		printf("Memory not allocated for some unknown reason ");
		exit(1);
	}

	else
	{

		printf("Enter the string : ");
		scanf("%99s", s);

		printf("\n ---------------- \n");
		for (int i = 0; i <= strlen(s); ++i)
			printf("%c", s[i]);
		return 0;

	}


}

