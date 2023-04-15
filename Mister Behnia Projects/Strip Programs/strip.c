#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int none_space_count = 0;

    char name[] = "   while i was watching tv my phone rang";
    
    for (;name[i] != '\0'; i++)
    {
        if (name[i] != ' ')
        {
            name[none_space_count] = name[i];
            none_space_count++;
        }
    }

    name[none_space_count] = '\0';
    for (i = 0; i <= strlen(name); i++)
        printf("%c", name[i]);

    return 0;
}