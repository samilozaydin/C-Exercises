#include <stdio.h>

int sum(int);

int main()
{

    printf("%d", sum(5));
}
int sum(int num)
{
    if (num == 0)
    {
        return num;
    }
    else if (num < 0)
    {
        return;
    }
    return num + sum(num - 1);
}