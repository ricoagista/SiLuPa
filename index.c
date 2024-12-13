#include <stdio.h>

#define MAX_BARANG 100

struct barang {
    char nama[50];
    int berat;
    int benih;
};

struct barang daftarPanen[MAX_BARANG];
int jenisBenih = 0;

void inputBarang() {
    if (jenisBenih < MAX_BARANG) {
        printf("Masukkan data barang:\n");
        printf("Jenis Tanaman: ");
        scanf("%s", daftarPanen[jenisBenih].nama);
        printf("berat: ");
        scanf("%d", &daftarPanen[jenisBenih].berat);
        printf("benih: ");
        scanf("%d", &daftarPanen[jenisBenih].benih);
        jenisBenih++;
        printf("Data barang berhasil ditambahkan!\n");
    } else {
        printf("Maaf, kapasitas penyimpanan barang sudah penuh.\n");
    }
}

void tampilkanData() {
    if (jenisBenih == 0) {
        printf("Belum ada data barang yang dimasukkan.\n");
    } else {
        printf("Daftar Barang:\n");
        for (int i = 0; i < jenisBenih; i++) {
            printf("Jenis Tanaman: %s\n", daftarPanen[i].nama);
            printf("berat: %d\n", daftarPanen[i].berat);
            printf("benih: %d\n", daftarPanen[i].benih);
            printf("berat Total: %d\n\n", daftarPanen[i].berat * daftarPanen[i].benih);
        }
    }
}

int main() {
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Input Panen\n");
        printf("2. Tampilkan Data Panen\n");
        printf("3. Update Data Panen\n");
        printf("4. Hapus Data Panen\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                inputBarang();
                break;
            case 2:
                tampilkanData();
                break;
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}
