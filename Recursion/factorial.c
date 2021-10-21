#include <stdio.h>

int factorial(int);

int main()
{

    printf("%d", factorial(6));

    return 0;
}
int factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else if (num < 0)
    {
        return;
    }
    return num * factorial(num - 1);
}