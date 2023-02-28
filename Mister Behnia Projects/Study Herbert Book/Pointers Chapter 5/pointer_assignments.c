#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void wrong_assignment(void);

int main(void)
{
	wrong_assignment();

	int x = 99;
	int* p1, * p2;

	p1 = &x;
	p2 = p1;

	printf("The value of x is : %d , the value of p1 is : %d , the value of p2 is : %d \n", x, *p1, *p2);
	printf("the address of p1 is : %p , the address of p2 is : %p \n", p1, p2);

	return 0;
}

void wrong_assignment(void)
{
	double x = 100.1, y;
	int* p;

	p = (int*)&x;

	y = *p;

	printf("the (incorrect) value of x is : %f", y);

}