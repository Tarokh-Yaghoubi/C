
// A program to compare two strings or two digits and say if they are equals or not !
// Tarokh Yaghoubi . Jacob

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void check(char* a, char* b, int (*cmp)(const char*, const char*));
int compvalues(const char*, const char*);

int main(void)
{
	char s1[80], s2[80];

	printf("Enter two values or two strings . \n");

	gets(s1);
	gets(s2);

	if (isdigit(*s1))
	{
		printf("Testing values for equality \n");
		check(s1, s2, compvalues);
	}
	else
	{
		printf("Testing strings for equality \n");
		check(s1, s2, strcmp);
	}

	return 0;
}

int compvalues(const char* a, const char* b)
{

	if (atoi(a) == atoi(b)) return 0;
	else return 1;
	
}

void check(char* a, char* b, int (*cmp)(const char*, const char*))
{
	if (!(*cmp)(a, b)) printf("Equal \n");
	else printf("Not Equal \n");
}

// EOF 