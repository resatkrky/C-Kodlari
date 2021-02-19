#include <stdio.h>
#include <stdlib.h>


int toplama(int sayi1,int sayi2)
{
    int toplama=0;
    toplama=sayi1+sayi2;
    return toplama;
}
int carpma(int sayi1,int sayi2)
{
    int carpma=0;
    carpma=sayi1*sayi2;
    return carpma;
}
int cikarma(int sayi1,int sayi2)
{
    int cikarma;
    cikarma=sayi1-sayi2;
    return cikarma;
}
int bolme(int sayi1,int sayi2)
{
    int bolme;
    bolme=sayi1/sayi2;
    return bolme;
}
int mod(int sayi1,int sayi2)
{
    int mod;
    mod=sayi1%sayi2;
    return mod;
}

int main()
{

   printf("1-Toplama \n2-Carpma \n3-Cikarma \n4-Bolme \n5-Mod \nYapmak istediginiz islem:");
   int secim;
   scanf("%d",&secim);
   int a,b;
   switch(secim)
   {
       case 1:
          scanf("%d%d",&a,&b);
          printf("%d",toplama(a,b));
          break;
       case 2:
          scanf("%d%d",&a,&b);
          printf("%d",carpma(a,b));
          break;
       case 3:
          scanf("%d%d",&a,&b);
            printf("%d",cikarma(a,b));
          break;
       case 4:
          scanf("%d%d",&a,&b);
          printf("%d",bolme(a,b));
          break;
       case 5:
          scanf("%d%d",&a,&b);
          printf("%d",mod(a,b));
          break;
       default:
        printf("girilen deger yanlis");
}
    return 0;
}
