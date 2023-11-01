#include <stdio.h>
#include "../boolean.h"
#include "graf.h"

/* *** Konstruktor *** */
void CreateVertex(vertex *V, int uid){
/* I.S. uid */
/* F.S. Terbentuk vertex V yang berisi UserID uid dan idxAdjMtx -1 */
    USERID(*V) = uid;
    IDX(*V) = -1;

}

void CreateGraf(Graf *G){
/* I.S. sembarang; */
/* F.S. Membuat sebuah graf G yang kosong berkapasitas MaxEl */
    NEFF(*G) = 0;
}

/* ************ Cek Kondisi Graf ************ */
boolean IsGrafEmpty(Graf G){
/* Mengirim true jika adjacency matrix kosong */
    return (NEFF(G) == 0);
}

boolean IsGrafFull(Graf G){
/* Mengirim true jika adjacency matrix penuh */
    return (NEFF(G) == MaxEl);
}

/* ************ Fungsi Primitif Graf ************ */
void addVertex(Graf *G, vertex *V){
/* I.S. Graf G terdefinisi, mungkin kosong */
/* F.S. Menambahkan sebuah vertex V pada graf G */
    int i, j, idx;
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
    ELMTG(*G, IDX(V1), IDX(V2)) = 1;
    ELMTG(*G, IDX(V2), IDX(V1)) = 1;
}

void removeVertex(Graf *G, vertex *V){
/* I.S. Graf G terdefinisi dan vertex V ada pada graf G */
/* F.S. Menghapus vertex V dari Graf G, elemen adjacency matrix diubah menjadi Nil */
    NEFF(*G) = NEFF(*G);
/* Belum/Tidak diimplementasikan karena tidak berguna dalam tubes ini */
}

void removeEdge(Graf *G, vertex V1, vertex V2){
/* I.S. Graf G terdefinisi dan vertex V1 dan V2 berhubungan (memiliki edge) */
/* F.S. Edge vertex V1 dan V2 dihapus, elemen adjacency matrix berubah (1 -> 0) */
    ELMTG(*G, IDX(V1), IDX(V2)) = 0;
    ELMTG(*G, IDX(V2), IDX(V1)) = 0;
}

boolean isVertexInGraf(Graf G, vertex V){
/* Mengembalikan true jika vertex V berada di Graf G, false jika tidak */
    return (IDX(V) < NEFF(G));
}

boolean isConnected(Graf G, vertex V1, vertex V2){
/* Mengembalikan true jika  V1 dan V2 memiliki edge */
    return (ELMTG(G, IDX(V1), IDX(V2)) == 1);
}

void displayGraf(Graf G){
/* I.S. G tidak kosong*/
/* F.S. Menampilkan Graf G dengan representasi adjacency matrix pada layar */
    int i, j, neff;
    neff = NEFF(G);
    for (i = 0; i < neff; i++){
        for (j = 0; j < neff; j++){
            printf("%d ", ELMTG(G, i, j));
        }
        printf("\n");
    }
}