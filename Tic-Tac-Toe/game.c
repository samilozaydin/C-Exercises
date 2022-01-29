#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(char **);
void createBoard(char **);
int isWin(char **);
int hasEmptySpace(char **);
void playerMove(char **, char);
void computerMove(char **, char);
void printWinner(char);
int minimax(char **, int);

int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char const PLAYER = 'X';
    char const COMPUTER = 'O';
    char winner = ' ';
    char *pBoard[3];
    pBoard[0] = board[0];
    pBoard[1] = board[1];
    pBoard[2] = board[2];
    while (hasEmptySpace(pBoard) != 0 && winner == ' ')
    {
        printBoard(pBoard);

        playerMove(pBoard, PLAYER);
        if (isWin(pBoard) == 2)
        {
            winner = 'O';
        }
        else if (isWin(pBoard) == 1)
        {
            winner = 'X';
        }
        else
        {
            winner = ' ';
        }
        if (hasEmptySpace(pBoard) == 0 && winner == ' ')
        {
            break;
        }

        computerMove(pBoard, COMPUTER);
        if (isWin(pBoard) == 2)
        {
            winner = 'O';
        }
        else if (isWin(pBoard) == 1)
        {
            winner = 'X';
        }
        else
        {
            winner = ' ';
        }
        if (hasEmptySpace(pBoard) == 0 && winner == ' ')
        {
            break;
        }
    }
    printBoard(pBoard);
    printWinner(winner);

    return 0;
}
void printBoard(char **broad)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("\t%c\t|\t%c\t|\t%c\t", *(*(broad + i)), *(*(broad + i) + 1), *(*(broad + i) + 2));
        if (i != 2)
            printf("\n----------------------------------------------\n");
    }
    printf("\n");
}
void createBoard(char **board)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    printf("Board is resetted.\n");
    printBoard(board);
}
int isWin(char **board)
{
    int i, j;
    //Horizontal control
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            if (board[i][0] == 'X')
            {
                return 1;
            }
            else if (board[i][0] == 'O')
            {
                return 2;
            }
        }
    }
    //Vertical control
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            if (board[0][i] == 'X')
            {
                return 1;
            }
            else if (board[0][i] == 'O')
            {
                return 2;
            }
        }
    }
    //Diagonal control
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        if (board[0][0] == 'X')
        {
            return 1;
        }
        else if (board[0][0] == 'O')
        {
            return 2;
        }
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        if (board[0][2] == 'X')
        {
            return 1;
        }
        else if (board[0][2] == 'O')
        {
            return 2;
        }
    }

    return 0;
}
int hasEmptySpace(char **board)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 1;
            }
        }
    }
    return 0;
}
void playerMove(char **board, char move)
{
    int row;
    int col;
    while (1)
    {
        printf("Enter a number from 1 to 9 :");
        scanf("%d", &row);
        row--;

        col = row;
        row /= 3;
        col %= 3;

        if (board[row][col] == ' ')
        {
            board[row][col] = move;
            break;
        }
        printf("This space is not suitable. Please reconsider\n");
    }
}
void computerMove(char **board, char move)
{
    int i, j;
    int row, col;
    int score;
    int bestscore = -100;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = move;
                score = minimax(board, 1);
                board[i][j] = ' ';
                if (score > bestscore)
                {
                    bestscore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    board[row][col] = move;
}
int minimax(char **board, int currentPlayer)
{
    if (isWin(board) == 2)
    {
        return 1;
    }
    else if (isWin(board) == 1)
    {
        return -1;
    }
    else if (isWin(board) == 0 && hasEmptySpace(board) == 0)
    {
        return 0;
    }
    int i, j;
    int score;
    int bestscore;

    if (currentPlayer == 1)
    {
        bestscore = 100;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'X';
                    score = minimax(board, 2);
                    board[i][j] = ' ';
                    if (score < bestscore)
                    {
                        bestscore = score;
                    }
                }
            }
        }
        return bestscore;
    }
    else
    {
        bestscore = -100;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'O';
                    score = minimax(board, 1);
                    board[i][j] = ' ';
                    if (score > bestscore)
                    {
                        bestscore = score;
                    }
                }
            }
        }
        return bestscore;
    }
}
void printWinner(char winner)
{
    if (winner == 'X')
    {
        printf("You win!\n");
    }
    else if (winner == 'O')
    {
        printf("You lost!\n");
    }
    else
    {
        printf("Draw!\n");
    }
}
