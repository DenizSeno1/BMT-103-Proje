#include <stdio.h>
#include "projeodevi.h"
int main() {

    Gorev gorevler[MAX_GOREV_SAYISI];
    int sayac = 0;
    int secim,secim1;
    gorevleri_yazmadan_Oku(gorevler,&sayac);
    do {
        printf("\n--- GOREV YONETIMI ---\n");
        printf("1. Gorev Ekle\n");
        printf("2. Gorev Sil\n");
        printf("3. Gorev Duzenleme\n");
        printf("4. Gorevleri Goruntule\n");
        printf("5. Gorevleri Dosyaya Kaydet\n");
        printf("6. Dosyadan Gorevleri Goruntule \n");
        printf("0. Cikis\n");

        secim = alSecim(); // Kullanıcının hatalı girişleri kontrol edilerek alınıyor

        switch (secim) {
            case 1:
                gorev_ekle(gorevler, &sayac);
                break;
            case 2:
                gorev_sil(gorevler, &sayac);
                break;
            case 3:
                printf("Duzenlemek istediginiz ogeyi seciniz\n");
                printf("1.Gorev Adi\n");
                printf("2.Gorev Detayi\n");
                printf("3.Son Tarihi\n");
                printf("Iptal etmek icin herhangi bir deger giriniz\n");
                printf("Secim:");
                scanf("%d",&secim1);
                switch (secim1) {
                    case 1:
                        gorev_ad_duzenleme(gorevler,sayac);
                        break;
                    case 2:
                        gorev_detay_duzenleme(gorevler,sayac);
                        break;
                    case 3:
                        gorev_son_tarih_duzenleme(gorevler,sayac);
                        break;
                    default:
                        temizleBuffer();
                        break;
                }
                break;
            case 4:
                gorevleri_goruntule(gorevler,sayac);
                break;
            case 5:
                gorevleri_kaydet(gorevler,sayac);
                break;
            case 6:
                gorevleri_dosyadan_goruntule(gorevler, &sayac);
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    } while (secim != 0);

    return 0;
}
