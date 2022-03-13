/* run gcc -o hello hello.c -lcs50 to compile */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What is your name : ");
    printf("Your name is : %s \n", answer);
}
