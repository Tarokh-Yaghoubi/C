#include <stdio.h>

int main()
{
	// Program number 11 

	int a, b, c;

	printf("Enter Angle a , b and c \n");
	scanf("%d %d %d", &a, &b, &c);

	if (a != 0 && b != 0 && c != 0)

		if (a + b + c == 180 && !(a >= 120) && !(b >= 120) && !(c >= 120))

			printf("It is a triangle\n");
		else
			printf("not a triagle");
	else
		printf("One of the angles is zero");

	return 0;
}