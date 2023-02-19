#include <stdio.h>

int main()
{
	char i = 'a'; // i has the value 'a'

	char* d;	 // understand that : d is not a character , but a pointer to character ;
	/* the type of data that the pointer points to in this case is a character {char} and it is called 
	 the base type of the pointer */
	int w, r;

	w = (r = 3, ++r, --r, --r);
	// the comma operator has somewhat the same meaning as the word 'and' in english as used in phrase :
		// 'do this and this and this and .... '

	d = &i; // d has the address of 'i'

	int x = 10, y;
	y = (x > 10) ? 14 : 200;
	printf("%d \n", y);
	printf("%p \n", d);

	char ans = *d; // ans recieves the value at address 'd' 
	printf("the value of the 'd' is %c \n", ans);
	printf("the value of w is : %d \n", w);
	
	/*	note :  
	the multiplication symbol and the 'at address' symbol are the same '*' 
	the BitWise and '&' and the 'address of' symbol are the same but they have no relationship
	with eachother 	
	*/


	/* the Dot ( . ) and the Arrow operator ( -> ) : 
	
	access the individual elements of structures and elements in 'structures' and 'unions'

	an structure be like : 

	*/

	
	struct employee
	{
		char name[80];
		int age;
		float wage;
	
	} emp;


	struct employee* p = &emp; // creating an object of the employee strcture 


	emp.age = 15;
	p->wage = 13.3F;

	printf("the age is : %d \n", emp.age);
	printf("the wage is : %.1f \n", p->wage);


	/* the () and [] operators */

	// Parantheses are used to increase the precedence of the operations inside them ()
	// Square Barackets perform array indexing []

	// the expression within the square barackets provides an index into that array [] .

	/* remember all arrays begin at index 0 */

		
	char s[100];

	s[3] = 'a';
	printf("the third s[3] will be [%c]	 \n", s[3]);


	/* you can force an expression to be of a specific type by using a cast  */
	// the general form of a cast is : (type) expression 



	int x_1 = 4;
	float answer;
	answer = (float)x_1 / 2;
	printf("the answer of x_1 / 4 is :  %.1f \n", answer);


	return 0;




	/*  
		! you can add tabs and spaces to make an expression much easier to read 	
		! Redundant or additional parantheses do not cause errors or slow down the executions 
		  of an expression , you should use them to clarify the order of evaluation  
	
		'' the end of chapter 2 ''

	*/

}