#include <stdio.h>

extern int variable;
void increment();

int main()
{
    variable = 10;
    increment();

    printf("%d", variable);
    return 0;
}