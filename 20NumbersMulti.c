#include <stdio.h>

int main()
{
	int multi_array[20];
	int i, multiplication = 1;
	int number;

	for (i = 0; i < 20; i++)
	{
		printf("Enter the %d number ... \n", i);
		scanf("%d", &number);
		multi_array[i] = number;
	}

	for (i = 0; i < 20; ++i)

		multiplication = multiplication * multi_array[i];

	printf("-----------MULTIPLICATION----------\n");
	printf("RESULT : %d \n", multiplication);

	return 0;
	

}