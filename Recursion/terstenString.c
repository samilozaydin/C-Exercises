#include <stdio.h>
void dondur(char arr[], int a);

int main()
{

    char array[] = "bakalim";
    char arraye[20];
    dondur(array, 8, arraye);
    gets(arraye);
    return 0;
}

void dondur(char arr[], int i, char empty[])
{
    if (arr[i])
    {
        dondur(arr, i);
        empty[sizeof(arr) - i - 1] = arr[i];
    }
}