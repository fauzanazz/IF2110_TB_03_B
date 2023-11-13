#ifndef UTAS_H
#define UTAS_H

#include "../Mesin-Kata/charmachine.h"
#include "../Time/datetime.h"

typedef struct ListKicauanWUtas {
    ListUtas *ListuUtas;
    int neff;
};

typedef struct ListUtas {
    int id_kicauan;
    Utas *Utas;
    int neff;
};

typedef struct Utas{
    char *isiutas;
    int id_author;
    DATETIME TanggalEditTerakhir;
};

#define ListKicauanWUtasElmt(L,i) (L).ListuUtas[(i)]
#define ListKicauanWUtasNeff(L) (L).neff

#endif