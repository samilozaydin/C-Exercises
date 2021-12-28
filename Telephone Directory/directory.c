#include <stdio.h>
#include <stdlib.h>

struct person
{
    int id;
    char number[20];
    char name[50];
};

int main()
{
}

void addPerson(FILE *dosya)
{
    rewind(dosya);
    int id;
    struct person temporary = {0, "", ""};

    printf("Enter an id:");
    scanf("%d", &id);

    fseek(dosya, sizeof(struct person) * (id - 1), SEEK_SET);
    fread(&temporary, sizeof(struct person), 1, dosya);

    if (temporary.id == id)
    {
        printf("This slot is not empty");
    }
    else
    {
        printf("Enter name/surname:");
        scanf("%s", &temporary.name);
        printf("Enter phone number:");
        scanf("%s", &temporary.number);
        temporary.id = id;

        fseek(dosya, sizeof(struct person) * (id - 1), SEEK_SET);
        fwrite(&temporary, sizeof(struct person), 1, dosya);
    }
}