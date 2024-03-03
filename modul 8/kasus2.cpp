#include <stdio.h>

int perkalianRekursif(int a, int b) {
  if (b == 0) {
    return 0;
  }
  else if (b == 1) {
    return a;
  }
  else {
    return a + perkalianRekursif(a, b-1);
  }
}

int main() {
  int a, b, hasil;

  printf("Masukkan bilangan pertama: ");
  scanf("%d", &a);
  printf("Masukkan bilangan kedua: ");
  scanf("%d", &b);

  hasil = perkalianRekursif(a, b);

  printf("Hasil perkalian %d x %d adalah %d\n", a, b, hasil);

  return 0;
}
