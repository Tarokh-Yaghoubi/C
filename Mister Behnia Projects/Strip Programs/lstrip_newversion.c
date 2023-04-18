#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 
    Tarokh (Jacob) Yaghoubi , A program to remove white-space
    on the left side of an Character-Array

*/

int strstrip(char* s);

int main()
{
    char name[] = "   tarokh    yaghoubi";
    int len = strlen(name);
    int j = strstrip(name);

    memmove(&name[0], &name[j], len - j);
    
    name[len - j] = '\0';
    
    printf("%s", name);    
    return 0;
}


int strstrip(char* s)
{
    int i = 0;
    while (*s && isspace(*s))
    {
        i++;
        s++;
    }    

    return i;
}