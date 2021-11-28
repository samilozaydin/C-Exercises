#include <stdio.h>

int main()
{

    char hey[20];
    printf("yaz :");
    gets(hey);
    printf("\n");
    printf(hey);
    printf("\n");
    puts(hey);
    for (int i = 0; i < 20; i++)
    {
        printf("%c", hey[i]);
    }
    printf("\n");
    printf("-------------------------\n");
    printf(hey);
    printf("\n");
    puts(hey);

    return 0;
}