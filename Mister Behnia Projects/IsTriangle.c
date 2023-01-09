#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 

take three numbers and detect if they can be angles of a triangle 
a Better version of program number 11 
- isTriangle -> Triangles.c

*/

int main()
{
	int first, second, last;
	first = second = last = 0;
	
	printf("Enter the angles  ... \n");
	scanf("%d %d %d", &first, &second, &last);

	if (first + second > last && first + last > second && second + last > first)
		printf("It can be a triangle \n");
	else
		printf("it can not be a triangle \n");

	return 0;

}