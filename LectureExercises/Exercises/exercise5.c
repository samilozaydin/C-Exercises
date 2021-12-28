#include <stdio.h>
#include <stdlib.h>
void listele(FILE *dosya, int sayi);
void ekle(FILE *dosya);
void sil(FILE *dosya);
void update(FILE *dosya);

struct ogrenci
{
    int id;
    char ad[20];
    char soyad[20];
    int not ;
};

int main()
{
    FILE *dosya;
    dosya = fopen("exercise5.txt", "r+");
    /* int i;
    struct ogrenci blank = {0, "", "", 0};
    for (i = 0; i < 100; i++)
    {
        fwrite(&blank, sizeof(struct ogrenci), 1, dosya);
    }*/

    //ekle(dosya);
    ekle(dosya);
    listele(dosya, 0);
    /* printf("\n");
    update(dosya);
    listele(dosya, 0);
    printf("\n");
    sil(dosya);
    listele(dosya, 0);
    printf("\n");
    fclose(dosya);*/
}
void listele(FILE *dosya, int sayi)
{
    rewind(dosya);
    struct ogrenci siradan = {0, "", "", 0};
    while (!(feof(dosya)))
    {
        fread(&siradan, sizeof(struct ogrenci), 1, dosya);
        if (siradan.not >= sayi && siradan.id != 0)
        {
            printf("ad:%s,soyad:%s,id:%d,not=%d\n", siradan.ad, siradan.soyad, siradan.id, siradan.not );
        }
    }
}
void ekle(FILE *dosya)
{
    rewind(dosya);
    struct ogrenci siradan = {0, "", "", 0};
    printf("id giriniz");
    int id;
    scanf("%d", &id);

    fseek(dosya, (id - 1) * sizeof(struct ogrenci), SEEK_SET);
    fread(&siradan, sizeof(struct ogrenci), 1, dosya);
    if (siradan.id == id)
    {
        printf("bu kullanici var");
        return;
    }
    else
    {
        printf("sirasiyla ad,soyad,not giriniz");
        siradan.id = id;
        scanf("%s%s%d", siradan.ad, siradan.soyad, &siradan.not );
        printf("sirasiyla id giriniz: %d %s %s %d\n", siradan.id, siradan.ad, siradan.soyad, siradan.not );

        fseek(dosya, (id - 1) * sizeof(struct ogrenci), SEEK_SET);
        fwrite(&siradan, sizeof(struct ogrenci), 1, dosya);
    }
}
void sil(FILE *dosya)
{
    rewind(dosya);
    struct ogrenci bos, siradan = {0, "", "", 0};
    int id;
    printf("hangi ogrenci silinisn:");
    scanf("%d", &id);

    fseek(dosya, (id - 1) * sizeof(struct ogrenci), SEEK_SET);
    fread(&bos, sizeof(struct ogrenci), 1, dosya);

    if (bos.id == 0)
    {
        printf("bos bu alan");
    }
    else
    {
        fseek(dosya, (id - 1) * sizeof(struct ogrenci), SEEK_SET);
        fwrite(&siradan, sizeof(struct ogrenci), 1, dosya);
    }
}
void update(FILE *dosya)
{
    rewind(dosya);
    struct ogrenci siradan = {0, "", "", 0};
    int id;
    printf("hangi ogrenci update:");
    scanf("%d", &id);

    fseek(dosya, (id - 1) * sizeof(struct ogrenci), SEEK_SET);
    fread(&siradan, sizeof(struct ogrenci), 1, dosya);
    if (siradan.id == 0)
    {
        printf("id 0 mevcut degil");
    }
    else
    {
        fseek(dosya, (id - 1) * sizeof(struct ogrenci), SEEK_SET);

        printf("sirasiyla ad,soyad,not giriniz");
        siradan.id = id;
        scanf("%s%s%d", siradan.ad, siradan.soyad, &siradan.not );
        fwrite(&siradan, sizeof(struct ogrenci), 1, dosya);
    }
}