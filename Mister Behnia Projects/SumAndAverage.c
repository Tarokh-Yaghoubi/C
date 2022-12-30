#include <stdio.h>


int main()
{
	// Program number 13 


	int i, numbers;
	int sum = 0, average;
	i = 0;
	numbers = 0;

	L2: printf("enter a number : \n");
	scanf("%d", &numbers);

	while (numbers >= 0)
	{
		sum = sum + numbers;
		i++;
		goto L2;

	}
	average = sum / i;
 
	printf("SUM : %d\n", sum);
	printf("Average is: %d\n", average);
	return 0;
}