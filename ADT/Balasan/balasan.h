#ifndef BALASAN_H
#define BALASAN_H

#include "../Tree/tree.h"
#include "../Kicauan/kicauan.h"

typedef treeCDT ElType;

typedef struct {
    treeCDT *ListBalasan;
    int id;
} ListBalasan;


#define ListBalasanElmt(L,i) (L).list_balasan.T[(i)]
#define ListBalasanNeff(L) (L).list_balasan.Neff
#define ListBalasanId(L) (L).id

void BalasanCreateEmpty(ListBalasan *L, int id);
void BalasanAddAsLastEl(ListBalasan *L, ElType X);


#endif
