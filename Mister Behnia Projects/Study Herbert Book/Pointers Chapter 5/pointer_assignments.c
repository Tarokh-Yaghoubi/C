#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int x = 99;
	int* p1, * p2;

	p1 = &x;
	p2 = p1;

	printf("The value of x is : %d , the value of p1 is : %d , the value of p2 is : %d \n", x, *p1, *p2);
	printf("the address of p1 is : %p , the address of p2 is : %p \n", p1, p2);

	return 0;
}