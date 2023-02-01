#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#define NAME "tarokh"
#define AGE 18
#ifndef SIRNAME
#define SIRNAME "jacob"
#endif
#undef AGE

#define SUM(a, b)(a + b)

int main(int argc, char* argv[])
{
	int x = 5, y = 4;
	int ans = 0;
	
	ans = SUM(x, y);

	//#define AGE 19

#if AGE > 0 
	#if AGE
		#if AGE > 12
			goto l2;
		#elif AGE < 12	
			printf("you are underage , i am sorry you have no rights to get in \n");
			sleep(1);
			exit(0);
		#endif
	#endif
#elif AGE <= 0
	#error the age shoud not be smaller than 0
	printf("the age is not valid ,  you must  be at least one year old\n");
	sleep(1);
	exit(0);
#endif

	#ifdef AGE
		l2: printf("%s is %d years old \n", NAME, AGE);
	#endif
	#ifndef AGE
		#warning "the age isn't defined , becareful"

		printf("the age is not defined \n");
	#endif

		printf("The SUM defined function is : %d \n",  ans);
		

		return 0;
} 