#include <stdio.h>
int strUzun(char *str);
int main()
{

    char *dizi = "yazdirma adina bir cumle";
    printf("uzunluk : %d", strUzun(dizi));
    return 0;
}

int strUzun(char *str)
{
    int i;
    int count = 0;
    for (i = 0; *(str + i) != '\0'; i++)
    {
        count++;
    }
    return count;
}
