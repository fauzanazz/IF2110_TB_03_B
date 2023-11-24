#include <stdio.h>
#include "../boolean.h"
#include "graf.h"

/* *** Konstruktor *** */
void CreateGraf(Graf *G){
/* I.S. sembarang; */
/* F.S. Membuat sebuah graf G yang kosong berkapasitas MaxEl */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    NEFF(*G) = 0;
}

/* ************ Cek Kondisi Graf ************ */
boolean IsGrafEmpty(Graf G){
/* Mengirim true jika adjacency matrix kosong */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (NEFF(G) == 0);
}

boolean IsGrafFull(Graf G){
/* Mengirim true jika adjacency matrix penuh */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (NEFF(G) == MaxEl);
}

/* ************ Fungsi Primitif Graf ************ */
void addVertex(Graf *G, int UID){
/* I.S. Graf G terdefinisi, mungkin kosong */
/* F.S. Menambahkan sebuah vertex yang mewakili pengguna dengan user id UID pada graf G */

    /* KAMUS LOKAL */
    int i, idx;

    /* ALGORITMA */
    idx = NEFF(*G);
    for (i = 0; i < idx + 1; i++){
        if (i != idx){
            ELMTG(*G, i, idx) = 0;
            ELMTG(*G, idx, i) = 0;
        } else {
            ELMTG(*G, i, idx) = 1;
        }
    }
    NEFF(*G) = NEFF(*G) + 1;
}

void addEdge(Graf *G, int UID1, int UID2){
/* I.S. Graf G terdefinisi, UID1 dan UID2 adalah user id yang valid */
/* F.S. Menghubungkan UID1 dan UID2 dengan penambahan edge, elemen adjacency matrix berubah (0 -> 1) */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    ELMTG(*G, UID1, UID2) = 1;
    ELMTG(*G, UID2, UID1) = 1;
}

void removeEdge(Graf *G, int UID1, int UID2){
/* I.S. Graf G terdefinisi serta UID1 dan UID2 berhubungan (memiliki edge) */
/* F.S. Edge vertex yang mewakili UID1 dan UID2 dihapus, elemen adjacency matrix berubah (1 -> 0) */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    ELMTG(*G, UID1, UID2) = 0;
    ELMTG(*G, UID2, UID1) = 0;
}

boolean isConnected(Graf G, int UID1, int UID2){
/* Mengembalikan true jika vertex yang mewakili UID1 dan UID2 memiliki edge */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (ELMTG(G, UID1, UID2) == 1);
}

void displayGraf(Graf G){
/* I.S. G tidak kosong*/
/* F.S. Menampilkan Graf G dengan representasi adjacency matrix pada layar */

    /* KAMUS LOKAL */
    int i, j, neff;

    /* ALGORITMA */
    neff = NEFF(G);
    for (i = 0; i < neff; i++){
        for (j = 0; j < neff; j++){
            printf("%d ", ELMTG(G, i, j));
        }
        printf("\n");
    }
}