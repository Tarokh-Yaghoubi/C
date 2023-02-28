/*

		The TIC TAC TOE program (game) - C programming 
		Tarokh Yaghoubi , Jacob

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char matrix[3][3]; /* tic tac toe matrix */

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main(void)
{

	// Write your code here

	char done;

	printf("This is the game of Tic-Tac-Toe . \n");
	printf("You will be playing against the computer \n");


	done = ' ';
	init_matrix();

	do
	{
		disp_matrix();
		get_player_move();
		done = check();	/* See if anyone wins */
		if (done != ' ') break; /* WINNER */
		get_computer_move();
		done = check(); /* See if winner */

	} while (done == ' ');

	if (done == 'X') printf("You won !! \n");

	else printf("I won !! \n");
	disp_matrix();		/* SHOW FINAL POSITIONS  */


	return 0;
}


// Initialize Matrix 

void init_matrix(void)
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			matrix[i][j] = ' ';
}

/* get players move */

void get_player_move(void)
{
	int x, y;

	printf("Enter X,Y coordinates for your move : ");
	scanf("%d%*c%d", &x, &y);

	x--; y--;

	if (matrix[x][y] != ' ')
	{
		printf("Invalid move , try again \n");
		get_player_move();
	}
	else matrix[x][y] = 'X';
}

/* get a move from computer */

void get_computer_move(void)
{
	int i, j;

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

/* Display the matrix */

void disp_matrix(void)
{
	int t;

	for (t = 0; t < 3; t++)
	{
		printf("  %c |   %c  | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
		if (t != 2) printf("\n--- | ---  | ---\n");
	}
	printf("\n");
}

// Check if anybody wins

char check(void)
{
	// some code

	int i;

	for (i = 0; i < 3; i++)		/* Check the rows */
		if (matrix[i][0] == matrix[i][1]
			&& matrix[i][0] == matrix[i][2]) return matrix[i][0];

	
	for (i = 0; i < 3; i++)
		if (matrix[0][i] == matrix[1][i]
			&& matrix[0][i] == matrix[2][i]) return matrix[0][i];


	/* Lets check DIAGONALS ! */

	if (matrix[0][0] == matrix[1][1]
		&& matrix[1][1] == matrix[2][2]) return matrix[0][0];

	if (matrix[0][2] == matrix[1][1]
		&& matrix[1][1] == matrix[2][0]) return matrix[0][2];


	return ' ';


}