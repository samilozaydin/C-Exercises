#include <stdio.h>

struct animal
{
    int age;
    int ya;

} kanat, gaga;

int main()
{

    kanat.age = 1;
    kanat.ya = 4;
    struct animal x;
    x.age = 2;
    x.ya = 3;

    gaga.age = 2;
    printf("%d", x.age);
    return 0;
}