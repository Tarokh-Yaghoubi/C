/*

	Tarokh (Jacob) Yaghoubi , A Program to remove special Characters from 
	both-sides of a character array .

*/

#include <stdio.h>
#include <string.h>

char* index_last(char* ptr);
int index_beginning(char* ptr);

int main()
{
	char name[] = "@# THIS IS A TEST FROM C  @@#!@##$";
	char* ptr;
	ptr = &name[0];
	int len = strlen(name);
	int first_char = index_beginning(name);
	memmove(&name[0], &name[first_char], (len - first_char));
	
	// name[len - first_char] = '\0';

	printf("{%s}\n", index_last(name));
	printf("{%s} \n", ptr);
	printf("{%s} \n", name);
	

	return 0;
}

int index_beginning(char* ptr)
{
	// Start from very first

	int i = 0;
	while ((*ptr < 65 || *ptr > 91) && (*ptr < 97 || *ptr > 122))
	{
		
		i++;	
		ptr++;
		
	}
	
	return i;
}

char* index_last(char* ptr)
{
	// Start from the very last

	size_t size;
	char* end;

	size = strlen(ptr);

	if (!size)
		return ptr;

	end = (ptr + size) - 1;
	while (end >= ptr && ((*end < 65 || *end > 91) && (*end < 97 || *end > 122)))
		end--;

	*(end + 1) = '\0';

	return ptr;
}
