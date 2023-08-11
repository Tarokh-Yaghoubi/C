
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    string name = get_string("What is your name ? ");
    int n = 0;
    int nn;

    while (name[n] != '\0')
    {
        ++n;
    }
    printf("%i\n", n);

    nn = strlen(name);
    printf("another way to take the length : %i\n", nn);

    return 0;
}
