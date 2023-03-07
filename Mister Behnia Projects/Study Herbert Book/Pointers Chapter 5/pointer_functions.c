#include <stdio.h>
#include <string.h>

/* a program that compares two strings together */

void check(char* a, char* b, int (*cmp)(const char*, const char*));


int main(void)
{
	// Write your code here

	char s1[80], s2[80];
	int (*p)(const char*, const char*);		/* Function Pointer	*/

	p = strcmp;		/* assign the address of strcmp to p (p is pointer pointing to the address of strcmp)*/

	printf("Enter two strings : \n");
	gets(s1);
	gets(s2);

	check(s1, s2, p);

	return 0;
}

void check(char* a, char* b, int (*cmp)(const char*, const char*))
{
	printf("testing for equality \n");
	if (!(*cmp)(a, b)) printf("Equal \n");
	else printf("Not Equal \n");
}