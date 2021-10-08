#include <stdio.h>

int main()
{

    int sayi;
    printf("bir sayi al: ");
    scanf("%d", &sayi);

    if (sayi % 3 == 0 && sayi % 2 == 0)
    {
        printf("sayi 3 ve 2 ile bolunur\n");
    }
    if (sayi % 3 == 0 || sayi % 2 == 0)
        printf("2 veya 3 ile bolunur");
    if (sayi % 3 == 0 ^ sayi % 2 == 0)
    {
        printf("sayi 2 ve 3 ile ayni anda bolunmez");
    }

    return 0;
}