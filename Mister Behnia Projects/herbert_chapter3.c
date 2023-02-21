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



/*	if-else-if ladder - staircase

	if (expression) statement;
	else 
		if (expression) statement;
		else
			if (expression) statement;
			.
			.
			.
			else statement;

			as soon as a true condition is found the associated statement is executed and the rest of the ladder is bypassed
			if none of the conditions is TRUE then the final else is executed . 

			the ladder if - else if is like this : 

			if (expression)
				statement;
			else if (expression)
				statement;
			else if (expression)
				statement;
			else
				statement;

*/

void menu(void);

int main()
{
	menu();

	int magic, guess;

	magic = rand();

	printf("Guess the magic number : ... \n");
	scanf("%d", &guess);

	// this is how if is used 

	if (guess == magic)
	{
		printf("the guess is correct , numbers match \n");
		printf("the magic number is : ... %d \n", magic);

	}
	else if (magic > guess)
		printf("too low \n");
	else if (magic < guess)
		printf("too high \n");
	else
		printf("pretty close \n the magic number is : %d \n", magic);

	

	return 0;
}


/* 	switch : works only on characters and integers . it is a built-in multiple-branch selection statement

	the value of expressions is tested one after another . when a match is found the statements associated with the case 
	will be executed until the break statement is found or the end of the switch statement is reached .
	the 'default' statement is executed if no matches found , the 'default' is optional . nothing will be done if none of the cases
	is true and there is no default statement . 

	switch(expression) {
	
	case constant1:
		statement sequence .
		break .
	case constant2:
		statement sequence .
		break .
	.
	.
	.
	.
	default
		statement sequence 	
	
	}

*/

/* C89 specifies that a switch can have maximum 257 case statements . this number is increased in the C99 to 1023 */

/* ! case is a label statement, it can not exist by itself outside of the switch */
// ! break is one of the C's Jump statements . you can use 'break' in loops as well as switch statement 


/* NOTE : switch can only test for 'equality' whereas if can evaluate any type of relational or logical expression */

/* NOTE : if character constants are used in switch-case they are automatically converted to integer */


void menu(void)

{

	char ch;

	printf("1 . check spelling : .. \n");
	printf("2 . Correct spelling errors :  \n");
	printf("3 . Display Spelling errors :  \n");
	printf("Strike any other key to skip \n");

	printf("	Enter your choice :  \n");


	ch = getchar();

	/* this is how switch-case works */
	
	switch (ch)
	{
	case '1':
		printf("check spelling is done \n");
		break;
	case '2':
		printf("Correct spelling errors is done \n");
		break;
	case '3':
		printf("Display Spelling errors is done \n");
		break;
	default:		// default is somehow the same as 'else' in 'if' statement
		printf("OTHERS :) \n");
	}
}

/*

Technically, the break statements inside the switch statement are optional. They terminate the
statement sequence associated with each constant. If the break statement is omitted, execution will
continue on into the next case's statements until either a break or the end of the switch is reached.

*/

// when cases have common statement sequences you can use the break after all of them once . 
// for example the first three cases execute the same statement , so we use break after all of them . 

// NESTED SWITCH is also acceptable in C programming