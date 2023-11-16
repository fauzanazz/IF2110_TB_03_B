#ifndef DRAF_H
#define DRAF_H

typedef struct {
    char *nama_pengguna;
    int jumlahdraf;
} listDrafPengguna;

typedef struct {
    listDrafPengguna *list_draf_pengguna;
    int neff;
} ListPenggunaDraf;

typedef struct{
    char *isidraf;
    DATETIME tanggaledit;
    int id;
} draf;

typedef struct {
    draf *draf;
    int neff;
} listDraf;

void createListPenggunaDraf(ListPenggunaDraf *L);
void createListDrafPengguna(listDrafPengguna *L);
void createListDraf(listDraf *L);
void createDraf(draf *draf, char *isidraf, DATETIME tanggaledit, int id);
void addDraf(listDraf *L, draf draf);
void addPengguna(ListPenggunaDraf *L, listDrafPengguna pengguna);
void addDrafPengguna(listDrafPengguna *L, draf draf);


#endif