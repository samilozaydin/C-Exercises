#include <stdio.h>

void yeniKayit(FILE *);
void goster(FILE *);
void guncelle(FILE *);
void kayitSil(FILE *);
void notListele(FILE *);

struct ogrenci
{
    int ogrNo;
    char adi[15];
    char soyadi[15];
    int notu;
};

int main()
{

    FILE *dosya = fopen("ogrenciler2.txt", "r+");
    if (dosya == NULL)
    {
        printf("Dosya acilamadi");
    }

    return 0;
}
void yeniKayıt(FILE *dosya)
{
    int ogrNum;
    struct ogrenci ogr;
    printf("ogreni no giriniz");
    scanf("%d", &ogrNum);
    fseek(dosya, (ogrNum - 1) * sizeof(struct ogrenci), SEEK_SET);
    printf("adi soyadı ve notu giriniz");
    scanf("%s%s%d", ogr.adi, ogr.soyadi, &ogr.notu);
    ogr.ogrNo = ogrNum;
    fwrite(&ogr, sizeof(struct ogrenci), 1, dosya);
}
void goster(FILE *dosya)
{

    struct ogrenci ogr;

    rewind(dosya);
    while (!feof(dosya))
    {
        fread(&ogr, sizeof(struct ogrenci), 1, dosya);
        if (ogr.ogrNo != 0)
        {
            printf("%5d%15s%15s%10d", ogr.ogrNo, ogr.adi, ogr.soyadi, ogr.notu) //BILGILERI GIRMELISIN
        }
    }
}
void kayıtSil(FILE *dosya)
{
}
void notListele(FILE *dosya)
{
}