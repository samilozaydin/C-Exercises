#include <stdio.h>
int sumRowDirect(int arr[][], int sum[], int rw, int col);
void sumRow(int *arr, int *sum, int size, int sizeCol);
void sumCol(int *arr, int *sum, int size, int sizeCol);

int main()
{

    int arr[5][3] = {{23, 5, 23}, {54, 13, 65}, {3, 84, 43}, {76, 13, 10}, {95, 56, 75}};
    int sum[5] = {0};
    sumCol(arr, sum, 5, 3);
    return 0;
}
void sumRow(int *arr, int *sum, int size, int sizeCol)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < sizeCol; j++)
        {
            *sum += *(arr);
            arr++;
        }
        printf("%d\n", *sum);
        sum++;
    }
}
int sumRowDirect(int arr[][], int sum[], int rw, int col)
{
    int i, j;
    for (i = 0; i < rw; i++)
    {
        for (j = 0; j < col; j++)
        {
            sum[i] += arr[i][j];
        }
        printf("sum :%d\n", sum[i]);
    }
}
void sumCol(int *arr, int *sum, int size, int sizeCol)
{
    int i, j;
    int *tut;
    for (i = 0; i < sizeCol; i++)
    {
        tut = arr;
        for (j = 0; j < size; j++)
        {
            *sum += *(arr);
            arr += 3;
        }
        printf("%d\n", *sum);
        arr = tut;
        arr++;
        sum++;
    }
}