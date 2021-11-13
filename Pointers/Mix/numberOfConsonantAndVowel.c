#include <stdio.h>
void numberOfSpell(char *, int *, int *);

int main()
{

    char *arr = "balblacaooyfsfyu";
    int sesli = 0;
    int sessiz = 0;
    int *pSesli = &sesli;
    int *pSessiz = &sessiz;

    numberOfSpell(arr, pSesli, pSessiz);

    printf("Sessiz: %d, sesli: %d", sesli, sessiz);
    return 0;
}

void numberOfSpell(char *str, int *countVowel, int *countConsonant)
{

    while (*str != '\0')
    {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u')
        {
            *(countVowel) += 1;
        }
        else
        {
            *(countConsonant) += 1;
        }
        str++;
    }
}