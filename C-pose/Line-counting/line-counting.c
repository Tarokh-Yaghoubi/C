#include <stdio.h>

int main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)

		if (c == '\n')
			++nl;

		else if (c == '\t' || c == ' ')
			++nl;

		printf("%d\n", nl);

}

