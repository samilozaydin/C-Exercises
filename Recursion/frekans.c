#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNum();
void frekansGetir(int array[]);

int main()
{
    srand(time(NULL));
    int array[10] = {0};
    frekansGetir(array);
    return 0;
}
int randomNum()
{
    int num = (rand() % 9) + 1;
    return num;
}
void frekansGetir(int array[])
{
    int i;
    for (i = 0; i < 1000; i++)
    {
        array[randomNum()]++;
    }
    for (i = 1; i < 10; i++)
    {
        printf("array[%d] = %d time\n", i, array[i]);
    }
}