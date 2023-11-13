#ifndef PENGGUNA_H
#define PENGGUNA_H

#define pahing "pahing"
#define kliwon "kliwon"
#define wage "wage"
#define pon "pon"
#define legi "legi"

#include "../Mesin-Kata/charmachine.h"
#include "../Mesin-Kata/wordmachine.h"
// #include "matrix.h"
#include "boolean.h"

typedef struct {
    char Nama[20];
    char Pass[20];
    char Bio[135];
    Word Number;
    Word Weton;
    boolean privat;
    // Matrix foto;
    int id_pengguna;
} Pengguna;

long long int stringToInt(Word word);

boolean cekSimbol(Word word);

boolean cekAngka(Word weton);

void convertLower(Word weton);

boolean cekLengthUsername(Word name);

boolean cekLengthBio(Word bio);

void writePengguna(Word word);

int idIncrement();

void Daftar();

void Masuk();

void Keluar();

#endif