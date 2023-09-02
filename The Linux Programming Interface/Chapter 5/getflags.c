
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

void something_else(void);

int main(int argc, char* argv[])
{
    int accessMode = 0;
    int flags = 0;
    int fd;
    int retValue = 0;

    fd = open(argv[1], O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

    if (argc < 2)
          perror("open: what is the file name ? ");
  
    if (fd == -1)
    {
          perror("open : could not open the file");
    }

    flags = fcntl(fd, F_GETFL);
    flags |= O_APPEND;
    if (fcntl(fd, F_SETFL, flags) == -1)
        perror("fcntl");
    flags = fcntl(fd, F_GETFL);
    accessMode = flags & O_ACCMODE;
    printf("flag value is : %ld\n", (long)flags);
    printf("The access mode is : %ld\n", (long)accessMode);
    switch (accessMode) {
        case O_WRONLY:
            printf("The file is write only \n");
            break;
        case O_RDONLY:
            printf("The file is read only \n");
            break;

        case O_RDWR:
            printf(("The file is both readable and writeable \n"));
            break;
        case O_ASYNC:
            printf("The file is ASYNC\n");
            break;
        default:
            printf("the file access is something else \n");
            break;
    }
    close(fd);
    something_else();
    return 0;
}

void something_else(void)
{
    printf("the man is a good man\n");
}
      
