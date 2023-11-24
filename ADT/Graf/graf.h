/* Deklarasi Graf yang diimplementasi dengan adjacency matrix */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef GRAF_H
#define GRAF_H

#include "../boolean.h"

#define Nil -1
#define MaxEl 20 /* verteks maksimum graf 20 */
/* Nil adalah stack dengan elemen kosong . */

typedef int ElType; /* isi adjacency matrix (0 atau 1)*/

/* tipe data bentukan Graf */
typedef struct { 
  ElType mat[MaxEl][MaxEl]; /* adjacency matrix */
  int NEff;
} Graf;
/* Definisi Graf G kosong : G.Neff = Nil */
/* ElType M.mat[i][j]: bernilai 0 jika i tidak berhubungan dengan j, bernilai 1 jika i berhubungan dengan j */

/* Definisi akses dengan Selektor : Set dan Get */
#define NEFF(G) (G).NEff
#define ELMTG(G, i, j) (G).mat[(i)][(j)]

/* *** Konstruktor *** */
void CreateGraf(Graf *G);
/* I.S. sembarang; */
/* F.S. Membuat sebuah graf G yang kosong berkapasitas MaxEl */

/* ************ Cek Kondisi Graf ************ */
boolean IsGrafEmpty(Graf G);
/* Mengirim true jika adjacency matrix kosong */

boolean IsGrafFull(Graf G);
/* Mengirim true jika adjacency matrix penuh */

/* ************ Fungsi Primitif Graf ************ */
void addVertex(Graf *G, int UID);
/* I.S. Graf G terdefinisi, mungkin kosong */
/* F.S. Menambahkan sebuah vertex yang mewakili pengguna dengan user id UID pada graf G */

void addEdge(Graf *G, int UID1, int UID2);
/* I.S. Graf G terdefinisi, UID1 dan UID2 adalah user id yang valid */
/* F.S. Menghubungkan UID1 dan UID2 dengan penambahan edge, elemen adjacency matrix berubah (0 -> 1) */

void removeEdge(Graf *G, int UID1, int UID2);
/* I.S. Graf G terdefinisi serta UID1 dan UID2 berhubungan (memiliki edge) */
/* F.S. Edge vertex yang mewakili UID1 dan UID2 dihapus, elemen adjacency matrix berubah (1 -> 0) */

boolean isConnected(Graf G, int UID1, int UID2);
/* Mengembalikan true jika vertex yang mewakili UID1 dan UID2 memiliki edge */

void displayGraf(Graf G);
/* I.S. G tidak kosong*/
/* F.S. Menampilkan Graf G dengan representasi adjacency matrix pada layar */

#endif