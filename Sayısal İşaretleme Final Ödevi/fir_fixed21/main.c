#include <stdio.h>
#include <stdint.h>
//////////////////////////////////////////////////////////////
// Filter Code Definitions
//////////////////////////////////////////////////////////////
// ��lenebilecek maksimum giri� say�s�
// bir i�lev �a�r�s�nda
#define MAX_INPUT_LEN 80
// ele al�nabilecek maksimum filtre uzunlu�u
#define MAX_FLT_LEN 63
// t�m girdi �rneklerini tutmak i�in arabellek
#define BUFFER_LEN (MAX_FLT_LEN - 1 + MAX_INPUT_LEN)
// giri� �rneklerini tutacak dizi
#define FILTER_LEN 63
#define FILTER_LEN_MA 8
#define SAMPLES 80
int16_t insamp[ BUFFER_LEN ];
// FIR init
void firFixedInit( void )
{
    memset( insamp, 0, sizeof( insamp ) );
}
// yeni girdi �rneklerini sakla
int16_t *firStoreNewSamples( int16_t *inp, int uzunluk )
{
    // yeni �rnekleri arabelle�in �st ucuna koyun
    memcpy( &insamp[MAX_FLT_LEN - 1], inp,
    uzunluk * sizeof(int16_t) );
    // filtrelemenin uygulanaca�� konumu d�nd�r
    return &insamp[MAX_FLT_LEN - 1];
}
// i�lenmi� �rnekleri ta��
void firMoveProcSamples( int uzunluk )
{
    // giri� �rneklerini bir dahaki sefere geri kayd�rma
    memmove( &insamp[0], &insamp[uzunluk],
    (MAX_FLT_LEN - 1) * sizeof(int16_t) );
}
// FIR filtre i�levi
void firFixed( int16_t *coeffs, int16_t *giris, int16_t *cikis,
        int uzunluk, int filterLength )
{
    int32_t acc; // MAC'ler i�in ak�m�lat�r
    int16_t *coeffp; // MAC'ler i�in ak�m�lat�r
    int16_t *girisp; // MAC'ler i�in ak�m�lat�r
    int n;
    int k;
    // filtreyi her giri� �rne�ine uygulay�n
    for ( n = 0; n < uzunluk; n++ ) {
        // ��kt�y� hesapla n
        coeffp = coeffs;
        girisp = &giris[n];
        // y�k yuvarlama sabiti
        acc = 1 << 14;
        // �arpma biriktirme i�lemini ger�ekle�tir
        for ( k = 0; k < filterLength; k++ ) {
            acc += (int32_t)(*coeffp++) * (int32_t)(*girisp--);
        }
        // sonucu doyur
        if ( acc > 0x3fffffff ) {
            acc = 0x3fffffff;
        } else if ( acc < -0x40000000 ) {
            acc = -0x40000000;
        }
        // Q30'dan Q15'e d�n��t�rme
        cikis[n] = (int16_t)(acc >> 15);
    }
}
//////////////////////////////////////////////////////////////
// Test program
//////////////////////////////////////////////////////////////
// 1000 Hz merkezli bant ge�iren filtre
// �rnekleme h�z� = 8000 Hz
// 1000 Hz'de kazan� yakla��k 1.13

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
// 8 uzunlu�unda hareketli ortalama (al�ak ge�iren) filtre
// 1000 Hz'de spektrumda bir s�f�r var

int16_t coeffsMa[ FILTER_LEN_MA ] =
{
    32768/8, 32768/8, 32768/8, 32768/8,
    32768/8, 32768/8, 32768/8, 32768/8
};
// d�ng� ba��na okunacak �rnek say�s�

int main( void )
{
    int boyut;
    int16_t giris[SAMPLES];
    int16_t cikis[SAMPLES];
    int16_t *inp;
    FILE *in_fid;
    FILE *out_fid;
    FILE *out_fid2;
    // giri� dalga formu dosyas�n� a��n
    in_fid = fopen( "giris.pcm", "rb" );
    if ( in_fid == 0 ) {
        printf("couldn't open giris.pcm");
        return;
    }
    // ��k�� dalga formu dosyalar�n� a�
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
    // filtreyi ba�lat
    firFixedInit();
    // t�m �rnekleri i�lemek
    do {
        // t�m �rnek i�lemek
        boyut = fread( giris, sizeof(int16_t), SAMPLES, in_fid );
        // yeni �rnekleri �al��ma dizisinde sakla
        inp = firStoreNewSamples( giris, boyut );
        // her filtreyi uygula
        firFixed( coeffs, inp, cikis, boyut, FILTER_LEN );
        fwrite( cikis, sizeof(int16_t), boyut, out_fid );
        firFixed( coeffsMa, inp, cikis, boyut, FILTER_LEN_MA );
        fwrite( cikis, sizeof(int16_t), boyut, out_fid2 );
        // i�lenmi� �rnekleri ta��
        firMoveProcSamples( boyut );
    } while ( boyut != 0 );
    fclose( in_fid );
    fclose( out_fid );
    fclose( out_fid2 );
    return 0;
}
