#include <stdio.h>

extern int degisken;

void function();
void function2();

int main()
{

    printf("degisken =%d\n", degisken);
    function();
    printf("degisken =%d\n", degisken);
    function2();
    printf("degisken =%d\n", degisken);

    return 0;
}