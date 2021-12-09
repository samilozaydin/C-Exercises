#include <stdio.h>
#include <math.h>
#include "matrisoperations.h"

int main()
{
    int matris1[5][5] = {{21, 19, 17, 25, 28}, {71, 76, 73, 68, 59}, {153, 154, 164, 157, 155}, {200, 201, 190, 185, 180}, {205, 210, 215, 230, 232}};
    int matris2[3][3] = {{-1, -1, -1}, {-1, 8, -1}, {-1, -1, -1}};
    int **matrisal1;
    int **matrisal2;

    operasyon1(matrisal1, matrisal2, 1, 25, 9);
    return 0;
}