

/*
**	Tarokh Yaghoubi (Jacob)
**	LInux Programming Interface
**	Duplicating File Descriptors
*/

/*
**	USING the Bourne Shell I/O redirection syntax 2>&1 informs the shell that we wish to have standard
**	error (file descriptor 2) redirected to the same place to which standard output (file descriptor 1)
**	is being sent . Thus, the following command would send both standard output and standard error to the
**	file result.log
**
**	$ ./mscript > result.log 2>&1
*/

/*
**	The shell achieves the redirection of standard error by duplicating file descriptor 2 so that it refers
**	to the same open file description as file descriptor 1 .
**	This affect can be achieved using dup() and dup2() system calls . Note that it is not sufficient for the
**	SHELL simply to open the results.log file twice: once on descriptor 1 and once on descriptor 2 . One reason
**	for this is that the two file descriptors would not share a file offset pointer , and hence could end up
**	overwriting each others output . Another reason is that the file may not be a disk file . Consider the following
**	command , which send standard error down the same pipe as standard output :
**
**	$ ./mscript 2>&1 | less
*/

/*
**	The dup() call takes oldfd, an open file descriptor , and returns a new descriptor that refers to the same
**	open file description . The new descriptor is guaranteed to be the lowest unused file descriptor .
**
**	#include <unistd.h>
**	int dup(int oldfd);		// RETURNS (new) file descriptor on success, or -1 on error
*/

/*
**	Suppose we make the following call :
**	newfd = dup(1);
**	Assuming the normal situation where the SHELL has opened file descriptors  (0, 1 and 2) on the programs behalf
**	and no other descriptors are in use , dup() will create the duplicate of descriptor 1 using file 3 .
**
**	If we wanted the duplicate to be descriptor 2, we could use the following technique :
**
**	close(2);	// Frees file descriptor 2
**	newfd = dup(1);
**
**	This code works only if descriptor 0 was open . To make the above code simpler, and to ensure we always get the
**	file descriptor we want, we can use dup2().
**
**	#include <unistd.h>
**	int dup2(int oldfd, int newfd);		// RETURNS (new) file descriptor on success , or -1 on error
*/

/*
**	The dup2() system call makes a duplicate of the file descriptor given in oldfd using the descriptor number supplied
**	in newfd . if the file descriptor specified in newfd is already open, dup2() closes it first . (Any error that occurs
**	during this close is silently ignored; safer programming practice is to explicitly close() newfd if it is open before the call
**	to dup2().)
**
**	we could simplify the preceding calls to close() and dup() to the following  :
**
**	dup2(1, 2);
**
**	A successful dup2() call returns the number of the duplicate descriptor (i.e., the value passed in newfd).
*/

/*
**	If oldfd is not a valid descriptor , then dup2() fails with the error EBADF and newfd is not closed .
**	If oldfd is a valid file descriptor , and oldfd and newfd have the same value , then dup2() does nothing .
**	newfd is not closed , and dup2() will return newfd as its function result .
*/

/*
**	A further interface that provides some extra flexibility for duplicating file descriptors in the fcntl() F_DUPFD operation :
**
**	newfd = fcntl(oldfd, F_DUPFD, startfd);
**
**	This call makes a duplicate of oldfd by using the lowest unused file descriptor greater than or equal to startfd.
**	This is useful if we want a guarantee that the new descriptor (newfd) falls in a certain range of values.
**	Calls to dup() and dup2() can always be recoded as calls to close() and fcntl(), although the former calls are more
**	concise .
**
**	NOTE : that some of the errno error codes returned by dup2() and fcntl() differ, as described in the manual pages .
*/

/*
**	Duplicated file descriptors share the same file offset value and status flags in their shared open file description
**	However, the new file descriptor has its own set of file descriptor flags, and its close-on-exec flag (FD_CLOEXEC)
**	is always turned off. The interfaces that we describe next allow explicit control of the new file descriptors
**	close-on-exec flag .
*/

/*
**	The dup3() system call performs the same task as dup2(), but adds an additional argument , flags, that is a bit mask
**	that modifies the behavior of the system call .
**
**	#define _GNU_SOURCE
**	#include <unistd.h>
**
**	int dup3(int oldfd, int newfd, int flags);		// RETURNS (new) file descriptor on success , or -1 on error .
**
**	Currently , dup3() only supports one flag , FD_CLOEXEC
*/

#define _GNU_SOURCE
#include <fcntl.h>	/*Obtain O_* constant definitions */
#include <unistd.h>

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int dup_test(char*);
int t_api_printf(const char*, ...);
int main(int argc, char* argv[]) {

	// main
	int age = 19;
	dup_test(argv[1]);
	t_api_printf("[tar_debug] first log written");
	t_api_printf("[tar_debug] second log written");
	t_api_printf("[tar_debug] third log is my age %d", age);
	t_api_printf("[tar_debug] this is the last log , %x", 0x0545);
	return 0;
}

int dup_test(char* filename) {
	int exitcode = 0;
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	printf("fd file descriptor is : %ld\n", (long )fd);
	if (fd == -1)	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}

	// Save the current standard output (file descriptor 1)
	int saved_stdout = dup(1);
	printf("saved_stdout is : %ld\n", (long )saved_stdout);
	if (saved_stdout == -1) {
		perror("Failed to duplicate standard output");
		close(fd);
		exit(EXIT_FAILURE);
	}

	// Redirect standard output to the file .

	if (dup2(fd, 1) == -1) {
		perror("Failed to redirect standard output");
		close(fd);
		exit(EXIT_FAILURE);
	}

	// Now, Standard output is redirected to the file .

	printf("This will be written to the file\n.");

	// Restore Standard output to the terminal

	if (dup2(saved_stdout, 1) == -1) {
		perror("Failed to restore standard output");
		close(fd);
		exit(EXIT_FAILURE);
	}

	// Now . standard output is back to the terminal

	printf("This will be shown on the terminal\n");

	// Close the file and exit

	close(fd);

	return exitcode;

}

/*
int t_api_printf(const char* format, ...)
{

	int exitcode = 0;
	int fd = open("output.log", O_RDWR | O_APPEND | O_CREAT, 1666);
	if (fd == -1)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}

	int save_stdout = dup(1);
	if (save_stdout == -1)
	{
		perror("Failed to duplicate standard output");
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (dup2(fd, 1) == -1)
	{
		perror("Failed to redirect standard output");
		close(fd);
		exit(EXIT_FAILURE);
	}

        va_list args;
        va_start(args, format);
        vfprintf(stdout, format, args); // Print to stdout
        va_end(args);

	if (dup2(save_stdout, 1) == -1)
	{
		perror("Failed to restore standard output");
		close(fd);
		exit(EXIT_FAILURE);
	}

	close(fd);
	return exitcode;
}
*/



int t_api_printf(const char* format, ...)
{
    int exitcode = 0;
    int fd = open("output.log", O_RDWR | O_APPEND | O_CREAT, 1666);
    if (fd == -1)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fflush(stdout); // flush stdout before redirecting it
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("Failed to redirect standard output");
        close(fd);
        exit(EXIT_FAILURE);
    }

    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args); // Print to stdout
    fprintf(stdout, "\n");
    va_end(args);

    fflush(stdout); // flush stdout after writing to it
    if (dup2(STDOUT_FILENO, fd) == -1)
    {
        perror("Failed to restore standard output");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    return exitcode;
}

