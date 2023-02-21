/*  

	WHILE LOOP IN C PROGRAMMING 
	HERBERT SHIELDT REFERENCE - TAROKH YAGHOUBI 
	C programming . 

*/

/* 

	WHILE LOOP GENERERAL FORM  IS :
	while (condition) statement; 

	the loop iterates while the condition is true . (any result that is none zero)

*/

#include <stdio.h>
#include <string.h>

char wait_for_char(void);

void pad(char* s, int length);

int main()
{

	char str[80];

	strcpy(str, "this is just a test adasd asdasd asdasd asdasd ");
	pad(str, 40);

	printf("\n\n %d \n\n", strlen(str));
	
	// write your code here
	printf("The program about to start \n");
	wait_for_char();

}

char wait_for_char(void)
{

	char ch;
	ch = '\0';
	
	// this is how while loop works 

	while (ch != 'A') ch = getchar();
	if (ch == 'A') printf("A Detected \n");
	return ch;

}


void pad(char* s, int length)
{
	int l;
	l = strlen(s);

	while (l < length)
	{
		s[l] = ' '; 
		l++;
	}
	s[l] = '\0';
}

/*

void func(void)
{
	int working;

	while (working)
	{
		working = process1();

		if working
			working = process2();
		if working
			working = process3();	
	}

}						*/

// there need not need any statements in the body of the while loop - example : 
/*   while (ch = getchar() != 'A');   */ // -> this will simply loop until the user types 'A'