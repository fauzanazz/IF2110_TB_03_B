#ifndef PENGGUNA_H
#define PENGGUNA_H

#define pahing "pahing"
#define kliwon "kliwon"
#define wage "wage"
#define pon "pon"
#define legi "legi"

#include "charmachine.h"
#include "matrix.h"
#include "boolean.h"

typedef struct {
    char[20] Nama;
    char[20] Pass;
    char[135] Bio;
    Word Number;
    Word Weton;
    boolean privat;
    Matrix foto;
}

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