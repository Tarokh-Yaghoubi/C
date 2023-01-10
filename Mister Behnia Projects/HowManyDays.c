#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

/* 

Calculate how many days has passed 
since the beggining of the year . 
{Tarokh Yaghoubi} - Project Number /22 (last one | first season)

*/

int dayspassed(int*, int*, int*);

struct theDate {

	int finMonth;
	int finDay;
};

int main(int argc, char* argv[])
{
	struct theDate date;

	int i; i = 0;
	int container, last;
	int day, month, year;
	day = month = year = 0;

	printf("Enter date in this format (day/month/year) for calculation : ... \n");
	scanf("%d/%d/%d", &day, &month, &year);
	
	dayspassed(&day, &month, &year);


	return 0;
}

int dayspassed(int* day, int* month, int* year)
{
	int container; container = 0;
	struct theDate date;

	if (!(*year > 1500 || *year < 1000) && !(*month > 12 || *month < 0) && !(*day > 31 || *day < 0))
	{
		date.finMonth = *month;

		if (*month >= 1 && *month <= 6)
			date.finDay = (*month - 1) * 31 + *day;

		else if (*month > 6 && *month <= 12)
		{
			date.finDay = (6 - 1) * 31 + *day;
			container = *month - 6;
			container = (container - 1) * 30 + *day;
			date.finDay += container;
		}

		// printf("About (%d) days has past since the beggining of the year\nnow we are in the (%d)'th month \n", (date.finDay), (date.finMonth));
		return date.finDay;
	}
	else
	{
		printf("\nthe date is not valid \t\t Do you live in mars ??? \n");
		sleep(2);
		printf("the program is exiting \t\t you ruined everything !! \n");
		sleep(2.5);

		return -1;

	}

}