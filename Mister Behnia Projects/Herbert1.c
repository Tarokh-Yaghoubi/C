#include <stdio.h>

#include <string.h>

int is_in(char* s, char c);

int main()
{
	char* str = "tarokh is a friend of jay and jay is the best friend he ever had";
	char p = 'j';

	printf("%d ", is_in(str, p));

}

int is_in(char* s, char c)
{
	while (*s)
	{
		if (*s == c) return 1;
		else s++;
		
	}
	return 0;
	// gets_s
}