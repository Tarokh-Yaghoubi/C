/*	DO-WHILE IN C PROGRAMMING	*/	

/*

	Unlike for and while loops, which test the loop condition at the top of the loop, the do-while loop
	checks its condition at the bottom of the loop. This means that a do-while loop always executes at
	least once. The general form of the do-while loop is :


	do {
		statement;
	} while (condition);

	the braces are not necessary when only one statement is present .
	The do-while loop iterates until the condition becomes false .

*/


#include <stdio.h>
#include <string.h>

void break_func(void);
void menu(void);

int main(int argc, char* argv[])
{
	// write your code here 
	break_func();
	menu();
	int num = 0;

	do {
		scanf("%d", &num);
	} while (num > 100);

	printf("The end of the loop \n");

	return 0;
}



void menu(void)
{
	// the menu function , using a do-while for test 
	
	char ch;
	int x = 0;
	printf("1 - Check Spelling \n");
	printf("2 - Correct spelling errors \n");
	printf("3 - Display spelling errors \n");
	printf("	Enter your choice : \n");

	do
	{
		ch = getchar();
		
		

		switch (ch)
		{
		case '1':
			printf("1 - Check Spelling \n");
			break;
		
		case '2':
			printf("2 - Correct spelling errors \n");
			break;

		case '3':
			printf("3 - Display spelling errors \n");
			break;
		}
		x++;
		if (x == 4)
			printf("too much attempts \n");
		
	} while (ch != '1' && ch != '2' && ch != '3' && x != 4);
}

void break_func(void)
{
	
	int x;
	x = 0;
	for (; x <= 100; x++)
	{
		if (x == 15)
			break;
	}
	printf("X is : %d \n", x);
}