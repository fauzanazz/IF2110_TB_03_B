/* list vertex dengan alokasi memori statik */
/* Penempatan elemen selalu rapat kiri */

#ifndef LISTVERTEX_H
#define LISTVERTEX_H

#include "../boolean.h"
#include "../Graf/graf.h"

/*  Kamus Umum */
#define CAPACITYLV 20
/* Kapasitas penyimpanan, maksimal 20 karena maksimal 20 user */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct {
   vertex contents[CAPACITYLV]; /* list penyimpanan vertex */
   int nEff; /* nilai efektif list */
} ListVertex;
/* Indeks yang digunakan [0..CAPACITYLV-1] */
/* Definisi : 
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define VTX(lv, i) (lv).contents[(i)]
#define NEFFLV(lv) (lv).nEff
#define UIDLV(lv, i) USERID((lv).contents[(i)])
#define IDXGLV(lv, i) IDX((lv).contents[(i)])
/* Akses elemen list vertex : */
/* VTX(l, i) mengakses vertex pada list vertex dengan indeks i */
/* NEFFLV(lv) mengakses nilai efektif list vertex */
/* UIDLV(l, i) mengakses UID vertex pada list vertex l indeks i */
/* IDXGLV(l, i) mengakses index vertex di graf pada list vertex l indeks i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListVertex(ListVertex *lv);
/* I.S. l sembarang */
/* F.S. Terbentuk List Vertex lv kosong dengan kapasitas CAPACITYLV, nEff bernilai 0 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isLVEmpty(ListVertex lv);
/* Mengirimkan true jika List Vertex lv kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isLVFull(ListVertex lv);
/* Mengirimkan true jika List Vertex lv penuh, mengirimkan false jika tidak */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListVertex *lv, vertex V);
/* Proses: Menambahkan vertex V sebagai elemen terakhir List Vertex lv */
/* I.S. ListVertex lv boleh kosong, tetapi tidak penuh */
/* F.S. V adalah elemen terakhir lv yang baru */

/* ********** ADDITIONAL PROCEDURE/FUNCTION ********** */
vertex vertexWithIDX(ListVertex lv, int idx);
/* Mengembalikan vertex pada List Vertex lv yang berisi index idx pada adjacency matrix Graf */

#endif