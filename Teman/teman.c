#include <stdio.h>
#include "teman.h"

void daftarTeman(Graf GFriend, ListVertex LVertex, int UID){
/* I.S. UID adalah User ID yang valid */
/* F.S. Menampilkan daftar teman pengguna dengan User ID UID */

    /* KAMUS LOKAL */
    int i, idxUID, cntFriend;

    /* ALGORITMA */
    idxUID = uidtoIdx(LVertex, UID);
    cntFriend = hitungTeman(GFriend, idxUID);

    if (cntFriend == 0){ // jika belum punya teman
        printf("User belum mempunyai teman\n");
    } else { // jika punya teman
        printf("User memiliki %d teman\n", cntFriend);
        printf("Daftar teman User\n");
        
        for (i = 0; i < NEFF(GFriend); i++){
        /* loop untuk ngeprint semua teman, tapi masih UID, gatau databasenya gmn jadi belum nama usernya */
            if ((ELMTG(GFriend, idxUID, i) == 1) && (idxUID != i)){
                printf("| %d\n", idxToUID(LVertex, i));
            }
        }
    }

}

void hapusTeman(Graf *GFriend, ListVertex LVertex, int UIDSelf, int UIDFriend){
/* I.S. Pengguna dengan User ID UIDSelf berteman dengan pengguna dengan User ID UIDFriend */
/* F.S. Pengguna dengan User ID UIDSelf tidak lagi berteman dengan pengguna dengan User ID UIDFriend, hubungan pada adjacency matrix GFriend berubah (1 -> 0) */

    /* KAMUS LOKAL */
    vertex VSelf, VFriend;

    /* ALGORITMA */
    printf("Masukkan nama pengguna:\n");
    /* mesin kata ngab */

    printf("Apakah anda yakin ingin menghapus [User Friend] dari daftar teman anda? (YA/TIDAK)");
    /* mesin kata lagi */

    if (false){ // jika TIDAK
        printf("Penghapusan teman dibatalkan.\n");
    } else { // jika YA
        VSelf = vertexWithIDX(LVertex, uidtoIdx(LVertex, UIDSelf));
        VFriend = vertexWithIDX(LVertex, uidtoIdx(LVertex, UIDFriend));
        if (isConnected(*GFriend, VSelf, VFriend)){ // jika berteman
            removeEdge(&(*GFriend), VSelf, VFriend);
            printf("[User Ex-Friend] berhasil dihapus dari daftar teman Anda.\n");
        } else { // jika tidak berteman
            printf("[User Random] bukan teman Anda.\n");
        }
        
    }
    
}

int hitungTeman(Graf GFriend, int idx){
/* Mengembalikan banyak teman pengguna dengan User ID UID yang di-assign dengan index idx pada adjacency matrix Graf GFriend */

    /* KAMUS LOKAL */
    int i, count;

    /* ALGORITMA */
    count = 0;
    for (i = 0; i < NEFF(GFriend); i++){
        if ((ELMTG(GFriend, idx, i) == 1) && (idx != i)){
            count = count + 1;
        }
    }
    return count;
}

int idxToUID(ListVertex LVertex, int idx){
/* Mengembalikan UID user yang di-assign dengan index idx pada adjacency matrix graf GFriend */

    /* KAMUS LOKAL */
    int i, length, id;

    /* ALGORITMA */
    id = IDX_UNDEF;
    if (isLVEmpty(LVertex)){
        return id;
    } else {
        length = NEFFLV(LVertex);
        for (i = 0; i < length; i++){
            if (IDXGLV(LVertex, i) == idx){
                id = UIDLV(LVertex, i);
            }
        }
        return id;
    }
}

int uidtoIdx(ListVertex LVertex, int UID){
/* Mengembalikan index user dengan User ID UID yang di-assign pada adjacency matrix graf GFriend */

    /* KAMUS LOKAL */
    int i, length, idx;

    /* ALGORITMA */
    idx = IDX_UNDEF;
    if (isLVEmpty(LVertex)){
        return idx;
    } else {
        length = NEFFLV(LVertex);
        for (i = 0; i < length; i++){
            if (UIDLV(LVertex, i) == UID){
                idx = IDXGLV(LVertex, i);
            }
        }
        return idx;
    }
}