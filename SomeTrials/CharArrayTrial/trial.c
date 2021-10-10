#include <stdio.h>

int main()
{

    char array[50];
    printf("enter : ");
    scanf("%s", array);

    int i;
    for (i = 0; i < 50; i++)
    {
        if (array[i] == '\0')
        {
            break;
        }
        printf("%c", array[i]);
    }
    printf("\n");
    return 0;
}