#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main_1()
{
	int LEN, i;
	char* tmp;
	char* str;
	
	printf("Enter the size of the string : ");
	
	scanf("%d", &LEN);

	str = (char*)malloc(LEN * sizeof(char));

	if (str != NULL)
	{
		printf("the str is not null and the memory is allocated");
	}
	printf("\n-------------------\n");
	fgets(str, LEN, stdin);
	printf("%s", str);
	tmp = str;
//	printf("%s \n", string);
//	printf("%s \n", tmp);


	return 0;
}

int main()
{
	int len;
	char* name;
	char* ptr;
	scanf("%[^\n]s", name);
	
	ptr = name;
	//len = strlen(name);
	
	printf("%d\n", strlen(name));
	printf("%c \n", ptr[0]);

	for (int i = 0; i < strlen(name); i++)
		printf("%c \n", ptr[i]);
	// printf("\n ------------------- \n");


	return 0;
}