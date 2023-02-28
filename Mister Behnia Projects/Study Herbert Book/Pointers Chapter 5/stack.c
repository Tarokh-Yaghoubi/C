#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void push(int i);
int pop(void);

int* tos, * pl;
int stack[SIZE];


int main(void)
{
	int value;
	tos = stack;
	pl = stack;

	do
	{
		printf("Enter a value : \n");
		scanf("%d", &value);

		if (value != 0) push(value);
		else printf("Value on top is : %d \n", pop());


	} while (value != -1);

	return 0;
}

void push(int i)
{
	pl++;
	if (pl == (tos + SIZE)) {
		printf("StackOverflow \n");
		exit(1);
	}	
	*pl = i;
}

int pop(void)
{
	if (pl == tos)
	{
		printf("Stack Underflow \n");
		exit(-1);
	}
	pl --;
	return *(pl + 1);
}