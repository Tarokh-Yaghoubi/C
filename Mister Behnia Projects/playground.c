#include <stdio.h>

int main()
{
	char i = 'a'; // i has the value 'a'

	char* d;	 // understand that : d is not a character , but a pointer to character ;
	/* the type of data that the pointer points to in this case is a character {char} and it is called 
	 the base type of the pointer */

	d = &i; // d has the address of 'i'

	int x = 10, y;
	y = (x > 10) ? 14 : 200;
	printf("%d \n", y);
	printf("%p \n", d);

	char ans = *d; // ans recieves the value at address 'd' 
	printf("the value of the 'd' is %c \n", ans);
	
	/*	note :  
	the multiplication symbol and the 'at address' symbol are the same '*' 
	the BitWise and '&' and the 'address of' symbol are the same but they have no relationship
	with eachother 	
	*/


	return 0;
}