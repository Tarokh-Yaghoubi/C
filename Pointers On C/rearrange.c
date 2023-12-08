/* Rearrange program 
    Pointers on C 
    C programming language - Book */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS    20      /* Max # of numbers to process */
#define MAX_INPUT   1000    /* max len of input and output lines */

int read_column_numbers( int columns[], int max );
void rearrange( char* output, char const *input,
                int n_columns, int const columns[] );

int
main( void ) {
    int n_columns;      /* # of columns to process */
    int columns[MAX_COLS];  /* the columns to process */
    int input[MAX_INPUT];
    int output[MAX_INPUT];

    n_columns = read_column_numbers( columns, MAX_COLS );   // read the list of column numbers 

    /*
     **    Read, process and print the remaining lines of input 
    */

   while ( gets(input) != NULL ) {
        printf("Original input : %s\n", input );
        rearrange( output, input, n_columns, columns );
        printf("Rearrange line : %s\n", output);
   }

    return EXIT_SUCCESS;
}

/**
 *  Read the list of column numbers , ignoring any beyond the specified maximum 
*/