#include <stdio.h>
void bubbleSort(int const *arr, const int size);
void swap(int *first, int *second);

int main()
{

    int array[10] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%4d", array[i]);
    } /* end for */
    printf("\n");
    bubbleSort(array, 10);

    for (i = 0; i < 10; i++)
    {
        printf("%4d", array[i]);
    } /* end for */

    return 0;
}
void bubbleSort(int const *arr, const int size)
{
    void swap(int *first, int *second);

    int i;
    int j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            /*           if (*(arr + j) > *(arr + j + 1))
            {
                swap((arr + j), (arr + j + 1));
            }
*/
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void swap(int *first, int *second)
{
    int hold = *first;
    *first = *second;
    *second = hold;
}