
/*
 *      Tarokh Yaghoubi (Jacob)
 *      C programming , Linux Programming
 *      Scatter Gather , I/O
 * */

/*
 *      The readv() and writev() system calls perform scatter-gather I/O
 *
 *      #include <sys/uio.h>
 *
 *      ssize_t readv(int fd, const struct iovec *iov, int iovcnt);
 *      // RETURNS number of bytes read , 0 on EOF , -1 on ERROR
 *      ssize_t writev(int fd, const struct iovec* iov, int iovcnt);
 *      // RETURNS number of bytes written , or -1 on ERROR
 * */

/*
 *      Instead of accepting a single buffer of data to be read or written ,
 *      these functions transfer multiple buffers of data in a single
 *      system call . The set of buffers to be transferred is defined by the
 *      array iov . The integer count, specifies the number of elements in iov.
 *      Each element of iov is a structure of the following form :
 *
 *      struct iovec {
 *          void *iov_base;         // Start address of buffer
 *          size_t iov_len;         // Number of bytes to transfer to/from buffer
 *      };
 * */