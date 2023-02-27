#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


char matrix[3][3];      /* the tic-tac-toe matrix */

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main(void)
{
    // Write your code here 


}

/* Initialize the matrix */

void init_matrix(void)
{
    int i, j;

    for(i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            matrix[i][j] = ' ';
        
}

/* get a players move */

void get_player_move(void)
{
    int x , y;

    printf("Enter X,Y coordinates for your move :  ");
    scanf("%d%*c%d", &x, &y);

    x--; y--;

    if (matrix[x][y] != ' ')
    {
        printf("Invalid move , try again : \n");
        get_player_move();

    } else matrix[x][y] = 'X';
    
}

/* Get a move from the computer */

void get_computer_move(void)
{
    int i , j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (matrix[i][j] == ' ') break;

        if (matrix[i][j] == ' ') break;
    }
    
    if (i * j == 9) {
        printf("Draw \n");
        exit(0);
    }
    else matrix[i][j] = 'O';

}
