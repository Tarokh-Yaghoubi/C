#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Rever(char* str);

int main()
{
	char name[1024];
	scanf("%[^\n]s", name);
	Rever(name);

//	printf(" \n %d ", len);

	return 0;

}

void Rever(char* str)
{
	char* p;
	int len = 0;
	p = str;
	len = strlen(str);
	printf("%s\n", p);

	for (int i = len - 1; i > -1; --i)
		printf("%c", p[i]);

}