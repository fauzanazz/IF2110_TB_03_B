#include <stdio.h>
#include <math.h>
#include "tagar.h"          

void init_LCG(LCG *lcg, unsigned int seed) {
    lcg->state = seed;
    lcg->a = 331;
    lcg->c = 0;
    lcg->m = 1000;
}

unsigned int Hash_key(LCG lcg){
    lcg.state = (lcg.a * lcg.state + lcg.c) % lcg.m;
    return lcg.state;
}

void Get_Word(Word key, Word * hash){
    if (key.Length < 4) {
        for (int i = 0; i < key.Length; i++) {
            hash->TabWord[i] = key.TabWord[i];
        }
        for (int i = key.Length; i < 4; i++) {
            hash->TabWord[i] = ' ';
        }
    }
    hash->Length = 4;
    hash->TabWord[0] = key.TabWord[0];
    hash->TabWord[1] = key.TabWord[1];
    hash->TabWord[2] = key.TabWord[key.Length-1];
    hash->TabWord[3] = key.TabWord[key.Length-2];
}

void Enum_Hash(Word hash, int * hashkey) {
    int temp;
    for (int i = 0 ; i < 4; i++) {
        temp = (int) hash.TabWord[i];
        if (temp < 91){
            hashkey[i] = temp - 65;
        } else {
            hashkey[i] = temp - 97;
        }
    }
}

int Make_Key(int * Hash_Key) {
    int hashkey = 0;
    for (int i = 0; i < 4; i++){
        printf("%d\n",  Hash_Key[i]);
        hashkey +=  Hash_Key[i] * pow(10, i*2);
    }
    printf("%d\n", hashkey);
    return hashkey;
}


void Cari_Kicauan(Word Tagar, HashTable * T){
    Get_Word(Tagar, &Tagar);
    int Hash_Key[4];
    Enum_Hash(Tagar, Hash_Key);
    int key = Make_Key(Hash_Key);
    int idx = Cari_Index(*T, key, Tagar);
    
    if (idx != IDX_UNDEF) {
        printf("Kicauan dengan tagar #%s:\n", Tagar.TabWord);
        displayLinkedList(T->T[idx]->listKicauan);
    } else {
        printf("Tidak ada kicauan dengan tagar #%s\n", Tagar.TabWord);
    }
}

void insertHash(HashTable * T, Kicau_struct kicauan){
    Word hash;
    Get_Word(kicauan.Tagar, &hash);
    int Hash_Key[4];
    Enum_Hash(hash, Hash_Key);
    int key = Make_Key(Hash_Key);
    int idx = Cari_Index(*T, key, hash);
    if (idx == IDX_UNDEF){
        T->T[T->size] = (Hash_ *) malloc(sizeof(Hash_));
        T->T[T->size]->key = hash;
        T->T[T->size]->value = key;
        T->T[T->size]->listKicauan = createLinkedList();
        insertLastLinkedList(&T->T[T->size]->listKicauan, kicauan);
        T->size++;
    } else {
        insertLastLinkedList(&T->T[idx]->listKicauan, kicauan);
    }
}

int Cari_Index(HashTable T, int key, Word Tagar){
    int idx = key;
    boolean found = false;
    currentWord = T.T[idx]->key;
    if (CheckInput(Tagar.TabWord)) {
        found = true;
    }
    do {
        idx++;
        currentWord = T.T[idx]->key;
        if (CheckInput(Tagar.TabWord)) {
            found = true;
        }
    } while (!found && idx != key);
    if (found) {
        return idx;
    } else {
        return IDX_UNDEF;
    }
}