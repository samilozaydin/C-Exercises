#include <stdlib.h>
#include <stdio.h>

char another[7][7];
int isaret[7][7];

void boardControl(char **board)
{

    int i, j, k;
    int counter = 0;
    int select = 1;
    int indexs[7] = {-1};
    int counterright = 0;
    int counterleft = 0;
    int temp1;
    int temp2;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            while (1) //Horizontal amount control
            {
                if (select == 1) //right side control
                {
                    indexs[0] = j;
                    if (j + select <= 6 && board[i][j] == board[i][j + select])
                    {
                        counter++;
                        indexs[counter] = j + select;
                        select++;
                    }
                    else
                    {
                        select = -1;
                    }
                }
                else //left side control
                {
                    if (j + select >= 0 && board[i][j] == board[i][j + select])
                    {
                        counter++;
                        indexs[counter] = j + select;
                        select--;
                    }
                    else
                    {
                        select = 1;
                        break;
                    }
                }
            }
            if (counter > 1)
            {
                while (counter != -1)
                {
                    board[i][indexs[counter]] = 'h'; //new block.
                    indexs[counter--] = -1;
                }
            }
            counter = 0;

            while (1)
            {
                if (select == 1) //up side control
                {
                    indexs[0] = i;
                    if (i + select <= 6 && board[i][j] == board[i + select][j])
                    {
                        counter++;
                        indexs[counter] = i + select;
                        select++;
                    }
                    else
                    {
                        select = -1;
                    }
                }
                else //down side control
                {
                    if (i + select >= 0 && board[i][j] == board[i + select][j])
                    {
                        counter++;
                        indexs[counter] = j + select;
                        select--;
                    }
                    else
                    {
                        select = 1;
                        break;
                    }
                }
            }
            if (counter > 1)
            {
                while (counter != -1)
                {
                    board[indexs[counter]][j] = 'h'; //new block.
                    indexs[counter--] = -1;
                }
            }
            counter = 0;
        }
    }
}

void func2(int x, int y, char color)
{
    if (x >= 0 && x < 7 && y >= 0 && y < 7)
    {
        if (color == another[x][y])
        {
            isaret[x][y] = 1;

            func2(x + 1, y - 1, another[x][y]);
            func2(x + 1, y, another[x][y]);
            func2(x + 1, y + 1, another[x][y]);
            func2(x, y - 1, another[x][y]);
            func2(x, y + 1, another[x][y]);
            func2(x - 1, y - 1, another[x][y]);
            func2(x - 1, y, another[x][y]);
            func2(x - 1, y + 1, another[x][y]);
        }
    }
}
/* do
            {
                temp1 = counterright;
                temp2 = counterleft;

                if (j < 6 && board[i][j] == board[i][j + counterright + 1] && counterright + j < 7)
                {
                    counterright++;
                }
                else if (j > 0 && board[i][j] == board[i][j - counterleft - 1] && j - counterleft > 0)
                {
                    counterleft++;
                }
            } while (counterright != temp1 || counterleft != temp2);*/
/*for (k = j + 1; k < 7; k++) //horizontal control.
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
            for (k = i + 1; k < 7; k++) //horizontal control.
            {
                if (board[i][j] == board[k][j])
                {
                    counter++;
                }
                else
                {
                    i = k;
                    if (counter >= 2)
                    {
                        while (counter)
                        {
                            board[i + counter][j] = 'H'; //newBrick();
                            counter--;
                        }
                    }
                    counter = 0;
                }
            }*/