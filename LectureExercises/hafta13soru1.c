#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int i;
    char *ters;
    for (i = 1; i < argc; i++)
    {
        ters = strrev(argv[i]);
        printf("%s ", ters);
    }

    return 0;
}