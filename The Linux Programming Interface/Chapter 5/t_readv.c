

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int         /* K&R Style */
main(int argc, char *argv[]) {
    int fd = 0;

    struct iovec iov[3];
    struct stat myStruct;        /* First Buffer */
    int x;        /* Second Buffer */

#define STR_SIZE 100
    char str[STR_SIZE];
    ssize_t numRead, totRequired;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
    {
        printf("%s file\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        perror("open");

    totRequired = 0;

    iov[0].iov_base = &myStruct;
    iov[0].iov_len = sizeof(struct stat);
    totRequired += iov[0].iov_len;

    iov[1].iov_base = &x;
    iov[1].iov_len = sizeof(x);
    totRequired += iov[1].iov_len;

    iov[2].iov_base = str;
    iov[2].iov_len = STR_SIZE;
    totRequired += iov[2].iov_len;

    numRead = 0;
    numRead = readv(fd, iov, 3);
    printf("str is : %s\n", str);
    if (numRead == -1)
        perror("readv");

    if (numRead < totRequired)
        printf("Read fewer bytes than requested \n");

    printf("Total Bytes required: %ld; bytes read : %ld\n",
           (long ) totRequired, (long ) numRead);

    exit(EXIT_SUCCESS);
}
