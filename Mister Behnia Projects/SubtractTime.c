#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

/*

a program to subtract time with time 
written after AddTime Program 
as a completion

Program number 20 

- Tarokh Yaghoubi

*/

int main()
{
	int current_hour, current_minute, current_second;
	int sub_hour, sub_minute, sub_second;

	int final_hour, final_minute, final_second;

	current_hour = current_minute = current_second = 0;
	sub_hour = sub_minute = sub_second = 0;
	final_hour = final_minute = final_second = 0;

	printf("Enter the current time : ... \n");
	scanf("%d %d %d", &current_hour, &current_minute, &current_second);
	
	if (current_hour <= 24 && current_hour >= 0 && current_minute < 60 && current_minute >= 0 && current_second < 60 && current_second >= 0)
		printf("\nCurrent time set to -> ( %d:%d:%d )\n", current_hour, current_minute, current_second);
	
	else
	{
		printf("The time is incorrect ! -- do you live in mars ???? \n");
		sleep(2);
		printf("the program is exiting , you ruined everything \n");
		sleep(2);
		exit(0);
	}
	printf("----------------------------------\n");

	printf("Enter the other hour , minute and second for subtraction : .... \n");
	scanf("%d %d %d", &sub_hour, &sub_minute, &sub_second);

	printf("\n ---------- CALCULATING ---------- \n");

	if (current_hour - sub_hour < 0)
	{
		final_hour = current_hour - sub_hour;
		final_hour = final_hour + 24;
	}
	else
	{
		final_hour = current_hour - sub_hour;
	}
	if (current_minute - sub_minute < 0)
	{
		final_minute = current_minute - sub_minute;
		final_minute = final_minute + 60;
	}
	else
	{
		final_minute = current_minute - sub_minute;
	}
	if (current_second - sub_second < 0)
	{
		final_second = current_second - sub_second;
		final_second = final_second + 60;
	}
	else
	{
		final_second = current_second - sub_second;
	}


	printf("\n------------RESULT-----------\n");
	printf("THE TIME IS -> ( %d:%d:%d )\n", final_hour, final_minute, final_second);

	return 0;
}