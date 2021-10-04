#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int WIDTH = 50;
const int HEIGHT = 15;

void boundary (int board[HEIGHT][WIDTH])
{
    int cols, rows;
    for (cols =0; cols <WIDTH; cols++)
    {
        board[0][cols] = '#';
        board[HEIGHT -1][cols]= '#';
    }
    for (rows =1; rows <HEIGHT; rows++)
    {
        board[rows][0] = '#';
        board[rows][WIDTH -1] = '#';
    }
}

void randomly(int board[HEIGHT][WIDTH])
{
    int i, j, num;
    srand((unsigned)time(NULL));
    for(i =1; i <HEIGHT -1; i++)
        for(j=1; j <WIDTH -1;j++)
        {
            num = rand()%11;
            if (num == 1)
                board[i][j] = 'O';
            else board[i][j] = ' ';
        }
}
void display(int board[HEIGHT][WIDTH])
{
int rows,cols;
    for (rows = 0; rows <HEIGHT; rows++)
    {
        for(cols =0; cols <WIDTH; cols++)
            printf ("%3c", board[rows][cols]);
        printf ("\n");
    }
}
void countneighbors (int board[HEIGHT][WIDTH])
{
    int neighbors,rows,cols,a,b;
    for (rows =1; rows <HEIGHT; rows++)
    {
        for (cols = 1; cols <WIDTH; cols ++)
        {
            neighbors = 0;
            if (board[rows][cols] == 'O')
            {
                for (a = -1; a <2; a++)  /*It will run a vertical search along the respective live cell*/
                {
                    for (b = -1; b <2; b++) /*It will run a horizontal search along the respective live cell*/
                    {
                        if (((rows +a) == rows) && ((cols +b) == cols))
                             neighbors = neighbors;
                        else if ((board[rows +a][cols +b] == 'O') ||(board[rows +a][cols +b] == 1) || (board[rows +a][cols +b] == 0))
                            neighbors++;
                    }
                }
                if ((neighbors == 2) || (neighbors == 3))
                    board[rows][cols] = 1; /*live*/
                else if ((neighbors < 2) || (neighbors >= 4))
                    board[rows][cols] = 0; /*die*/
            }
        }
    }
}
void checknewborns (int board[HEIGHT][WIDTH])
{
    int neighbors,rows,cols,a,b;

    for (rows =1; rows <HEIGHT -1; rows++)
    {
        for (cols = 1; cols <WIDTH -1; cols ++)
        {
            neighbors = 0;
            if (board[rows][cols] == ' ')
            {
                for (a = -1; a <2; a++) /*It will run a vertical search along the respective dead cell*/
                {
                    for (b = -1; b <2; b++) /*It will run a horizontal search along the respective live cell*/
                        if (((rows +a) == rows) && ((cols +b) == cols))
                            neighbors = neighbors;
                        else if ((board[rows +a][cols +b] == 'O') || (board[rows +a][cols +b] == 1) || (board[rows +a][cols +b] == 0))
                            neighbors++;
                }
                if ((neighbors == 3))
                    board[rows][cols] = 2; /*newborn*/
                else if (neighbors >= 4)
                    board[rows][cols] = 0; /*die*/
            }
        }
    }
}
void newgeneration (int board[HEIGHT][WIDTH])
{
    int rows,cols;

    for (rows =1; rows <HEIGHT -1; rows++)
    {
        for (cols = 1; cols <WIDTH -1; cols ++)
        {
            if (board[rows][cols] == 1)
                board[rows][cols] = 'O';  /*Confirm live cell*/
            else if (board[rows][cols] == 2)
                board[rows][cols] = 'O';   /*Confirm newborn cell*/
            else if (board[rows][cols] == 0)
                board[rows][cols] = ' ';   /*Confirm dead cell*/
        }
    }
}

void playgame (int board[HEIGHT][WIDTH], int numgeneration)
{
    int i;
    for (i = 1; i <= numgeneration; i++)
    {
        system("cls");
        countneighbors(board);
        checknewborns(board);
        newgeneration(board);
        printf ("Generation: %i\n", i);
        display(board);
    }
}

void play (int board[HEIGHT][WIDTH])
{
    int generation;
    randomly(board);
    display(board);
    printf ("\nPlease select a number of generation: ");
    scanf ("%d", &generation);

    playgame(board, generation);


}
int main (void)
{
    int board[HEIGHT][WIDTH];
    boundary(board);
    printf ("CONWAY'S GAME OF LIFE\n\n");

    play (board);


return 0;
}

