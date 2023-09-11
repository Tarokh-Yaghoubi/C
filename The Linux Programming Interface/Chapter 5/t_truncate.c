
/*
 *      Author : Tarokh Yaghoubi (Jacob)
 *      Descriptor : An example on truncate system call
 *
 * */

/*
 *      #include <unistd.h>
 *      int truncate(const char *pathname, off_t length);
 *      int ftruncate(int fd, off_t length);
 *
 *      Both Return 0 on Success, or -1 on ERROR
 *
 * */

/*
 *      the ftruncate() is system call takes descriptor for a file that has
 *      been opened for writing . It does not change the file offset for the
 *      file .
 *
 *      the truncate() take the filename in its pathname argument , the file
 *      must be accessible / (The filename must be specified as a pathname string)
 *      If the pathname is a symbolic link, it is de-referenced .
 */

// In this program we will use truncate() to resize an exisiting file to a specified length

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void ftruncate_example(void);

int
main(int argc, char *argv[])
{
    const char *filename = "trunc_test.txt";
    off_t newFileSize = 1024;   // New file size in bytes

    // Use truncate to resize the file

    if (truncate(filename, newFileSize) == -1)
    {
        perror("truncate");
        return -1;
    }

    printf("File : %s has been truncated to : %ld bytes\n",
           filename, (long ) newFileSize);

    return 0;
}

// the above code using ftruncate()

void
ftruncate_example(void)
{
    const char *nfilename = "trunc_test.txt";
    int fd = 0;
    off_t newFileSize = 1024;   // new file size in bytes

    fd = open(nfilename, O_RDWR);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }


    // Use ftruncate() to resize the file

    if (ftruncate(fd, newFileSize) == -1)
    {
        perror("ftruncate");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("File %s has been truncated to : %ld size in bytes \n",
           nfilename, (long ) newFileSize);

}

