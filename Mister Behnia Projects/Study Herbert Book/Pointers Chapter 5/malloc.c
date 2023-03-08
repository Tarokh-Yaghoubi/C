/* Memory Allocation Example in C programming language */
// Tarokh yaghoubi . Jacob

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int* ptr;
	int n, i;

	printf("Enter number of elements : \n");
	scanf("%d", &n);
	printf("Entered number of elements : %d\n", n);

	// Dynamically allocate memory using malloc()

	ptr = (int*)malloc(n * sizeof(int));

	// Check if the memory has been successfully allocated by malloc or not 

	if (ptr == NULL)
	{
		printf("Memory Not Allocated");
		exit(0);
	}
	else
	{
		printf("Memory was successfully allocated using malloc . \n");

		// Get the elements of the array 

		for (i = 0; i < n; i++)
		{
			ptr[i] = i + 1;
		}

		// Print the elements of the array 

		printf("The elements of the array are : \n");
		for (i = 0; i < n; ++i) printf("%d ", ptr[i]);
	}

	return 0;

}