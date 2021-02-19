#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,j;
   for(i=0;i<15;i++)
   {
       for(j=0;j<10;j++)
       {
           printf("%d + %d =%d\n",i,j,i+j);
       }
   }
}
