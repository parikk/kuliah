#include <stdio.h>
#include <string.h>

struct Buku {
    char judul[100];
    char pengarang[100];
    int jumlahHalaman;
    char penerbit[100];
    int tahunTerbit;
};

int main() {
    struct Buku daftarBuku;

    strcpy(daftarBuku.judul, "Judul Buku 1");
    strcpy(daftarBuku.pengarang, "Pengarang Buku 1");
    daftarBuku.jumlahHalaman = 200;
    strcpy(daftarBuku.penerbit, "Penerbit Buku 1");
    daftarBuku.tahunTerbit = 2020;

    printf("Judul: %s\n", daftarBuku.judul);
    printf("Pengarang: %s\n", daftarBuku.pengarang);
    printf("Jumlah Halaman: %d\n", daftarBuku.jumlahHalaman);
    printf("Penerbit: %s\n", daftarBuku.penerbit);
    printf("Tahun Terbit: %d\n", daftarBuku.tahunTerbit);

    return 0;
}
