#define _POSIX_C_SOURCE
#define _POSIX_SOURCE


#include <stdio.h>
#include <stdarg.h>
#include "tlpi_hdr.h"

#include <linux/reboot.h>




int main()
{
    size_t sz = 15;
    __pid_t mypid;
    /* A portable way to use sembuf structure is this */

    struct sembuf s;
    s.sem_num = 3;
    s.sem_op = -1;
    s.sem_flg = SEM_UNDO;
    

    /* C99 new syntax for structure initializers */
    struct sembuf ss = {
        .sem_num = 3,
        .sem_op = -1,
        .sem_flg = SEM_UNDO
    };

#ifdef WCOREDUMP
    /* Use WCOREDUMP() macro */
#endif


    mypid = getpid();

    printf("My PID is : %ld\n", (long)mypid);
    printf("The size of sz is : %zd\n", (long)sz);
    
    return 0;

}