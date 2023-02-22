/*

	ARRAYS IN C PROGRAMMING , HERBERT SHIELDT
	TAROKH YAGHOUBI 

*/

/*

	An array is a collection of variables of the same type that are referred to through a common name.
	A specific element in an array is accessed by an index. In C, all arrays consist of contiguous
	memory locations. The lowest address corresponds to the first element and the highest address to the
	last element. Arrays can have from one to several dimensions. The most common array is the string,
	which is simply an array of characters terminated by a null.

*/

// Note : ! " Arrays and pointers are closely related "

/*
		Single-Dimention Array : 
		
		Note : ! Like other variables, arrays must be explicitly declared so that the compiler can allocate space for 
		them in memory.
		
		type var_name[size];
		double balance[100];

		Note : ! In C89 the size of an array must be specified using a constant expression .
		Note : ! An element is accessed by indexing the array name :
		
		balance[3] = 12.32;
		printf("%d \n", balance[3]);
		
		Note : ! In ' C ' arrays start at index number 0 'zero'
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int x[100];
	int t;

	for (t = 0; t <= 99; t++) x[t] = t;
	for (t = 0; t <= 99; t++) printf(" %d ", x[t]);

	return 0;
}