/*

	A program to get the grades of 30 students in each 3 CLASSES
	in C programming , Herbert Shieldt book 
	Tarokh Yaghoubi - Jacob

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CLASSES 3
#define GRADES 30

int grade[CLASSES][GRADES];

void display_grades(int g[][GRADES]);
void enter_grades(void);
int get_grade(int num);

int main(void)
{
	// write your code here

	char c, str[80];

	for (;;)
	{
		do
		{
			printf("[E] Enter the Grades : \n");
			printf("[R] Report the Grades : \n");
			printf("[Q] Quit \n");

			gets(str);
			c = toupper(*str);

			switch (c)
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
		} while (c != 'E' && c != 'R' && c != 'Q');
	}

	return 0;
}

void enter_grades(void)
{
	int t, i;

	for  (t = 0; t < CLASSES; t++)
	{
		printf("Class # : %d \n", t + 1);
		for (i = 0; i < GRADES; i++)
			grade[t][i] = get_grade(i);
	}
}

int get_grade(int num)
{
	char s[80];

	printf("Enter the grade for student : %d \n", num + 1);

	gets(s);

	return (atoi(s));

}

void display_grades(int g[][GRADES])
{
	int t, i;

	for ( t = 0; t < CLASSES; t++)
	{
		printf("Class # : %d \n", t + 1);
		for (i = 0; i < GRADES; i++)
		{
			printf("The grade of student number  : %d is : %d \n", i + 1, g[t][i]);
		}
	}
}