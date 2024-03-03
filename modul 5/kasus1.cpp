#include <stdio.h>
#include <ctype.h>

int main() {
  char kalimat[256];
  int jumlahHurufKecil = 0, jumlahHurufKapital = 0;

  printf("Masukkan kalimat: ");
  fgets(kalimat, sizeof(kalimat), stdin);

  for (int i = 0; kalimat[i] != '\0'; i++) {
    if (islower(kalimat[i])) {
      jumlahHurufKecil++;
    } else if (isupper(kalimat[i])) {
      jumlahHurufKapital++;
    }
  }

  printf("Jumlah huruf kecil: %d\n", jumlahHurufKecil);
  printf("Jumlah huruf kapital: %d\n", jumlahHurufKapital);

  return 0;
}
