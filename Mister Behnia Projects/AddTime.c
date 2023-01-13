#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

/*

{ 

    A program for time addition (AddTime.c)
    program number 19 .
    this is the 19th program i have written in C programming language }

*/

int main(void)
{
    int current_hour;
    int current_minute;
    int current_second;

    int addition_hour;
    int addition_minute;
    int addition_second;

    int final_hour, final_minute, final_second;
    final_hour = final_minute = final_second = 0;

    printf("Enter the first hour and minute and also second : .. \n");
    scanf("%d %d %d", &current_hour, &current_minute, &current_second);
    
    if (current_hour <= 24 && current_hour >= 0 && current_minute < 60 && current_minute >= 0 && current_second < 60 && current_second >= 0)
        printf("SET THE TIME TO  ->  ( %d:%d:%d )\n", current_hour, current_minute, current_second);

    else
    {
        printf("wrong hour , do you live in mars ???? \n");
        sleep(1);
        printf("program is exiting , you ruined everything ... \n");
        sleep(2);
        exit(0);
    }
        
    
    printf("---------------------------\n");

    printf("Enter the hour you wanna add : \n");
    scanf("%d", &addition_hour);
    printf("Enter the minute : \n");
    scanf("%d", &addition_minute);

    printf("Enter the second you wanna add : \n");
    scanf("%d", &addition_second);

    if (current_hour + addition_hour > 24)
    {
        final_hour = current_hour + addition_hour;
        final_hour = final_hour - 24;
    }
    else
    {
        final_hour = current_hour + addition_hour;
    }

    if (current_minute + addition_minute >= 60)
    {
        final_minute = current_minute + addition_minute;
        final_minute = final_minute - 60;
        final_hour++;
    }
    else
    {
        final_minute = current_minute + addition_minute;
    }

    if (current_second + addition_second >= 60)
    {
        final_second = current_second + addition_second;
        final_second = final_second - 60;
        final_minute++;
    }
    else
    {
        final_second = current_second + addition_second;
    }

    printf("now i have the new time it might be wrong \n");
    printf("\n-------------------------------------\n");
    printf("TIME IS -> ( %d:%d:%d )\n", final_hour, final_minute, final_second);

    return 0;
        
}