
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
  #define CLEAR_CMD "cls"
#else

/* --- Deklarasi fungsi --- */
void pressEnterToContinue();
void showMenu();
void calcOhm();
void calcPower();
void calcSeries();
void calcParallel();
void decToOthers();
void binToDec();
void octToDec();
void hexToDec();

/* --- Fungsi utama --- */
int main() {
    int choice;
    do {
        system(CLEAR_CMD);
        showMenu();
        printf("Masukkan pilihan Anda (1-9): ");
        if (scanf("%d", &choice) != 1) {
            // jika input bukan angka, buang input dan ulang
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            choice = 0;
        }

        // buang newline yang tersisa
        int c; while ((c = getchar()) != '\n' && c != EOF) {}

        switch (choice) {
            case 1: calcOhm(); break;
            case 2: calcPower(); break;
            case 3: calcSeries(); break;
            case 4: calcParallel(); break;
            case 5: decToOthers(); break;
            case 6: binToDec(); break;
            case 7: octToDec(); break;
            case 8: hexToDec(); break;
            case 9:
                printf("\nTerima kasih telah menggunakan toolkit ini!\n");
                break;
            default:
                printf("\nPilihan tidak valid. Silakan masukkan angka 1-9.\n");
                pressEnterToContinue();
        }
    } while (choice != 9);

    return 0;
}

/* --- Implementasi fungsi bantu --- */
void showMenu() {
    printf("=================================================\n");
    printf("| TOOLKIT LENGKAP ASISTEN LABORATORIUM ELEKTRO |\n");
    printf("=================================================\n");
    printf("| --- Verifikasi Rangkaian Elektrik ---         |\n");
    printf("| 1. Kalkulator Hukum Ohm (V = I * R)          |\n");
    printf("| 2. Kalkulator Daya Listrik (P = V * I)       |\n");
    printf("| 3. Kalkulator Resistor Seri                   |\n");
    printf("| 4. Kalkulator Resistor Paralel                |\n");
    printf("|                                              |\n");
    printf("| --- Utilitas Sistem Digital ---              |\n");
    printf("| 5. Desimal -> Biner / Oktal / Heksadesimal   |\n");
    printf("| 6. Biner -> Desimal                           |\n");
    printf("| 7. Oktal -> Desimal                           |\n");
    printf("| 8. Heksadesimal -> Desimal                    |\n");
    printf("|                                              |\n");
    printf("| 9. Keluar                                     |\n");
    printf("-------------------------------------------------\n");
}

