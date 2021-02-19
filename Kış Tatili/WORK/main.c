#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dizi[2][2];
    int i,j;
    printf("Lutfen Matrisin degerlerini giriniz.");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&dizi[i][j]);
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d ",dizi[i][j]);
        }
        printf("\n");
    }
    printf("Sutunlarin toplam degeri sirasiyla: ");
    int toplam=0;
    for(j=0;j<2;j++){
        for(i=0;i<2;i++){

            toplam+=dizi[i][j];
        }
        printf("%d ",toplam);
        toplam=0;
    }printf("\n");

    printf("Satirlarin toplam degeri sirasiyla: ");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){

            toplam+=dizi[i][j];
        }
        printf("%d ",toplam);
        toplam=0;
    }

}
