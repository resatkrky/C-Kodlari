// #330103 #Oğuzhan Akkaya #oguzhanakkayaaa@gmail.com   #Dosyalama İşlemleri
// #359142 #     #      #Struct Kullanımı


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct takim{

char takimismi[20];
int oynadigimac;
int galibiyetsayisi;
int maglubiyetsayisi;
int beraberliksayisi;
int attigigol;
int yedigigol;
int puan;
int averaj;
};
struct sonuc{

char ev[1];
int ev_at;
char dep[1];
int dep_at;


};

struct ayarlar{
int takimsayisi;
int galibiyetpuani;
int beraberlikpuani;
int maglubiyetpuani;

}t;
struct sonuc a[1];

void degerlerisifirlama(struct takim b[])
{
    for(int i=0;i<10;i++)
    {
        b[i].oynadigimac=0;
        b[i].galibiyetsayisi=0;
        b[i].maglubiyetsayisi=0;
        b[i].beraberliksayisi=0;
        b[i].attigigol=0;
        b[i].yedigigol=0;
        b[i].puan=0;
        b[i].averaj=0;
    }


}

void puantablosuyazdirma(struct takim c[])
{
    int j;

    printf( " Takim\t\tO\tG\tM\tB\tAG\tYG\tA\tP\n");

    for(j=0;j<t.takimsayisi;j++){


  printf( "%s\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",c[j].takimismi,c[j].oynadigimac,c[j].galibiyetsayisi,c[j].maglubiyetsayisi,c[j].beraberliksayisi,c[j].attigigol,c[j].yedigigol,c[j].averaj,c[j].puan);


    }


}
void ayarlar()
{
    FILE *dosya2;

    if((dosya2=fopen("ayarlar.txt","r"))== NULL)
    {
        printf("\n\nDosya acilamadi\n\n\n");
    }
    else
    {

            fscanf(dosya2,"%d%d%d%d",&t.takimsayisi,&t.galibiyetpuani,&t.beraberlikpuani,&t.maglubiyetpuani);
    }
}
void hesaplama(struct takim d[])
{

    int secimci2;

   printf("Ayarlar.txt dosyasina gore puanlandirmayi hesaplamak icin 1 i\n");
   printf("Normale puanlandirmaya gore hesaplamak icin 2 ye basiniz\n ");
   scanf("%d",&secimci2);

   int galibiyetpuani,maglubiyetpuani,beraberlikpuani;

   if(secimci2=1)
   {

     for(int k=0;k<t.takimsayisi;k++)
    {
        d[k].averaj=d[k].attigigol-d[k].yedigigol;
        d[k].puan=t.galibiyetpuani*d[k].galibiyetsayisi + t.beraberlikpuani*d[k].beraberliksayisi - t.maglubiyetpuani*d[k].maglubiyetsayisi;
    }


    }


   else if(secimci2=2)
   {

    for(int k=0;k<t.takimsayisi;k++)
    {
        d[k].averaj=d[k].attigigol-d[k].yedigigol;
        d[k].puan=2*d[k].galibiyetsayisi + d[k].beraberliksayisi - d[k].maglubiyetsayisi;
    }

   }
   else
   {
       printf("Hatalý giriþ yaptýnýz");
   }


}






void dosyadan_musabakalar(struct takim e[])
{



FILE *dosya1;
    if((dosya1=fopen("maclar.txt","r"))== NULL)
    {
        printf("\n\nDosya acilamadi\n\n\n");
    }
    else
    {
        while(!feof(dosya1))
        {


         fscanf(dosya1,"%s %d %s %d",a[0].ev,&a[0].ev_at,a[0].dep,&a[0].dep_at);


      printf("\n\nDosyadan maclar basariyla alindi\n\n");


int c=0,b=0;

switch(a[0].ev[0]){

  case 'A':
  c=0;
  break;

  case 'B':
  c=1;
  break;

   case 'C':
  c=2;
  break;

   case 'D':
  c=3;
  break;

   case 'E':
  c=4;
  break;

   case 'F':
  c=5;
  break;

   case 'G':
  c=6;
  break;

   case 'H':
  c=7;
  break;

   case 'I':
  c=8;
  break;

   case 'J':
  c=9;
  break;

}

switch(a[0].dep[0]){

  case 'A':
  b=0;
  break;

  case 'B':
  b=1;
  break;

   case 'C':
  b=2;
  break;

   case 'D':
   b=3;
  break;

   case 'E':
  b=4;
  break;

   case 'F':
  b=5;
  break;

   case 'G':
  b=6;
  break;

   case 'H':
  b=7;
  break;

   case 'I':
  b=8;
  break;

   case 'J':
  b=9;
  break;

}


   if(a[0].ev_at > a[0].dep_at)
   {
       e[c].galibiyetsayisi=e[c].galibiyetsayisi +1;
       e[b].maglubiyetsayisi=e[b].maglubiyetsayisi +1;

   }

 else if(a[0].ev_at < a[0].dep_at)
   {
       e[b].galibiyetsayisi=e[b].galibiyetsayisi +1;
       e[c].maglubiyetsayisi=e[c].maglubiyetsayisi +1;

   }

else
   {
       e[b].beraberliksayisi=e[b].beraberliksayisi +1;
       e[c].beraberliksayisi=e[c].beraberliksayisi +1;
   }

 e[b].oynadigimac+=1;
 e[c].oynadigimac+=1;

 e[b].attigigol+=a[0].dep_at;
 e[c].attigigol+=a[0].ev_at;

 e[b].yedigigol+=a[0].ev_at;
 e[c].yedigigol+=a[0].dep_at;



    }
    }





}

void klavyeden_okuma()
{

    scanf("%s %d %s %d",a[0].ev,&a[0].ev_at,a[0].dep,&a[0].dep_at);

}

void klavyeden_musabakalar(struct takim g[])
{
printf("Mac giriniz \n");
klavyeden_okuma();
printf("%s %d %s %d\n",a[0].ev,a[0].ev_at,a[0].dep,a[0].dep_at);

int c=0,b=0;

if((a[0].ev_at || a[0].dep_at)<0)
{
    printf("Atilan goller 0 dan kucuk olamaz");
}
else
{
switch(a[0].ev[0]){

  case 'A':
  c=0;
  break;

  case 'B':
  c=1;
  break;

   case 'C':
  c=2;
  break;

   case 'D':
  c=3;
  break;

   case 'E':
  c=4;
  break;

   case 'F':
  c=5;
  break;

   case 'G':
  c=6;
  break;

   case 'H':
  c=7;
  break;

   case 'I':
  c=8;
  break;

   case 'J':
  c=9;
  break;

}

switch(a[0].dep[0]){

  case 'A':
  b=0;
  break;

  case 'B':
  b=1;
  break;

   case 'C':
  b=2;
  break;

   case 'D':
   b=3;
  break;

   case 'E':
  b=4;
  break;

   case 'F':
  b=5;
  break;

   case 'G':
  b=6;
  break;

   case 'H':
  b=7;
  break;

   case 'I':
  b=8;
  break;

   case 'J':
  b=9;
  break;

}


   if(a[0].ev_at > a[0].dep_at)
   {
       g[c].galibiyetsayisi=g[c].galibiyetsayisi +1;
       g[b].maglubiyetsayisi=g[b].maglubiyetsayisi +1;

   }

 else if(a[0].ev_at < a[0].dep_at)
   {
       g[b].galibiyetsayisi=g[b].galibiyetsayisi +1;
       g[c].maglubiyetsayisi=g[c].maglubiyetsayisi +1;

   }

else
   {
       g[b].beraberliksayisi=g[b].beraberliksayisi +1;
       g[c].beraberliksayisi=g[c].beraberliksayisi +1;
   }

 g[b].oynadigimac+=1;
 g[c].oynadigimac+=1;

 g[b].attigigol+=a[0].dep_at;
 g[c].attigigol+=a[0].ev_at;

 g[b].yedigigol+=a[0].ev_at;
 g[c].yedigigol+=a[0].dep_at;

}
}
void dosyadantakimalma(struct takim f[])
{
    FILE *dosya;
    if((dosya=fopen("takimlar.txt","r"))== NULL)
    {
        printf("\n\nDosya acilamadi\n\n\n");
    }
    else
    {
            int n=0;
        while(n<t.takimsayisi)
        {
            fscanf(dosya,"%s",f[n].takimismi);
            n++;
        }
      printf("\n\nDosyadan takimlar basariyla alindi\n\n");
    }

}

int main()
{
struct takim a[10];

 int secilensayi,c=0;

      while(c<100)
    {
    printf("Dosyadan Mac girmek icin 1\nKlavyeden Mac girmek icin 2\nPuan tablosunu gormek icin 3\nPuan tablosunu sifirlamak icin 4 e basiniz\n");
   printf("Dosyadan takimlari almak icin 5 e basiniz\nPuan tablosunu hesaplamak icin 6 ya basiniz\nAyarlar.txt den veri almak icin 7 ye basiniz\nProgramdan cikmak icin 8 ye basiniz\n");
    scanf("%d",&secilensayi);
    printf("\n");

   if(secilensayi==1)
    {
       dosyadan_musabakalar(a);
        hesaplama(a);
    }
    if(secilensayi==2)
    {
       klavyeden_musabakalar(a);
       hesaplama(a);

    }
    else if(secilensayi==3)
    {
        puantablosuyazdirma(a);
    }
    else if(secilensayi==4)
    {
        degerlerisifirlama(a);
    }
    else if(secilensayi==5)
    {
       dosyadantakimalma(a);
    }
    else if(secilensayi==6)
    {
        hesaplama(a);
    }
      else if(secilensayi==7)
    {
       ayarlar();
    }
          else if(secilensayi==8)
    {
       exit(0);
    }
    else
    {
        printf("Hatali tuslama yaptiniz\n");
    }
    c++;

    }
    return 0;
}


