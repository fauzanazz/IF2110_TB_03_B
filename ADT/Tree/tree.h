#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "kicauan.h"

#define parent_root -1
#define max 100

typedef Kicau_struct treeElType;
typedef struct {
  treeElType  element;
  struct treeNode *firstChild;
  treeNode *nextChild;
  treeNode *nextNode;
} treeNode;

typedef struct {
  treeNode *root;
} treeCDT;

void makeTree(treeCDT *T);
void addRoot(treeCDT *T, treeElType X);
void addChild(treeCDT *T, treeElType X);
void printTree(treeCDT T);


#endif