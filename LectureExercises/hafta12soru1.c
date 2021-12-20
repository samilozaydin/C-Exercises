#include <stdio.h>

int main()
{

    FILE *dosya = fopen("ogrenciler.txt", "a+");
    int i;
    int num;
    char adi[20];
    if (dosya == NULL)
    {
        printf("dosya bulunamadi");
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            printf("ad gir:");
            scanf("%s", adi);
            printf("numara gir:");
            scanf("%d", &num);
            fprintf(dosya, "%s\t%5d\n", adi, num);
            printf(" \n");
        }
    }
    printf("adlar ve numalara \n");
    rewind(dosya);
    while (fscanf(dosya, "%s%d", adi, &num) != EOF)
    {
        printf("%s\t%5d\n", adi, num);
    }
    fclose(dosya);
    return 0;
}