#include <stdio.h>
#include <stdlib.h>

typedef struct peserta {
  char nama[50];
  float lompatan;
} PESERTA;

void bacaDataPeserta(PESERTA *peserta, int n) {
  for (int i = 0; i < n; i++) {
    printf("Masukkan nama peserta %d: ", i + 1);
    scanf("%s", peserta[i].nama);
    printf("Masukkan tinggi lompatan peserta %d: ", i + 1);
    scanf("%f", &peserta[i].lompatan);
  }
}

void tukarData(PESERTA *a, PESERTA *b) {
  PESERTA temp = *a;
  *a = *b;
  *b = temp;
}

void urutkanData(PESERTA *peserta, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (peserta[i].lompatan < peserta[j].lompatan) {
        tukarData(&peserta[i], &peserta[j]);
      }
    }
  }
}

void tampilkanData(PESERTA *peserta, int n) {
  printf("\nDaftar Peserta Lompat Tinggi\n");
  printf("------------------------\n");
  for (int i = 0; i < n; i++) {
    printf("%d. %s: %.2f meter\n", i + 1, peserta[i].nama, peserta[i].lompatan);
  }
}

int main() {
  int n;

  do {
    printf("Masukkan jumlah peserta: ");
    scanf("%d", &n);
  } while (n <= 0);

  PESERTA *peserta = (PESERTA*) malloc(n * sizeof(PESERTA)); 
  if (peserta == NULL) {
      printf("Error alokasi memori!\n");
      exit(1); 
  }

  bacaDataPeserta(peserta, n);
  urutkanData(peserta, n);
  tampilkanData(peserta, n);
  free(peserta); 

  return 0;
}
