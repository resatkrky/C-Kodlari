#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define B2L_ENDIAN(num) (((num >> 24) & 0xff) | ((num << 8) & 0xff0000) | ((num >> 8) & 0xff00) | ((num << 24) & 0xff000000))
// 32 bit sayinin büyük endian'dan küçük endian'a dönüþümü

//348284 - Reþat KARAKAYA - 1.Ogretim

// küçük endian bayt sýrasý kullanýlýyor mu?
int little_endian_mi() {
    uint16_t word = 0x0001;
    uint8_t* ptr = (uint8_t*)&word;
    return (ptr[0]) ? 1 : 0;
}

// Buffer'a almak için ikili dosya okuma
uint8_t* dosya_oku(const char* dosya_yolu, size_t* boyut) {
    FILE* fp = fopen(dosya_yolu, "rb");

    if (!fp) {
        fprintf(stderr, "Dosya Bulunamadi\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    *boyut = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint8_t* buf = (uint8_t*)malloc(*boyut);

    if (!buf) {
        fprintf(stderr, "Buffer bos\n");
        exit(1);
    }

    fread(buf, *boyut, 1, fp);
    fclose(fp);
    return buf;
}

// Buffer'a ikili dosya yazma
void dosya_yaz(const uint8_t* buf, const char* dosya_yolu, size_t boyut) {
    FILE* fp = fopen(dosya_yolu, "wb");

    if (!fp) {
        fprintf(stderr, "File couldn't created\n");
        exit(1);
    }

    fwrite(buf, boyut, 1, fp);
    fclose(fp);
}

// Piksel verilerinin histogramini, ortalamasini ve varyansini hesaplama
void histogram(const uint8_t* buf, size_t boyut) {
    int i, bins[256] = { 0 };
    float ortalama, varyans;

    for (i = 0; i < boyut; i++)
        bins[buf[i]]++;

    printf("HISTOGRAM\n\n");
    for (i = 0; i < 256; i++)
        printf("H(%03d) = %d\n", i, bins[i]);

    ortalama = 0.0f;
    for (i = 0; i < 256; i++)
        ortalama += i * bins[i];
    ortalama = ortalama / boyut;

    printf("\nortalama : %.2f\n", ortalama);

    varyans = 0.0f;
    for (i = 0; i < 256; i++)
        varyans += (i - ortalama) * (i - ortalama) * bins[i];
    varyans = varyans / (boyut - 1);

    printf("\nvaryans : %.2f\n", varyans);
}

int main()
{
    uint8_t* buf;
    uint32_t offset, genislik, yukseklik; // offset piksel verilerinin baþladýðý konumdur
    size_t boyut;

    buf = dosya_oku("girdi.bmp", &boyut);

    if (little_endian_mi()) {
        offset  = *((uint32_t*)(&buf[10]));
        genislik   = *((uint32_t*)(&buf[18]));
        yukseklik  = *((uint32_t*)(&buf[22]));
    }
    else {
        offset  = B2L_ENDIAN(*((uint32_t*)(&buf[10])));
        genislik   = B2L_ENDIAN(*((uint32_t*)(&buf[18])));
        yukseklik  = B2L_ENDIAN(*((uint32_t*)(&buf[22])));
    }

    histogram(&buf[offset], genislik * yukseklik);
    //write_file(buffer, "lena_gray2.bmp", size);

    return 0;
}
