#include <stdio.h>
void diziYazdir(int dizi[], int boyut);

int main()
{
    int dizi[3] = {1, 2, 3};
    diziYazdir(dizi, 3);

    return 0;
}
void diziYazdir(int dizi[], int boyut)
{
    int i;

    for (i = 0; i < boyut; i++)
    {
        printf("%d\n", *(dizi + i));
    }
}
