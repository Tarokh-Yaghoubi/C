/*

	Tarokh (Jacob) Yaghoubi 
	Macros in C

*/

#include <stdio.h>

int main()
{
	printf("Line number is  :%d \n", __LINE__);
	printf("The filename is :%s \n", __FILE__);
	printf("The Date program was compiled is : %s \n", __DATE__);
	printf("Hour , Minute and Second that the code was compied : %s \n", __TIME__);
	printf("The func name is : %s \n", ((char *) __func__));
	printf("The func size is : %d \n", sizeof(__func__));

	return 0;
}