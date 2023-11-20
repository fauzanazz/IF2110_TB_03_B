/* File : LinkedList.h */
/* contoh ADT LinkedList berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#ifndef LinkedList_H
#define LinkedList_H

#include "../boolean.h"
#include "../Kicauan/kicauan.h"

/* Definisi Node : */
typedef Kicau_struct ElType;
typedef struct node* Address;
typedef struct node {
    ElType info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNodeLiList(ElType val);

/* Definisi LinkedList : */
/* LinkedList kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir LinkedList: jika addressnya Last, maka NEXT(Last)=NULL */

typedef Address LinkedList;

#define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LinkedList KOSONG ******************/
void CreateLinkedList(LinkedList *l);
/* I.S. sembarang             */
/* F.S. Terbentuk LinkedList kosong */

/****************** TEST LinkedList KOSONG ******************/
boolean isEmpty(LinkedList l);
/* Mengirim true jika LinkedList kosong */

int LengthLinkedList(LinkedList l);

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(LinkedList *l, ElType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(LinkedList *l, ElType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen LinkedList di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(LinkedList *l, ElType val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam LinkedList pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(LinkedList *l, ElType *val);
/* I.S. LinkedList l tidak kosong  */
/* F.S. Elemen pertama LinkedList dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(LinkedList *l, ElType *val);
/* I.S. LinkedList tidak kosong */
/* F.S. Elemen terakhir LinkedList dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(LinkedList *l, int idx, ElType *val);
/* I.S. LinkedList tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LinkedList ******************/
void displayLinkedList(LinkedList l);
// void printInfo(LinkedList l);
/* I.S. LinkedList mungkin kosong */
/* F.S. Jika LinkedList tidak kosong, iai LinkedList dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika LinkedList kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

#endif
