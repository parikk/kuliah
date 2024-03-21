#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_PARTICIPANTS 100

struct Participant {
    char name[50];
    float ropeLength;
    float angle;
    float height;
};

float calculateHeight(float ropeLength, float angle) {
    float radians = angle * PI / 180;
    return ropeLength * sin(radians);
}

void addParticipant(struct Participant participants[], int *count) {
    if (*count >= MAX_PARTICIPANTS) {
        printf("Jumlah peserta telah mencapai batas maksimum.\n");
        return;
    }

    struct Participant newParticipant;

    printf("Masukkan nama peserta: ");
    scanf("%s", newParticipant.name);
    printf("Masukkan panjang tali yang terulur (meter): ");
    scanf("%f", &newParticipant.ropeLength);
    printf("Masukkan sudut elevasi tali dengan tanah (derajat): ");
    scanf("%f", &newParticipant.angle);

    newParticipant.height = calculateHeight(newParticipant.ropeLength, newParticipant.angle);

    participants[*count] = newParticipant;
    (*count)++;

    printf("Data peserta telah ditambahkan.\n");
}

void searchParticipant(struct Participant participants[], int count, char *name) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(participants[i].name, name) == 0) {
            printf("Data Peserta:\n");
            printf("Nama: %s\n", participants[i].name);
            printf("Tinggi Layangan: %.2f meter\n", participants[i].height);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Data peserta dengan nama '%s' tidak ditemukan.\n", name);
    }
}

void displayParticipants(struct Participant participants[], int count) {
    printf("Daftar Peserta dan Tinggi Layangan:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Nama: %s, Tinggi Layangan: %.2f meter\n", i + 1, participants[i].name, participants[i].height);
    }
}

void determineWinner(struct Participant participants[], int count) {
    if (count == 0) {
        printf("Tidak ada peserta yang terdaftar.\n");
        return;
    }

    struct Participant winner = participants[0];
    for (int i = 1; i < count; i++) {
        if (participants[i].height > winner.height) {
            winner = participants[i];
        }
    }

    printf("Pemenang Lomba:\n");
    printf("Nama: %s, Tinggi Layangan: %.2f meter\n", winner.name, winner.height);
}

int main() {
    struct Participant participants[MAX_PARTICIPANTS];
    int count = 0;
    int choice;
    char searchName[50];

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Peserta\n");
        printf("2. Cari Peserta\n");
        printf("3. Tampilkan Semua Peserta\n");
        printf("4. Tentukan Pemenang\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addParticipant(participants, &count);
                break;
            case 2:
                printf("Masukkan nama peserta yang ingin dicari: ");
                scanf("%s", searchName);
                searchParticipant(participants, count, searchName);
                break;
            case 3:
                displayParticipants(participants, count);
                break;
            case 4:
                determineWinner(participants, count);
                break;
            case 5:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 5);

    return 0;
}
