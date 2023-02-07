#include <stdio.h>

int main(void)
{
	unsigned int i;
	int j;
	i = 1;

	/* left shifts */

	for (j = 0; j < 4; j++)
	{
		i = i << 1;
		printf("the multiplied %d is : %d\n", j, i);
	}

	for (j = 0; j < 4; j++)
	{
		i = i >> 1;
		/* right shift the i by 1 which is equivalent with a division by 2 */
		printf("right shift %d : %d \n", j, i);
	}

	return 0;

}