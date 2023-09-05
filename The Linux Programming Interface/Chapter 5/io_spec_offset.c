
/*
**	The pread() and pwrite() system calls operate just like read() and write(), except that
**	the file I/O is performed at the location specified by offset, rather than at the current
**	file offset . The file offset is left unchaned by these calls .
*/

/*
**	#include <unistd.h>
**
**	ssize_t pread(int fd, void *buf, size_t count, off_t offset);		// RETURNS number of bytes read , 0 on EOF, or -1 on error
**	ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);		// RETURNS number of bytes written , or -1 on error
**
*/

// Calling pread() is equivalent to ATOMICALLY performing the following calls :
/*

	off_t orig;

	orig = lseek(fd, 0, SEEK_CUR);		// Save current offset .
	lseek(fd, offset, SEEK_SET);
	s = read(fd, buf, len);
	lseek(fd, orig, SEEK_SET);		// RESTORE original file offset

*/


/*
**	for both pread() and pwrite(), the file referred to by fd must be seekable (i.e., a file descriptor
**	on which it is permissible to call lseek()).
**	These system calls can be particularly useful in multithreaded applications . All of the threads in
**	a process share the same file descriptor table . This means that the file offset for each open file
**	is global to all threads . Using pread() or pwrite(), multiple threads can simultaneously perform I/O
**	on the same file descriptor without being affected by changes made to the file offset by other threads
**	if we attempted to use lseek() plus read() (or write() instead, then we would create a race condition )
**	The pread() and pwrite() system calls can similarly be useful for avoiding race conditions in applications
**	when multiple processes have file descriptors referring to the same open file description .
**
*/

/*
**
**	If we are repeatedly performing lseek() calls followed by fikle I/O, then the pread() and pwrite()
**	system calls can also offer a performance advantage in some cases . This is because the cost of a
**	single pread() or pwrite() system call is less than the cost of two system calls : lseek and read()
**	or write() , However, the cost of system calls is usually dwarfed by the time required to actually
**	perform I/O.
**
*/

/*
**	pread() and pwrite() are more thread-safe than read() and write() because they leave the file offset
**	unchanged . This makes it safer for multiple threads or processes to read and write to the same file
**	simultaneously .
**
**	ATOMICITY : pwrite() can provide atomicity guarantees for writing data at a specific offset .
**	It ensures that the data is written to the specified location without being affected by other
**	concurrent writes .
**
**	SEEK OPERATIONS : pread() and pwrite() are particularly useful when you want to perform read or
**	write operations at specific positions in a file without modifying the current file offset ,
**	which may be important in certain file access patterns .
**
**	COMPLEXITY : While pread() and pwrite() offer advantages in certain situations , they may be less
**	intuitive to use than read() and write(), which simply operate on the current file offset .
**	Choosing between them depends on the specific requirements of your application .
*/

