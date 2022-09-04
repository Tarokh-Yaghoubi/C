#include <stdio.h>

/* Copy input to output - first version . */

int main()

{
	int c;

	c = getchar();

	while (c != 'x') {

		putchar(c);
		c = getchar();

	}

}

