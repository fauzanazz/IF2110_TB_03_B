#include "tree.h"
#include <stdio.h>

void makeTree(treeCDT *T){
  (*T).root = NULL;
}

void addRoot(treeCDT *T, treeElType X){
  treeNode *newNode;
  newNode = (treeNode *) malloc(sizeof(treeNode));
  newNode->element = X;
  newNode->firstChild = NULL;
  newNode->nextChild = NULL;
  newNode->nextNode = NULL;
  (*T).root = newNode;
}

void addChild(treeCDT *T, treeElType X){
  treeNode *newNode;
  newNode = (treeNode *) malloc(sizeof(treeNode));
  newNode->element = X;
  newNode->firstChild = NULL;
  newNode->nextChild = NULL;
  newNode->nextNode = NULL;
  treeNode *currNode = T->root;
  while (currNode->nextChild != NULL){
    currNode = currNode->nextChild;
  }
  currNode->nextChild = newNode;
}


void printTree(treeCDT T){
  treeNode *currNode = T.root;
  while (currNode != NULL){
    printf("%d ", currNode->element);
    currNode = currNode->nextChild;
  }
  printf("\n");
}