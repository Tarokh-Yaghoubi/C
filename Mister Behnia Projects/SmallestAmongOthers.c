#include <stdio.h>

int main()
{
	//  Program number 10 and 9 
	/* I WROTE THIS INSTEAD OF PROGRAM NUMBER 8 */
	// A better version of Program number 8

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