#include <stdio.h>

int main() {
  int a, b, c, min;

  printf("Masukkan nilai a: ");
  scanf("%d", &a);
  printf("Masukkan nilai b: ");
  scanf("%d", &b);
  printf("Masukkan nilai c: ");
  scanf("%d", &c);

  min = a;

  if (b < min) {
    min = b;
  }
  if (c < min) {
    min = c;
  }

  printf("Nilai terkecil adalah: %d\n", min);

  return 0;
}
