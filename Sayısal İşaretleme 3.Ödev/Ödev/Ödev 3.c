#include <stdio.h>
#include <stdlib.h>

#define euler 2.7182f
#define pi 3.14159f
#define gauss(x) (pow(euler, - ((x) * (x)) * 0.5f) / sqrt(2.0f * pi))

float midpoint(float sapma_standart)
{
    float ortalama = 0.0f;
	float dx = 0.001f;
    float i = -3.0f;

    while( i < sapma_standart )
	{
        ortalama += gauss((2.0f * i + dx) * 0.5f) * dx;
    	i += dx;
	}
    return ortalama;
}

int main() {
    float standartSapma = 1.0f;

    printf("Midpoint icin Standart Sapma = %.1f oldugunda CDF = %f", standartSapma , midpoint(standartSapma) );
}
