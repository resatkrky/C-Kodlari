#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayilar[5]={1,2,3,4,5};

    int *p;

    p=&sayilar[0];
    int i;
    for(i=0;i<5;i++)
    {

         printf("%u\n",p[i]);
    }

}
