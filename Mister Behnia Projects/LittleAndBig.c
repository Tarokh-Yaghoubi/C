#include <stdio.h>

int main()
{
	int min, max, i;
	int numbers = 0;
	int container[1024 + 1];
	min = max = i = 0;

	printf("waiting for a number : ... \n");
	L2: scanf("%d", &numbers);

	while (numbers >= 0)
	{
		container[i] = numbers;
		i++;

		if (numbers > max)
			max = numbers;

		goto L2;
		
	}

	printf("MAX %d \n", max);

	min = max;
	for (int j = 0; j < i; j++)
		if (min > container[j])
			min = container[j];

	
	printf("------------\n");
	printf("MIN %d \n", min);

	return 0;
}