#include "listvertex.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListVertex(ListVertex *lv){
/* I.S. l sembarang */
/* F.S. Terbentuk List Vertex lv kosong dengan kapasitas CAPACITY, nEff bernilai 0 */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    NEFFLV(*lv) = 0;

}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isLVEmpty(ListVertex lv){
/* Mengirimkan true jika List Vertex lv kosong, mengirimkan false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (NEFFLV(lv) == 0);

}
/* *** Test List penuh *** */
boolean isLVFull(ListVertex lv){
/* Mengirimkan true jika List Vertex lv penuh, mengirimkan false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (NEFFLV(lv) == CAPACITYLV);

}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListVertex *lv, vertex V){
/* Proses: Menambahkan vertex V sebagai elemen terakhir List Vertex lv, nilai efektif bertambah 1 */
/* I.S. ListVertex lv boleh kosong, tetapi tidak penuh */
/* F.S. V adalah elemen terakhir lv yang baru */

    /* KAMUS LOKAL */
    int idxInsert;

    /* ALGORITMA */
    idxInsert = NEFFLV(*lv);
    VTX((*lv), idxInsert) = V;
    NEFFLV(*lv)++;
}

/* ********** ADDITIONAL PROCEDURE/FUNCTION ********** */
vertex vertexWithIDX(ListVertex lv, int idx){
/* Mengembalikan vertex pada List Vertex lv yang berisi index idx pada adjacency matrix Graf */

    /* KAMUS LOKAL */
    int i, length;

    /* ALGORITMA */
    length = NEFFLV(lv);
    for (i = 0; i < length; i++){
        if (IDXGLV(lv, i) == idx){
            return VTX(lv, i);
        }
    }

    return VTX(lv, i);

}