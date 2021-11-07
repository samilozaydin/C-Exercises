#include <stdio.h>
void wrap(int arr[], int size);

int main()
{

    int arr[] = {55, 9, 4, 2, 5, 6, 94};
    int size = 7;
    wrap(arr, size);
}
void wrap(int arr[], int size)
{

    int i, j;
    int min;
    int mindeks;
    int temp;
    for (i = 0; i < size; i++)
    {
        mindeks = i;
        min = arr[i];
        for (j = i; j < size; j++)
        {
            if (arr[j] < min)
            {
                mindeks = j;
                min = arr[j];
            }
        }
        if (i != mindeks)
        {
            arr[mindeks] = arr[i];
            arr[i] = min;
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}