// How free() is used to reduce the wastage of memory after dynamic memory allocation
// free the memory after allocation in C programming 

// Tarokh Yaghoubi , Jacob 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

	int* ptr, * ptr1;

	int n, i;

	printf("Enter the number of elements : \n");
	scanf("%d", &n);
	printf("The number of elements is : %d \n", n);

	ptr = (int*)malloc(n * sizeof(int));
	ptr1 = (int*)calloc(n, sizeof(int));

	if (ptr == NULL || ptr1 == NULL)
	{
		printf("Memory not allocated \n");
		exit(0);
	}
	else
	{
		printf("Memory successfully allocated using calloc and malloc \n");

		for (i = 0; i < n; i++)
		{
			ptr[i] = i + 1;
			ptr1[i] = i + 1;
		}

		printf("The elements of the array allocated using malloc are : \n");
		for (i = 0; i < n; i++)
			printf("%d ", ptr[i]);

		printf("\n ------------ \n");

		printf("The elements of the array allocated using calloc are : \n");
		for (i = 0; i < n; i++)
			printf("%d ", ptr1[i]);

		printf(" \n ------------ \n");

		printf("free the memory allocated by malloc \n");
		free(ptr);
		printf("malloc memory is free \n");
		printf("free the memory allocated by calloc \n");
		free(ptr1);
		printf("calloc memory is free \n");

	}

	return 0;
}