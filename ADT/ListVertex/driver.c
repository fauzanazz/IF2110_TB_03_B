#include <stdio.h>
#include "listvertex.h"

int main(){
    ListVertex L;
    vertex V;
    CreateListVertex(&L);
    CreateVertex(&V, 13522144);
    printf("%d %d\n", V.UserID, V.idxAdjMtx);
    insertLast(&L, V);
    printf("%d %d %d\n", UIDLV(L, 0), IDXGLV(L, 0), NEFFLV(L));

    return 0;
}