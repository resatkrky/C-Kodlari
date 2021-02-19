#include <stdio.h>
#include <stdlib.h>

struct ogrenci{
    char ad[50];
    char soyad[50];
    int yas;
};

struct ogrenci bilgial{
    struct ogrenci student;
    printf("Ogrenci Ad Soyad Yas Bilgilerini Giriniz:");
    scanf("%s %s %d",&student.ad,&student.soyad,&student.yas);
    return student;
};

void bastir(struct ogrenci a){
    printf("Ogrenci Ad Soyad Yas:%s %s %d",a.ad,a.soyad,a.yas);
}

int main()
{
        struct ogrenci ogrenci1=bilgial();
        bastir(ogrenci1);

}
