#include <stdio.h>
#include <cs50.h>
string printname(string name);
int main(void)
{
    string username = get_string("Enter your name : ");
    printname(username);
}

string printname(string name)
{
    printf("Hello, %s \n", name);
}