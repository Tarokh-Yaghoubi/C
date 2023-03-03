#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char* p[], char* name);

char* names[] = {

	"Tarokh",
	"Mohammad",
	"Jacob",
	"Tommy",
	"Sara",
	NULL
};

int main(void)
{
	// write your code

	if (search(names, "Tarokh") != -1)
		printf("Tarokh is in list \n");

	if (search(names, "Mohammad") == -1)
		printf("MOhmmad not found");
	else printf("Mohammad is in the list \n");

	return 0;
}

int search(char* p[], char* name)
{
	register int t;

	for (t = 0; p[t]; t++)
		if (!strcmp(p[t], name)) return t;

	return -1;	/* not found */
}