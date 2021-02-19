#include <stdio.h>
#include <stdlib.h>

struct ogrenci
{
    char isim[50];
    char soyisim[25];
    char bolum[50];
    int no;
    int yas;
};

int main()
{


   struct ogrenci Student1 = {"Resat","Karakaya","Bilgisayar Muhendisligi",348284,20};
   printf("Ogrenci Adi:%s\nOgrenci Soyadi:%s\nOgrencinin Bolumu:%s\nOgrencinin Numarasi:%d\nOgrencinin Yasi:%d\n",Student1.isim,Student1.soyisim,Student1.bolum,Student1.no,Student1.yas);
}
