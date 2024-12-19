#include <stdio.h>
#include <string.h>

#define MAX_PRODUK 100
#define FILENAME "silupa_databases.txt"

typedef struct {
    char tanggal_panen[50];
    char jenis_tanaman[50];
    char jenis_benih[50];
    float harga;
    int stok;
} Produk;

void welcomeMessage() {
    printf("====================================\n");
    printf("Selamat Datang di Manajemen Toko Elektronik\n");
    printf("====================================\n");
}

void tambahProduk() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file.\n");
        return;
    }

    Produk produk;
    printf("Masukkan Tanggal Panen (DD-MM-YYYY): ");
    scanf("%s", &produk.tanggal_panen);

    Produk temp;
    int found = 0;
    FILE *checkFile = fopen(FILENAME, "r");
    while (fscanf(checkFile, "%s %s %s %f %d\n", temp.tanggal_panen, temp.jenis_tanaman, temp.jenis_benih, &temp.harga, &temp.stok) != EOF) {
        if (strcmp(temp.tanggal_panen, produk.tanggal_panen) == 0) {
            found = 1;
            break;
        }
    }
    fclose(checkFile);

    if (found) {
        printf("Tanggal Panen SUDAH TERDAFTAR. Silakan masukkan Tanggal Panen yang berbeda.\n");
        fclose(file);
        return;
    }

    printf("Masukkan Jenis Tanaman: ");
    scanf("%s", &produk.jenis_tanaman);
    printf("Masukkan Jenis Benih: ");
    scanf("%s", &produk.jenis_benih);
    printf("Masukkan Harga: ");
    scanf("%f", &produk.harga);
    printf("Masukkan Stok: ");
    scanf("%d", &produk.stok);

fprintf(file, "%s %s %s %.2f %d\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, produk.harga, produk.stok);
fclose(file);
printf("Produk berhasil ditambahkan.\n");
}

void tampilkanDaftarProduk() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file.\n");
        return;
    }

    Produk produk;
    printf("Daftar Produk:\n");
    printf("%-15s %-15s %-15s %-15s %-10s\n", "Tanggal Panen", "Jenis Tanaman", "Jenis Benih", "Harga", "Stok");
    while (fscanf(file, "%s %s %s %f %d\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, &produk.harga, &produk.stok) != EOF) {
        printf("%-15s %-15s %-15s %-15.2f %-5d\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, produk.harga, produk.stok);
    }
    fclose(file);
}

void updateInformasiProduk() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file.\n");
        return;
    }

    Produk produk;
    char tanggal_panen[50];
    printf("Masukkan Tanggal Panen yang ingin diupdate (YYYY-MM-DD): ");
    scanf("%s", tanggal_panen);

    int found = 0;
    Produk produkList[MAX_PRODUK];
    int count = 0;

    while (fscanf(file, "%s %s %s %f %d\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, &produk.harga, &produk.stok) != EOF) {
        if (strcmp(produk.tanggal_panen, tanggal_panen) == 0) {
            found = 1;
            printf("Masukkan Jenis Tanaman Baru: ");
            scanf("%s", &produk.jenis_tanaman);
            printf("Masukkan Jenis Benih Baru: ");
            scanf("%s", &produk.jenis_benih);
            printf("Masukkan Harga Baru: ");
            scanf("%f", &produk.harga);
            printf("Masukkan Stok Baru: ");
            scanf("%d", &produk.stok);
        }
        produkList[count++] = produk;
    }
    fclose(file);

    if (!found) {
        printf("Produk dengan Tanggal Panen %s tidak ditemukan.\n", tanggal_panen);
        return;
    }

    file = fopen(FILENAME, "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s %.2f %d\n", produkList[i].tanggal_panen, produkList[i].jenis_tanaman, produkList[i].jenis_benih, produkList[i].harga, produkList[i].stok);
    }
    fclose(file);
    printf("Informasi produk berhasil diupdate.\n");
}

void hapusProduk() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file.\n");
        return;
    }

    Produk produk;
    char tanggal_panen[50];
    printf("Masukkan Tanggal Panen yang ingin dihapus (YYYY-MM-DD): ");
    scanf("%s", &tanggal_panen);

    int found = 0;
    Produk produkList[MAX_PRODUK];
    int count = 0;

    while (fscanf(file, "%s %s %s %f %d\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, &produk.harga, &produk.stok) != EOF) {
        if (strcmp(produk.tanggal_panen, tanggal_panen) != 0) {
            produkList[count++] = produk;
        } else {
            found = 1;
        }
    }
    fclose(file);

    if (!found) {
        printf("Produk dengan Tanggal Panen %s tidak ditemukan.\n", tanggal_panen);
        return;
    }

    file = fopen(FILENAME, "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s %.2f %d\n", produkList[i].tanggal_panen, produkList[i].jenis_tanaman, produkList[i].jenis_benih, produkList[i].harga, produkList[i].stok);
    }
    fclose(file);
    printf("Produk dengan Tanggal Panen %s berhasil dihapus.\n", tanggal_panen);
}

int main() {
    int pilihan;
    welcomeMessage();
    do {
        printf("\n1. Masukan data produk\n");
        printf("2. Tampilkan daftar produk\n");
        printf("3. Uptade data produk\n");
        printf("4. Hapus data produk\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahProduk();
                break;
            case 2:
                tampilkanDaftarProduk();
                break;
            case 3:
                updateInformasiProduk();
                break;
            case 4:
                hapusProduk();
                break;
            case 5:
                printf("Terima kasih! Program selesai.\n");
                   break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 5);

    return 0;
}