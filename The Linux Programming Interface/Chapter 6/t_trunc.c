

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

enum RETVALS {

	SUCCESS,
	ERRUSAGE,
	ERRTRUNC,
	ERRFILEOPEN,
	ERRWRITETOFILE
};

int
main(int argc, char* argv[]) {

	off_t size = 524;
	char* msg = "tarokh is a good C developer";
	off_t offset;
	size_t msg_len = 0;
	int retVal = 0;
	int fd;
	fd = 0;

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

	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		perror("open: could not open the file that has been truncated");
		close(fd);
		return ERRFILEOPEN;
	}

	lseek(fd, 0, SEEK_SET);

	msg_len = strlen(msg);

	ssize_t bytes_written = write(fd, msg, msg_len);
	if (bytes_written == -1) {
		perror("write");
		close(fd);
		return ERRWRITETOFILE;
	}

	close(fd);

	return 0;

}

