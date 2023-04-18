#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *rstripstring(char* s);

/*
    
    Tarokh (Jacob) Yaghoubi , A program to remove white-space 
    from right-side of a Character Array

*/

int main(int argc, char *argv[])
{
    char name[] = "tarokh yaghoubi      ";
    // Before
    printf("{%s}\n", name);

    // After 
    printf("{%s}\n", rstripstring(name));
    
    // Main Character Array has changed 
    printf("{%s}", name);
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