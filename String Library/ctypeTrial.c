#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main()
{

    char kelime[20] = "5653.0 fafsaf";
    char *point;
    int sayi = atoi(kelime);
    printf("sayi karsiligi: %d\n", sayi);

    double sayi2 = strtod(kelime, &point);
    printf("yazdir %s olarak: %.2f and %s\n", kelime, sayi2, point);

    char olustur[50];
    float sayi3;
    sscanf(kelime, "%f %s", &sayi3, olustur);
    printf("olustur : %f %s", sayi3, olustur);

    return 0;
}