#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"


void CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (ElType *) malloc (capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}
void dealocateList(ListDin *l){
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int listLength(ListDin l){
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l){
    return IDX_MIN;
}
IdxType getLastIdx(ListDin l){
    return NEFF(l) - 1;
}
boolean isIdxValid(ListDin l, IdxType i){
    return (i >= IDX_MIN && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i){
    return (i >= IDX_MIN && i <= NEFF(l));
}
boolean isEmpty(ListDin l){
    return (NEFF(l) == 0);
}
boolean isFull(ListDin l){
    return (NEFF(l) == CAPACITY(l));
}
void readList(ListDin *l){
    int n;
    scanf("%d", &n);
    while(n<0 || n>CAPACITY(*l)){
        scanf("%d", &n);
    }
    NEFF(*l) = n;
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &ELMT(*l, i));
    }
}
void printList(ListDin l){
    int i;
    printf("[");
    for (i = 0; i < NEFF(l); i++){
        printf("%d", ELMT(l, i));
        if (i != NEFF(l) - 1){
            printf(",");
        }
    }
    printf("]");
}

void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    int i;
    for (i = 0; i < NEFF(lIn); i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}


void swapthis(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertLast(ListDin *l, ElType val){
    NEFF(*l)++;
    ELMT(*l, getLastIdx(*l)) = val;
}
void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--;
}
void expandList(ListDin *l, int num){
    CAPACITY(*l) += num;
}
void shrinkList(ListDin *l, int num){
    CAPACITY(*l) -= num;
}
void compressList(ListDin *l){
    CAPACITY(*l) = NEFF(*l);
}