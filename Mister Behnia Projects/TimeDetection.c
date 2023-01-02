#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    /* 
    
    program number 18 , tells you if the time is valid
    this is how it works -> time.exe 23 45 12 >> VALID 
    23 is hour , 45 is minute , 12 is second .

    */

    char max_hour = 24;
    char max_min = 59;
    char max_sec = 59;

    printf("%d %d %d\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

    if (argc > 2) {
        if (atoi(argv[1]) == max_hour && atoi(argv[2]) == 0 && atoi(argv[3]) == 0)
        {
            printf("VALID");
        }
        else
        {
            if (atoi(argv[1]) == 0 && atoi(argv[2]) == 0 && atoi(argv[3]) == 0)
                printf("INVALID\n");
            else
            {
                if (atoi(argv[1]) <= max_hour && atoi(argv[1]) >= 0)
                {
                    if (atoi(argv[2]) <= max_min && atoi(argv[2]) >= 0)
                    {
                        if (atoi(argv[3]) <= max_sec && atoi(argv[3]) >= 0)
                        {
                            printf("VALID");
                        }
                        else
                            printf("INVALID\n");
                    }
                    else
                        printf("INVALID\n");

                }
                else
                {
                    printf("INVALID");
                }
            }
           
        }
        // printf("The argument supplied is %s\n", argv[1]);
        
    }

    else if (argc == 1) {
        printf("Enter a time for gods sake\n");
    }
    else {
        printf("One argument expected.\n");
    }
}