#include <stdio.h>

struct person
{
    char *name;
    char *surname;
    int age;
    int salary;
};
typedef struct
{
    char *family;
    int age;
} animal;

int main()
{

    struct person ahmet;
    ahmet.age = 30;
    ahmet.salary = 10000;
    ahmet.name = "Selim";
    printf("Surname gir: ");
    scanf("%s", &ahmet.surname);

    animal first;
    first.age = 10;
    first.family = "Duck";

    printf("%s and %s", first.family, ahmet.name);
    return 0;
}