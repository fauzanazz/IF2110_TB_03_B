/* deklarasi Graf yang diimplementasi dengan adjacency matrix */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef GRAF_H
#define GRAF_H

#include "boolean.h"

#define Nil -1 /* isi adjacency matrix belum terdefinisi */
#define MaxEl 20 /* verteks maksimum graf 20 */
/* Nil adalah stack dengan elemen kosong . */

typedef int ElType; /* isi adjacency matrix (0 atau 1)*/
/* tipe data bentukan vertex */
typedef struct {
  int UserID; /* id user */
  int idxAdjMtx; /* index yang merepresentasikan UID pada adjacency matrix */
} vertex;

/* tipe data bentukan Graf */
typedef struct { 
  ElType mat[MaxEl][MaxEl]; /* adjacency matrix */
  int NEff;
} Graf;
/* Definisi Graf G kosong : G.Neff = Nil */
/* ElType M.mat[i][j]: bernilai 0 jika i tidak berhubungan dengan j, bernilai 1 jika i berhubungan dengan j, bernilai -1 jika i atau j belum terdefinisi */

/* Definisi akses dengan Selektor : Set dan Get */
#define USERID(V) (V).UserID
#define IDX(V) (V).idxAdjMtx
#define NEFF(G) (G).NEff
#define ELMT(G, i, j) (G).mat[(i)][(j)]

/* *** Konstruktor *** */
void CreateVertex(vertex *V, int uid, int idx);
/* I.S. uid dan idx bernilai valid */
/* F.S. Terbentuk vertex V yang berisi UserID uid dan idxAdjMtx idx */

void CreateGraf(Graf *G);
/* I.S. sembarang; */
/* F.S. Membuat sebuah graf G yang kosong berkapasitas MaxEl yang berisi Nil */

/* ************ Cek Kondisi Graf ************ */
boolean IsGrafEmpty(Graf G);
/* Mengirim true jika adjacency matrix kosong */

boolean IsGrafFull(Graf G);
/* Mengirim true jika adjacency matrix penuh */

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

#endif