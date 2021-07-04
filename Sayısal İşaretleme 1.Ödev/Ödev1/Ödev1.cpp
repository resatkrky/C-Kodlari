#include <fstream>
#include <iostream>

using namespace std;

double ortHesapla(int sayılar[], int boyut)
{
    int toplam = 0;
    double ortalama;
    for (int i = 0; i < boyut; i++)
    {
        toplam += sayılar[i];
    }
    ortalama = (double)toplam / boyut;

    return ortalama;
}

void standartSapma(int sayılar[], int boyut)
{
    float stsapma = 0, varyans = 0;
    double ort = ortHesapla(sayılar, boyut);

    for (int i = 0; i < boyut; i++)
    {
        varyans = varyans + (sayılar[i] - ort) * (sayılar[i] - ort);
    }
    varyans = varyans / boyut;
    //stsapma = sqrt(varyans);

    cout << "Aritmetik Ortalama: " << ort << endl;
    cout << "Varyans: " << varyans << endl;
    cout << "Standart Sapma: " << stsapma << endl;
}


int main()
{
    int* dizi = new int[1000];
    int i, boyut;

    ifstream dosya("Sayilar.txt");
    if (!dosya.is_open())
    {
        cout << "Hata";
    }
    else
    {
        dosya >> boyut;
        for (i = 0; i < boyut; i++)
        {
            dosya >> dizi[i];
        }
    }

    dosya.close();

    standartSapma(dizi, boyut);
}
