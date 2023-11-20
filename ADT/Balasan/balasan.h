#ifndef BALASAN_H
#define BALASAN_H

#include "../Mesin-Kata/wordmachine.h"
#include "../Time/datetime.h"
#include "../Pengguna/pengguna.h"
#include "../Kicauan/kicauan.h"
#include "../Teman/teman.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100;
/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

typedef struct {
    int ID_balasan;
    int ID_Author;
    DATETIME DT;
    Word TextBalasan;
} BalasanStruct;

typedef struct Node {
    BalasanStruct key;
    int childCount;
    struct Node** child;
} Node;

Node* newNode(BalasanStruct key) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->childCount = 0;
    temp->child = NULL;
    return temp;
}

typedef struct {
    int ID_Kicau;
    Node* root;
} Tree;

typedef struct {
    Tree *T;
    int Neff;
    int Capacity;
    int LastID;
} BalasanList;

typedef struct Queue {
    Node** items;
    int front, rear, capacity;
} Queue;

#endif