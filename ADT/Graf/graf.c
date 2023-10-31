#include <stdio.h>
#include "boolean.h"
#include "graf.h"

/* *** Konstruktor *** */
void CreateVertex(vertex *V, int uid, int idx){
    USERID(*V) = uid;
    IDX(*V) = idx;
/* I.S. uid dan idx bernilai valid */
/* F.S. Terbentuk vertex V yang berisi UserID uid dan idxAdjMtx idx */
}

void CreateGraf(Graf *G){
    int i, j;
    for (i = 0; i < MaxEl; i++){
        for (j = 0; j < MaxEl; j++){
            ELMT(*G, i, j) = Nil;
        }
    }
    NEFF(*G) = 0;
/* I.S. sembarang; */
/* F.S. Membuat sebuah graf G yang kosong berkapasitas MaxEl yang berisi Nil */
}

/* ************ Cek Kondisi Graf ************ */
boolean IsGrafEmpty(Graf G){
    return (NEFF(G) == 0);
/* Mengirim true jika adjacency matrix kosong */
}

boolean IsGrafFull(Graf G){
    return (NEFF(G) == MaxEl);
/* Mengirim true jika adjacency matrix penuh */
}

/* ************ Fungsi Primitif Graf ************ */
void addVertex(Graf *G, vertex *V, int ID);
/* I.S. Graf G terdefinisi, mungkin kosong */
/* F.S. Menambahkan sebuah vertex V pada graf G */

void addEdge(Graf *G, vertex V1, vertex V2);
/* I.S. Graf G terdefinisi, V1 dan V2 adalah vertex yang valid pada Graf */
/* F.S. Menghubungkan V1 dan V2 dengan penambahan edge, elemen adjacency matrix berubah (0 -> 1) */

void removeVertex(Graf *G, vertex *V);
/* I.S. Graf G terdefinisi dan vertex V ada pada graf G */
/* F.S. Menghapus vertex V dari Graf G, elemen adjacency matrix diubah menjadi Nil */

void removeEdge(Graf *G, vertex V1, vertex V2);
/* I.S. Graf G terdefinisi dan vertex V1 dan V2 berhubungan (memiliki edge) */
/* F.S. Edge vertex V1 dan V2 dihapus, elemen adjacency matrix berubah (1 -> 0) */

boolean isVertexInGraf(Graf G, vertex V);
/* Mengembalikan true jika vertex V berada di Graf G, false jika tidak */

boolean isConnected(Graf G, vertex V1, vertex V2);
/* Mengembalikan true jika  V1 dan V2 memiliki edge */

void displayGraf(Graf G);
/* I.S. G tidak kosong*/
/* F.S. Menampilkan Graf G dengan representasi adjacency matrix pada layar */