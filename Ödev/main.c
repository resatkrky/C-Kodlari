#include <stdio.h>
#include <stdlib.h>

int main()
{

   int birinci_kenar;
   int ikinci_kenar;
   int ucuncu_kenar;

   printf("Lutfen birincikenar Giriniz.");  scanf("%d",&birinci_kenar);
   printf("Lutfen ikincikenar Giriniz.");   scanf("%d",&ikinci_kenar);
   printf("Lutfen ucuncukenar Giriniz.");   scanf("%d",&ucuncu_kenar);


    if(birinci_kenar==ikinci_kenar)
        printf("Ikizkenar Ucgen");
    else if(birinci_kenar==ucuncu_kenar)
        printf("Ikizkenar Ucgen");
    else if(ikinci_kenar==ucuncu_kenar)
        printf("Ikizkenar Ucgen");
    else if(birinci_kenar==ikinci_kenar;birinci_kenar==ucuncu_kenar;ikinci_kenar==ucuncu_kenar)
        printf("Eskenar Ucgen");
    else
        printf("Cesitkenar Ucgen");


   }








