/*

  Author : Tarokh 
  Description : An example on fcntl(), retrieve settings of an open file descriptor .

*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{

  int fd, flags;
  int accessMode, isNonBlocking;
  const char* filename = "tfile";

  
  /* open the file in read-only mode */

  fd = open(filename, O_RDWR);
  if (fd == -1)
  {
    perror("Error opening the file");
    close(fd);
    return 1;
  }

  /* Retrieve file access mode and status flags  */
  flags = fcntl(fd, F_GETFL);
  if (flags == -1)
  {

    perror("Error retrieving file settings");
    close(fd);
    return 1;
  }

  /* Determin the access mode and the flag  */
  printf("The value of flags is : %ld \n", (long)flags);
  printf("The value of O_ACCMODE is : %ld\n", (long)O_ACCMODE);
  printf("The value of O_NONBLOCK is : %ld\n", (long)O_NONBLOCK);
  
  accessMode = flags & O_ACCMODE;
  isNonBlocking = flags & O_NONBLOCK;
  printf("The value of accessMode is : %x\n", accessMode);
  printf("The value of O_RDWR is : %d\n", O_RDWR);
  
  printf("Access Mode : ");
  switch(accessMode) {

  case O_RDONLY:
    printf("Read-Only\n");
    break;
  case O_WRONLY:
    printf("Write-Only\n");
    break;

  case O_RDWR:
    printf("Read-Write\n");
    break;

  default:
    printf("Unknown access mode\n");

  }

  if (isNonBlocking) {

    printf("Non-blocking mode is enabled \n");

  } else {
    
    printf("Blocking mode is enabled \n");

  }


  /* Close the file  */
  close (fd);

  return 0;

}
