#include <stdio.h>
#include <stdlib.h>

int determinant(int arr3[2][2]){//sadece 2*2 lik matrisin det i

    int det;
    det=(arr3[0][0]*arr3[1][1])-(arr3[0][1]*arr3[1][0]);

    return det;
}


int main()
{
    int dizi1[2][2],dizi2[2][2],dizi3[2][2];
    printf("Lutfen ilk matrisin degerlerini giriniz.\n");
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&dizi1[i][j]);
        }
    }

    printf("Lutfen ikinci matrisin degerlerini giriniz.\n");
    int k,l;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&dizi2[i][j]);
        }
    }

     printf("Toplam Matris :\n");
    int m,n;
    for(i=0;i<2;i++){
        for(j=0;j<2;j
        ++){
            dizi3[i][j] = dizi1[i][j] + dizi2[i][j];
            printf("%d ",dizi3[i][j]);
        }printf("\n");
    }

    printf("%d\n",determinant(dizi3));

    return 0;
}
