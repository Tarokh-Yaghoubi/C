/*

	A Database for students grades 
	3 Classes and 30 Grades 


*/



#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define CLASSES 3
#define	GRADES 30

int grade[CLASSES][GRADES];

void display_grades(void);
void enter_grades(int g[][GRADES]);
int get_grade(int num);

int main(void)
{
	char ch, str[80];

	for (;;)
	{
		do
		{
			printf("[E] Enter grades : \n");
			printf("[R] Report grades : \n");
			printf("[Q] Quit : \n");

			gets(str);
			ch = toupper(*str);

		} while (ch != 'R' && ch != 'E' && ch != 'Q');

		switch (ch)
		{
		case 'R':
			display_grades();
			break;
		case 'E':
			enter_grades(grade);
			break;
		case 'Q':
			exit(0);
		}
	}
	return 0;
}

int get_grade(int num)
{
	char s[80];

	printf("Enter grade for student : %d \n", num + 1);

	gets(s);

	return(atoi(s));
}


void display_grades(void)
{
	int t, i;

	for (t = 0; t < CLASSES; t++)
	{
		printf("Class # : %d \n", t + 1);
		for (i = 0; i < GRADES; i++)
			printf("Class # : %d - Student Grade # : %d \n", i + 1, grade[t][i]);
	}
}

void enter_grades(int g[][GRADES])
{
	int t, i;
	for (t = 0; t < CLASSES; t++)
	{
		printf("Class # : %d \n", t + 1);
		for (i = 0; i < GRADES; i++)
			grade[t][i] = get_grade(i);
	}
}