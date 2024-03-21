#include <stdio.h>
#include <string.h>

typedef struct Peserta {
  char nama[50];
  int nilai[3];
  int totalNilai;
} Peserta;

void entriData(Peserta *peserta, int n);
void cariPeserta(Peserta *peserta, int n, char *nama);
void daftarHasilPertandingan(Peserta *peserta, int n);
void daftarJuaraPertandingan(Peserta *peserta, int n);

int main() {
  int n, pilihan;
  Peserta peserta[100];
  char nama[50];

  printf("Masukkan jumlah peserta: ");
  scanf("%d", &n);

  do {
    printf("\nMenu Pilihan:\n");
    printf("1. Entri Data\n");
    printf("2. Cari Peserta\n");
    printf("3. Daftar Hasil Pertandingan\n");
    printf("4. Daftar Juara Pertandingan\n");
    printf("5. Keluar\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
      case 1:
        entriData(peserta, n);
        break;
      case 2:
        printf("Masukkan nama peserta yang ingin dicari: ");
        scanf(" %[^\n]%*c", nama);
        cariPeserta(peserta, n, nama);
        break;
      case 3:
        daftarHasilPertandingan(peserta, n);
        break;
      case 4:
        daftarJuaraPertandingan(peserta, n);
        break;
      case 5:
        printf("Terima kasih telah menggunakan program ini!\n");
        break;
      default:
        printf("Pilihan tidak valid!\n");
    }
  } while (pilihan != 5);

  return 0;
}

void entriData(Peserta *peserta, int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    printf("Masukkan nama peserta ke-%d: ", i + 1);
    scanf(" %[^\n]%*c", peserta[i].nama);

    for (j = 0; j < 3; j++) {
      do {
        printf("Masukkan nilai kesempatan memanah ke-%d (0 - 100): ", j + 1);
        scanf("%d", &peserta[i].nilai[j]);
      } while(peserta[i].nilai[j] < 0 || peserta[i].nilai[j] > 100);
    }

    peserta[i].totalNilai = 0;
    for (j = 0; j < 3; j++) {
      peserta[i].totalNilai += peserta[i].nilai[j];
    }
  }
}

void cariPeserta(Peserta *peserta, int n, char *nama) {
  int i, found = 0;

  for (i = 0; i < n; i++) {
    if (strcmp(peserta[i].nama, nama) == 0) {
      found = 1;
      printf("Nama: %s\n", peserta[i].nama);
      for (int j = 0; j < 3; j++) {
        printf("Nilai kesempatan memanah ke-%d: %d\n", j + 1, peserta[i].nilai[j]);
      }
      printf("Total nilai: %d\n", peserta[i].totalNilai);
      break;
    }
  }

  if (!found) {
    printf("Peserta dengan nama %s tidak ditemukan!\n", nama);
  }
}

void daftarHasilPertandingan(Peserta *peserta, int n) { 
  printf("Daftar Hasil Pertandingan:\n");
  printf("-------------------------\n"); 
  printf("| Nama | Nilai 1 | Nilai 2 | Nilai 3 | Total Nilai |\n"); 
  printf("-------------------------\n");
  for (int i = 0; i < n; i++) { 
    printf("| %-15s | %5d | %5d | %5d | %5d |\n", peserta[i].nama, peserta[i].nilai[0], peserta[i].nilai[1], peserta[i].nilai[2], peserta[i].totalNilai); 
  }
  printf("-------------------------\n"); 
} 

void daftarJuaraPertandingan(Peserta *peserta, int n) {
  int i, j, maxNilai, juara1, juara2, juara3;

  maxNilai = peserta[0].totalNilai;
  juara1 = 0;
  for (i = 1; i < n; i++) {
    if (peserta[i].totalNilai > maxNilai) {
      maxNilai = peserta[i].totalNilai;
      juara1 = i;
    }
  }

  maxNilai = 0;
  juara2 = -1;
  for (i = 0; i < n; i++) {
    if (i != juara1 && peserta[i].totalNilai > maxNilai) {
      maxNilai = peserta[i].totalNilai;
      juara2 = i;
    }
  }

  maxNilai = 0;
  juara3 = -1;
  for (i = 0; i < n; i++) {
    if (i != juara1 && i != juara2 && peserta[i].totalNilai > maxNilai) {
      maxNilai = peserta[i].totalNilai;
      juara3 = i;
    }
  }

  printf("\nDaftar Juara Pertandingan:\n");
  printf("-------------------------\n");
  printf("| Juara | Nama | Total Nilai |\n");
  printf("-------------------------\n");
  printf("| 1 | %-15s | %5d |\n", peserta[juara1].nama, peserta[juara1].totalNilai);
  printf("| 2 | %-15s | %5d |\n", peserta[juara2].nama, peserta[juara2].totalNilai);
  printf("| 3 | %-15s | %5d |\n", peserta[juara3].nama, peserta[juara3].totalNilai);
}
