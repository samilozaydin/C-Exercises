#include <stdlib.h>
#include <stdio.h>

void boardControl(char **board)
{

    int i, j, k;
    int counter = 0;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            for (k = j + 1; k < 7; k++) //horizontal control.
            {
                if (board[i][j] == board[i][k])
                {
                    counter++;
                }
                else
                {
                    j = k;
                    if (counter >= 2)
                    {
                        while (counter)
                        {
                            board[i][j + counter] = 'H'; //newBrick();
                            counter--;
                        }
                    }
                    counter = 0;
                }
            }
        }
    }
}