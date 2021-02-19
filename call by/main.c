#include <stdio.h>
#include <stdlib.h>
/*
void terscevir(int a,int b)
{
    int gecici;

    gecici=a;

    a=b;

    b=gecici;

}


int main()
{
    int x=4,y=5;

    terscevir(x,y);

    printf("x=%d y=%d",x,y);

}
*/

void terscevir(int *a,int *b)
{
    int gecici;

    gecici=*a;

    *a=*b;

    *b=gecici;

}


int main()
{
    int x=4,y=5;

    terscevir(&x,&y);

    printf("x=%d y=%d",x,y);

}

//Pointerlar ile yaptigimiz da x ve y nin degerleri degisti
//Normal yaptigimizda degismedi cunku pointerlar adresten yola cikarak yaptý
