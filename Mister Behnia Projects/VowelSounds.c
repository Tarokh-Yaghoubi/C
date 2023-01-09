#include <stdio.h>
#include <string.h>

int main()
{
	char ch;
	printf("Enter a char : \n");
	scanf("%c", &ch);

	switch (ch)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("YEs");
		break;
	default:
		printf("no");
		break;
	}

	return 0;
}