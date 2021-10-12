#include <stdio.h>

int asalMi(int sayi);

int altKumeleriAsalMi(int sayi);

int main()
{
    int say = 7331;
    printf("%d", altKumeleriAsalMi(say));

    return 0;
}
int asalMi(int sayi)
{
    if (sayi == 1)
    {
        return 1;
    }
    int i;
    for (i = 2; i <= sayi / 2; i++)
    {
        if (sayi % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int altKumeleriAsalMi(int sayi)
{
    if (sayi < 100)
    {
        return 0;
    }
    while (sayi > 0)
    {
        if (asalMi(sayi))
        {
            sayi /= 10;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
