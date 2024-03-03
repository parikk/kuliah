#include <stdio.h>

int main() {
  int bil1, bil2;
  float hasilBagi;

  printf("Masukkan bilangan pertama: ");
  scanf("%d", &bil1);
  printf("Masukkan bilangan kedua: ");
  scanf("%d", &bil2);

  if (bil2 == 0) {
    printf("Error: Pembagian dengan nol tidak diizinkan!\n");
  } else {
    hasilBagi = (float) bil1 / bil2;

    printf("%.3f\n", hasilBagi);
  }

  return 0;
}
