#include <stdio.h>

enum dogruMu
{
    dogru,
    yanlis
};
struct insan
{
    char *adSoyad;
    int yas;
    int maas;
    enum dogruMu dogrulandi;
};

int main()
{
    struct insan kisi1;

    kisi1.adSoyad = "hello";
    kisi1.dogrulandi = dogru;
    printf("kisi ad: %s\n", kisi1.adSoyad);
    printf("kisi dogrulandi %d", kisi1.dogrulandi);

    return 0;
}