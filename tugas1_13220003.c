/*  Nama    : Rani Isramiharti
    NIM     : 13220003
    Program : program berhenti saat ada teko yang berisi 4 liter 
*/

#include <stdio.h>

int tekoA,tekoB,input = 0;

void teko(){
    while (tekoB != 4) {
        printf("Keadaan Teko Sekarang:\n");
        printf("1. Teko A berisi: %d liter air\n",tekoA);
        printf("2. Teko B berisi: %d liter air\n\n",tekoB);
        printf("Pilihan instruksi:\n");
        printf("1. Penuhi ember 3 liter (teko A)\n");
        printf("2. Penuhi ember 5 liter (teko B)\n");
        printf("3. Kosongkan ember 3 liter (teko A)\n");
        printf("4. Kosongkan ember 5 liter (teko B)\n");
        printf("5. Tuang isi ember 3 liter (teko A) ke ember 5 liter (teko B)\n");
        printf("6. Tuang isi ember 5 liter (teko B) ke ember 3 liter (teko A)\n");
        printf("Masukkan nomor pilihan: ");
        scanf("%d", &input);
        if (input == 1) {
            tekoA = 3;
            printf("\nTeko A sudah penuh berisi 3 liter air\n\n");

        } else if (input == 2) {
            tekoB = 5;
            printf("\nTeko B sudah penuh berisi 3 liter air\n\n");

        } else if (input == 3) {
            tekoA = 0;
            printf("\nTeko A sudah dikosongkan\n\n");

        } else if (input == 4) {
            tekoB = 0;
            printf("\nTeko B sudah dikosongkan\n\n");

        } else if (input == 5) {
            if (tekoA + tekoB > 5) {
                tekoA = (tekoA + tekoB) - 5;
                tekoB = 5;
            } else {
                tekoB += tekoA;
                tekoA = 0;
            }
            printf("\nIsi teko A telah dituangkan ke teko B\n\n");

        } else if (input == 6) {
            if (tekoA + tekoB > 3) {
                tekoB = (tekoA + tekoB) - 3;
                tekoA = 3;
            } else {
                tekoA += tekoB;
                tekoB = 0;
            }
            printf("\nIsi teko A telah dituangkan ke teko B\n\n");

        } else {
            printf("\nInvalid input.\n\n");
        }
    }
}
int main() {
    printf("Selamat Datang Di Program Water JUG!!!!\n");
    system("COLOR 0A");
    printf("Program Akan Berakhir Jika Terdapat Teko yang Berisi 4 Liter air\n\n");
    printf("Kapasitas Maksimum teko A adalah 3 liter dan teko B adalah 5 liter\n");
    teko();
    printf("Misi Selesai!\n");
}
