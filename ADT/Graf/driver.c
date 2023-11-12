#include <stdio.h>
#include "graf.c"

int main(){
    Graf G;
    vertex V1, V2, V3;
    CreateVertex(&V1, 12731);
    CreateVertex(&V2, 1283718);
    CreateVertex(&V3, 129173);
    CreateGraf(&G);
    displayGraf(G);printf("\n");
    addVertex(&G, &V1);
    displayGraf(G);printf("\n");
    addVertex(&G, &V2);
    displayGraf(G);printf("\n");
    addVertex(&G, &V3);
    displayGraf(G);printf("\n");
    addEdge(&G, V1, V3);
    displayGraf(G);printf("\n");
    removeEdge(&G, V1, V3);
    displayGraf(G);printf("\n");

    printf("Ukuran: %zu bits\n", sizeof(Graf) * 8);
    return 0;
}