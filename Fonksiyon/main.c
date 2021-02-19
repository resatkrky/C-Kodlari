#include <stdio.h>
#include <stdlib.h>

int faktoriyel(int a)
{
  int deger=1;
  for(;a>0;a--){

    deger*=a;


  }

    return(deger);

}

int main()
{
    int sayi;

    printf("Lutfen sayi giriniz:");scanf("%d",&sayi);

    printf("%d",faktoriyel(sayi));


}




