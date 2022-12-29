#include <stdio.h>


int main()
{
	// Program number Seven 7

	int i = 0;
	int number, average = 0;
	int user_numbers = 0;
	int sum = 0;

	printf("Enter a number : \n");
	scanf("%d", &number);

	for (i = 0; i < number; i++)
	{
		printf("Enter the [%d] number \n", i);
		scanf("%d", &user_numbers);
		sum += user_numbers;
	}
		
	average = sum / number;
	printf("USER SUM : %d \n", sum);
	printf("AVERAGE : %d \n", average);


	return 0;
	
}