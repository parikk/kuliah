#include <stdio.h>
#include <string.h>

int main() {
  char kalimat[256];
  int i, j;

  printf("Masukkan kalimat: ");
  fgets(kalimat, sizeof(kalimat), stdin);

  kalimat[strcspn(kalimat, "\n")] = '\0';

  for (i = 0, j = 0; kalimat[i] != '\0'; i++) {
    if (kalimat[i] == ' ') {
      kalimat[i] = '\0';
      printf("%s\n", &kalimat[j]);
      j = i + 1;
    }
  }

  printf("%s\n", &kalimat[j]);

  return 0;
}
