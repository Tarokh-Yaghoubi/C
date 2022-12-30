#include <stdio.h>

int main()
{
	// Program number 15 

	int numbers;
	int i, sum = 0;
	int container[10];

	i = 0, numbers = 0;

	printf("Waiting for numbers : ... \n");
	L2: scanf("%d", &numbers);

	while (numbers > 0 && i < 10)
	{
		container[i] = numbers;
		i++;
		goto L2;
	}

	for (int j = 0; j < i; j++)
	{
		sum += container[j];
		printf(" %d ", container[j]);
		
	}
	
	printf(" = %d\n", sum);
	
	
	if (numbers == 0)
	{
		printf("---------------\n");
		if (i < 10)
			printf("the numbers are less than ten \n");

	}
		
	return 0;

}