#include <stdio.h>
#include <math.h>

#define EULER 2.7182f
#define PI 3.14159f
#define GAUSS(x) (pow(EULER, -((x) * (x)) * 0.5f) / sqrt(2.0f * PI))
#define DX 0.001f

float SIMPSON_CDF(float x1) {
    float sum = 0.0f;
	float x;
	
    for (x = -3.0f; x < x1; x += DX)
	{
    	sum += (DX / 6.0f) * (GAUSS(x) + 4.0f * GAUSS((2.0f * x + DX) * 0.5f) + GAUSS(x + DX));
	}
        
    return sum;
}

float MIDPOINT_CDF(float x1) {
    float sum = 0.0f;
	float x;
	
    for (x = -3.0f; x < x1; x += DX)
	{
    	sum += GAUSS((2.0f * x + DX) * 0.5f) * DX;
	}
      
    return sum;
}

float TRAPEZOID_CDF(float x1) {
    float sum = 0.0f;
	float x;
	
    for (x = -3.0f; x < x1; x += DX)
	{
    	sum += (DX / 2.0f) * (GAUSS(x) + GAUSS(x - DX));
	}
        
    return sum;
}

float BENIMKI_CDF(float x1) {
    float sum = 0.0f;
	float x;
	
    for (x = -3.0f; x < x1; x += DX)
	{
    	sum += GAUSS(x) * DX;
	}
        
    return sum;
}

int main() {
    float x = 1.0f;

    printf("(BENIMKI) CDF(%.2f) = %.2f\n", x, BENIMKI_CDF(x));
    printf("(SIMPSON) CDF(%.2f) = %.2f\n", x, SIMPSON_CDF(x));
    printf("(MIDPOINT) CDF(%.2f) = %.2f\n", x, MIDPOINT_CDF(x));
    printf("(TRAPEZOID) CDF(%.2f) = %.2f\n", x, TRAPEZOID_CDF(x));
}
