#include <stdio.h>
//void findGreat(int *arra, int row, int col);

int main()
{

    int arr[5][3] = {{23, 5, 23}, {54, 13, 65}, {3, 84, 43}, {76, 13, 10}, {95, 56, 75}};
    //findGreat(arr, 5, 3);
    int row = 5;
    int col = 3;

    int i, j;
    int max[3] = {0}, max2[3] = {0};
    int sum[3] = {0};
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            sum[i] += arr[j][i];
            if (arr[j][i] > max[i])
            {
                max[i] = arr[j][i];
            }
        }
    }
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            sum[i] += arr[j][i];
            if (arr[j][i] > max2[i] && max[i] != arr[j][i])
            {
                max2[i] = arr[j][i];
            }
        }
    }
    for (i = 0; i < col; i++)
    {

        printf("max: %d, max2: %d", max[i], max2[i]);

        printf("\n");
    }
} /*
void findGreat(int *arr, int row, int col)
{
    int i, j;
    int max[3] = {0}, max2[3] = {0};
    int sum[3] = {0};
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            sum[i] += arr[j][i];
            if (arr[j][i] > max[i])
            {
                max[i] = arr[j][i];
            }
        }
    }
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            sum[i] += arr[j][i];
            if (arr[j][i] > max2[i] && max[i] != max2[i])
            {
                max2 = arr[j][i];
            }
        }
    }
    for (i = 0; i < row; i++)
    {
        for (i = 0; i < col; i++)
        {
            printf("max: %d, max2: %d", max[i], max2[i]);
        }
        printf("\n");
    }
}*/