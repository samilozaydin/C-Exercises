#include <stdio.h>

enum tur
{
    pop,
    rock,
    klasik,
    rb,
    folk,
};

struct sarki
{
    char sarkiAd;
    char sarkici;
    short yil;
    enum tur sarkiTur;
};
struct sarki takeInfo(char sarkiAd, char Sarkici, short yil, enum tur sarkiTur);
void printSarki(struct sarki user);

int main()
{

    struct sarki user1 = takeInfo('A', 'b', 2000, rock);
    struct sarki user2 = takeInfo('z', 'L', 2000, klasik);
    struct sarki user3 = takeInfo('X', 'w', 2000, folk);

    if (user1.sarkiTur == rock)
    {
        printSarki(user1);
    }
    if (user2.sarkiTur == rock)
    {
        printSarki(user2);
    }
    if (user3.sarkiTur == rock)
    {
        printSarki(user3);
    }
    return 0;
}

struct sarki takeInfo(char sarkiAd, char Sarkici, short yil, enum tur sarkiTur)
{
    struct sarki user1 = {sarkiAd, Sarkici, yil, sarkiTur};
    return user1;
}
void printSarki(struct sarki user)
{
    printf("sarki Ad: %c\n", user.sarkiAd);
    printf("sarkici Ad: %c\n", user.sarkici);
    printf("Yil: %d\n", user.yil);
    printf("tur: %d", user.sarkiTur);
}
