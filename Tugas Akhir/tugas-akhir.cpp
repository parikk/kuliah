#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaksi {
  char nomorFaktur[15];
  char tanggalFaktur[11];
  char namaPenyewa[30];
  int lamaSewa;
  char jenisMobil[10];
  int biayaSewa;
  int totalBiayaSewa;
};

struct Transaksi dataTransaksi[100];
int jumlahTransaksi = 0;

void menu() {
  printf("\n<<<< Menu Pilihan >>>\n");
  printf("                      Transaksi Rental Mobil\n");
  printf("                    Ketentuan Proses:\n");
  printf("                    1. Tarif Sewa\n");
  printf("                    Jika Jenis Mobil = Pick-Up; Tarif Sewa = Rp.200.000,\n");
  printf("                    Jika Jenis Mobil = Minibus; Tarif Sewa = Rp.250.000,\n");
  printf("                    Jika Jenis Mobil Sedan; Tarif Sewa = Rp.350.000,\n");
  printf("\n1. Entry Data Transaksi\n");
  printf("2. Tambah Data Transaksi\n");
  printf("3. Informasi Transaksi\n");
  printf("4. Exit\n");
}

void entryDataTransaksi() {
  printf("\nNandi Hati Rental Car\n");
  printf("Jl. Soekarno-Hatta No. 65 Padang\n");

  printf("\nEntry Data Transaksi\n");
  printf("Masukkan Nomor Faktur: ");
  scanf("%s", dataTransaksi[jumlahTransaksi].nomorFaktur);
  printf("Masukkan Tanggal Faktur (DD/MM/YYYY): ");
  scanf("%s", dataTransaksi[jumlahTransaksi].tanggalFaktur);
  printf("Masukkan Nama Penyewa: ");
  scanf(" %[^\n]", dataTransaksi[jumlahTransaksi].namaPenyewa); // fgets untuk keamanan
  printf("Masukkan Lama Sewa (hari): ");
  scanf("%d", &dataTransaksi[jumlahTransaksi].lamaSewa);
  printf("Masukkan Jenis Mobil (Pick-Up/Minibus/Sedan): ");
  scanf("%s", dataTransaksi[jumlahTransaksi].jenisMobil);

  int tarifSewa = 0;
  if (strcmp(dataTransaksi[jumlahTransaksi].jenisMobil, "Pick-Up") == 0) {
    tarifSewa = 200000;
  } else if (strcmp(dataTransaksi[jumlahTransaksi].jenisMobil, "Minibus") == 0) {
    tarifSewa = 250000;
  } else if (strcmp(dataTransaksi[jumlahTransaksi].jenisMobil, "Sedan") == 0) {
    tarifSewa = 350000;
  } else {
    printf("Jenis mobil tidak valid\n");
    return;
  }

  dataTransaksi[jumlahTransaksi].biayaSewa = tarifSewa * dataTransaksi[jumlahTransaksi].lamaSewa;
  dataTransaksi[jumlahTransaksi].totalBiayaSewa = dataTransaksi[jumlahTransaksi].biayaSewa;
  jumlahTransaksi++;

  printf("\nData Sudah Benar? (Y/T): ");
  char konfirmasi;
  scanf(" %c", &konfirmasi);
  if (konfirmasi == 'T' || konfirmasi == 't') {
    entryDataTransaksi();
  }
}

void tambahDataTransaksi() {
  if (jumlahTransaksi == 100) {
    printf("Data sudah penuh\n");
    return;
  }

  entryDataTransaksi();
}

void tampilInformasiTransaksi() {
  if (jumlahTransaksi == 0) {
    printf("Belum ada transaksi\n");
    return;
  }

  printf("\nLaporan Rental Mobil\n");
  printf("=====================================================================================================================\n");
  printf("| No. |  Nomor Faktur  |   Tanggal    |   Nama Penyewa  | Lama Sewa | Jenis Mobil  | Tarif Sewa Rp. | Biaya Sewa Rp. |\n");
  printf("=====================================================================================================================\n");
  for (int i = 0; i < jumlahTransaksi; i++) {
        printf("| %2d | %15s | %20s | %35s | %8d | %10s | %12d | %13d |\n",
           i + 1, dataTransaksi[i].nomorFaktur, dataTransaksi[i].tanggalFaktur, dataTransaksi[i].namaPenyewa,
           dataTransaksi[i].lamaSewa, dataTransaksi[i].jenisMobil, dataTransaksi[i].biayaSewa,
           dataTransaksi[i].totalBiayaSewa);
  }
  printf("=====================================================================================================================\n");
}

int main() {
  int pilihan;
  do {
    menu();
    printf("Masukkan pilihan Anda (1-4): ");
    scanf("%d", &pilihan);
    switch (pilihan) {
      case 1:
        entryDataTransaksi();
        break;
      case 2:
        tambahDataTransaksi();
        break;
      case 3:
        tampilInformasiTransaksi();
        break;
      case 4:
        printf("Terima kasih telah menggunakan Nandi Hati Rental Car!\n");
        exit(0);
        break;
      default:
        printf("Pilihan tidak valid\n");
    }
  } while (pilihan != 4);

  return 0;
}
