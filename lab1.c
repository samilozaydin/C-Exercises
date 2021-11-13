#include <stdio.h>
int divide(int a, int b, int *kalan);

int main()
{
    int a = 14;
    int b = 4;
    int kalan, bolum;
    bolum = divide(a, b, kalan);

    return 0;
}

int divide(int a, int b, int *kalan)
{
    int divide = a / (b);
    *kalan = a % (b);
    return divide;
}