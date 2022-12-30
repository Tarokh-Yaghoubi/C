#include <stdio.h>

int main()
{
	int i, number;
	int user_number;

	int max = 0;
	int min = 0;

	printf("Enter a number : \n");
	scanf("%d", &number);
	
	int arr[number];

	for (i = 0; i < number; i++)
	{
		printf("Enter the number %d : \n", i);
		scanf("%d", &user_number);
		arr[i] = user_number;
		if (max < user_number)
		{
			max = user_number;
		}
	}
	min = max;
	for (i = 0; i < number; i++)
	{
		
		if (min > arr[i])
			min = arr[i];
	}
	printf("------------------\n");
	printf("MAX IS : %d\n", max);
	printf("MIN IS : %d\n", min);
	return 0;
}