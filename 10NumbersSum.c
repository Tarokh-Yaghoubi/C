#include <stdio.h>

int main()
{
	int arr[10];
	int i, number, sum = 0;
	i = 0;

	for (i = 0; i < 10; i++)
	{
		printf("Enter the %d number : \n", i);
		scanf("%d", &number);
		arr[i] = number;
	}
	
	printf("--------LIST ITEMS ARE : -------\n");

	for (i = 0; i < 10; ++i)
		printf("List ITEM[%d] is : %d\n", i, arr[i]);


	for (i = 0; i < 10; i++)
		sum = sum + arr[i];

	printf("-----SUM IS :------\n");
	printf("SUM : %d\n", sum);

	return 0;

}	