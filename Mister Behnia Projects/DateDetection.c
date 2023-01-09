#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

project number 21
detect the date
if the date is valid or not ;

*/


int main()
{

	int day, month, year;
	month = day = year = 0;

	printf("Enter the date in this format -> ( day/month/year ) : .. \n");
	scanf("%d/%d/%d", &day, &month, &year);

	if (year >= 1900 && year <= 2100)
	{
		if (month >= 1 && month <= 12)
		{
			if ((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
			{
				printf("Date is vaild ! \n");
			}
			else if ((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
				printf("Date is vaild ! \n");
			else if ((day >= 1 && day <= 28) && (month == 2))
				printf("Date is valid ! \n");
			else if (day == 29 && month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
				printf("Date is vaild ! \n");
			else
				printf("Day is invaild \n");
		}
		else
			printf("month is not valid ! \n");
	}
	else
		printf("Year is not valid ! \n");

	return 0;
}