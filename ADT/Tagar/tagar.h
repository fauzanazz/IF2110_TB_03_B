/* File: tagar.h */
/* Definisi : Tagar menggunakan LCG 4 char hash */

#ifndef __TAGAR_H__
#define __TAGAR_H__

#include "../boolean.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../Kicauan/kicauan.h"
#include "../LinkedList/LinkedList.h"

#include <stdio.h>

#define IDX_UNDEF -1

typedef struct {
    unsigned int state;
    unsigned int a;
    unsigned int c;
    unsigned int m;
} LCG;

typedef struct {
    Word key;
    LinkedList listKicauan;
    int value;
} Hash_;

typedef struct {
    Hash_ * T[1000];
    int size;
} HashTable;

void initLCG(LCG *lcg, unsigned int seed, unsigned int a, unsigned int c, unsigned int m);

void Get_Word(Word key, Word * hash);

unsigned int Hash_key(LCG lcg);

int Make_Key(int * Hash_Key);

void Enum_Hash(Word hash, int * hashkey);

void insertHash(HashTable * T, Kicau_struct kicauan);

//Konflik dengan tagar.c sebelumnya  HashTable T, word tagar
void Cari_Kicauan(Word Tagar, HashTable *T);

#endif