#include <stdio.h>

int main()
{
	int a, b;

	printf("Enter two numbers in this format -> (firstnumber) (secondnumber) : \n");
	scanf("%d %d", &a, &b);

	printf("SUM : %d\n", (a + b));

	return 0;
}