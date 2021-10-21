#include <stdio.h>

int partition(int, int);

int main()
{

    printf("%d", partition(5, 3));
    return 0;
}
int partition(int n, int m)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0 || m == 0)
    {
        return 0;
    }
    return partition(n - m, m) + partition(n, m - 1);
}