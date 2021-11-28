#include <stdio.h>
int kesinKosegenMi(int N, int C[N][N]);

int main()
{

    return 0;
}

int kesinKosegenMi(int N, int C[N][N])
{
    int i, j, sum = 0;
    int result = 1;

    for (i = 0; i < N; i++)
    {
        sum = 0;
        for (j = 0; j < N; j++)
        {
            if (i != j)
            {
                sum += abs(C[i][j]);
            }
            if (abs(C[i][i] < sum))
            {
                result = 0;
            }
        }
    }
    return result;
}