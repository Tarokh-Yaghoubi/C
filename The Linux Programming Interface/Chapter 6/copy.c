

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int
main(int argc, char* argv[]) {

	int fd, fd1;
	fd = fd1 = 0;

	char buffer[100] = { 0 };

	if (argc != 3 || (strcmp(argv[1], "--help") == 0))
	{
		printf("open: first file - second file");
		return 3;
	}


	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return 1;
	}

	fd1 = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd1 == -1)
	{
		perror("open: could not open the second file to copy contents...");
		return 2;
	}


	while(read(fd, buffer, sizeof(buffer)) != 0)
		write(fd1, buffer, sizeof(buffer));

	close(fd);
	close(fd1);

	return 0;

}


