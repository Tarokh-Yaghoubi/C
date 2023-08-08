/*////////////////////////////////////////////////////*/
//                                                   //   
//                                                   //
//             Author : Tarokh                       //
//             Most used header files                //
//                                                   //
//                                                   //
/*////////////////////////////////////////////////////*/


#ifndef TPLI_HEADER_H
#define TPLI_HEADER_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>


#include <unistd.h>
#include <errno.h>
#include <string.h>


#include "error_functions.h"    /* Declares our error-handling functions */
#include "get_num.h"

typedef enum { FALSE, TRUE } Boolean;

#define min(m,n) ((m) < (n) ? (m) : (n))
#define max(m,n) ((m) > (n) ? (m) : (n))

#endif
