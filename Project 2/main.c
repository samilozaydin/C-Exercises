#include <stdio.h>
#include <stdint.h>
#include "islemler.h"
#include <stdlib.h>
void menu(char *islem);

int main()
{

    char *islem;
    char operasyon = '+';
    menu(islem);

    uint8_t *num1 = NULL;
    int num1Size = 0;

    uint8_t *num2 = NULL;
    int num2Size = 0;

    uint8_t *sum = NULL;
    uint8_t *substract = NULL;
    while (1)
    {
        switch (*islem)
        {
        case '1':
            printf("\n***********************\n");
            printf("1.sayinin dosya adini giriniz:\n");
            printf("2.sayinin dosya adini giriniz:\n");
            char num1c[] = "sayideneme.txt";
            num1 = readFile(num1c, &num1Size);

            char num2c[] = "sayideneme2.txt";
            num2 = readFile(num2c, &num2Size);
            printf("Dosyalar basariyla okundu.\n");
            break;
        case '2':
            printf("\n***********************\n\n");
            printf("1.sayi= ");
            displayNumber(num1, num1Size);
            printf("\n\n****************************************************************\n\n");
            printf("2.sayi= ");
            displayNumber(num2, num2Size);
            printf("\n\n***********************\n");
            printf("Sayilar basariyla okundu");

            break;
        case '+':
            operasyon = '+';
            printf("Operansyon toplama islemi olarak degistirildi.\n");
            break;
        case '-':
            operasyon = '-';
            printf("Operansyon cikarma islemi olarak degistirildi.\n");

            break;
        case '4':
            if (operasyon == '+')
            {
                int sumSize = 0;
                char notation = '+';
                sum = sumFile(num1, num2, num1Size, num2Size, &sumSize);
                printIntoFile(sum, sumSize, notation);

                printf("Toplama islemi sonucu : ");
                readResult();
            }
            else if (operasyon == '-')
            {
                int substractSize = 0;
                char notation = '+';
                substract = substractFile(num1, num2, num1Size, num2Size, &substractSize, &notation);
                uint8_t *nonZeroSubstract = removeZeros(substract, &substractSize);
                printf("Cikarma islemi sonucu : ");
                printIntoFile(nonZeroSubstract, substractSize, notation);

                readResult();
            }
            break;
        case '5':
            printf("Programdan cikiliyor\n");
            break;
        default:
            printf("Girilen ifadeye ait bir islem bulunmamakta\n");
            break;
        }
        if (*islem == '5')
        {
            break;
        }
        printf("\n***********************\n");

        printf("Islem giriniz: ");
        scanf("%s", islem);
    }

    /* uint8_t *num1 = NULL;
    int num1Size = 0;
    char num1c[] = "sayi1.txt";
    num1 = readFile(num1c, &num1Size);

    uint8_t *num2 = NULL;
    int num2Size = 0;
    char num2c[] = "sayi2.txt";
    num2 = readFile(num2c, &num2Size);

    int sumSize = 0;
    uint8_t *sum = sumFile(num1, num2, num1Size, num2Size, &sumSize);
    printf("Toplama islemi sonucu : ");
    displayNumber(sum, sumSize);
    printf("\n***********************\n");

    int substractSize = 0;
    char notation;
    uint8_t *substract = substractFile(num1, num2, num1Size, num2Size, &substractSize, &notation);
    printf("\n***********************\n");
    printf("Cikarma islemi raw sonucu : ");

    displayNumber(substract, substractSize);
    printf("\n***********************\n");

    uint8_t *nonZeroSubstract = removeZeros(substract, &substractSize);
    printf("Cikarma islemi sonucu : ");
    if (notation == '-')
    {
        printf("%c", notation);
    }
    displayNumber(nonZeroSubstract, substractSize);
    printf("\n***********************\n");*/

    free(substract);
    free(sum);
    free(num2);
    free(num1);
    return 0;
}
void menu(char *islem)
{
    printf("----------Buyuk sayilarla matematiksel islemler ----------\n");
    printf("(1-) Dosyadan sayi oku: \n");
    printf("(2-) Okunan sayilari ekrana yaz: \n");
    printf("(3-) Islemi belirle (+) veya (-): \n");
    printf("(4-) Sonucu ekrana yazdir: \n");
    printf("(5-) Programdan ayril: \n");
    printf("Isleminiz: ");
    scanf("%s", islem);
}