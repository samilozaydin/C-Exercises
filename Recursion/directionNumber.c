#include <stdio.h>

int paths(int, int);

int main()
{

    printf("%d", paths(3, 3));
    return 0;
}
int paths(int n, int m)
{
    if (n == 1 || m == 1)
    {
        return 1;
    }
    else if (n < 1 || m < 1)
    {
        return;
    }
    return paths(n - 1, m) + paths(n, m - 1);
}