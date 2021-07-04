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
#define FILTER_LEN 63
#define FILTER_LEN_MA 8
#define SAMPLES 80
int16_t insamp[ BUFFER_LEN ];
// FIR init
void firFixedInit( void )
{
    memset( insamp, 0, sizeof( insamp ) );
}
// yeni girdi örneklerini sakla
int16_t *firStoreNewSamples( int16_t *inp, int uzunluk )
{
    // yeni örnekleri arabelleðin üst ucuna koyun
    memcpy( &insamp[MAX_FLT_LEN - 1], inp,
    uzunluk * sizeof(int16_t) );
    // filtrelemenin uygulanacaðý konumu döndür
    return &insamp[MAX_FLT_LEN - 1];
}
// iþlenmiþ örnekleri taþý
void firMoveProcSamples( int uzunluk )
{
    // giriþ örneklerini bir dahaki sefere geri kaydýrma
    memmove( &insamp[0], &insamp[uzunluk],
    (MAX_FLT_LEN - 1) * sizeof(int16_t) );
}
// FIR filtre iþlevi
void firFixed( int16_t *coeffs, int16_t *giris, int16_t *cikis,
        int uzunluk, int filterLength )
{
    int32_t acc; // MAC'ler için akümülatör
    int16_t *coeffp; // MAC'ler için akümülatör
    int16_t *girisp; // MAC'ler için akümülatör
    int n;
    int k;
    // filtreyi her giriþ örneðine uygulayýn
    for ( n = 0; n < uzunluk; n++ ) {
        // çýktýyý hesapla n
        coeffp = coeffs;
        girisp = &giris[n];
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
// 8 uzunluðunda hareketli ortalama (alçak geçiren) filtre
// 1000 Hz'de spektrumda bir sýfýr var

int16_t coeffsMa[ FILTER_LEN_MA ] =
{
    32768/8, 32768/8, 32768/8, 32768/8,
    32768/8, 32768/8, 32768/8, 32768/8
};
// döngü baþýna okunacak örnek sayýsý

int main( void )
{
    int boyut;
    int16_t giris[SAMPLES];
    int16_t cikis[SAMPLES];
    int16_t *inp;
    FILE *in_fid;
    FILE *out_fid;
    FILE *out_fid2;
    // giriþ dalga formu dosyasýný açýn
    in_fid = fopen( "giris.pcm", "rb" );
    if ( in_fid == 0 ) {
        printf("couldn't open giris.pcm");
        return;
    }
    // çýkýþ dalga formu dosyalarýný aç
    out_fid = fopen( "ciktiSabit.pcm", "wb" );
    if ( out_fid == 0 ) {
        printf("couldn't open ciktiSabit.pcm");
        return;
    }
    out_fid2 = fopen( "ciktiSabitMa.pcm", "wb" );
    if ( out_fid == 0 ) {
        printf("couldn't open ciktiSabitMa.pcm");
        return;
    }
    // filtreyi baþlat
    firFixedInit();
    // tüm örnekleri iþlemek
    do {
        // tüm örnek iþlemek
        boyut = fread( giris, sizeof(int16_t), SAMPLES, in_fid );
        // yeni örnekleri çalýþma dizisinde sakla
        inp = firStoreNewSamples( giris, boyut );
        // her filtreyi uygula
        firFixed( coeffs, inp, cikis, boyut, FILTER_LEN );
        fwrite( cikis, sizeof(int16_t), boyut, out_fid );
        firFixed( coeffsMa, inp, cikis, boyut, FILTER_LEN_MA );
        fwrite( cikis, sizeof(int16_t), boyut, out_fid2 );
        // iþlenmiþ örnekleri taþý
        firMoveProcSamples( boyut );
    } while ( boyut != 0 );
    fclose( in_fid );
    fclose( out_fid );
    fclose( out_fid2 );
    return 0;
}
