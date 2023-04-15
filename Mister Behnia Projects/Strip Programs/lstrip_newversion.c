#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strstrip(char* s);

int main()
{
    char name[] = "   tarokh    yaghoubi";
    printf("address name:%p", name);
    int len = strlen(name);
    int j = strstrip(name);
    memmove(&name[0], &name[j], len - j);
    name[len - j] = '\0';
    name[0] = name[j];
    printf("%s", name);
    printf("address name:%p", name);
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