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
    struct Buku daftarBuku[5];

    strcpy(daftarBuku[0].judul, "Judul Buku 1");
    strcpy(daftarBuku[0].pengarang, "Pengarang Buku 1");
    daftarBuku[0].jumlahHalaman = 201;
    strcpy(daftarBuku[0].penerbit, "Penerbit Buku 1");
    daftarBuku[0].tahunTerbit = 2021;

    strcpy(daftarBuku[1].judul, "Judul Buku 2");
    strcpy(daftarBuku[1].pengarang, "Pengarang Buku 2");
    daftarBuku[1].jumlahHalaman = 202;
    strcpy(daftarBuku[1].penerbit, "Penerbit Buku 2");
    daftarBuku[1].tahunTerbit = 2022;

    strcpy(daftarBuku[2].judul, "Judul Buku 3");
    strcpy(daftarBuku[2].pengarang, "Pengarang Buku 3");
    daftarBuku[2].jumlahHalaman = 203;
    strcpy(daftarBuku[2].penerbit, "Penerbit Buku 3");
    daftarBuku[2].tahunTerbit = 2023;

    strcpy(daftarBuku[3].judul, "Judul Buku 4");
    strcpy(daftarBuku[3].pengarang, "Pengarang Buku 4");
    daftarBuku[3].jumlahHalaman = 204;
    strcpy(daftarBuku[3].penerbit, "Penerbit Buku 4");
    daftarBuku[3].tahunTerbit = 2024;

    strcpy(daftarBuku[4].judul, "Judul Buku 5");
    strcpy(daftarBuku[4].pengarang, "Pengarang Buku 5");
    daftarBuku[4].jumlahHalaman = 200;
    strcpy(daftarBuku[4].penerbit, "Penerbit Buku 5");
    daftarBuku[4].tahunTerbit = 2020;

    for (int i = 0; i < 5; i++) {
        printf("Judul: %s\n", daftarBuku[i].judul);
        printf("Pengarang: %s\n", daftarBuku[i].pengarang);
        printf("Jumlah Halaman: %d\n", daftarBuku[i].jumlahHalaman);
        printf("Penerbit: %s\n", daftarBuku[i].penerbit);
        printf("Tahun Terbit: %d\n", daftarBuku[i].tahunTerbit);
        printf("\n");
    }

    return 0;
}
