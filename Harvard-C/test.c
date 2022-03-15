#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int age = get_int("Enter your age please : ");
    string name = get_string("What is your name: ");

    printf("Hello %s , you are %i years old ! \n ", name, age);
}