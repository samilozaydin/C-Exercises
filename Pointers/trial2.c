#include <stdio.h>
void diziYazdir(char *dizi);

int main()
{

    char *dizi = "yazdirma adina bir cumle";
    diziYazdir(dizi);

    return 0;
}
void diziYazdir(char *dizi)
{
    int i;
    for (i = 0; *(dizi + i) != '\0'; i++)
    {
        printf("%c", *(dizi + i));
    }
}
