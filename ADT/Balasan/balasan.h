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

void CreateListBalasan(BalasanList *listBalasan);
void dealocateListBalasan(BalasanList *l);
void insertLastBalasan(BalasanList *l, Tree val);
void deleteLastBalasan(BalasanList *l);
void expandListBalasan(BalasanList *l, int num);
void shrinkListBalasan(BalasanList *l, int num);
void compressListBalasan(BalasanList *l);
void createEmptyTree(Tree *T, int ID_Kicau);
void displayBalasan(BalasanStruct key);
void addChild(Node* parent, Node* child);
void printIndent(int depth);
Node* newNodeBalasan(BalasanStruct key);
void printBalasan(Node* root, int depth);
void ReadBalasan(BalasanStruct *newBalasan);
Node** findNode(Node*** node, int ID_balasan);
int FindKicauan(int ID_kicau);
void deleteNode(Node** node);
void Balas(int ID_kicau, int IDBalasan);
void Balasan(int idKicau);
void HapusBalasan(int ID_kicauan, int ID_balasan);

#endif