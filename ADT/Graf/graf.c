#include <stdio.h>
#include "../boolean.h"
#include "graf.h"

/* *** Konstruktor *** */
void CreateVertex(vertex *V, int uid){
/* I.S. uid */
/* F.S. Terbentuk vertex V yang berisi UserID uid dan idxAdjMtx -1 */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    USERID(*V) = uid;
    IDX(*V) = -1;
}

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
void addVertex(Graf *G, vertex *V){
/* I.S. Graf G terdefinisi, mungkin kosong */
/* F.S. Menambahkan sebuah vertex V pada graf G */

    /* KAMUS LOKAL */
    int i, j, idx;

    /* ALGORITMA */
    idx = NEFF(*G);
    IDX(*V) = idx;
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

void addEdge(Graf *G, vertex V1, vertex V2){
/* I.S. Graf G terdefinisi, V1 dan V2 adalah vertex yang valid pada Graf */
/* F.S. Menghubungkan V1 dan V2 dengan penambahan edge, elemen adjacency matrix berubah (0 -> 1) */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    ELMTG(*G, IDX(V1), IDX(V2)) = 1;
    ELMTG(*G, IDX(V2), IDX(V1)) = 1;
}

void removeEdge(Graf *G, vertex V1, vertex V2){
/* I.S. Graf G terdefinisi dan vertex V1 dan V2 berhubungan (memiliki edge) */
/* F.S. Edge vertex V1 dan V2 dihapus, elemen adjacency matrix berubah (1 -> 0) */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    ELMTG(*G, IDX(V1), IDX(V2)) = 0;
    ELMTG(*G, IDX(V2), IDX(V1)) = 0;
}

boolean isVertexInGraf(Graf G, vertex V){
/* Mengembalikan true jika vertex V berada di Graf G, false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (IDX(V) < NEFF(G));
}

boolean isConnected(Graf G, vertex V1, vertex V2){
/* Mengembalikan true jika  V1 dan V2 memiliki edge */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (ELMTG(G, IDX(V1), IDX(V2)) == 1);
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