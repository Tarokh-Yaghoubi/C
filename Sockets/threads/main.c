

// Multi-threading in C 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* routine(){

	printf("This is a test from thread number one \n");
	sleep(3);
	printf("Ending Thread !\n");
}


int main(int argc, char* argv[])
{
	pthread_t thread_one;
	pthread_t thread_two;

	if (pthread_create(&thread_one, NULL, &routine, NULL) != 0)
		return -1;

	if (pthread_create(&thread_two, NULL, &routine, NULL) != 0)
		return -2;

	if (pthread_join(thread_one, NULL) != 0)
		return -3;

	if (pthread_join(thread_two, NULL) != 0)
		return -4;


	return 0;
}
