#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#define MAX 30


char nim[MAX][20];
float nilai[MAX][3]; // [Tugas][UTS][UAS]
int jumlah = 3;

void tampil();
void tambah();
void ubah();
void hapus();
void hitungPengolahan();
void fiturRekursif();

int faktorial(int n);
int fibonacci(int n);


int main() {
    int menu;

    // DATA AWAL
    strcpy(nim[0], "C2483207015");
    nilai[0][0] = 83; nilai[0][1] = 89; nilai[0][2] = 92;

    strcpy(nim[1], "C2483207016");
    nilai[1][0] = 87; nilai[1][1] = 90; nilai[1][2] = 90;

    strcpy(nim[2], "C2483207017");
    nilai[2][0] = 89; nilai[2][1] = 92; nilai[2][2] = 95;

    do {
        printf("\n=== MENU PROGRAM ===\n");
        printf("1. Tampilkan data mahasiswa\n");
        printf("2. Tambah data mahasiswa\n");
        printf("3. Ubah nilai mahasiswa\n");
        printf("4. Hapus data mahasiswa\n");
        printf("5. Pengolahan nilai (Matriks)\n");
        printf("6. Fitur rekursif\n");
        printf("7. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: tampil(); break;
            case 2: tambah(); break;
            case 3: ubah(); break;
            case 4: hapus(); break;
            case 5: hitungPengolahan(); break;
            case 6: fiturRekursif(); break;
            case 7: printf("Program selesai.\n"); break;
            default: printf("Menu tidak valid.\n");
        }
    } while (menu != 7);

    return 0;
}

// ====== MENU 1 ======
void tampil() {
    int i;
    printf("\nNIM\t\tTugas\tUTS\tUAS\tRata-rata\n");
    printf("-------------------------------------------------\n");
    for (i = 0; i < jumlah; i++) {
        float rata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;
        printf("%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
               nim[i], nilai[i][0], nilai[i][1], nilai[i][2], rata);
    }
}

// ====== MENU 2 ======
void tambah() {
    if (jumlah >= MAX) {
        printf("Data penuh.\n");
        return;
    }

    printf("Masukkan NIM: ");
    scanf("%s", nim[jumlah]);
    printf("Nilai Tugas: ");
    scanf("%f", &nilai[jumlah][0]);
    printf("Nilai UTS  : ");
    scanf("%f", &nilai[jumlah][1]);
    printf("Nilai UAS  : ");
    scanf("%f", &nilai[jumlah][2]);

    jumlah++;
    printf("Data berhasil ditambahkan.\n");
}

// ====== MENU 3 ======
void ubah() {
    char cari[20];
    int i, ketemu = 0;

    printf("Masukkan NIM yang akan diubah: ");
    scanf("%s", cari);

    for (i = 0; i < jumlah; i++) {
        if (strcmp(nim[i], cari) == 0) {
            printf("Nilai Tugas baru: ");
            scanf("%f", &nilai[i][0]);
            printf("Nilai UTS baru : ");
            scanf("%f", &nilai[i][1]);
            printf("Nilai UAS baru : ");
            scanf("%f", &nilai[i][2]);
            printf("Data berhasil diubah.\n");
            ketemu = 1;
            break;
        }
    }
    if (!ketemu)
        printf("NIM tidak ditemukan.\n");
}

// ====== MENU 4 ======
void hapus() {
    char cari[20];
    int i, j, ketemu = 0;

    printf("Masukkan NIM yang akan dihapus: ");
    scanf("%s", cari);

    for (i = 0; i < jumlah; i++) {
        if (strcmp(nim[i], cari) == 0) {
            for (j = i; j < jumlah - 1; j++) {
                strcpy(nim[j], nim[j + 1]);
                nilai[j][0] = nilai[j + 1][0];
                nilai[j][1] = nilai[j + 1][1];
                nilai[j][2] = nilai[j + 1][2];
            }
            jumlah--;
            printf("Data berhasil dihapus.\n");
            ketemu = 1;
            break;
        }
    }
    if (!ketemu)
        printf("NIM tidak ditemukan.\n");
}

// ====== MENU 5 (PENGOLAHAN NILAI MATRIKS) ======
void hitungPengolahan() {
    int i;
    float rataMhs[MAX];
    float rataTugas = 0, rataUTS = 0, rataUAS = 0;
    int idxMax = 0, idxMin = 0;

    for (i = 0; i < jumlah; i++) {
        rataMhs[i] = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;
        rataTugas += nilai[i][0];
        rataUTS   += nilai[i][1];
        rataUAS   += nilai[i][2];
    }

    rataTugas /= jumlah;
    rataUTS   /= jumlah;
    rataUAS   /= jumlah;

    for (i = 1; i < jumlah; i++) {
        if (rataMhs[i] > rataMhs[idxMax]) idxMax = i;
        if (rataMhs[i] < rataMhs[idxMin]) idxMin = i;
    }

    printf("\n=== HASIL PENGOLAHAN NILAI ===\n");
    printf("Rata-rata Tugas : %.2f\n", rataTugas);
    printf("Rata-rata UTS   : %.2f\n", rataUTS);
    printf("Rata-rata UAS   : %.2f\n", rataUAS);

    printf("\nMahasiswa nilai TERTINGGI: %s (%.2f)\n",
           nim[idxMax], rataMhs[idxMax]);
    printf("Mahasiswa nilai TERENDAH : %s (%.2f)\n",
           nim[idxMin], rataMhs[idxMin]);
}

// ====== MENU 6 (REKURSIF) ======
void fiturRekursif() {
    int i;
    printf("\nFaktorial jumlah mahasiswa (%d!) = %d\n",
           jumlah, faktorial(jumlah));

    printf("Deret Fibonacci (%d data): ", jumlah);
    for (i = 0; i < jumlah; i++)
        printf("%d ", fibonacci(i));
    printf("\n");
}

// ====== FUNGSI REKURSIF ======
int faktorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * faktorial(n - 1);
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
