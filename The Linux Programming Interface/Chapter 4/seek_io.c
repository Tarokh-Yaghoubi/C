/*

    Author : Tarokh
    Book : The Linux Programming Interface

*/

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

typedef char uint6;

int
main(int argc, char* argv[])
{
    size_t len;
    off_t offset;
    int fd, ap, j;
    uint6* buffer;
    size_t numRead, numWritten;

    if (argc < 3 || strcmp(argv[1], "--help") == 0)
        perror("%s file {r<length>|R<length>|w<string>|s<offset>}...\n", argv[0]);

    fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);     /* rw-rw-rw- */

    if (fd == -1)
        perror("open");

    for (ap = 2; ap < argc; ap++)
    {
        switch (argv[ap][0])
        {
        case 'r':   /* Display Bytes at current offset, as text */
        case 'R':   /* Display Bytes at current offset, in hex */
            len = getlong(&argv[ap][1], GN_ANY_BASE, argv[p]);
            buffer = malloc(len);
            if (buffer == NULL)
                perror("malloc");
            numRead = read(fd, buffer, len);
            if (numRead == -1)
                perror("read");

            if (numRead == 0)
            {
                printf("%s: end-of-file\n", argv[ap]);
            } else {
                printf("%s : ", argv[p]);
                for (j = 0; j < numRead; ++j) {
                    if (argv[ap][0] == 'r')
                        printf("%c ", isprint((unsigned char) buffer[j]) ? buffer[j] : '?');
                    else
                        printf("%02x ", (unsigned int) buffer[j]);
                }
                printf("\n");
            }
            free(buffer);
            break;
        
        case 'w':   /* Write String at Current Offset */
            numWritten = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
            if (numWritten == -1)
                perror("write");

            printf("%s : wrote %ld bytes \n", argv[ap], (long)numWritten);
            break;

        case 's':   /* Change file offset */
            offset = getlong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
            if (lseek(fd, offset, SEEK_SET) == -1)
                perror("lseek");

            printf("%s: seek succeeded \n", argv[ap]);
            break;
        
        default:
            printf("Argument must start with [rRws]: %s\n", argv[ap]);
            exit(1);
        }
    }
    exit(EXIT_SUCCESS);
}
