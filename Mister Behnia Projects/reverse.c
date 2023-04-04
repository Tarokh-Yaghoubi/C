#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Rever(char* str);

int main()
{
	char* name;
	scanf("%[^\n]s", name);
	Rever(name);

	//	printf(" \n %d ", len);
	printf("%s", name);
	return 0;

}

void Rever(char* str)
{
	char* p, * ptr;
	char* tmp;

	int len = 0;
	p = str;
	len = strlen(str);
	
	// printf("%s\n", p);
	
	for (int i = len - 1, h = 0; i > -1; --i, h++)
	{
		tmp[h] = p[i];
	}
	// ptr = tmp;
	sprintf(str,"%s", tmp);
	

}