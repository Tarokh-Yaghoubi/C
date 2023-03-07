#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void wrong_assignment(void);


void print_number(void);

int main(void)
{
	// wrong_assignment();

	print_number();

	char db[5] = { 'h', 'w', 'c', 'a'  };
	char* ptrarray[10];

	int number;
	number = 586;

	int* ptrtoNum, ** ptr2Ptr;
	ptrtoNum = &number;
	ptr2Ptr = &ptrtoNum;


	ptrarray[1] = db;

	char *p;
	char nm = 't';
	char* ptr;
	char* specific;
	
	ptr = &nm;	
	specific = &db[2];

	p = db;
	printf("The address of db embedded in p : %p \n", p);
	
	p++;

	if (specific > p) printf("specific points to higher mem than p | { specific : [%p] - p : [%p] } \n", specific, p);
	else printf("p points to higher mem than specific | { specific : [%p] - p : [%p] }  \n", specific, p);
	printf("The address of db embedded in p after incrementing : %p \n", p);
	// p++;
	
	printf("The address of db embedded in p after incrementing again : %p \n", p);
	printf("first %c \n", p[0]);
	printf("second %c \n", *(p+1));
	printf("third %c \n", p[2]);
	printf("forth %c \n", p[3]);
	printf("The pointer ptrarray has the address of : %p \n", &ptrarray);
	printf("The pointer ptrarray has the address of : %p \n", ptrarray[1]);
	printf("The pointer ptrarray has the address of : %p \n", &db[0]);
	printf("The pointer ptrarray[1] has the value of : %c \n", *ptrarray[1]);
	
	printf("\n +-------------------+ \n");
	printf("the address of the number variable is : %p and the value is equal to : %d \n", &number, number);
	printf("the address of inside the pointer holding the address of number is : %p with the value of : %d \n", ptrtoNum, *ptrtoNum);
	printf("the address of the pointer holding the address of number is : %p with the value of : %d \n", &ptrtoNum, *ptrtoNum);
	printf("the address of the pointer which is pointing to the pointer holding the address of number is : %p , with the value of : %d \n ", ptr2Ptr, **ptr2Ptr);

	//float* floatPtr;	
	//void* voidPtr;
	//int* intPtr;
	//int ans;

	//float trash;
	//trash = 568.36F;


	//
	//floatPtr = &trash;
	//voidPtr = floatPtr;
	//intPtr = (int*)&voidPtr;
	//ans = *intPtr;
	//printf("The voidPtr p is %p \n", voidPtr);
	//printf("The voidPtr p is %p \n", &voidPtr);
	//printf("The voidPtr p is %p \n", intPtr);
	//printf("The float ptr value is : %p \n", ans);


	//int var = 54, *ptr, *ptr1;		// type of object to which the pointer will point 

	//ptr1 = &trash;
	//ptr = &var;
	//ptr++;
	//printf("the ptr address is : %p \n", ptr);
	//printf("the ptr value is : %d \n", *ptr);
	//ptr = ++ptr;
	//ptr++;
	//printf("the ptr value is : %d \n", ++*ptr);
	//

	//int x = 200;
	//int* p1, * p2;
	//p1 = &x;
	//p2 = p1;

	//printf("The value of x is : %d , the value of p1 is : %d , the value of p2 is : %d \n", x, *p1, *p2);
	//printf("the address of p1 is : %p , the address of p2 is : %p \n", p1, p2);

	return 0;
}

//void wrong_assignment(void)
//{
//	double x = 100.1, y;
//	int* p;
//
//	p = (int*)&x;
//
//	y = *p;
//
//	printf("the (incorrect) value of x is : %f", y);
//
//}

void print_number(void)
{
	char* str = "Hello C programmers !";

	register int t;

	printf("%s \n", str);

	for (t = strlen(str) - 1; t > -1; t--) printf("%c ", str[t]);
	printf("\n");
}