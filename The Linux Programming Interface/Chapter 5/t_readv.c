


#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>


int
main(int argc, char *argv[])
{

  int fd = 0;
  struct iovec iov[3];
  struct stat nyStruct;        /* First Buffer */
  int x;        /* Second Buffer */

#define STR_SIZE 100
  char str[STR_SIZE];
  ssize_t numRead, totRequired;

  
