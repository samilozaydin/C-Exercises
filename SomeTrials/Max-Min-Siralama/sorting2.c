#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sorting(int arr[], int size, int n);
void numberalize(int arr[], int N);
void show(int arr[], int size);
void sorting2(int arr[], int size, int n);

int main()
{
    srand(time(NULL));
    int N;
    printf("bir boyut giriniz: ");
    scanf("%d", &N);

    int array[N];
    numberalize(array, N);

    int n;
    printf("Kac defa yer degistirilsin?: ");
    scanf("%d", &n);
    sorting2(array, N, n);
    show(array, N);
    return 0;
}

void numberalize(int arr[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        arr[i] = rand() % 1000;
    }
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}
void sorting(int arr[], int size, int n)
{
    int i, j;
    while (n > 0)
    {
        int temp = arr[0];
        for (i = 0; i < size; i++)
        {
            if (i == size - 1)
            {
                arr[i] = temp;
                printf("%d\n", temp);
            }
            else
            {
                arr[i] = arr[i + 1];
            }
        }
        n--;
    }
}
void show(int arr[], int size)
{
    printf("\n");
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void sorting2(int arr[], int size, int n)
{
    int i, j;
    while (n > 0)
    {
        int temp = arr[size - 1];
        for (i = size - 1; i >= 0; i--)
        {
            if (i == 0)
            {
                arr[i] = temp;
                printf("%d\n", temp);
            }
            else
            {
                arr[i] = arr[i - 1];
            }
        }
        n--;
    }
}