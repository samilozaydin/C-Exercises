#include <stdio.h>
#include <stdlib.h>

int *dosyaKarakterFrekans(char *dosyaYolu);

int main(int argc, char *argv[])
{

    int *dizi;
    int i;
    if (argc < 2)
    {
        printf("eksik arguman");
    }
    else if (argc == 2)
    {
        dizi = dosyaKarakterFrekans(argv[1]);
        for (i = 0; i < 26; i++)
        {
            printf("%c + %d \n", i + 'a', *(dizi + i));
        }
    }
    return 0;
}

int *dosyaKarakterFrekans(char *dosyaYolu)
{
    FILE *dosya;
    char c;
    int *frekans = (int *)calloc(26, sizeof(int));

    dosya = fopen(dosyaYolu, "r");
    if (dosya == NULL)
    {
        printf("dosya acilamadi");
        exit(1);
    }
    while (!(feof(dosya)))
    {
        c = getc(dosya);
        int sayi = ((int)c) - 97;
        (*(frekans + sayi))++;
    }
    fclose(dosya);
    return frekans;
}