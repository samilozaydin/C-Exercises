#include <stdio.h>
void dondur(int *arr, int size);

int main()
{
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    dondur(array, 7);
    int i;
    for (i = 0; i < 7; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
void dondur(int *arr, int size)
{
    int i;
    int temp;
    int *p = arr + size - 1;

    while (p - arr >= 0)
    {
        temp = *p;
        *p = *arr;
        *arr = temp;
        arr++;
        p--;
    }
}