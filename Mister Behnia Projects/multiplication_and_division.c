#include <stdio.h>

int main()
{
	// second program 


	int a, b;
	float c;

	printf("Enter two number for operation ... \n");
	scanf("%d %d", &a, &b);

	printf("MULTIPLICATION : %d\n", (a * b));

	c = a / b;

	printf("DIVISION : %.1f\n", c);

	return 0;
}