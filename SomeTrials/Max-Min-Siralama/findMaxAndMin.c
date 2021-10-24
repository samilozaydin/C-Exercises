#include <stdio.h>

int main()
{
    int array[] = {1, 3, 5, 2};
    findMin(array, 4);
    return 0;
}

void findMax(int arr[], int size)
{

    int i, j;
    int max = arr[0];
    int max2;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                max = arr[j];
            }
        }
    }
    printf("%d", max);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (arr[j] != max)
            {
                if (arr[i] < arr[j])
                {
                    max2 = arr[j];
                }
            }
        }
    }
    printf("\n%d", max2);
}
void findMin(int[] arr, int size)
{

    int i, j;
    int min = arr[0];
    int min2;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                min = arr[j];
            }
        }
    }
    printf("\n%d", min);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (arr[i] > arr[j] && arr[j] != min)
            {
                min = arr[j];
            }
        }
    }
    printf("\n%d", min2);
}