#include <stdio.h>
#include <string.h>

int main()
{

    // char s1[] = "qala";
    char s2[5] = "zala";
    //char s3[4] = "sala";
    //char *s4 = "bala";

    int i;
    int a = 0;
    for (i = 0; s2[i] != '\0'; i++)
    {
        printf("zz %c\n", s2[i]);

        a++;
    }
    if (s2[4] == '\0')
        printf("%cyav\n", s2[4]);
    printf("%d", a);
    return 0;
}