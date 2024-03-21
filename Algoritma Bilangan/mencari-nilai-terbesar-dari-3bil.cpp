#include <stdio.h>

int main() {
  int a, b, c, max;

  printf("Masukkan nilai bilangan pertama: ");
  scanf("%d", &a);
  printf("Masukkan nilai bilangan kedua: ");
  scanf("%d", &b);
  printf("Masukkan nilai bilangan ketiga: ");
  scanf("%d", &c);

  if (a > b) {
    max = a;
  } else {
    max = b;
  }

  if (c > max) {
    max = c;
  }

  printf("Nilai terbesar adalah: %d\n", max);

  return 0;
}
