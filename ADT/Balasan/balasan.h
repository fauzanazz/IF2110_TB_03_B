#ifndef BALASAN_H
#define BALASAN_H

#include "../Mesin-Kata/wordmachine.h"
#include "../Time/datetime.h"
#include "../Pengguna/pengguna.h"
#include "../Kicauan/kicauan.h"
#include "../Teman/teman.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100;
/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/**
 * Struktur data untuk menyimpan informasi sebuah balasan.
 */
typedef struct {
    int ID_Target; // ID kicauan yang dibalas
    int ID_balasan; // ID balasan
    int ID_Author; // ID penulis balasan
    DATETIME DT; // Waktu balasan
    Word TextBalasan; // Teks balasan
} BalasanStruct;

/**
 * Struktur data untuk merepresentasikan sebuah node dalam pohon balasan.
 */
typedef struct Node {
    BalasanStruct key; // Data balasan
    int childCount; // Jumlah anak dari node
    struct Node** child; // Array pointer ke anak-anak node
} Node;

/**
 * Struktur data untuk merepresentasikan sebuah pohon balasan.
 */
typedef struct {
    int ID_Kicau; // ID kicauan
    Node* root; // Pointer ke akar pohon
} Tree;

/**
 * Struktur data untuk menyimpan daftar balasan.
 */
typedef struct {
    Tree *T; // Pointer ke pohon balasan
    int Neff; // Jumlah balasan dalam daftar
    int Capacity; // Kapasitas maksimum daftar
    int LastID; // ID terakhir dari balasan
} BalasanList;

/**
 * Struktur data untuk merepresentasikan sebuah antrian.
 */
typedef struct Queue {
    Node** items; // Array pointer ke item dalam antrian
    int front, rear, capacity; // Indeks depan, belakang, dan kapasitas antrian
} Queue;

/**
 * Membuat daftar balasan kosong.
 * @param listBalasan Pointer ke daftar balasan
 */
void CreateListBalasan(BalasanList *listBalasan);

/**
 * Mendealokasi memori yang digunakan oleh daftar balasan.
 * @param l Pointer ke daftar balasan
 */
void dealocateListBalasan(BalasanList *l);

/**
 * Menambahkan balasan baru ke akhir daftar balasan.
 * @param l Pointer ke daftar balasan
 * @param val Pohon balasan yang akan ditambahkan
 */
void insertLastBalasan(BalasanList *l, Tree val);

/**
 * Menghapus balasan terakhir dari daftar balasan.
 * @param l Pointer ke daftar balasan
 */
void deleteLastBalasan(BalasanList *l);

/**
 * Memperluas kapasitas daftar balasan.
 * @param l Pointer ke daftar balasan
 * @param num Jumlah elemen yang akan ditambahkan
 */
void expandListBalasan(BalasanList *l, int num);

/**
 * Mengurangi kapasitas daftar balasan.
 * @param l Pointer ke daftar balasan
 * @param num Jumlah elemen yang akan dihapus
 */
void shrinkListBalasan(BalasanList *l, int num);

/**
 * Memampatkan daftar balasan sehingga tidak ada slot kosong di antara elemen-elemen.
 * @param l Pointer ke daftar balasan
 */
void compressListBalasan(BalasanList *l);

/**
 * Membuat pohon balasan kosong.
 * @param T Pointer ke pohon balasan
 * @param ID_Kicau ID kicauan
 */
void createEmptyTree(Tree *T, int ID_Kicau);

/**
 * Menampilkan informasi sebuah balasan.
 * @param key Data balasan
 */
void displayBalasan(BalasanStruct key);

/**
 * Menambahkan anak ke sebuah node dalam pohon balasan.
 * @param parent Pointer ke node induk
 * @param child Pointer ke node anak
 */
void addChild(Node* parent, Node* child);

/**
 * Mencetak indentasi sesuai dengan kedalaman node dalam pohon balasan.
 * @param depth Kedalaman node
 */
void printIndent(int depth);

/**
 * Membuat node balasan baru dengan data balasan tertentu.
 * @param key Data balasan
 * @return Pointer ke node balasan baru
 */
Node* newNodeBalasan(BalasanStruct key);

/**
 * Mencetak seluruh balasan dalam pohon balasan secara rekursif.
 * @param root Pointer ke akar pohon balasan
 * @param depth Kedalaman node
 */
void printBalasan(Node* root, int depth);

/**
 * Membaca informasi sebuah balasan dari input pengguna.
 * @param newBalasan Pointer ke data balasan baru
 */
/**
 * Reads the balasan data for a specific target ID.
 *
 * @param newBalasan A pointer to the BalasanStruct where the data will be stored.
 * @param ID_Target The ID of the target for which the balasan data will be read.
 */
void ReadBalasan(BalasanStruct *newBalasan, int ID_Target);

/**
 * Mencari node dengan ID balasan tertentu dalam pohon balasan.
 * @param root Pointer ke akar pohon balasan
 * @param ID_balasan ID balasan yang dicari
 * @return Pointer ke node dengan ID balasan tertentu, NULL jika tidak ditemukan
 */
Node* findNode(Node* root, int ID_balasan);

/**
 * Mencari ID kicauan berdasarkan ID balasan.
 * @param ID_kicau ID balasan
 * @return ID kicauan yang terkait dengan ID balasan, -1 jika tidak ditemukan
 */
int FindKicauan(int ID_kicau);

/**
 * Menghapus node dengan ID balasan tertentu dari pohon balasan.
 * @param tree Pointer ke pohon balasan
 * @param ID_balasan ID balasan yang akan dihapus
 */
void deleteNode(Tree* tree, int ID_balasan);

/**
 * Fungsi rekursif untuk menghapus node dengan ID balasan tertentu dari pohon balasan.
 * @param root Pointer ke akar pohon balasan
 * @param ID_balasan ID balasan yang akan dihapus
 * @param parent Pointer ke node induk
 * @param childIndex Indeks anak dalam node induk
 */
void deleteNodeHelper(Node* root, int ID_balasan, Node** parent, int childIndex);

/**
 * Menanggapi kicauan dengan melakukan balasan.
 * @param ID_kicau ID kicauan yang akan dibalas
 * @param IDBalasan ID balasan yang akan ditambahkan
 */
void Balas(int ID_kicau, int IDBalasan);

/**
 * Menampilkan seluruh balasan dari suatu kicauan.
 * @param idKicau ID kicauan
 */
void Balasan(int idKicau);

/**
 * Menghapus balasan dari suatu kicauan.
 * @param ID_kicauan ID kicauan
 * @param ID_balasan ID balasan yang akan dihapus
 */
void HapusBalasan(int ID_kicauan, int ID_balasan);

#endif