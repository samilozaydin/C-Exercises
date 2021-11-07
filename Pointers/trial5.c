#include <stdio.h>
int *enKucuk(int dizi[], int boyut);

int main()
{
    int dizi[5] = {3, 6, 2, 78, 7};
    int *address = enKucuk(dizi, 5);

    printf("min sayi : %d", *address);
    return 0;
}
int *enKucuk(int dizi[], int boyut)
{
    int i;
    int min = *(dizi);
    int index = 0;
    for (i = 0; i < boyut; i++)
    {
        if (min > *(dizi + i))
        {
            min = *(dizi + i);
            index = i;
        }
    }
    int *address = dizi + index;
    return address;
}
