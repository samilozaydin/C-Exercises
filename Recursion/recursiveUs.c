#include <stdio.h>
int usAl(int sayi, int miktar);

int main()
{
    int x = 2;
    printf("%d", usAl(x, 5));
}

int usAl(int sayi, int miktar)
{
    if (miktar == 0)
    {
        return 1;
    }
    else if (miktar < 0)
    {
        return -1;
    }
    return sayi * usAl(sayi, miktar - 1);
}