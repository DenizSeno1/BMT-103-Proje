//
// Created by deniz on 8.01.2024.
//

#ifndef PROJEODEVI_PROJEODEVI_H
#define PROJEODEVI_PROJEODEVI_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GOREV_ADI 100
#define MAX_DETAYLAR 1000
#define MAX_SON_TARIH 100
#define MAX_GOREV_SAYISI 100 //gerekli olacak sayıları önceden global değişken olarak tanımladık


typedef struct Gorev {
    int id;
    char ad[MAX_GOREV_ADI];
    char detaylar[MAX_DETAYLAR];
    char sonTarih[MAX_SON_TARIH];
} Gorev; //Gerekli olan görev yapısını tanımladık

void temizle() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
} //Kullanıcı hatalı giriş yaptığında satır sonuna ya da dosya sonuna ulaşana kadar satırı temizleyecek olan fonksiyondur.

void gorev_ekle(Gorev gorevler[], int *sayac) {
    printf("Gorev Adi: ");
    getchar(); //kullanıcıdan enter alana kadar beklemesini sağlama amacıyla kullanıldı
    fgets(gorevler[*sayac].ad, MAX_GOREV_ADI, stdin); //Boşluklarla beraber girilen cümleyi string olarak kaydedebilmek için fgets kullandık.
    gorevler[*sayac].ad[strcspn(gorevler[*sayac].ad, "\n")] = '\0'; // Satır sonu karakterini kaldırır ve '\0' ile diziyi bitirir.
    printf("Gorev Detaylari: ");
    fgets(gorevler[*sayac].detaylar, MAX_DETAYLAR, stdin);
    gorevler[*sayac].detaylar[strcspn(gorevler[*sayac].detaylar, "\n")] = '\0';


    printf("Gorev Son Tarihi: ");
    fgets(gorevler[*sayac].sonTarih, MAX_SON_TARIH, stdin);
    gorevler[*sayac].sonTarih[strcspn(gorevler[*sayac].sonTarih, "\n")] = '\0';

    gorevler[*sayac].id = *sayac + 1;
    (*sayac)++;
}

void gorev_sil(Gorev gorevler[], int *sayac) {
    int id;
    while (1) {
        printf("Silinecek Gorev ID: ");
        if (scanf("%d", &id) == 1) {
            temizle(); //enter karakterini siler
            break;
        }
        printf("Hatali giris. Bir sayi bekleniyor.\n");
        temizle();
    }

    for (int i = 0; i < *sayac; i++) {
        if (gorevler[i].id == id) {
            for (int j = i; j < *sayac - 1; j++) {
                gorevler[j] = gorevler[j + 1]; //silenen görevden sonraki her bir görevin sayısını bir azaltır bu sayede sıra bozulmaz
                gorevler[j].id=gorevler[j].id-1; // id sırasını düzenler
            }
            (*sayac)--;
            return;
        }
    }
    printf("Gorev ID bulunamadi.\n");
}

// Görevleri görüntüleme
void gorevleri_goruntule(Gorev gorevler[], int sayac) {
    for (int i = 0; i < sayac; i++) {
        printf("\nGorev ID: %d\n", gorevler[i].id);
        printf("Gorev Adi: %s\n", gorevler[i].ad);
        printf("Gorev Detaylari: %s\n", gorevler[i].detaylar);
        printf("Gorev Son Tarihi: %s\n", gorevler[i].sonTarih);
    }
}

// Görevleri dosyaya yazma
void gorevleri_kaydet(Gorev gorevler[], int sayac) {
    FILE *dosya = fopen("gorevler.txt", "w"); // yazma amacıyla görevler dosyasını 1 seferlik oluşturur daha sonrasında yazma amacıyla açar.
    if (dosya == NULL) {
        printf("Dosya olusturulamadi.\n"); //dosyanın oluşuturulup oluşturulmadığını kontrol eder.
        return;
    }

    for (int i = 0; i < sayac; i++) {
        fprintf(dosya, "%s\n", gorevler[i].ad);
        fprintf(dosya, "%s\n", gorevler[i].detaylar);
        fprintf(dosya, "%s\n", gorevler[i].sonTarih);
        fprintf(dosya, "%d\n", gorevler[i].id);
    }  // görevleri dosyaya yazdırmaya yarıyan for döngüsüdür.

    if (fclose(dosya) == EOF) {
        printf("Dosya kapatilamadi.\n");
        return;
    } //dosyayı kapatır ve dosyanın başarılı bir şekilde kapatılmazsa hata mesajı verir.
}
void gorev_ad_duzenleme(Gorev gorevler[],int sayac){
    int id;
    while (1) {
        printf("Duzenlenecek Gorev ID: ");
        if (scanf("%d", &id) == 1) {
            temizle();
            break;
        }
        printf("Hatali giris. Bir sayi bekleniyor.\n");
        temizle();
    }
    for (int i = 0; i < sayac; ++i) { //girilen idnin görev yapısını bulmaya yarıyan for döngüsü
       if (gorevler[i].id==id) {
           printf("Yeni Gorev Adi:");
           fgets(gorevler[i].ad, MAX_GOREV_ADI, stdin);
           gorevler[i].ad[strcspn(gorevler[i].ad, "\n")] = '\0';
           break;
       }
    }
}
void gorev_detay_duzenleme(Gorev gorevler[],int sayac){
    int id;
    while (1) {
        printf("Duzenlenecek Gorev ID: ");
        if (scanf("%d", &id) == 1) {
            temizle();
            break;
        }
        printf("Hatali giris. Bir sayi bekleniyor.\n");
        temizle();
    }
    for (int i = 0; i < sayac; ++i) {//girilen idnin görev yapısını bulmaya yarıyan for döngüsü
        if (gorevler[i].id==id) {
            printf("Yeni Gorev Detayi:");
            fgets(gorevler[i].detaylar, MAX_GOREV_ADI, stdin);
            gorevler[i].detaylar[strcspn(gorevler[i].detaylar, "\n")] = '\0'; // Satır sonu karakterini kaldır
            break;
        }
    }
}
void gorev_son_tarih_duzenleme(Gorev gorevler[],int sayac){
    int id;
    while (1) {
        printf("Duzenlenecek Gorev ID: ");
        if (scanf("%d", &id) == 1) {
            temizle(); // Hatalı girişi temizle
            break;
        }
        printf("Hatali giris. Bir sayi bekleniyor.\n");
        temizle();
    }
    for (int i = 0; i < sayac; ++i) {//girilen idnin görev yapısını bulmaya yarıyan for döngüsü
        if (gorevler[i].id==id) {
            printf("Yeni Gorev Detayi:");
            fgets(gorevler[i].sonTarih, MAX_GOREV_ADI, stdin);
            gorevler[i].sonTarih[strcspn(gorevler[i].sonTarih, "\n")] = '\0';
            break;
        }
    }
}

void gorevleri_dosyadan_goruntule(Gorev gorevler[], int *sayac) {
    FILE *dosya = fopen("gorevler.txt", "r"); //okuma amacıyla dosyayı açar.
    if (dosya == NULL) {
        printf("Dosya bulunamadi.\n");
        return;
    }

    // Dosyayı satır satır okur ve ekrana görevleri yazdırır.
    while (fscanf(dosya, " %[^\n]", gorevler[*sayac].ad) == 1) { //yeni satır karakteri hariç satırı taramak için %[^\n] kullanılır.
        fscanf(dosya, " %[^\n]", gorevler[*sayac].detaylar);
        fscanf(dosya, " %[^\n]", gorevler[*sayac].sonTarih);
        fscanf(dosya, "%d%*c", &gorevler[*sayac].id);
        printf("id: %d\n",gorevler[*sayac].id);
        printf("gorev adi: %s\n",gorevler[*sayac].ad);
        printf("gorev detayi: %s\n",gorevler[*sayac].detaylar);
        printf("son tarihi: %s\n",gorevler[*sayac].sonTarih);
        (*sayac)++;
    }

    fclose(dosya);
}
void gorevleri_yazmadan_Oku(Gorev gorevler[], int *sayac) { // gorevleri_dosyadan_goruntule fonksiyonundan farklı olarak ekrana yazdırmaz bu kaydedilmiş görevleri program başladığında dosyadan çekmeye yarar.
    FILE *dosya = fopen("gorevler.txt", "r");
    if (dosya == NULL) {
        printf("Dosya bulunamadi.\n");
        return;
    }

    while (fscanf(dosya, " %[^\n]", gorevler[*sayac].ad) == 1) {
        fscanf(dosya, " %[^\n]", gorevler[*sayac].detaylar);
        fscanf(dosya, " %[^\n]", gorevler[*sayac].sonTarih);
        fscanf(dosya, "%d%*c", &gorevler[*sayac].id);
        (*sayac)++;
    }

    fclose(dosya);
}


// Kullanıcıdan seçim alırken hatalı girişi kontrol etme
int alSecim() {
    int secim;
    printf("Secim: ");
    while (scanf("%d", &secim) != 1) {
        printf("Hatali giris. Bir sayi bekleniyor. Tekrar deneyin: ");
        temizle();
    }
    return secim;
}



#endif //PROJEODEVI_PROJEODEVI_H
