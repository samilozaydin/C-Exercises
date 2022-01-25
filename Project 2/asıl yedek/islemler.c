#include <stdio.h>
#include "islemler.h"
#include <stdint.h>
#include <stdlib.h>

uint8_t *readFile(char *des, int *numSize)
{
    FILE *file;
    uint8_t *num = NULL;
    if ((file = fopen(des, "r+")) == NULL)
    {
        printf("File cannot be opened so num is send as NULL");
    }
    else
    {
        *numSize = sizeFile(file);
        // printf("%d\n", *numSize);
        num = createArray(*numSize);
        int i = 0;
        while (!(feof(file)))
        {
            char temp = fgetc(file);
            if (temp >= 48 && temp <= 57)
            {
                //  printf("char      :%c\n", temp);
                //  printf("char digit: %d\n", temp);
                *(num + i) = (uint8_t)(temp - 48);
                // printf("num digit: %d\n", *(num + i));
                i++;
            }
        }
        //  printf("\n");
    }
    fclose(file);
    return num;
}
int sizeFile(FILE *file)
{ //DOSYA ARASINDAKI BOSLUKLAR VAR KABUL EDILECEK MI EDILMEYECEK MI?
    int size = 0;
    char temp;
    while (!((temp = fgetc(file)) == EOF))
    {
        if (temp >= 48 && temp <= 57)
            size++;
    }
    rewind(file);
    return size;
}
uint8_t *createArray(int size)
{
    uint8_t *arr = (uint8_t *)malloc(size * sizeof(uint8_t));
    return arr;
}
uint8_t *sumFile(uint8_t *num1, uint8_t *num2, int num1Size, int num2Size, int *sumSize)
{
    uint8_t *sum;
    uint8_t *big;
    uint8_t *low;

    int size;
    int diff;

    // specifyMaxMin();
    if (num1Size > num2Size)
    {
        size = num1Size;
        diff = num1Size - num2Size;
        big = num1;
        low = num2;
    }
    else
    {
        size = num2Size;
        diff = num2Size - num1Size;
        big = num2;
        low = num1;
    }

    int flag = 0;
    /*  if (diff == 0) //toplam basamak arttirimi sadece her iki sayinin basamak sayisi esitse yapilir.
    {
        if (*(num1 + 1) + *(num2 + 1) > 9) //ilk iki basamagin toplaminin basamagi buyutup buyutmedigine bakilir.
        {
            if (*(num1) + *(num2) + 1 > 9)
            {
                *sumSize = size + 1;
                sum = createArray(size + 1);
                flag = 1;
            }
            else
            {
                *sumSize = size;
                sum = createArray(size);
            }
        }
        else
        {
            if (*(num1) + *(num2) > 9)
            {
                *sumSize = size + 1;
                sum = createArray(size + 1);
                flag = 1;
            }
            else
            {
                *sumSize = size;
                sum = createArray(size);
            }
        }
    }
    else*/
    //  {
    *sumSize = size + 1;
    sum = createArray(size + 1);
    // }

    // size = (num1Size > num2Size) ? (num1Size) : num2Size;

    int i;
    int get = 0;
    for (i = size - 1; i >= 0; i--)
    {
        if (i >= diff)
        {
            *(sum + i + 1) = (*(big + i) + *(low + i - diff) + get) % 10;
            //printf("i = %d icin sayi : %d\n", i, (*(big + i) + *(low + i - diff) + get) % 10);
            //printf("i = %d icin get : %d\n", i, (*(big + i) + *(low + i - diff)) / 10);
            // printf("number 1: %d ve number 2: %d\n", *(big + i), *(low + i - diff));
            //printf("*******************\n");
            get = (*(big + i) + *(low + i - diff) + get) / 10;
        }
        else
        {
            *(sum + i + 1) = (*(big + i) + get) % 10;
            //  printf("i = %d icin sayi : %d\n", i, (*(big + i) + get) % 10);
            //  printf("i = %d icin get : %d\n", i, (*(big + i)) / 10);
            //  printf("number 1: %d ve number 2 bulunmaz\n", *(big + i));
            // printf("*******************\n");
            get = 0;
        }
    }
    if (get == 1)
    {
        *(sum) = 1;
    }
    else
    {
        *sum = 0;
    }
    //  printf("FLAG = %d\n", flag);
    // printf("sumSize : %d\n", *sumSize);
    /* if (flag == 1)
    {
        *sum = 1;
    }*/

    return sum;
}
uint8_t *substractFile(uint8_t *num1, uint8_t *num2, int num1Size, int num2Size, int *substractSize, char *notation)
{
    uint8_t *substruct;
    uint8_t *big;
    uint8_t *low;

    int size;
    int diff;

    // specifyMaxMin();
    if (num1Size > num2Size)
    {
        size = num1Size;
        diff = num1Size - num2Size;
        big = num1;
        low = num2;
    }
    else if (num2Size == num1Size) //sayi icerikleri kontrol edilir. Buyuk olan basa gecirilir.
    {
        int i;
        for (i = 0; i < num1Size; i++)
        {
            if (*(num1 + i) > *(num2 + i))
            {
                size = num1Size;
                diff = num1Size - num2Size;
                big = num1;
                low = num2;
                break;
            }
            else if (*(num1 + i) == *(num2 + i))
            {
                continue;
            }
            else
            {
                size = num2Size;
                diff = num2Size - num1Size;
                big = num2;
                low = num1;
                *notation = '-';
                break;
            }
        }
    }
    else
    {
        size = num2Size;
        diff = num2Size - num1Size;
        big = num2;
        low = num1;
        *notation = '-';
    }

    int flag = 0;

    *substractSize = size;
    substruct = createArray(size);

    // size = (num1Size > num2Size) ? (num1Size) : num2Size;

    int i;
    int debt = 0;
    for (i = size - 1; i >= 0; i--)
    {
        if (i >= diff)
        {
            *(substruct + i + flag) = (*(big + i) - *(low + i - diff) - debt);
            debt = 0;
            if (*(substruct + i + flag) > 10)
            {
                //      printf("i = %d icin sayi (eldeki hal) : %d\n", i, *(substruct + i + flag));
                debt = 1;
                *(substruct + i + flag) += 10;
            }
            // printf("i = %d icin sayi : %d\n", i, *(substruct + i + flag));
            // printf("i = %d icin debt : %d\n", i, debt);
            // printf("number 1: %d ve number 2: %d\n", *(big + i), *(low + i - diff));
            //  printf("*******************\n");
        }
        else
        {
            *(substruct + i + flag) = (*(big + i) - debt);
            // printf("i = %d icin sayi : %d\n", i, *(substruct + i + flag));
            //  printf("i = %d icin debt : %d\n", i, debt);
            //  printf("number 1: %d ve number 2 bulunmaz\n", *(big + i));
            // printf("*******************\n");
            debt = 0;
        }
    }
    //  printf("FLAG = %d\n", flag);
    // printf("sumSize : %d\n", *sumSize);

    return substruct;
}
//void specifyMaxMin(){

//}
uint8_t *removeZeros(uint8_t *arr, int *arrSize)
{
    int i;
    uint8_t *newArr;
    for (i = 0; i < *arrSize; i++)
    {
        if (*(arr + i) != 0)
        {
            newArr = (arr + i);
            *arrSize = *arrSize - i;
            break;
        }
    }
    return newArr;
}
void displayNumber(uint8_t *num, int numSize)
{
    int i;
    for (i = 0; i < numSize; i++)
    {
        printf("%d", *(num + i));
    }
}
void printIntoFile(uint8_t *result, int resultSize, char notation)
{
    FILE *file;
    int i = 0;
    if ((file = fopen("sonuclar.txt", "w+")) == NULL)
    {
        printf("sonuclar.txt olusturulamadi.");
    }
    else
    {
        if (notation == '-')
        {
            fprintf(file, "%c", notation);
        }
        while (i != resultSize)
        {
            //fwrite((result + i), sizeof(uint8_t), 1, file);
            fprintf(file, "%u", *(result + i));
            i++;
        }
    }
    fclose(file);
}
void readResult()
{
    FILE *file;
    int i = 0;
    char num;
    if ((file = fopen("sonuclar.txt", "r")) == NULL)
    {
        printf("sonuclar.txt olusturulamadi.");
    }
    else
    {
        while (!(feof(file)))
        {
            num = fgetc(file);
            printf("%c", num);
        }
    }
    fclose(file);
}
