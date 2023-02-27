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

#define CLASSES 3
#define GRADES 30

#include <stdio.h>
#include <string.h>

#include <ctype.h>
#include <stdlib.h>

int grade[CLASSES][GRADES];

void entergrades(void);
int get_grade(int num);
void display_grades(int g[][GRADES]);

// array string function : 
void arraystring(void);


char justastring(char* x);
int testfuncs(void);


int main(void)
{
	char ch, str[80];

	for (; ;)
	{
		do
		{
			printf("[E] Enter Grades : \n");
			printf("[R] Report Grades : \n");
			printf("[Q] Quit : \n");
			gets(str);
			ch = toupper(*str);
		} while (ch != 'E' && ch != 'Q' && ch != 'R');
		
		switch (ch) {
		
		case 'E':
			entergrades();
			break;
		
		case 'R':
			display_grades(grade);
			break;
		
		case 'Q':
			exit(0);
		}
	}
	return 0;
}

/* enter the students grade */

void entergrades(void)
{
	int t, i;

	for (t = 0; t < CLASSES; t++)
	{
		printf("Class # %d: \n", t + 1);
		for (i = 0; i < GRADES; i++)
			grade[t][i] = get_grade(i);
	}
}

/* Read a grade */

int get_grade(int num)
{
	char s[80];

	printf("Enter grade for student # %d : \n", num + 1);
	gets(s);
	return (atoi(s));

}

/* Display grades */

void display_grades(int g[][GRADES])
{
	int t, i;

	for (t = 0; t < CLASSES; t++)
	{
		printf("CLASS # : %d \n", t + 1);
		for (i = 0; i < GRADES; i++)
			printf("Student # : %d has the grade : %d \n", i + 1, grade[t][i]);
	}
}


int main_2()
{
	
	// How Arrays Are Defined And How They Work 

	int num[3][4];
	int x[100];
	int t;
	char* ptr = "this is a simple string";
	
	for (t = 0; t <= 99; t++) x[t] = t;
	for (t = 0; t <= 99; t++) printf(" %d ", x[t]);
	
	printf("\n\n done \n\n");

	testfuncs();
	printf("\n---------------\n");

	justastring(ptr);
	return 0;
}

/*

		Arrays Size :
		total bytes = sizeof(base type) × length of array

*/


/*

		You can generate a pointer to the first element of an array by simply specifying the array name, 
		without any index .

		int* p;
		int sample[10];

		Note :

		p = sample;  -> this assigns 'p' the address of the first element of sample .
		you can also specify the address of the first element of sample using &
		'sample' and &sample[0] are the same , anyway in professional C programs you 
		rarely see &sample[0].
*/

/*

		You cannot pass an array as an argument to a function in C programming . 
		You can ! but their are three ways to do it :
		1 - Pass the array as a pointer
		2 - Pass the array with the size specified
		3 - Pass the array without its size

		void func1(int *x) -> pointer
		void func1(int x[10]) -> sized array
		void func1(int x[]) -> unsized array

		As you can see the length of the array does not matter as of the function is concerned 
		because C does not have bound checking 
*/

/* STRINGS IN C PROGRAMMING  */		


// In C , a string is a null-terminated character array , the null-terminated string is the only type of string defined by C .

/*

		some notes on C strings : 

		When declaring a character array that will hold a string, you need to declare it to be one character
		longer than the largest string that it will hold. For example, to declare an array str that can hold a
		10-character string, you would write :

		char str[11];	->		Specifying 11 for the size makes room for the null at the end of the string.


*/

/*	  { a wide range of functions that manipulate strings in C programming } 


			Name				Function
		
		strcpy(s1, s2)		Copies s2 into s1
		
		strcat(s1, s2)		Concatenates s2 onto the end of s1
		
		strlen(s1)		    Returns the length of s1
		
		strcmp(s1, s2)      Returns 0 if s1 and s2 are the same; less than 0 if s1 < s2; greater than 0 if s1 > s2
		
		strchr(s1, ch)		Returns a pointer to the first occurrence of ch in s1
		
		strstr(s1, s2)		Returns a pointer to the first occurrence of s2 in s1

		Note : ! these functions use the standard header , - <string.h> -  
*/

int testfuncs(void)

{
	char s1[80], s2[80];

	printf("Enter the s1 : \n");
	gets(s1);
	printf("Enter the s2 : \n");
	gets(s2);

	printf("Lengths : .. %d %d \n", strlen(s1), strlen(s2));


	/*	
	
		Remember, strcmp( ) returns false if the strings are equal. Be sure to use the logical ! operator to 
		reverse the condition, as just shown, if you are testing for equality.
	
	*/

	if (!strcmp(s1, s2)) printf("The strings are equal \n");


	strcat(s1, s2);
	printf(" %s \n", s1);

	strcpy(s1, "This is a test of how copy works \n");

	if (strchr("tarokh is a good programmer", 't')) printf("t is in s1 \n");
	if (strstr(s2, "programmer")) printf("found programmer in s2 \n");

	return 0;
}

char justastring(char* x)
{

	// print the character array
	printf("the string is : %s \n", x[5]);

	return 0;
}


/*

				The size of the left dimension determines the number
				of strings, and the size of the right dimension specifies
			    the maximum length of each string.

*/


// An array of 30 strings with a maximum of 79 characters :

// it is easy to access an individual string , you will only specify the left index (String row index) : 

void arraystring(void)
{
	char arr_string[30][80];	// maximum 79 characters because the last one will be the null-char \0 


	gets(arr_string[2]);

	gets(&arr_string[2][0]);	// this is also possible but the first form is more general in professionally written C code .
}


