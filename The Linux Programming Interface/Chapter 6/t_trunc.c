

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>


enum RETVALS {

	SUCCESS,
	ERRUSAGE,
	ERRTRUNC
};

int
main(int argc, char* argv[]) {

	off_t size = 524;
	int retVal = 0;

	if (argc != 2 || (strcmp(argv[1], "--help")) == 0)
	{

		fprintf(stderr, "Usage: %s filename", argv[0]);
		return ERRUSAGE;
	}

	retVal = truncate(argv[1], size);
	if (retVal == -1) {
		perror("truncate");
		return ERRTRUNC;
	}

	return 0;

}

