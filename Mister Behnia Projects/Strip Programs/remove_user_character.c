/*
	
	Tarokh (Jacob) Yaghoubi , A program to remove the character 
	that users types in from beinning or the end of a Character-Array
	if exists .

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* rstripstring(char* s);
int strstrip(char* s);

int main()
{
    char c;
    char name[] = "   tarokh    yaghoubi    ";
    int len = strlen(name);
    int j = strstrip(name);

    memmove(&name[0], &name[j], len - j);

    name[len - j] = '\0';
    rstripstring(name);
    len = strlen(name);

    printf("Type in the character to check : .. ");
    c = getchar();
    
    if (c == name[0])
    {
        memmove(&name[0], &name[1], (len - 1));
        name[len - 1] = '\0';
    }
    else if (c == name[len - 1])
    {
        name[len - 1] = '\0';
    }    

    printf("The string is : {%s}", name);
    
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