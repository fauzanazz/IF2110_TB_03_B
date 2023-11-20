#include <stdio.h>
#include "graf.c"

int main(){
    Graf G;
    CreateGraf(&G);
    displayGraf(G);printf("\n");
    addVertex(&G, 0);
    displayGraf(G);printf("\n");
    addVertex(&G, 1);
    displayGraf(G);printf("\n");
    addVertex(&G, 2);
    displayGraf(G);printf("\n");
    addEdge(&G, 0, 2);
    displayGraf(G);printf("\n");
    removeEdge(&G, 0, 2);
    displayGraf(G);printf("\n");

    printf("Ukuran: %zu bits\n", sizeof(Graf) * 8);
    return 0;
}