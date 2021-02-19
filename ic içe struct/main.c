#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct aile{
    char baba[20];
    char anne[20];
    char abi[20];
    char abla[20];
    char kardes[20];
};
struct ogrenci{
    char ad[20];
    char soyad[20];
    char bolum[20];
    int no;
    int yas;
    struct aile aile1;
};
int main()
{
    struct ogrenci ogrenci1;
    strcpy(ogrenci1.ad,"Resat");
    strcpy(ogrenci1.soyad,"Karakaya");
    strcpy(ogrenci1.bolum,"Bilgisayar Muhendisligi");
    ogrenci1.no = 348284;
    ogrenci1.yas = 20;
    strcpy(ogrenci1.aile1.baba,"Ibrahim");
    strcpy(ogrenci1.aile1.anne,"Fatma");
    strcpy(ogrenci1.aile1.abi,"Mehmet");
    strcpy(ogrenci1.aile1.abla,"Gamze");
    strcpy(ogrenci1.aile1.kardes,"Melih");
    printf("Ad:%s\nSoyad:%s\nBolum:%s\nNo:%d\nYas:%d\nBaba:%s\nAnne:%s\nAbi:%s\nAbla:%s\nKardes:%s",ogrenci1.ad,ogrenci1.soyad,ogrenci1.bolum,ogrenci1.no,ogrenci1.yas,ogrenci1.aile1.baba,ogrenci1.aile1.anne,ogrenci1.aile1.abi,ogrenci1.aile1.abla,ogrenci1.aile1.kardes);
}
