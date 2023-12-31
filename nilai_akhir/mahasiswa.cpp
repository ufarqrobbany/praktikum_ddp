#include "mahasiswa.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// procedure input data mahasiswa
void addDataMhs(Mahasiswa (*mhs)[100], int *jmlMhs) {
    int tambah, jmlMhsSebelumnya;
    jmlMhsSebelumnya = *jmlMhs;

    printf("\nTambah berapa mahasiswa? ");
    scanf("%d", &tambah);

    *jmlMhs += tambah;

    for (int i = jmlMhsSebelumnya; i < *jmlMhs; i++) {
        (*mhs)[i].nama = (const char *)malloc(50 * sizeof(char));
        (*mhs)[i].nim = (const char *)malloc(20 * sizeof(char));

        printf("\n");
        printf("Mahasiswa %d \n", (i + 1));
        printf("Nama\t: ");
        scanf(" %49[^\n]", (char *)(*mhs)[i].nama);
        printf("NIM\t: ");
        scanf(" %19[^\n]", (char *)(*mhs)[i].nim);
        printf("ETS\t: ");
        scanf("%f", &(*mhs)[i].ets);
        printf("EAS\t: ");
        scanf("%f", &(*mhs)[i].eas);
        printf("Kuis\t: ");
        scanf("%f", &(*mhs)[i].kuis);

        (*mhs)[i].total = get_total((*mhs)[i].ets, (*mhs)[i].eas, (*mhs)[i].kuis);
        (*mhs)[i].predikat = get_predicate((*mhs)[i].total);
    }

    displayDataMhs(*mhs, *jmlMhs);
}

// function menghitung total nilai mahasiswa
float get_total(float nilaiEts, float nilaiEas, float nilaiKuis) {
    float ets, eas, kuis, total;
    ets = nilaiEts * BOBOT_ETS;
    eas = nilaiEas * BOBOT_EAS;
    kuis = nilaiKuis * BOBOT_KUIS;
    total = ets + eas + kuis;
    return total;
}

// function menentukan predikat nilai mahasiswa
const char *get_predicate(float total) {
    const char *predikat;

    if (total >= 80 && total <= 100) {
        predikat = "A";
    } else if (total >= 75) {
        predikat = "AB";
    } else if (total >= 70) {
        predikat = "B";
    } else if (total >= 65) {
        predikat = "BC";
    } else if (total >= 60) {
        predikat = "C";
    } else if (total >= 55) {
        predikat = "CD";
    } else if (total >= 40) {
        predikat = "D";
    } else {
        predikat = "E";
    }

    return predikat;
}

// procedure untuk memilih aksi yang akan dilakukan pada data mahasiswa
void aksiDataMhs(Mahasiswa (*mhs)[100], int *jmlMhs) {
    int opsi;

    printf("\nPilih Aksi \n");
    printf(" 1. Urutkan data\n");
    printf(" 2. Tambahkan data\n");
    do {
        printf("Pilih: ");
        scanf("%d", &opsi);
        switch (opsi) {
            case 1:
                opsiSortingDataMhs(&(*mhs), *jmlMhs);
                break;
            case 2:
                addDataMhs(&(*mhs), &(*jmlMhs));
                break;
            default:
                printf("Opsi tidak valid\n");
        }
    } while (opsi < 1 || opsi > 2);
}

// procedure menampilkan semua data mahasiswa dalam bentuk tabel
void displayDataMhs(Mahasiswa mhs[100], int jmlMhs) {
    printf("\n\nData Mahasiswa\n");
    printf("+------+--------------------------------+------------+--------+--------+--------+--------+------------+\n");
    printf("| %-4s | %-30s | %-10s | %-6s | %-6s | %-6s | %-6s | %-10s |\n", "No.", "Nama", "NIM", "ETS", "EAS", "Kuis", "Total", "Predikat");
    printf("+------+--------------------------------+------------+--------+--------+--------+--------+------------+\n");
    for (int i = 0; i < jmlMhs; i++) {
        printf("| %-4d | %-30s | %-10s | %-6.2f | %-6.2f | %-6.2f | %-6.2f | %-10s |\n", i + 1, mhs[i].nama, mhs[i].nim, mhs[i].ets, mhs[i].eas, mhs[i].kuis, mhs[i].total, mhs[i].predikat);
    }
    printf("+------+--------------------------------+------------+--------+--------+--------+--------+------------+\n");
}

// procedure untuk memilih bagaimana data mahasiswa diurutkan
void opsiSortingDataMhs(Mahasiswa (*mhs)[100], int jmlMhs) {
    int sortBy, order;

    printf("\nUrutkan data mahasiswa berdasarkan: \n");
    printf(" 1. Nama\n");
    printf(" 2. NIM\n");
    printf(" 3. ETS\n");
    printf(" 4. EAS\n");
    printf(" 5. Kuis\n");
    printf(" 6. Total\n");
    do {
        printf("Pilih: ");
        scanf("%d", &sortBy);
        if (sortBy < 1 || sortBy > 6) {
            printf("Opsi tidak valid\n");
        }
    } while (sortBy < 1 || sortBy > 6);

    printf("\nBagaimana urutannya? \n");
    printf(" 1. Ascending\n");
    printf(" 2. Descending\n");
    do {
        printf("Pilih: ");
        scanf("%d", &order);
        if (order == 1 || order == 2) {
            sortDataMhs(&(*mhs), jmlMhs, sortBy, order);
            displayDataMhs(*mhs, jmlMhs);
        } else {
            printf("Opsi tidak valid\n");
        }
    } while (order != 1 && order != 2);
}

// procedure sorting data mahasiswa
void sortDataMhs(Mahasiswa (*mhs)[100], int jmlMhs, int sortBy, int order) {
    int i, j;
    Mahasiswa key, mhstemp;

    for (i = 1; i < jmlMhs; i++) {
        key = (*mhs)[i];
        mhstemp = (*mhs)[i];
        j = i - 1;

        switch (sortBy) {
            case 1:
                if (order == 1) {
                    while (j >= 0 && strcmp((*mhs)[j].nama, key.nama) > 0) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                } else if (order == 2) {
                    while (j >= 0 && strcmp((*mhs)[j].nama, key.nama) < 0) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                }
                break;

            case 2:
                if (order == 1) {
                    while (j >= 0 && strcmp((*mhs)[j].nim, key.nim) > 0) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                } else if (order == 2) {
                    while (j >= 0 && strcmp((*mhs)[j].nim, key.nim) < 0) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                }
                break;

            case 3:
                if (order == 1) {
                    while (j >= 0 && (*mhs)[j].ets > key.ets) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                } else if (order == 2) {
                    while (j >= 0 && (*mhs)[j].ets < key.ets) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                }
                break;

            case 4:
                if (order == 1) {
                    while (j >= 0 && (*mhs)[j].eas > key.eas) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                } else if (order == 2) {
                    while (j >= 0 && (*mhs)[j].eas < key.eas) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                }
                break;

            case 5:
                if (order == 1) {
                    while (j >= 0 && (*mhs)[j].kuis > key.kuis) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                } else if (order == 2) {
                    while (j >= 0 && (*mhs)[j].kuis < key.kuis) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                }
                break;

            case 6:
                if (order == 1) {
                    while (j >= 0 && (*mhs)[j].total > key.total) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                } else if (order == 2) {
                    while (j >= 0 && (*mhs)[j].total < key.total) {
                        (*mhs)[j + 1] = (*mhs)[j];
                        j = j - 1;
                    }
                }
                break;
        }

        (*mhs)[j + 1] = mhstemp;
    }
}
