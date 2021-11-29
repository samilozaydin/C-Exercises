#include <stdio.h>

int main()
{

    char *iller[20] = {"Sinop", "Mersin", "Mardin", "Kastamonu"};
    say(iller, 4);
    return 0;
}
void say(char *dizi[], int n)
{
    int i, j;
    int say = 0;
    char *p;
    for (i = 0; i < n; i++)
    {
        p = dizi[i];
        for (; *p != '\0'; p++)
        {
            say++;
        }
        printf("%d\n", say);
    }
}