#include <stdio.h>
void ucluDegis(int *a, int *b, int *c);
int main()
{
    int a = 1, b = 2, c = 3;
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    //    int *pa =&a,*pb= &b,*pc= &c;
    ucluDegis(&a, &b, &c);
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    ucluDegis(&a, &b, &c);
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    ucluDegis(&a, &b, &c);
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}
void ucluDegis(int *a, int *b, int *c)
{
    int hold = *a;
    *a = *b;
    *b = *c;
    *c = hold;
}
