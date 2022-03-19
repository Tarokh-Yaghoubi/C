#include <stdio.h>
#include <cs50.h>

void mew(int a, int n);

int main(void)
{
    mew(get_int("enter where it begins : "), get_int("Enter how many times : "));
}

void mew(int a, int n)
{
    for(int i = a; i < n; i++)
    {
        printf("mew\n");
    }
}
