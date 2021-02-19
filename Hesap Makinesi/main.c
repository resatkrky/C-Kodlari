#include <stdio.h>
#include <stdlib.h>
int cikarma(int value1,int value2){
    return(value1-value2);
}
float bolme(float value3,float value4){
    return(value3/value4);
}
int mod(int value5,int value6){
    return(value5%value6);
}
int main()
{
    int islem,i,adet,s1,s2;
    int sayi[50];
    int toplam=0,carpma=1;
    printf("1-Toplama\n2-Cikarma\n3-Carpma\n4-Bolme\n5-Mod Alma\n");
    printf("Lutfen yapilacak islemi seciniz:");
    scanf("%d",&islem);
        if(islem > 0 && islem <= 5){
        switch(islem){
        case 1:
            printf("Islem yapilacak sayi adedini giriniz:");
            scanf("%d",&adet);
            printf("Lutfen toplanacak sayilari giriniz:");
            for(i=0;i < adet;i++){
                scanf("%d",&sayi[i]);
            }
            for(i=0;i < adet;i++){
                toplam=toplam+sayi[i];

            } printf("%d",toplam);
            break;
        case 2:
            printf("Lutfen cikarilacak 2 sayiyi giriniz:");
            scanf("%d%d",&s1,&s2);
            printf("%d",cikarma(s1,s2));
          break;
        case 3:
            printf("Islem yapilacak sayi adedini giriniz:");
            scanf("%d",&adet);
            printf("Lutfen carpilacak sayilari giriniz:");
            for(i=0;i < adet;i++){
                scanf("%d",&sayi[i]);
            }
            for(i=0;i < adet;i++){
                carpma=carpma*sayi[i];

            } printf("%d\n",carpma);
           break;
        case 4:
            printf("Lutfen ilk once bolunecek sayiyi daha sonra bolen sayiyi ondalik olarak giriniz:");
            scanf("%d%d",&s1,&s2);
            printf("%f",bolme(s1,s2));
           break;
        case 5:
            printf("Lutfen modu alinacak sayilari giriniz.");
            scanf("%d%d",&s1,&s2);
            printf("%d",mod(s1,s2));
            break;
        }
        }
        else{
            printf("Islem yapabilmek icin 1 ile 5 arasinda islem seciniz.");
        }
        return 0;
}



