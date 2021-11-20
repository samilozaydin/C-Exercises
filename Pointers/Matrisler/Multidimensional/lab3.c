#include <stdio.h>
float kenarTopla(int m, int n, float A[m][n]);

int main()
{
    float A[4][3] = {{3, 2, 6}, {5, 1, 8}, {5, 4, 9}, {7, 1, 3}};
    float sum = kenarTopla(4, 3, A);
    printf("%f", sum);
    return 0;
}

float kenarTopla(int m, int n, float A[m][n])
{
    int i, j;
    float sum = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 || i == (m - 1) || j == 0 || j == (n - 1))
                sum += A[i][j];
        }
    }
    return sum;
}