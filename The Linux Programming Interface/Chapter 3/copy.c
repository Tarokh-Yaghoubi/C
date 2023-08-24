
/*////////////////////////////////////////////////////*/
//                                                   //   
//                                                   //
//             Author : Tarokh                       //
//             Copy Program                          //
//                                                   //
//                                                   //
/*////////////////////////////////////////////////////*/

#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

#include "headers/tlpi_hdr.h"


#ifndef BUFF_SIZE 
#define BUFF_SIZE 1024
#endif

int
main(int argc, char** argv)
{
    int inputFD, outputFD, openFlags;

    mode_t filePerms;
    ssize_t numRead;
    char buf[BUFF_SIZE];

    if ((argc != 3 || strcmp(argv[1], "--help")) == 0)
    {
        printf("%s old-file new-file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Open Input and Output files */

    if ((inputFD = open(argv[1], O_RDONLY)) < 0)
    {
        printf("error opening the file .. \n");
        exit(EXIT_FAILURE);
    }

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;


    if ((outputFD = open(argv[2], openFlags, filePerms)) < 0)
    {
        perror("open: error with opening file. ");
        exit(EXIT_FAILURE);
    }
        
    /* Transfer data until we encounter end of input or an error */

    while ((numRead = read(inputFD, buf, BUFF_SIZE)) > 0)
    {    
        if (write(outputFD, buf, numRead) != numRead) {
            printf("could not write whole buffer");
            exit(EXIT_FAILURE);
        }
    }

    if (numRead == -1)
        perror("read");

    if (close(inputFD) == -1)
        perror("close input");
    
    if (close(outputFD) == -1)
        perror("close output");
    
    exit(EXIT_SUCCESS);


}
