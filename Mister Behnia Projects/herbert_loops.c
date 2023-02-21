/* 

	In C, and all other modern programming languages, iteration statements (also called loops) allow a
	set of instructions to be repeatedly executed until a certain condition is reached. This condition may
	be predetermined (as in the for loop) or open ended (as in the while and do-while loops).

	THE FOR LOOP :
	
	the general form of the for loop is : for (initialization; condition; increment) statement;
	the for loop continues to execute as long as the condition is true .
	
*/


#include <stdio.h>
#include <string.h>

void coverage(char* targ, char* src);
void sign_on(void);
void endless(void);

int main()
{
	sign_on();
	 
	char target[80] = "XXXXXXXXXXXXXXXXXXXXXXXXXX";
	coverage(target, "this is a test of coverage");
	printf("final string : %s \n", target);

	// x is initialy set to 0 , and as of it is smaller than 100 the printf is called 
	printf("\n\n -------------------------- \n\n");

	endless();

	return 0;
}

/*

	In converge( ), the for loop uses two loop control variables, i and j, to index the string from
	opposite ends. As the loop iterates, i is increased and j is decreased. The loop stops when i is greater
	than j, thus ensuring that all characters are copied.

*/

void coverage(char* targ, char* src)
{
	int i, j;

	printf("%s \n", targ);

	/* this is how for works - also used two variables in the loop initialization */

	for (i = 0, j = strlen(src); i <= j; i++, j--)
	{
		targ[i] = src[i];
		targ[j] = src[j];
		printf("%s\n", targ);
	}
}


// in for loop you can test for several termination conditions 

void sign_on(void)
{
	char str[20];
	int x;


	for (x = 0; x < 3 && strcmp(str, "password"); x++)
	{
		printf("Enter the password please : \n");
		gets(str);
	}

	if (strcmp(str, "password") == 0) printf("the password is correct :) \n");

	if (x == 3) return;
}

void endless(void)
{

	// when the conditional expression is absent it is assumed to be ' True ' !
	char ch;
	for (; ; )
	{
		ch = getchar();
		if (ch == 'A') {
			printf("A detected"); break;
		}
	}
}


// for loops can have 'no' body {} :
/*

	for ( ; *str == ' '; str++);     * bypass whitespaces in a line
	for (y = 0; y < 10; y++);		* time delay . it is sometimes useful | { some compilers will optimize such time delay loops out of existence }
	then it may not have any effects in the program , useless
*/
//	a variable declared within the loop , will be local to that loop . LOOP VARIABLE DECLARATION IS NOT SUPPORTED BY C89

