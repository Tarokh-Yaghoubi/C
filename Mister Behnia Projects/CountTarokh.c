#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


/*

 Program number 16 
 how many times the name tarokh has been repeated 
 { TAROKH }

*/


int main(int argc, char* argv[])
{
	int i, j, count_tarokh = 0;
	char name[] = { "tarokh\0" };

	char username[20][20];
	char yourname[20];

	printf("\nWaiting for names to rain ... \n type in /exit to exit the program : ... \n\n");
	for (i = 0; i < 20; i++)
	{
		printf(">> ");
		scanf("%s", yourname);
		// printf("The strlen is : %d \n", strlen(yourname));
		
		if (strcmp(yourname, name) == 0)
			count_tarokh++;

		if (strlen(yourname) > 20)
		{
			printf("\nProgram can not support names that exceed 20 characters ... \n program shall stop in 3 seconds \n");
			sleep(3);
			exit(0);
		}
			
		
		if (strcmp(yourname, "/exit") == 0)
		{
			printf("\nYou are leaving but this is what i've done so far ... \n");
			printf("\n---------------------------\n");
			for (j = 0; j < i; ++j)
			{
				printf("%s \n", username[j]);
			}

			printf("\n---------------------------\n");
			printf("tarokh repeated %d times\n", count_tarokh);

			exit(0);
		}
		

		strcpy(username[i], yourname);
	}

	for (j = 0; j < i; ++j)
	{
		printf("%s \n", username[j]);	
	}

	printf("\n---------------------------\n");
	printf("tarokh repeated %d times\n", count_tarokh);
	return 0;
}