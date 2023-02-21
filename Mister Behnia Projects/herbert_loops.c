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

int main()
{
	char target[80] = "XXXXXXXXXXXXXXXXXXXXXXXXXX";
	coverage(target, "this is a test of coverage");
	printf("final string : %s \n", target);

	// x is initialy set to 0 , and as of it is smaller than 100 the printf is called 


}


void coverage(char* targ, char* src)
{
	int i, j;

	printf("%s \n", targ);
	for (i = 0, j = strlen(src); i <= j; i++, j--)
	{
		targ[i] = src[i];
		targ[j] = src[j];
		printf("%s\n", targ);
	}
}