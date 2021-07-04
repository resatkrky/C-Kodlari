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
#define FILTER_LEN 63
int16_t insamp[ BUFFER_LEN ];
// FIR init
void firFixedInit( void )
{
    memset( insamp, 0, sizeof( insamp ) );
}
// the FIR filter function
void firFixed( int16_t *coeffs, int16_t *giris, int16_t *cikis,
        int uzunluk, int filterLength )
{
    int32_t acc; // MAC'ler için akümülatör
    int16_t *coeffp; // katsayýlara iþaretçi
    int16_t *girisp; // giriþ örnekleri için iþaretçi
    int n;
    int k;
    // yeni örnekleri arabelleðin üst ucuna koyun
    memcpy( &insamp[filterLength - 1], giris,
    uzunluk * sizeof(int16_t) );
    // filtreyi her giriþ örneðine uygulayýn
    for ( n = 0; n < uzunluk; n++ ) {
        // çýktýyý hesapla n
        coeffp = coeffs;
        girisp = &insamp[filterLength - 1 + n];
        // yük yuvarlama sabiti
        acc = 1 << 14;
        // çarpma biriktirme iþlemini gerçekleþtir
        for ( k = 0; k < filterLength; k++ ) {
            acc += (int32_t)(*coeffp++) * (int32_t)(*girisp--);
        }
        // sonucu doyur
        if ( acc > 0x3fffffff ) {
            acc = 0x3fffffff;
        } else if ( acc < -0x40000000 ) {
            acc = -0x40000000;
        }
        // Q30'dan Q15'e dönüþtürme
        cikis[n] = (int16_t)(acc >> 15);
    }
    // giriþ örneklerini bir dahaki sefere geri kaydýrma
    memmove( &insamp[0], &insamp[uzunluk],
    (filterLength - 1) * sizeof(int16_t) );
}
//////////////////////////////////////////////////////////////
// Test program
//////////////////////////////////////////////////////////////
// 1000 Hz merkezli bant geçiren filtre
// örnekleme hýzý = 8000 Hz
// 1000 Hz'de kazanç yaklaþýk 1.13

int16_t coeffs[ FILTER_LEN ] =
{
    -1468, 1058, 594, 287, 186, 284, 485, 613,
    495, 90, -435, -762, -615, 21, 821, 1269,
    982, 9, -1132, -1721, -1296, 1, 1445, 2136,
    1570, 0, -1666, -2413, -1735, -2, 1770, 2512,
    1770, -2, -1735, -2413, -1666, 0, 1570, 2136,
    1445, 1, -1296, -1721, -1132, 9, 982, 1269,
    821, 21, -615, -762, -435, 90, 495, 613,
    485, 284, 186, 287, 594, 1058, -1468
};
// döngü baþýna okunacak örnek sayýsý

int main( void )
{
    int boyut;
    int16_t giris[SAMPLES];
    int16_t cikis[SAMPLES];
    FILE *in_fid;
    FILE *out_fid;
    // open the input waveform file
    in_fid = fopen( "giris.pcm", "rb" );
    if ( in_fid == 0 ) {
        printf("couldn't open giris.pcm");
        return;
    }
    // open the output waveform file
    out_fid = fopen( "ciktiSabit.pcm", "wb" );
    if ( out_fid == 0 ) {
        printf("couldn't open ciktiSabit.pcm");
        return;
    }
    // filtreyi baþlat
    firFixedInit();
    // tüm örnekleri iþlemek
    do {
        // dosyadan örnekleri oku
        boyut = fread( giris, sizeof(int16_t), SAMPLES, in_fid );
        // filtrelemeyi gerçekleþtir
        firFixed( coeffs, giris, cikis, boyut, FILTER_LEN );
        // dosyaya örnek yaz
        fwrite( cikis, sizeof(int16_t), boyut, out_fid );
    } while ( boyut != 0 );
    fclose( in_fid );
    fclose( out_fid );
    return 0;
}
