#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int dizi[2][2]= {{1,2},{3,4}};
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d ",dizi[i][j]);

        } printf("\n");
    }
    int toplam=0;
    printf("Satirlarin toplami sirasiyla ");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            toplam=toplam+dizi[i][j];

        }printf("%d",toplam);
        toplam=0;
        printf("\n");
    }
    printf("Sutunlarin toplami sirasiyla ");
    for(j=0;j<2;j++){
        for(i=0;i<2;i++){
            toplam=toplam+dizi[i][j];

        }printf("%d",toplam);
        toplam=0;
        printf("\n");
    }
}
