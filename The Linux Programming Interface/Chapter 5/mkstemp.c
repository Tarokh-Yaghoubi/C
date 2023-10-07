

#include <stdlib.h>

int main(void) {


	int fd;
	char template[] = "/tmp/somestringXXXXXX";


	fd = mkstemp(template);

	if (fd == -1)
	{
		perror("mkstemp");
		exit(EXIT_FAILURE);
	}

	printf("The generated file name was %s\n", template);
	unlink(template); 	/* Name disappears immediately, but the file is removed only after close()  */

	/* Use the file I/O system calls - read(), write() and so on  */

	if (close(fd) == -1)
		perror("close");


}

/*

	the tmpnam(),  tempnam() and mktemp() functions can also be used to generate unique filenames.
	However, these functions should be avoided because they can create security holes in an application.

*/
