#include <stdio.h>
#include <string.h>

int main() {
  char kalimat[256];
  int i, jumlahSpasi = 0;

  printf("Masukkan kalimat: ");
  fgets(kalimat, sizeof(kalimat), stdin);

  kalimat[strcspn(kalimat, "\n")] = '\0';

  for (i = 0; kalimat[i] != '\0'; i++) {
    if (kalimat[i] == ' ') {
      jumlahSpasi++;
    }
  }

  printf("Jumlah spasi: %d\n", jumlahSpasi);

  return 0;
}
