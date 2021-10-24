#include <stdio.h>

int isOrdered(int arr[], int size);

int main()
{
    int array[] = {3, 8, 7, 9};
    printf("%d", isOrdered(array, 4));
    return 0;
}

int isOrdered(int arr[], int size)
{
    int i, j;
    int flagMax = 1;
    int flagMin = 1;

    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                flagMax = 0;
            }
            if (arr[i] > arr[j])
            {
                flagMin = 0;
            }
        }
    }
    if (flagMin == 1)
    {
        return 1;
    }
    if (flagMax == 1)
        return 2;
    return 0;
}