#include <stdio.h>
#include <stdlib.h>

typedef struct pembalap {
  char nama[50];
  int waktu;
} PEMBALAP;

void urut_waktu(PEMBALAP *pembalap, int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (pembalap[i].waktu > pembalap[j].waktu) {
        PEMBALAP temp = pembalap[i];
        pembalap[i] = pembalap[j];
        pembalap[j] = temp;
      }
    }
  }
}

void tampilkan_hasil(PEMBALAP *pembalap, int n) {
  printf("\n--- Hasil Pertandingan Balap Sepeda ---\n");
  for (int i = 0; i < n; i++) {
    printf("%d. %s - %d detik\n", i + 1, pembalap[i].nama, pembalap[i].waktu);
  }
}

int main() {
  int n;
  PEMBALAP *pembalap;

  printf("Masukkan jumlah pembalap: ");
  scanf("%d", &n);

  pembalap = (PEMBALAP *)calloc(n, sizeof(PEMBALAP));

  if (pembalap == NULL) {
    printf("Alokasi memori gagal!\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("Masukkan nama pembalap %d: ", i + 1);
    scanf("%s", pembalap[i].nama);
    printf("Masukkan waktu finish pembalap %d: ", i + 1);
    scanf("%d", &pembalap[i].waktu);
  }

  urut_waktu(pembalap, n);
  tampilkan_hasil(pembalap, n);

  if (pembalap != NULL) {
    free(pembalap);
  }

  return 0;
}
