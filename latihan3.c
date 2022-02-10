//Rani Isramiharti
//13220003
// LATIHAN 3 PMC


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 255

struct mahasiswa {
    char nama[20];
    int NIM;
    int Kehadiran;
};

struct mahasiswa *ptr;

void printhasilcari(int index[], int n){
    printf("\nHasil pencarian:\n");
    for (int i = 0; i < n; ++i){
        printf("%s\t%d\t%d\n", (ptr + index[i])->nama, (ptr + index[i])->NIM, (ptr + index[i])-> Kehadiran);
    }
}

void printdata(struct mahasiswa *ptr, int n, int kategori){
    printf("\nHasil sorting berdasarkan ");
    if(kategori==0){
        printf("nama:\n");
    } else if(kategori==1){
        printf("NIM:\n");
    } else if(kategori==2){
        printf("Kehadiran:\n");
    }
    for (int i = 0; i < n; ++i){
        printf("%s\t%d\t%d\n", (ptr + i)->nama, (ptr + i)->NIM, (ptr + i)->Kehadiran);
    }
}

void cari(struct mahasiswa *ptr, int n, char find[20]){
    struct mahasiswa temp;
    int found = 0, arrfound[n];
    char str[9];

    for(int i=0; i<n; i++){
        if(strstr(ptr[i].nama, find)){
            arrfound[found] = i;
            found++;
        }
        sprintf(str, "%d", ptr[i].NIM);
        if(strstr(str, find)){
            arrfound[found] = i;
            found++;
        }
    }
    if(found>0){
        printhasilcari(arrfound, found);
    } else{
        printf("\nData tidak ditemukan!\n");
    }
}

int sortStrings(struct mahasiswa *ptr, int n) {
    struct mahasiswa temp;
    // Sorting strings using bubble sort
    for (int j=0; j<n-1; j++) {
        for (int i=j+1; i<n; i++) {
            if (strcmp(ptr[j].nama, ptr[i].nama) > 0) {
                temp = ptr[j];
                ptr[j] = ptr[i];
                ptr[i] = temp;
            }
        }
    }
    printdata(ptr, n, 0);

    for (int j=0; j<n-1; j++) {
        for (int i=j+1; i<n; i++) {
            if(ptr[j].NIM > ptr[i].NIM) {
                temp = ptr[j];
                ptr[j] = ptr[i];
                ptr[i] = temp;
            }
        }
    }
    printdata(ptr, n, 1);

    for (int j=0; j<n-1; j++) {
        for (int i=j+1; i<n; i++) {
            if (ptr[j].Kehadiran < ptr[i].Kehadiran) {
                temp = ptr[j];
                ptr[j] = ptr[i];
                ptr[i] = temp;
            }
        }
    }
    printdata(ptr, n, 2);
}





#include <stdio.h>

// deklarasi struktur mahasiswa
struct mahasiswa {
    char nama[10];
    int nim;
    float kehadiran;
};

int main() {
    // input tidak divalidasi lagi;
    // DIASUMSIKAN SEMUA INPUT VALID

    // inisialisasi
    int jumlahMhs = 5;

    struct mahasiswa kelas[5] = {
        {"Michael", 13220314, 0},
        {"James", 13220100, 0},
        {"Andre", 13220302, 0},
        {"Charles", 13220174, 0},
        {"Simeon", 13220999, 0}
    };

    // print isi kelas
    printf("\nDAFTAR MAHASISWA K09\n\n");
    for (int i = 0; i < 5; i++) {
        printf("[%d] %s\t(%d)\n", i+1, kelas[i].nama, kelas[i].nim);
    }

    printf("\n- - - - \n");

    // input presensi
    printf("\nPresensi berbentuk angka desimal,\ne.g. 1.0 untuk presensi 100 persen dan 0.75 untuk presensi 75 persen.\n");

    for (int i = 0; i < 5; i++) {
        printf("\nMasukkan presensi untuk %s:  ", kelas[i].nama);
        scanf("%f", &kelas[i].kehadiran);
    }

    printf("\n- - - - \n");

    // output
    printf("\nMahasiswa yang kehadirannya kurang dari 80%:\n\nNama\t\tNIM\t\tKehadiran\n\n");

    for (int i = 0; i < 5; i++) {
        if (kelas[i].kehadiran < 0.8) {
            printf("%s\t\t%d\t%.2f persen\n", kelas[i].nama, kelas[i].nim, kelas[i].kehadiran * 100);
        }
    }
}


int main() {
    int i, n;
    char find[20];
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    // Memory allocation for n structures
    ptr = (struct mahasiswa *)malloc(n * sizeof(struct mahasiswa));

    printf("Masukkan nama, NIM, dan Persentase Kehadiran:\n");
    for (i = 0; i < n; ++i) {
        scanf("%s %d %d", (ptr + i)->nama, &(ptr + i)->NIM, &(ptr + i)->Persentase Kehadiran);
    }

    printf("\nMasukkan Nama atau NIM yang ingin dicari:\n");
    scanf("%s", &find);

    cari(ptr, n, find);

    sortStrings(ptr, n);

    return 0;
}


void save(char nama[MAX_LEN][MAX_LEN],int Filter[50],int idx[50], int i)
{
    char file2[MAX_LEN];char new_line;
    printf("Masukkan Nama File yang Ingin Digunakan : ");
    scanf(" %[^\t\n]s%c",&file2,&new_line);
    FILE* fp = fopen(file2, "w");
    for (int j = 0; j < i ; ++j)
    {
        fprintf(fp,"%s,%d\n",nama[idx[j]],Filter[j]);
    }
    fclose(fp);
}

int main ()
{
    char NamaFile[MAX_LEN];
    printf("Masukkan Nama File Yang Digunakan : ");
    scanf("%[^\t\n]s", &NamaFile);
    FILE* fp = fopen(NamaFile,"r");
    char nama[MAX_LEN][MAX_LEN];
    int Kalkulus[MAX_LEN];
    int Kimia[MAX_LEN];
    int Fisika[MAX_LEN];
    char line[MAX_LEN];
    char* token;
    int i = 0;
    while (fgets(line,MAX_LEN,fp))
    {
        token = strtok(line, ",");
        strcpy(nama[i],token);
        token = strtok(NULL, ",");
        Kalkulus[i]=atol(token);
        token = strtok(NULL, ",");
        Kimia[i] = atol(token);
        token = strtok(NULL, "\n");
        Fisika[i] = atol(token);
        ++i;
    }
    int idx_Kalku = 0;
    int idx_Kimia = 0;
    int idx_Fisika = 0;
    int sum[i];
    int Nama_Kalku[i];
    int Nama_Kimia[i];
    int Nama_Fisika[i];
    int Filter_Kalku[i];
    int Filter_Kimia[i];
    int Filter_Fisika[i];
    for (int j = 0 ; j < i; ++j)
    {
        sum[j] = Kalkulus[j] + Kimia[j] + Fisika[j];  // Menghitung Jumlah Nilai Yang Diperoleh Siswa
        Filter_Kalku[j] = Kalkulus[j];
        Filter_Kimia[j] = Kimia[j];
        Filter_Fisika[j] = Fisika[j];
        Nama_Kalku[j] = j;
        Nama_Kimia[j] = j;
        Nama_Fisika[j] = j;
    }
    int a;
    int b;
    // Filter Kalkulus
    for (int j = 0; j < i; ++j)
    {
            for (int k = j + 1; k < i; ++k)
            {

                if (Filter_Kalku[j] > Filter_Kalku[k])
                {
                    b = Nama_Kalku[j];
                    a =  Filter_Kalku[j];
                    Filter_Kalku[j] = Filter_Kalku[k];
                    Nama_Kalku[j] = Nama_Kalku[k];
                    Filter_Kalku[k] = a;
                    Nama_Kalku[k] = b;

                }

            }
    }
