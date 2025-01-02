#include <stdio.h>
#include <string.h>

#define MAX_PRODUK 100
#define FILENAME "silupa_databases.txt"

typedef struct {
    char tanggal_panen[50];
    char jenis_tanaman[50];
    char jenis_benih[50];
    char tanggal_tanam[50];
    int berat_hasil_panen;
} Produk;

const char* tentukanPeriode(int count) {
    int periode = (count - 1) / 4 + 1;
    switch (periode) {
        case 1: return "Q1     ";
        case 2: return "Q2     ";
        case 3: return "Q3     ";
        case 4: return "Q4     ";
        default: return "N/A";
    }
}

    void TampilkanLaporan() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file.\n");
        return;
    }

    Produk produk;
    int totalBerat = 0;
    int count = 0;
    int periodeCount = 0;
    double rataRata = 0.0;
    const char *kategori;
    const char *periode;

    printf("+----------------------+-------------------+-------------------+ \n");
    printf("| Rata-rata Berat (kg) |   Kategori Panen  |   Periode Panen   | \n");
    printf("+----------------------+-------------------+-------------------+ \n");

    while (fscanf(file, "%49s %49s %49s %49s %d\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, produk.tanggal_tanam, &produk.berat_hasil_panen) != EOF) {
        totalBerat += produk.berat_hasil_panen;
        count++;
        periodeCount++;
      
     if (periodeCount == 4) {
            rataRata = (double)totalBerat / periodeCount;
            if (rataRata > 1000) {
                kategori = "Melimpah";
            } else if (rataRata > 500) {
                kategori = "Banyak ";
            } else {
                kategori = "Sedikit";
            }
            periode = tentukanPeriode(count);
            printf("|   %10.2f         |      %-5s      |      %-5s      |\n", rataRata, kategori, periode);
            totalBerat = 0;
            periodeCount = 0;
        }
    }
     if (periodeCount > 0) {
        rataRata = (double)totalBerat / periodeCount;
        if (rataRata > 1000) {
            kategori = "Melimpah";
        } else if (rataRata > 500) {
            kategori = "Banyak";
        } else {
            kategori = "Sedikit";
        }
        periode = tentukanPeriode(count);
        printf("|   %10.2f         |      %-5s       |      %-5s      |\n", rataRata, kategori, periode);
    }

    printf("+----------------------+-------------------+-------------------+ \n");
    fclose(file);
}


void welcomeMessage() {
    printf("   _____ _     _                   _                     _                         _____                         _ _    _____ _ _           _____        _ _ \n");
    printf("  / ____(_)   | |                 | |                   | |                       |  __ \\                       ( | )  / ____(_) |         |  __ \\      ( | )\n");
    printf(" | (___  _ ___| |_ ___ _ __ ___   | |    _   _ _ __ ___ | |__  _   _ _ __   __ _  | |__) |_ _ _ __   ___ _ __    V V  | (___  _| |    _   _| |__) |_ _   V V \n");
    printf("  \\___ \\| / __| __/ _ \\ '_ ` _ \\  | |   | | | | '_ ` _ \\| '_ \\| | | | '_ \\ / _` | |  ___/ _` | '_ \\ / _ \\ '_ \\         \\___ \\| | |   | | | |  ___/ _` |      \n");
    printf("  ____) | \\__ \\ ||  __/ | | | | | | |___| |_| | | | | | | |_) | |_| | | | | (_| | | |  | (_| | | | |  __/ | | |        ____) | | |___| |_| | |  | (_| |      \n");
    printf(" |_____/|_|___/\\__\\___|_| |_| |_| |______\\__,_|_| |_| |_|_.__/ \\__,_|_| |_|\\__, | |_|   \\__,_|_| |_|\\___|_| |_|       |_____/|_|______\\__,_|_|   \\__,_|      \n");
    printf("                                                                            __/ |                                                                            \n");
    printf("                                                                           |___/                                                                             \n");
}

void tambahProduk() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file.\n");
        return;
    }

    Produk produk;
    printf("\nMasukkan Tanggal tanam (DD-MM-YYYY): ");
    scanf("%s", &produk.tanggal_tanam);
    printf("Masukkan Jenis Tanaman: ");
    scanf("%s", &produk.jenis_tanaman);
    printf("Masukkan Jenis Benih: ");
    scanf("%s", &produk.jenis_benih);
    printf("Masukkan Tanggal Panen (DD-MM-YYYY): ");
    scanf("%s", &produk.tanggal_panen);
    printf("Masukkan Berat Hasil Panen (kg): ");
    scanf("%d", &produk.berat_hasil_panen);
    fprintf(file, "%s %s %s %s %d\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, produk.tanggal_tanam, produk.berat_hasil_panen);
    fclose(file);
    printf("\nPRODUK BERHASIL DITAMBAHKAN.\n");
}

void tampilkanDaftarProduk() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file.\n");
        return;  }

    Produk produk;
    printf("Isi Komoditas:\n");
    printf("+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
    printf("| Tanggal Panen   | Jenis Tanaman   | Jenis Benih     | Tanggal Tanam   | Berat (kg)      |\n");
    printf("+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
    while (fscanf(file, "%s %s %s %s %d\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, produk.tanggal_tanam, &produk.berat_hasil_panen) != EOF) {
        printf("| %-15s | %-15s | %-15s | %-15s | %-15d |\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, produk.tanggal_tanam, produk.berat_hasil_panen);
    }
    printf("+-----------------+-----------------+-----------------+-----------------+-----------------+\n");
    

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

    while (fscanf(file, "%s %s %s %s %d\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, produk.tanggal_tanam, &produk.berat_hasil_panen) != EOF) {
        if (strcmp(produk.tanggal_panen, tanggal_panen) == 0) {
            found = 1;
            printf("Masukkan Jenis Tanaman Baru: ");
            scanf("%s", &produk.jenis_tanaman);
            printf("Masukkan Jenis Benih Baru: ");
            scanf("%s", &produk.jenis_benih);
            printf("Masukkan Tanggal Tanam Baru: ");
            scanf("%s", &produk.tanggal_tanam);
            printf("Masukkan Berat Hasil Panen Baru (kg): ");
            scanf("%d", &produk.berat_hasil_panen);
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
        fprintf(file, "%s %s %s %s %d\n", produkList[i].tanggal_panen, produkList[i].jenis_tanaman, produkList[i].jenis_benih, produkList[i].tanggal_tanam, produkList[i].berat_hasil_panen);
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

    while (fscanf(file, "%s %s %s %s %d\n", produk.tanggal_panen, produk.jenis_tanaman, produk.jenis_benih, produk.tanggal_tanam, &produk.berat_hasil_panen) != EOF) {
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
        fprintf(file, "%s %s %s %s %d\n", produkList[i].tanggal_panen, produkList[i].jenis_tanaman, produkList[i].jenis_benih, produkList[i].tanggal_tanam, produkList[i].berat_hasil_panen);
    }
    fclose(file);
    printf("Produk dengan Tanggal Panen %s berhasil dihapus.\n", tanggal_panen);
}

int main() {
    int pilihan;
    welcomeMessage();
    do {
        printf("\nPilih Program:\n");
        printf("\n1. Masukkan data produk\n");
        printf("2. Tampilkan Komoditas\n");
        printf("3. Update data produk\n");
        printf("4. Hapus data produk\n");
        printf("5. Tampilkan Hasil Laporan\n");
        printf("6. Keluar\n");
        printf("\nMasukkan pilihan: ");
        scanf(" %d", &pilihan);

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
                TampilkanLaporan();
                break;
            case 6:
                printf("Terima kasih telah menggunakan Sistem Lumbung Padi (SiLuPa).\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 6);

    return 0;
}