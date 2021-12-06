#include <stdio.h>
int *enYakinEnUzakBul(int *dizi, int sayi);

int main()
{
    int dizi[] = {49, 17, 48, 82, 87, 71, 31, 34, 14, 29};
    int *olustu = enYakinEnUzakBul(dizi, 28);

    printf("en uzak :%d , en yakin %d", *olustu, *(olustu + 1));
    free(olustu);
    return 0;
}
int *enYakinEnUzakBul(int *dizi, int sayi)
{
    int i;
    int temp = 0;
    int min = 9999999;
    int mintemp = 99999;
    int max = 0;
    int maxtemp = 0;
    for (i = 0; i < 10; i++)
    {
        if ((*(dizi + i) - sayi) < 0)
        {
            temp = (*(dizi + i) - sayi) * (-1);
        }
        else
        {
            temp = (*(dizi + i) - sayi);
        }
        if (temp >= maxtemp)
        {
            max = *(dizi + i);
            maxtemp = temp;
        }
        if (temp <= mintemp)
        {
            min = *(dizi + i);
            mintemp = temp;
        }
    }
    int *olustur = malloc(2 * sizeof(int));
    *olustur = max;
    *(olustur + 1) = min;
    return olustur;
}
