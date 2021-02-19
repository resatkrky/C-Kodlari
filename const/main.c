#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int a=5;
    printf("%d\n",a);
    int b=9;
    a = b;
    printf("%d",b);
    return 0;
}
