#include <stdio.h>

int main() {
  int jam, menit, detik, totalDetik;

  printf("Masukkan jam: ");
  scanf("%d", &jam);

  printf("Masukkan menit: ");
  scanf("%d", &menit);

  printf("Masukkan detik: ");
  scanf("%d", &detik);

  totalDetik = (jam * 3600) + (menit * 60) + detik;

  printf("Total detik: %d\n", totalDetik);

  return 0;
}
