#include <stdio.h>
#include <stdlib.h>

struct deger{
    int taban;
    int us;

};

int power(int base,int exp)
{
    int i,temp=base;
    for(i=1;i<exp;i++)
    {
        base *= temp;
    }
    return base;
}

int main()
{
      struct deger islem;
      printf("taban ve us degeri:");
      scanf("%d %d",&islem.taban,&islem.us);
      printf("Taban degeri=%d\nUs degeri=%d\n",islem.taban,islem.us);

      printf("%d sayisinin %d. kuvveti = %d\n", islem.taban, islem.us, power(islem.taban,islem.us));


}
