#include <stdio.h>

int fib(int);

int main()
{
    printf("%d", fib(5));
    return 0;
}

int fib(int num)
{
    if (num == 1 || num == 0)
    {
        return 1;
    }
    else if (num < 0)
    {
        return;
    }
    return fib(num - 1) + fib(num - 2);
}