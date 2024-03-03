#include <stdio.h>

int main() {
  int totalDetik, jam, menit, detik;

  printf("Masukkan total detik: ");
  scanf("%d", &totalDetik);

  jam = totalDetik / 3600;

  totalDetik %= 3600;

  menit = totalDetik / 60;

  detik = totalDetik % 60;

  printf("%d jam %d menit %d detik\n", jam, menit, detik);

  return 0;
}
