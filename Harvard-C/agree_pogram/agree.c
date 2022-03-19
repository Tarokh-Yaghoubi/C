#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user to agree

    char c = get_char("Do you agree ? ");

    // Check wether user agree 
    if(c == 'y' || c == 'Y')
    {
        printf("agree\n");
    }
    else if(c == 'n' || c == 'N')
    {
        printf("dont agree \n");
    }
    else
    {
        printf("You entered nor 'y' neither 'n' . \n");
    }
}