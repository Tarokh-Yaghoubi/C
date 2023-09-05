

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


*/
