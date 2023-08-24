
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
  int fd;

  fd = open(argv[1], O_WRONLY);
  if (fd != -1) {
    printf("[PID %ld] File \"%s\" already exists \n", (long) getpid(), argv[1]);
    close(fd);

  } else {
    if (errno != ENOENT) {    /* failed for unexpected reason  */
      perror("open");
      exit(1);
    } else {
      /* WINDOW FOR FAILURE  */

      fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
      if (fd == -1)
	perror("open");

      printf("[PID %ld] Created file \"%s\" exclusively \n", (long) getpid(), argv[1]);
      /* May not be TRUE ! */

    }
  }
}

    
