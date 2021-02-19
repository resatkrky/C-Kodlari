#include <stdio.h>
#include <stdlib.h>

//Resat Karakaya-348284-Grubu:B-1.Ogretim

//Tanimlayacagim bazi sayilar buyuk bazi sayilar kucuk oldugu icin buyuk sayýlara long long int kucuk sayilara int kullandim.
//d1,d2,d3,d4,d5,d6,d7,d8,d9,d10 kucuk sayi olacagi icin int kullandim.
//d1_bulma,d1_ekleyen,sayi,girilen_sayi,tum_sayi,toplam,yeni_sayi buyuk sayi oldugu icin long long int kullandim.
long long int d1_bulma();
long long int d1_ekleyen(long long int param1,int param2);
long long int sayi;
int d1;

int main(int argc,char *argv[])
{
   int d1;
   long long int girilen_sayi;
   long long int tum_sayi;

   sayi=atoi(argv[1]);
   //char ile verilen sayiyi integer donusturmek icin atoi kullandým.

   girilen_sayi=d1_bulma();
   printf("%lld\n",girilen_sayi);
   //d1_bulma fonksiyonunu ekranda okutabilmek icin ilk once girilen_sayi degiskeni tanimladim.
   //Daha sonra bu degiskeni main icine printf ile yazdim.

   tum_sayi=d1_ekleyen(sayi,d1);
   printf("\n%lld\n",tum_sayi);
   //d1 eklendikten sonra oluþan yeni sayiyi ekranda okutabilmek icin tum_sayi degiskeni tanimladim.
   //Bu degiskeni d1_ekleyen fonksiyonuna esitledim.Fonskiyonun icinde sayiyi ve d1'i cagirdim.

}
long long int d1_bulma()
{
    int d2,d3,d4,d5,d6,d7,d8,d9,d10;

    long long int toplam;
    d2=sayi%10;
    d3=(sayi/10)%10;
    d4=(sayi/100)%10;
    d5=(sayi/1000)%10;
    d6=(sayi/10000)%10;
    d7=(sayi/100000)%10;
    d8=(sayi/1000000)%10;
    d9=(sayi/10000000)%10;
    d10=(sayi/100000000)%10;
    toplam=(2*d2)+(3*d3)+(4*d4)+(5*d5)+(6*d6)+(7*d7)+(8*d8)+(9*d9)+(10*d10);
    //Girilen sayinin bas.degerlerini bulabilmek icin d2,d3 vb degiskenler tanimladim ve sayi uzerinde bazi islemler yaparak elde ettim
    //Daha sonra bu sayilarin toplamini toplam degiskenine esitledim.

    if(toplam%11==0){

        d1=0;//Sayi 11'e tam bolundugunde d1'in 0 cýkmasýný if kosuluyla belirttim.(Yoksa d1'i 11 buluyordu.)
    }
    else{

    d1=11-(toplam%11);//d1'i 0'dan farkli bulabilmek icin else kosuluyla bir denklem yazarak belirttim.
    }
    return d1;//main icinde d1'i bulabilmesi icin return kullandým.
}
long long int d1_ekleyen(long long int param1,int param2)
{
    long long int yeni_sayi;
    yeni_sayi=sayi*10+d1;
    //d1 eklendikten sonra olusan sayiyi yeni_sayi degiskenine tanimladim.
    //Daha sonra bir denklem kullanarak yeni_sayiyi bulmus oldum.
    return yeni_sayi;//main icinde yeni_sayi'yi bulabilmesi icin return kullandým.
}
