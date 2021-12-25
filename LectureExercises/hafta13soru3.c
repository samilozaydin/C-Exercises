#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char sehirler[4][10] = {"izmir", "sivas", "adana", "eskisehir"};
    char gec[10];
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (strcmp(sehirler[j], sehirler[j + 1]) > 0)
            {
                strcpy(gec, sehirler[j]);
                strcpy(sehirler[j], sehirler[j + 1]);
                strcpy(sehirler[j + 1], gec);
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        printf("%s\n", sehirler[i]);
    }

    return 0;
}