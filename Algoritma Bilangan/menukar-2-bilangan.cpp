#include <stdio.h>

int main() {
  int a, b, temp;

  printf("Masukkan nilai a: ");
  scanf("%d", &a);
  printf("Masukkan nilai b: ");
  scanf("%d", &b);

  temp = a;
  a = b;
  b = temp;

  printf("Nilai a setelah ditukar: %d\n", a);
  printf("Nilai b setelah ditukar: %d\n", b);

  return 0;
}
