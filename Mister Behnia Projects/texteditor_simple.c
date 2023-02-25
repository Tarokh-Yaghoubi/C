
/*

	A Simple text editor in C ,
	A practice on two-dimensional arrays in C programming on the (Array Strings)
	Tarokh Yaghoubi - Jacob 

*/

#include <stdio.h>


#define MAX 100
#define LEN 80

char text[MAX][LEN];

int main(void)
{
	// write your code here

	register int t, i, j;

	printf("Enter an empty Line to quit \n");

	for (t = 0; t < MAX; t++)
	{
		printf("%d : \n", t);
		gets(&text[t][0]);		// this can also be -> gets(text[t]); (more simple and professional) :)
		if (!*text[t]) break;	/* Quit on the blank lines */
	}

	for (i = 0; i < t; i++)
	{
		for (j = 0; text[i][j]; j++) putchar(text[i][j]);
		putchar('\n');
	}

	return 0;
}