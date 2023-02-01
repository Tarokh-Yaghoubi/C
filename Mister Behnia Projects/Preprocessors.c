#include <stdio.h>
#include <string.h>

#define NAME "tarokh"
#define AGE 18

#undef AGE


int main(int argc, char* argv[])
{

	#define AGE 18

	#if AGE
		goto l2;
	#endif 

	#ifdef AGE
		l2: printf("%s is %d years old \n", NAME, AGE);
	#endif
	#ifndef AGE
		printf("the age is not defined \n");
	#endif
		
} 