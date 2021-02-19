#include <stdio.h>
#include <stdlib.h>

int main()
{
    int islem;
    int sayi1,sayi2;
    int toplam,cikarma,carpma,tambolum;
    float virgul;
    printf("1-Toplama\n2-Cikarma\n3-Carpma\n4-Tam Bolme\n");
    printf("Lutfen yapmak istediginiz islemi seciniz:");
    scanf("%d",&islem);

    switch(islem)
    {

        case 1:
        printf("Toplamak istediginiz 1. sayiyi giriniz:");
        scanf("%d",&sayi1);
        printf("Toplamak istediginiz 2. sayiyi giriniz:");
        scanf("%d",&sayi2);

        toplam=sayi1+sayi2;
        printf("%d",toplam);
        break;

        case 2:
        printf("Cikarmak istediginiz 1. sayiyi giriniz:");
        scanf("%d",&sayi1);
        printf("Cikarmak istediginiz 2. sayiyi giriniz:");
        scanf("%d",&sayi2);

        cikarma=sayi1-sayi2;
        printf("%d",cikarma);
        break;

        case 3:
        printf("Carpmak istediginiz 1. sayiyi giriniz:");
        scanf("%d",&sayi1);
        printf("Carpmak istediginiz 2. sayiyi giriniz:");
        scanf("%d",&sayi2);

        carpma=sayi1*sayi2;
        printf("%d",carpma);
        break;

        case 4:
        printf("Tam bolmek istediginiz 1. sayiyi giriniz:");
        scanf("%d",&sayi1);
        printf("Tam bolmek istediginiz 2. sayiyi giriniz:");
        scanf("%d",&sayi2);

        tambolum=sayi1/sayi2;
        printf("%d",tambolum);
        break;




    }


}
