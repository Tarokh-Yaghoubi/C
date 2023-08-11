
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void upper_ctype(void);

int main(void)
{
    /* changing lowercase to uppercase using classic math */

    string s = get_string("Before : ");
    printf("After : ");
    for (int i = 0, n = strlen(s); i <= n; ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {            
            printf("%c", s[i] - 32);
            s[i] = s[i] - 32;
        }
        else 
            printf("%c", s[i]);
    }
    printf("\nalso changed in the buffer : %s\n", s);
    printf("\n");
    upper_ctype();
    return 0;
}

void upper_ctype(void)
{

    /* changing lowercase to upper case using ctype library islower() and toupper() functions */

    string s = get_string("Enter another name : ");
    for (int a = 0, n = strlen(s); a <= n; ++a)
    {
        if (islower(s[a]))
        {
            s[a] = toupper(s[a]);
        }
    }
    printf("\nThis is the uppercase version of the string using the ctype library : %s \n", s);

}
