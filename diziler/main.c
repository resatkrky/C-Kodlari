#include <stdio.h>
#include <stdlib.h>
/*
int %d
string %s ismi komple alýyo
char %c sadece harfi alýyo
float %f
pointer %p
*/

int main()
{
  /*
    int toplam=0;
    int i,sayilar[10];
   for(i=1;i<6;i++)
    {
        printf("%d'inci sayiyi giriniz:",i);scanf("%d",&sayilar[i]);
     toplam += sayilar[i];
      printf("%d\n",toplam);

    }


    int i;
    char isim[8]="Resat";
    for(i=0;i<5;i++)
    {
        printf("%c",isim[i]);
    }

    int i;
    char isim[50];
    printf("Isminizi giriniz:");
    scanf("%s",isim);
    printf("Adiniz:%s",isim);
/*
Kullanýcýdan harf dizisi isterken %s kullanýlýr scanf ile
Eger kendimiz bi islem yapacak isek printf ile %c ile tek tek istenir
*/

    int dizi[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int i,j;


    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",dizi[i][j]);
        }
        printf("\n");
    }


    int toplam=0;
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            toplam=toplam+dizi[i][j];

        }
        printf("%d ",toplam);
        toplam=0;
    }






}
