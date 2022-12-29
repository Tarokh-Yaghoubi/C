#include <stdio.h>

int main()
{
	// Program number 8 

	int i;
	int max = 0;

	int number;
	int user_number;

	printf("Enter a number : \n");
	scanf("%d", &number);


	for (i = 0; i < number; i++)
	{
		printf("Enter number [%d] : ... \n", i);
		scanf("%d", &user_number);
		if (max < user_number)
			max = user_number;
	}

	printf("------------\n");
	printf("BIGGEST NUMBER : %d\n", max);

	return 0;
}