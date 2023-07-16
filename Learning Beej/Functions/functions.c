

#include <stdio.h>

int plus_one(int n)
{
	return n + 1;
}

void hello(void)
{
	printf("Hello, I am a function ! \n");
}

void increment(int a)
{
	++a;
}

int main(void)
{
	int a = 5;
	int i = 10, j = 0;
	j = plus_one(i);
	printf("The result of i + 1 is : %d\n", j);
	hello();
	increment(a);
	printf("\n a is : %d\n", a);
	printf("an int uses %zu bytes of memory \n", sizeof(int));
	return 0;
}

