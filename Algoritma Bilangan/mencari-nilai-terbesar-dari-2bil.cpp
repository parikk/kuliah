#include <stdio.h>

int main() {
  int bil1, bil2, max;

  printf("Masukkan bilangan pertama: ");
  scanf("%d", &bil1);

  printf("Masukkan bilangan kedua: ");
  scanf("%d", &bil2);

  if (bil1 > bil2) {
    max = bil1;
  } else {
    max = bil2;
  }

  printf("Nilai terbesar adalah: %d\n", max);

  return 0;
}
