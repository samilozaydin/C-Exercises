#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *removeCharFromString(char *str);

int main()
{
    char *p = "birseyler";
    p = removeCharFromString(p);
    printf("%s", p);
    free(p);
    return 0;
}
char *removeCharFromString(char *str)
{
    int size = 0;
    int size2 = 1;
    int i;
    char *nStr = (char *)(malloc(sizeof(char) * size2));
    for (i = 0; *(str + i) != '\0'; i++)
    {
        size++;
        if (*(str + i) == 'a' || *(str + i) == 'e' || *(str + i) == 'i' || *(str + i) == 'u' || *(str + i) == 'o' || *(str + i) == 'A' || *(str + i) == 'E' || *(str + i) == 'I' || *(str + i) == 'U' || *(str + i) == 'O')
        {
            continue;
        }
        else
        {
            size2++;
            nStr = realloc(nStr, sizeof(char *) * size2);
            *(nStr + size2 - 2) = *(str + i);
        }
    }
    *(nStr + size2 - 1) = '\0';
    return nStr;
}
