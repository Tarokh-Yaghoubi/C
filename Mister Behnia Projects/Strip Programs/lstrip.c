#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* strstrip(char* s);

int main()
{
    char name[] = "   tarokh     yaghoubi";
    printf("%s", strstrip(name));
    return 0;
}


char* strstrip(char* s)
{
    size_t size;
    char* end;

    size = strlen(s); // 9

    if (!size)
        return s;

    end = s + size - 1; // s + 22
    while (end >= s && isspace(*end))
        end--;
    *(end + 1) = '\0';

    while (*s && isspace(*s))
        s++;

    return s;
}