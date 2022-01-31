/*  Nama    : Rani Isramiharti
    NIM     : 13220003
    Program : Mendeteksi file ber-ekstensi .jpg atau .pdf atau sebuah tidak terdefenisi
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    // Deklarasi Variabel
    char FileName[] = "";
    unsigned char MagicNum[2];
    FILE *fp;
    
    // Algoritma
    printf("Masukkan nama file: "); // Input nama file.
    scanf("%s", FileName);

    fp = fopen(FileName, "r");    // Buka file untuk dibaca.
    
    if (MagicNum == NULL) {
        printf("File tidak dapat dibaca.");
    }
    else {
        fread(MagicNum, 2, 1, fp);

        if (MagicNum[0] == 0xFF && MagicNum[1] == 0xD8) {   // Memeriksa file signature 
            printf("File memiliki ekstensi .jpg");
        }
        else if (MagicNum[0] == 0x25 && MagicNum[1] == 0x50) {
            printf("File memiliki ekstensi .pdf");
        }
        else {
            printf("File memiliki ekstensi bukan .pdf maupun .jpg");
        }
    }
    return(0);
}
