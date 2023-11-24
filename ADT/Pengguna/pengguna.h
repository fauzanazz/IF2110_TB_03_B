#ifndef PENGGUNA_H
#define PENGGUNA_H

#include "../Mesin-Kata/charmachine.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../matrixprofil/matrixprofil.h"
#include "../boolean.h"

#define pahing "pahing"
#define kliwon "kliwon"
#define wage "wage"
#define pon "pon"
#define legi "legi"

typedef struct {
    Word Nama;
    Word Pass;
    Word Bio;
    Word Phone;
    Word Weton;
    boolean Publik;
    Foto ProfilePic;
} Pengguna;

typedef struct {
    Pengguna user[20];
    int usercount;
} ListPengguna;

extern boolean logged;
extern int currentId;

#define USER(lp ,i) (lp).user[i]
#define COUNT(lp) (lp).usercount
#define FOTO(user) (user).ProfilePic
/**
 * Fungsi untuk mengubah semua karakter dalam sebuah kata menjadi huruf kecil.
 * 
 * @param word Pointer ke objek Word yang akan diubah.
 */
void convertLower(Word *word);

/**
 * Prosedur untuk membuat list pengguna kosong.
 * 
 * @param lp Pointer ke objek ListPengguna yang akan dibuat.
 */
void createListPengguna(ListPengguna *lp);

/**
 * Prosedur untuk menginisialisasi nama pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diinisialisasi.
 */
void inisialisasiNamaPengguna(Pengguna *user);

/**
 * Prosedur untuk menginisialisasi password pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diinisialisasi.
 */
void inisialisasiPassPengguna(Pengguna *user);

/**
 * Prosedur untuk menginisialisasi bio pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diinisialisasi.
 */
void inisialisasiBioPengguna(Pengguna *user);

/**
 * Prosedur untuk menginisialisasi nomor telepon pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diinisialisasi.
 */
void inisialisasiPhonePengguna(Pengguna *user);

/**
 * Prosedur untuk menginisialisasi weton pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diinisialisasi.
 */
void inisialisasiWetonPengguna(Pengguna *user);

/**
 * Prosedur untuk menginisialisasi status pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diinisialisasi.
 */
void inisialisasiStatusPengguna(Pengguna *user);

/**
 * Prosedur untuk menginisialisasi foto pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diinisialisasi.
 */
void inisialisasiFotoPengguna(Pengguna *user);

/**
 * Prosedur untuk menginisialisasi pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diinisialisasi.
 */
void inisialisasiPengguna(Pengguna *user);

/**
 * Prosedur untuk melakukan pendaftaran pengguna baru.
 * 
 * @param lp Pointer ke objek ListPengguna.
 */
void Daftar(ListPengguna *lp);

/**
 * Prosedur untuk melakukan login pengguna.
 * 
 * @param lp Pointer ke objek ListPengguna.
 */
void Masuk(ListPengguna *lp);

/**
 * Prosedur untuk melakukan logout pengguna.
 */
void Keluar();

#endif