#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char max_hour, max_min, max_sec;
	max_hour = 24, max_min = 59, max_sec = 59;

	char* first_hour = argv[1];
	char* first_minute = argv[2];
	char* first_second = argv[3];

	char* second_hour = argv[4];
	char* second_minute = argv[5];
	char* second_second = argv[6];

	// printf("%d", atoi("48"));
						// time 14 16 56 13 24 28 => 
	int new_hour = atoi(first_hour) % atoi(second_hour);
	int new_minute = atoi(first_minute) % atoi(second_minute);
	int new_second = atoi(first_second) % atoi(second_second); 


	printf("---------------------------\n");
	printf("%d %d %d\n", new_hour, new_minute, new_second);
	return 0;
}