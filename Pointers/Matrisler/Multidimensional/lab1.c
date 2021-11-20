#include <stdio.h>
void pullRow(int M, int N, int A[M][N], int r, int row);

int main()
{

    int A[4][3] = {{3, 2, 6}, {5, 1, 8}, {5, 4, 9}, {7, 1, 3}};
    int B[3][4];
    int rw = 4;
    int col = 3;
    int i, j;
    for (i = 0; i < rw; i++)
    {
        for (j = 0; j < col; j++)
        {
            B[j][i] = A[i][j];
        }
    }
    int *p;
    pullRow(4, 5, A, 2, p);
    return 0;
}
void pullRow(int M, int N, int A[M][N], int r, int *row)
{
    int rw = M;
    int col = N;
    int i, j;
    for (i = 0; i < rw; i++)
    {
        for (j = 0; j < col; j++)
        {
            /* code */
        }
    }
}