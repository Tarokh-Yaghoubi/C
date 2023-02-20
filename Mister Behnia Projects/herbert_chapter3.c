#include <stdio.h>
#include <stdlib.h>

/*  Herbert Shieldt - chapter 3  */

// statement : a part of your program that can be executed , an statement , specifies an action 

/* C categories statements into these groups : 

	Selection - Iteration - Jump - Label - Expression - Block
	Selection statement is also called 'conditional statement'
*/

// Selection statements (Conditional statements ) -> if and switch
// Iteration statements (Loop statements ) -> while , for and do-while
// Jump statements -> break , continue , goto , return
// Label statements -> case and default statements 
// Expression statements -> statements composed of a valid expression
// Block statements (Compound statements ) -> a block of code that begins with a { and ends with a } 

/* many statements rely upon some conditional tests */

/* if statement :  -> else clause is optional in if 
	
	if (expression) statement; ->	no need for braces {} if it's only one statement under the conditional
		else statement;		->	else is optional

	IF the expression evaluates to TRUE (anything other than zero) the statement or block that forms the target of if 
	is executed ; otherwise the statement or block that is the target of else is executed (if it exists)
	"remember" : ! ONLY IF OR ELSE WILL BE EXECUTED (ONE OF THEM , NOT BOTH ) 
*/

/*
	Nested If : 

	if (i)
	{
		if (l) dosomething1();
		if (d) dosomething2();
		else dosomething3();
	
	}
	else dowsomething4();

	note : the inner else statement is associated with the if (d) . the outter else is associated with the if (i)

*/
	// NOTE :
	// C98 specifies that at least 15 level of nested if must be supported by the compiler but in C99 this number is 
	// increased to 127


int main()
{
	int magic, guess;

	magic = rand();

	printf("Guess the magic number : ... \n");
	scanf("%d", &guess);

	// this is how if is used 

	if (guess == magic)
	{
		printf("** RIGHT **\n");
		printf("%d is the magic number \n", guess);
	}
	else
	{
		printf("wrong answer \n");
		if (guess > magic) printf("too high \n");
		else printf("too low \n");
		printf("the magic number is : %d \n", magic);
	}
	

	return 0;
}