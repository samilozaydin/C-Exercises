#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

static int kareAl(int sayi)
{

    return sayi * sayi;
}
int numCreator()
{
    int num;
    srand(time(NULL));
    num = (rand() % 60) + 20;
    return num;
}
