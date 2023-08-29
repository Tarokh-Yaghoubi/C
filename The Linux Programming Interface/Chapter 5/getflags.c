
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>


int main(int argc, char* argv[])
{

  /* a program to get a file flags and show file permissions */

  int flags = 0;
  int retValue = 0;
  int fd;

  fd = open(argv[1], O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

  if (argc < 2)
    perror("open: what is the file name ? ");
  
  if (fd == -1)
  {
    perror("open : could not open the file");
  }

  flags = fcntl(fd, F_GETFL);
  printf("flag value is : %ld\n", (long)flags);

  close(fd);
  return 0;

}


      
