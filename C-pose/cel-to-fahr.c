#include <stdio.h>

int main()

{

	float cel , fahr;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	cel = lower;

	while (cel <= upper) {

		fahr = (cel * 1.8) + 32;
		printf("%3.0f %6.1f\n", cel , fahr);
		cel = cel + step;

	}

}

