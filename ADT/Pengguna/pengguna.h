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

#define FOTO(user) (user).profilepic

void convertLower(Word *word);

void createListPengguna(ListPengguna *lp);

void inisialisasiNamaPengguna(Pengguna *user);

void inisialisasiPassPengguna(Pengguna *user);

void inisialisasiBioPengguna(Pengguna *user);

void inisialisasiPhonePengguna(Pengguna *user);

void inisialisasiWetonPengguna(Pengguna *user);

void inisialisasiStatusPengguna(Pengguna *user);

void inisialisasiFotoPengguna(Pengguna *user);

void inisialisasiPengguna(Pengguna *user);

void Daftar(ListPengguna *lp);

void Masuk(ListPengguna *lp);

void Keluar();

#endif