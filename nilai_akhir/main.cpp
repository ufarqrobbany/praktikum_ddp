/*
  Program : Menghitung nilai akhir matakuliah DDP dan predikatnya
  Author : 231524028 Umar Faruq Robbany
  Tanggal : 16 November 2023
  I.S. : Belum diketahui nilai akhir dan predikat
  F.S. : menghitung nilai total akhir mata kuliah DDP dari komponen penilaian (ets, eas dan quiz).
         Setiap komponen penilaian memiliki bobot:
         - bobot ets : 35%
         - bobot eas : 40%
         - bobot quiz : 25%
         Nilai total akhir adalah jumlah bobot dikali tiap komponen nilai
         Nilai total akhir akan dikonversikan kedalam sebuah huruf mutu atau disebut predikat.
         Aturan konversi nilai ke predikat adalah
           A  (80 - 100), AB (75 - 79,9), B  (70 - 74,9), BC (65 - 79,9), C (60 - 64,9),
       CD (55 - 59,9), D  (40 - 54,9), E (< 40)

  Goal Praktikum :
  1. Bisa mendeklarasikan variabel struct
  2. Bisa memberi nilai pada variabel struct
  3. Bisa mendefinisikan konstanta variabel global (bobot)
  4. Bisa membuat fungsi dgn paramater struct
  5. Bisa memanggil fungsi dgn passing paramater bertipe struct.
  6. Paham menggunakan struct
*/

#include <stdio.h>
#include <stdlib.h>

#include "mahasiswa.h"

int main() {
    // deklarasi variabel array mhs bertipe Mahasiswa dan variabel jmlMhs bertipe integer
    Mahasiswa mhs[100];
    int jmlMhs;

    // file manipulation
    // FILE *DATA;
    // char CC;

    // DATA = fopen("data.txt", "r");

    // if(!DATA) {
    //     printf("Tidak ada file.\n");
    // } else {
    //     while(!feof(DATA)) {
    //         fscanf(DATA, "%[^#]#%d\n")
    //     }
    // }

    // tambahkan data mahasiswa
    jmlMhs = 2;

    mhs[0].nama = "Akhmad";
    mhs[0].nim = "101010";
    mhs[0].ets = 80;
    mhs[0].eas = 90;
    mhs[0].kuis = 85;

    mhs[1].nama = "Umar Faruq Robbany";
    mhs[1].nim = "231524028";
    mhs[1].ets = 87;
    mhs[1].eas = 90;
    mhs[1].kuis = 65;

    // panggil fungsi get_total dan get_predicate, kemudian simpan nilai ke data mahasiswa
    for (int i = 0; i < jmlMhs; i++) {
        mhs[i].total = get_total(mhs[i].ets, mhs[i].eas, mhs[i].kuis);
        mhs[i].predikat = get_predicate(mhs[i].total);
    }

    // tampilkan data mahasiswa
    displayDataMhs(mhs, jmlMhs);

    // panggil procedure aksiDataMhs
    do {
        aksiDataMhs(&mhs, &jmlMhs);
    } while (true);

    return 0;
}