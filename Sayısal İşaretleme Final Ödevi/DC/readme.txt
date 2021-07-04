Reşat Karakaya
348284

Kodun çalışması için girdi.wav, t1.wav ve t2.wav ses dosyaları aynı dizinde bulunmalı
girdi.wav ses dosyası FIR filtreleme işlemi yapılacak ses dosyasıdır.

Kod çalıştırıldığı zaman 3 seçenek sunar.
Birincisi High Pass FIR Filtre katsayılarıyla işlem yapar ve high.wav ses dosyası oluşur.
İkincisi Low Pass FIR Filtre katsayılarıyla işlem yapar ve low.wav ses dosyası oluşur.
Üçüncüsü FIR Filtre Katsayılarını kullanıcının girmesini sağlar.
Kullanıcın girdiği FIR Filtre katsayilariyla işlem yapar ve FIR.wav ses dosyası oluşur.
Program seçilen seçeneğe göre FIR Filtreleme yapar. 

Program ayrıca iki wav dosyasını toplar ve toplam için başka wav dosyası oluşturur.
Girdi Dosyaları -->toplanan t1.wav ve t2.wav dosyaları, FIR Filtre uygulanan girdi.wav dosyası
Çıktı Dosyaları -->seçilen seçeneğe göre oluşan high.wav, low.wav veya FIR.wav ses dosyaları
.csv uzantılı seçilen seçeneğe göre oluşan wav dosyasının sinyal verilerini tutan dosya
t1.wav ve t2.wav dosyalarının toplamından oluşan tToplam.wav

