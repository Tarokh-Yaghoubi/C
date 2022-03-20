#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("Enter a number : ");

    switch(x)
    {
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
            break;
        case 3:
            printf("three\n");
            break;
        default:
            printf("The number is out of my control ! \n");
    }
}