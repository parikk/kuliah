#include <stdio.h>

int main() {
  int n, i, nilai, min, max, total;

  printf("Masukkan jumlah data: ");
  scanf("%d", &n);

  min = 100;
  max = 0;
  total = 0;

  for (i = 1; i <= n; i++) {
    printf("Masukkan nilai ke-%d: ", i);
    scanf("%d", &nilai);

    if (nilai < min) {
      min = nilai;
    }

    if (nilai > max) {
      max = nilai;
    }

    total += nilai;
  }

  float rataRata = (float) total / n;

  printf("Nilai minimal: %d\n", min);
  printf("Nilai maksimal: %d\n", max);
  printf("Nilai rata-rata: %.2f\n", rataRata);

  return 0;
}
