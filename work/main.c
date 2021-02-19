#include <stdio.h>
#include <stdlib.h>

void degistir(int *x,int *y){

    int gecici;
    gecici=*x;
    *x=*y;
    *y=gecici;

    printf("%d %d \n",*x,*y);



}

int main()
{
    int a =5 , b= 10;

    degistir(&a,&b);

    printf("%d %d ",a,b);
}
