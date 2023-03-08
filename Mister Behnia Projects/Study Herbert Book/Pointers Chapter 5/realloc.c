/* re-allocation in C programming , 

Dynamically change the memory allocation of a previously allocated memory using malloc or calloc */

// Tarokh Yaghoubi , Jacob 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	// this pointer will hold the base address of the block created 

	int* ptr;
	int n, i;

	// Get the number of the elements for the array 

	n = 5;
	printf("Entered number of elements : %d \n", n);

	ptr = (int*)calloc(n, sizeof(int));
	
	if (ptr == NULL)
	{
		printf("Memory not allocated , \n");
		exit(0);
	}
	else
	{
		printf("Memory Successfully allocated using calloc \n");

		for (i = 0; i < n; i++)
		{
			ptr[i] = i + 1;
		}

		printf("The elements of the array are : \n");
		for (i = 0; i < n; i++)
			printf("%d ", ptr[i]);


		// Get the new size of the array for re-allocation 


		n = 10;

		ptr = realloc(ptr, n * sizeof(int));

		printf("\n Memory was successfully re-allocated \n");

		for (i = 5; i < n; i++)
			ptr[i] = i + 1;

		printf("The elements of the array are : \n");
		for (i = 0; i < n; i++)
			printf("%d ", ptr[i]);


		free(ptr);
	}


	return 0;

}