#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char nama[256];
  int i, j;

  printf("Masukkan nama Anda: ");
  fgets(nama, sizeof(nama), stdin);

  nama[strcspn(nama, "\n")] = '\0'; 

  for (i = 0; nama[i] != '\0'; i++) {
    nama[i] = toupper(nama[i]);
  }

  for (i = strlen(nama) - 1, j = 0; i >= 0; i--, j++) {
    char temp = nama[i];
    nama[i] = nama[j];
    nama[j] = temp;
  }

  printf("Hasil: %s\n", nama);

  return 0;
}
