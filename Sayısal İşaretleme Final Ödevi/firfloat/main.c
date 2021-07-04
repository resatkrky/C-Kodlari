#include <stdio.h>
#include <stdint.h>
//////////////////////////////////////////////////////////////
// Filter Code Definitions
//////////////////////////////////////////////////////////////
// Ýþlenebilecek maksimum giriþ sayýsý
// bir iþlev çaðrýsýnda
#define MAX_INPUT_LEN 80
// ele alýnabilecek maksimum filtre uzunluðu
#define MAX_FLT_LEN 63
// tüm girdi örneklerini tutmak için arabellek
#define BUFFER_LEN (MAX_FLT_LEN - 1 + MAX_INPUT_LEN)
// giriþ örneklerini tutacak dizi
#define SAMPLES 80
double insamp[ BUFFER_LEN ];
// FIR init
void firFloatInit( void )
{
    memset( insamp, 0, sizeof( insamp ) );
}
// the FIR filter function
void firFloat( double *coeffs, double *giris, double *cikis,
        int uzunluk, int filterLength )
{
    double acc; // accumulator for MACs
    double *coeffp; // pointer to coefficients
    double *girisp; // pointer to input samples
    int n;
    int k;
    // yeni örnekleri arabelleðin üst ucuna koyun
    memcpy( &insamp[filterLength - 1], giris,
            uzunluk * sizeof(double) );
    // filtreyi her giriþ örneðine uygulayýn
    for ( n = 0; n < uzunluk; n++ ) {
        // calculate output n
        coeffp = coeffs;
        girisp = &insamp[filterLength - 1 + n];
        acc = 0;
        for ( k = 0; k < filterLength; k++ ) {
            acc += (*coeffp++) * (*girisp--);
        }
        cikis[n] = acc;
    }
    // giriþ örneklerini bir dahaki sefere geri kaydýrma
    memmove( &insamp[0], &insamp[uzunluk],
    (filterLength - 1) * sizeof(double) );
}
//////////////////////////////////////////////////////////////
// Test program
//////////////////////////////////////////////////////////////
// 1000 Hz merkezli bant geçiren filtre
// örnekleme hýzý = 8000 Hz
#define FILTER_LEN 63
double coeffs[ FILTER_LEN ] =
{
    -0.0448093, 0.0322875, 0.0181163, 0.0087615, 0.0056797,
    0.0086685, 0.0148049, 0.0187190, 0.0151019, 0.0027594,
    -0.0132676, -0.0232561, -0.0187804, 0.0006382, 0.0250536,
    0.0387214, 0.0299817, 0.0002609, -0.0345546, -0.0525282,
    -0.0395620, 0.0000246, 0.0440998, 0.0651867, 0.0479110,
    0.0000135, -0.0508558, -0.0736313, -0.0529380, -0.0000709,
    0.0540186, 0.0766746, 0.0540186, -0.0000709, -0.0529380,
    -0.0736313, -0.0508558, 0.0000135, 0.0479110, 0.0651867,
    0.0440998, 0.0000246, -0.0395620, -0.0525282, -0.0345546,
    0.0002609, 0.0299817, 0.0387214, 0.0250536, 0.0006382,
    -0.0187804, -0.0232561, -0.0132676, 0.0027594, 0.0151019,
    0.0187190, 0.0148049, 0.0086685, 0.0056797, 0.0087615,
    0.0181163, 0.0322875, -0.0448093
};
void intToFloat( int16_t *giris, double *cikis, int uzunluk )
{
    int i;
    for ( i = 0; i < uzunluk; i++ ) {
        cikis[i] = (double)giris[i];
    }
}
void floatToInt( double *giris, int16_t *cikis, int uzunluk )
{
    int i;
    for ( i = 0; i < uzunluk; i++ ) {
        // yuvarlama sabiti ekle
        giris[i] += 0.5;
        // deðerleri 16 bite baðla
        if ( giris[i] > 32767.0 ) {
            giris[i] = 32767.0;
        } else if ( giris[i] < -32768.0 ) {
            giris[i] = -32768.0;
        }
        //dönüþtür
        cikis[i] = (int16_t)giris[i];
    }
}
// döngü baþýna okunacak örnek sayýsý

int main( void )
{
    int boyut;
    int16_t giris[SAMPLES];
    int16_t cikis[SAMPLES];
    double floatGiris[SAMPLES];
    double floatCikis[SAMPLES];
    FILE *in_fid;
    FILE *out_fid;
    // giriþ wave dosyasýný açýn
    in_fid = fopen( "giris.pcm", "rb" );
    if ( in_fid == 0 ) {
        printf("couldn't open giris.pcm");
        return;
    }
    // çýkýþ wave dosyasýný aç
    out_fid = fopen( "cikisFloat.pcm", "wb" );
    if ( out_fid == 0 ) {
        printf("couldn't open cikisFloat.pcm");
        return;
    }
    // filtreyi baþlat
    firFloatInit();
    // tüm örnekleri iþle
    do {
        // dosyadan örnekleri oku
        boyut = fread( giris, sizeof(int16_t), SAMPLES, in_fid );
        // çiftlere dönüþtür
        intToFloat( giris, floatGiris, boyut );
        // filtrelemeyi gerçekleþtir
        firFloat( coeffs, floatGiris, floatCikis, boyut,
        FILTER_LEN );
        // ints'ye dönüþtür
        floatToInt( floatCikis, cikis, boyut );
        // dosyaya örnek yaz
        fwrite( cikis, sizeof(int16_t), boyut, out_fid );
    } while ( boyut != 0 );
    fclose( in_fid );
    fclose( out_fid );
    return 0;
}
