/* Dynamic Memory Allocation in C programming */
// Tarokh Yaghoubi , Jacob 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int* ptr;
	int i, n;

	printf("Enter the number of elements : \n");

	scanf("%d", &n);

	printf("The number of elements is : %d \n", n);
	
	ptr = (int*)calloc(n, sizeof(int));

	if (ptr == NULL)
	{
		printf("Memory Not Allocated using calloc \n");
		exit(0);
	}
	else
	{

		printf("Memory is successfully allocated using calloc \n");

		for (i = 0; i < n; i++)
		{
			ptr[i] = i + 1;
		}

		printf("The elements of the array are : \n");

		for (i = 0; i < n; ++i)
			printf("%d ", ptr[i]);
	}

	return 0;

}