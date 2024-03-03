#include <stdio.h>

void balikKalimat(char c) {
  char nextChar = getchar();

  if (nextChar != '\n') {
    balikKalimat(nextChar);
  }

  putchar(c);
}

int main() {
  printf("Masukkan kalimat: ");

  balikKalimat(getchar());

  putchar('\n');

  return 0;
}
