
/*

		A Database for Entering the grades of 30 Students in each class
		We have 3 Classes , Each class has 30 students 

		Tarokh Yaghoubi

*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CLASSES 3
#define GRADES 30

int grade[CLASSES][GRADES];

void enter_grades(void);
void display_grades(int g[][GRADES]);
int get_grade(int num);


int main(void)
{
	char ch, str[80];

	for (; ;)
	{
		do
		{
			printf("[E] Enter Grades : \n");
			printf("[R] Report Grades : \n");
			printf("[Q] Quit : \n");
			gets(str);
			ch = toupper(*str);

		} while (ch != 'Q' && ch != 'R' && ch != 'E');

		switch (ch)
		{
		case 'E':
			enter_grades();
			break;
		case 'R':
			display_grades(grade);
			break;
		case 'Q':
			exit(0);
		}
	}
	return 0;
}

/* enter the grades into the database */

void enter_grades(void)
{
	int t, i;

	for (t = 0; t < CLASSES; t++)
	{
		printf("Class # : %d \n", t + 1);
		for (i = 0; i < GRADES; i++)
			grade[t][i] = get_grade(i);
	}
}

int get_grade(int num)
{
	char s[80];

	printf("Enter a grade for student # : %d \n", num + 1);

	gets(s);

	return (atoi(s));
}

void display_grades(int g[][GRADES])
{
	int t, i;

	for (t = 0; t  < CLASSES; t++)
	{
		printf("Grades for Class # : %d \n", t + 1);
		for (i = 0; i < GRADES; i++)
			printf("Student # : %d has the grade # : %d \n", i + 1, g[t][i]);
	}
}