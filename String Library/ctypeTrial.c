#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    /*  char hex[] = "0xa25e";
    int i;
    for (i = 0; *(hex + i) != '\0'; i++)
    {
        if (isxdigit(*(hex + i)) != 0 || *(hex + i) == 'x')
        {
            printf("%c is a hex char\n", *(hex + i));
        }
        else
        {
            printf("It is not a hex char\n");
        }
    }
*/

    /* char snt1[40] = "sentence first";
    char snt2[] = "different sentence";
    strcat(snt1, snt2);
    strncat(snt1, snt2, 3);
    puts(snt1);*/

    /* char kelime[20] = "5653.0 fafsaf";
    char *point;
    int sayi = atoi(kelime);
    printf("sayi karsiligi: %d\n", sayi);

    double sayi2 = strtod(kelime, &point);
    printf("yazdir %s olarak: %.2f and %s\n", kelime, sayi2, point);

    char olustur[50];
    float sayi3;
    sscanf(kelime, "%f %s", &sayi3, olustur);
    printf("olustur : %f %s", sayi3, olustur);
*/
    int str[3] = {1, 2, 3};
    int str2[3] = {17, 95588, 12};
    char p[] = "helebak";
    printf("%d", strlen(p));
    char p2[13];
    /*  printf("%X\n", str[2]);
    memcpy(str, str2, 12);

    int i;
    for (i = 0; i < 3; i++)
    {
        printf("%d %08X\n", str[i], str[i]);
    }*/
    printf("%X\n", str[0]);
    memset(str, -41, sizeof(int) * 1);
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("%d %08X\n", str[i], str[i]);
    }
    return 0;
}