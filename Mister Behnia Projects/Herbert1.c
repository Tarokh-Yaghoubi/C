#include <stdio.h>

#include <string.h>

int is_in(const char* str);

int main()
{
	char* str = "tarokh is a boy";

	is_in(str);

}

int is_in(const char* str)
{
	while (*str)
	{
		if (*str == ' ') printf("%c", '-');
		else printf("%c", *str);
		str++;
	}
}