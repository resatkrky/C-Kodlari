#include <stdio.h>
#include <stdlib.h>

int i,j,k,l,m,n;

void ilkmatris(int *arr1[2][2]){
    printf("Lutfen ilk matrisin degerlerini giriniz.\n");
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
}

void ikincimatris(int *arr2[2][2]){
    printf("Lutfen ikinci matrisin degerlerini giriniz.\n");
    int k,l;
    for(k=0;k<2;k++){
        for(l=0;l<2;l++){
            scanf("%d",&arr2[k][l]);
        }
    }
}

void toplammatris(int *arr1[2][2],int *arr2[2][2],int *arr3[2][2]){


    printf("Toplam Matris :\n");
    int m,n;
    for(m=0;m<2;m++){
        for(n=0;n<2;n++){
            *arr3[m][n] = *arr1[i][j] + *arr2[k][l];
            printf("%d ",*arr3[m][n]);
        }
    }printf("\n");
}



int main()
{
    int *dizi1[2][2],*dizi2[2][2],*dizi3[2][2];
    ilkmatris(&dizi1);
    ikincimatris(&dizi2);
    toplammatris(&dizi1,&dizi2,&dizi3);


}
