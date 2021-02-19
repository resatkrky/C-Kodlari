#include <stdio.h>
#include <stdlib.h>

int toplama(int s1,int s2)
{
    return(s1+s2);
}
int cikarma(int s1,int s2)
{
    return(s1-s2);
}
int carpma(int s1,int s2)
{
    return(s1*s2);
}
int bolme(int s1,int s2)
{
    return(s1/s2);
}


int main()
{
    int islem;
    int sayi1,sayi2;
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


        printf("%d",toplama(sayi1,sayi2));
        break;
        case 2:
        printf("Cikarmak istediginiz 1. sayiyi giriniz:");
        scanf("%d",&sayi1);
        printf("Cikarmak istediginiz 2. sayiyi giriniz:");
        scanf("%d",&sayi2);


        printf("%d",cikarma(sayi1,sayi2));
        break;
        case 3:
        printf("Carpmak istediginiz 1. sayiyi giriniz:");
        scanf("%d",&sayi1);
        printf("Carpmak istediginiz 2. sayiyi giriniz:");
        scanf("%d",&sayi2);


        printf("%d",carpma(sayi1,sayi2));
        break;
        case 4:
        printf("Bolmek istediginiz 1. sayiyi giriniz:");
        scanf("%d",&sayi1);
        printf("Bolmek istediginiz 2. sayiyi giriniz:");
        scanf("%d",&sayi2);


        printf("%d",bolme(sayi1,sayi2));
        break;

    }


}
