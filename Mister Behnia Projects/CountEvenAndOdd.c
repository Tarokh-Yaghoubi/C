#include <stdio.h>


int main()
{
	// Program number 12 

	int EVEN = 0, ODD = 0;
	int i, numbers;
	int user_numbers;
	
	printf("Enter the number of numbers : \n");
	scanf("%d", &numbers);

	for (i = 0; i < numbers; i++)
	{
		printf("Enter the number %d \n", i);
		scanf("%d", &user_numbers);
		if (user_numbers % 2 == 0)
			EVEN++;
		else
			ODD++;
	}

	printf("-------------------------\n");
	printf("ODD : %d\n", ODD);
	printf("EVEN : %d\n", EVEN);

	return 0;
}