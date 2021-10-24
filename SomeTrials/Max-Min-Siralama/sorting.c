#include <stdio.h>

void sortToMax(int arr[], int size);

int main()
{

    int array[] = {5, 9, 3, 7, 8};
    int i;
    sortToMax(array, 5);
    for (i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}

void sortToMax(int arr[], int size)
{

    int i, j;
    int temp;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void sortToMin(int arr[], int size)
{
    int i, j;
    int temp;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
