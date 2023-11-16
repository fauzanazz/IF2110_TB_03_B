#ifndef BALASAN_H
#define BALASAN_H

#include "../Mesin-Kata/wordmachine.h"
#include "../Time/datetime.h"
#include "../Tree/tree.h"
#include "../pengguna/pengguna.h"
#include "../kicauan/kicauan.h"
#include "../Teman/teman.h"
#include <time.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct
{
    int IDKicauan;
    int IDBalasan;
    Word TextBalasan;
    Word Author;
    DATETIME DT;
} BALASAN;

/* ********** SELEKTOR BALASAN ********** */
#define IDKicauan(l) (l).IDKicauan
#define IDBalasan(l) (l).IDBalasan
#define TxtBalasan(l) (l).TextBalasan
#define AuthorBalasan(l) (l).Author
#define DatetimeBalasan(l) (l).DT

typedef struct 
{
    int IDKicau;
    BALASAN *contentBalasan;
    int capacitybalasan;
    int nEffBalasan;
} ListDinBalasan;

/* ********** SELEKTOR List Dinamis BALASAN ********** */
#define IDKicauB(l) (l).IDKicau
#define ELMTBalasan(l, i) (l).contentBalasan[i]
#define ContentBalasan(l) (l).contentBalasan
#define NEFFBalasan(l) (l).nEffBalasan
#define CAPACITYBalasan(l) (l).capacitybalasan

typedef struct {
    ListDinBalasan *contentList;
    int capacityList;
    int nEffList;
} ListDinListB;

/************ Selektor List Dinamis ************/
#define ELMTListB(l, i) (l).contentList[i]
#define ContentListB(l) (l).contentList
#define NEFFListB(l) (l).nEffList
#define CAPACITYListB(l) (l).capacityList

/* ********** KONSTRUKTOR ListBalasan ********** */
/* Konstruktor : create list kosong  */
void CreateListBalasan(ListDinBalasan *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi BALASAN */

void dealocateBalasan(ListDinBalasan *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

void addBalasanConfig(ListDinBalasan *l, BALASAN B);
/* I.S. l berisi kicauan, mungkin penuh */
/* F.S. l diisi balasan baru nEffBalasan bertambah 1, capacity balasan menyesuaikan*/

/* ********** KONSTRUKTOR ListDinBalasan ********** */
/* Konstruktor : create list kosong  */
void CreateListDinB(ListDinListB *lb, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi ListBalasan */

void dealocateListDinB(ListDinListB *lb);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

void loadBalasanConfig(char filename[], ListDinListB *lb);
/* I.S. l kosong; */
/* F.S. l diisi sesuai config */

ListDinBalasan getListDinBalasan(ListDinListB *lb, int IDKicauan);

BALASAN getBalasan(ListDinListB *lb, int IDKicauan, int IDBalasan);

/* ********** BOOLEAN ********** */
boolean isFullBalasan(ListDinBalasan l);
/* return true jika penuh */

boolean isFullListDinB(ListDinListB l);
/* return true jika penuh */

/* ********** FUNGSI LAIN ********** */

void printBalasan(BALASAN B);

void displayBalasan(ListDinBalasan B);

void displayListB(ListDinListB lb);

int wordToInt(Word kata);

#endif