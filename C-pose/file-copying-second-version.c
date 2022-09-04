#include <stdio.h>

int main()

{
	int c;

	while ((c = getchar()) != EOF) {

		putchar(c);
		printf("\n");
		printf("EOF %d\n", EOF);
	}

}

