#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int num;
    srand(time(NULL));

    int i;
    for (i = 0; i < 10; i++)
    {
        num = rand();
        printf("%d\n", num);
    }

    return 0;
}