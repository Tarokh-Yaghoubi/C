#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *rstripstring(char* s);

int main(int argc, char *argv[])
{
    char name[] = "tarokh yaghoubi      ";
    printf("%s", rstripstring(name));
    return 0;
}
    
char* rstripstring(char* s)
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

    return s;    
}