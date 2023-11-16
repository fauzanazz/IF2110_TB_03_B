#ifndef UTAS_H
#define UTAS_H

#include "../Kicauan/kicauan.h"

typedef struct nodeUtas* AddressUtas;
typedef struct node { //Id Kicau -1
    Kicau_struct info;
    AddressUtas next;
} NodeUtas;

typedef struct{ // Linked List
    int id_kicauan;
    AddressUtas *Kicau_struct;
    int neff;
}  ListUtas;

typedef struct{ // List Dinamis
    ListUtas *ListuUtas;
    int neff;
    int capacity;
} ListKicauanUtas;

#define ELMTUtas(L,i) (L).ListUtas[(i)]
#define LISTUTAS(L) (L).ListUtas
#define NEFFUtas(L) (L).neff
#define CAPACITYUtas(L) (L).capacity
#define INFOUtas(U) (U)->info
#define NEXTUtas(U) (U)->next

void CreateListUtas(ListUtas *l, int capacity);
void dealocateListUtas(ListUtas *l);
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lisUtastLength(ListUtas l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
int getFirstIdxUtas(ListUtas l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
int getLastIdxUtas(ListUtas l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxUtasValid(ListUtas l, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxUtasEff(ListUtas l, int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListUtasEmpty(ListUtas l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isListUtasFull(ListUtas l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

void printListUtas(ListUtas l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERASI LAIN ********** */
void copyListUtas(ListUtas lIn, ListUtas *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 

/* ********** SORTING ********** */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListUtas(ListUtas *l, Kicau_struct val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastUtas(ListUtas *l, Kicau_struct *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListUtas(ListUtas *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListUtas(ListUtas *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressListUtas(ListUtas *l);
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */

void CreateUtas(AddressUtas *l);
/* I.S. sembarang             */
/* F.S. Terbentuk AddressUtas kosong */

/****************** TEST AddressUtas KOSONG ******************/
boolean isEmptyUtas(AddressUtas l);
/* Mengirim true jika AddressUtas kosong */

void insertLastUtas(AddressUtas *l, NodeUtas val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen AddressUtas di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void deleteAt(AddressUtas *l, int idx, NodeUtas *val);
/* I.S. AddressUtas tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA ELEMEN AddressUtas ******************/
void displayUtas(AddressUtas l);
// void printInfo(AddressUtas l);
/* I.S. LinkedList mungkin kosong */
/* F.S. Jika LinkedList tidak kosong, iai LinkedList dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika LinkedList kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

#endif