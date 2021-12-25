#include <stdio.h>
#include <string.h>

char *strEkle(char *arr1, char *const arr2)
{

    strcpy(arr1 + strlen(arr1), arr2);
}

int main()
{

    char metin1[20] = "artvin";
    char metin2[10] = "kars";

    strEkle(metin1, metin2);
    return 0;
}
