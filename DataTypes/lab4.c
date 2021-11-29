#include <stdio.h>

struct Personel
{
    char *ad;
    char *soyad;
    int maas;
    int calismaYil;
    int yas;
};

struct Personel personel(char *ad, char *soyad, int maas, int calismaYil, int yas)
{
    struct Personel personel;
    personel.ad = ad;
}
void printPersonel(struct Personel p)
{
}
void enYuksekMaasPer(struct Personel *per, int n)
{
    int i, max = per[0].maas;
    for (i = 1; i < n; i++)
    {
        if (per[i].maas > max)
        {
        }
    }
}
int main()
{
    struct Personel personeller[10];

    return 0;
}
