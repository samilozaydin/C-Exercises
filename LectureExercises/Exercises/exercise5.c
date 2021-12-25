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
    ekle(dosya);
    fclose(dosya);
}
void listele(FILE *dosya, int sayi)
{
    rewind(dosya);
    struct ogrenci siradan = {0, "", "", 0};
    while (!(feof(dosya)))
    {
        fread(&siradan, sizeof(struct ogrenci), 1, dosya);
        if (siradan.not >= sayi)
        {
            printf("ad:%s,soyad:%s,id:%d,not=%d\n", siradan.ad, siradan.soyad, siradan.id, siradan.not );
        }
    }
}
void ekle(FILE *dosya)
{
    rewind(dosya);
    struct ogrenci siradan = {0, "", "", 0};
    printf("sirasiyla id giriniz");
    int id;
    scanf("%d", &id);

    fseek(dosya, id - 1, SEEK_SET);
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
        printf("sirasiyla id giriniz%d %s %s %d", siradan.id, siradan.ad, siradan.soyad, siradan.not );

        fseek(dosya, id - 1, SEEK_SET);
        fwrite(&siradan, sizeof(struct ogrenci), 1, dosya);
    }
}
void sil(FILE *dosya)
{
    rewind(dosya);
    struct ogrenci siradan = {0, "", "", 0};
    int id;
    printf("hangi ogrenci silinisn:");
    scanf("%d", &id);

    fseek(dosya, id - 1, SEEK_SET);
    fread(&siradan, sizeof(struct ogrenci), 1, dosya);

    if (siradan.id == 0)
    {
        printf("bos bu alan");
    }
    else
    {
        fseek(dosya, id - 1, SEEK_SET);
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

    fseek(dosya, id - 1, SEEK_SET);
    fread(&siradan, sizeof(struct ogrenci), 1, dosya);
    if (siradan.id == 0)
    {
        printf("id 0 mevcut degil");
    }
    else
    {
        fseek(dosya, id - 1, SEEK_SET);

        char ad[20];
        char soyad[20];
        int not ;

        printf("sirasiyla ad,soyad,not giriniz");
        siradan.id = id;
        scanf("%s%s%d", siradan.ad, siradan.soyad, &siradan.not );
        fwrite(&siradan, sizeof(struct ogrenci), 1, dosya);
    }
}