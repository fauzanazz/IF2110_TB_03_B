#include "LinkedList.h"
#include <stdio.h> 
#include <stdlib.h>

Address newNode(ElType val){
    Address p;
    p = (Address) malloc (sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(LinkedList *l){
    *l = NULL;
}

boolean isEmpty(LinkedList l){
    return (l == NULL);
}

int LengthLinkedList(LinkedList l){
    int count = 0;
    Address p = l;
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

void insertFirst(LinkedList *l, ElType val){
    Address new = newNode(val);
    if (new != NULL){
        NEXT(new) = *l;
        *l = new;
    }
}
void insertLast(LinkedList *l, ElType val){
    Address p = *l;
    Address new = newNode(val);
    if (new != NULL){
        if (p == NULL){
            *l = new;
        } else {
            while (NEXT(p) != NULL){
                p = NEXT(p);
            }
            NEXT(p) = new;
        }
    }
}

void insertAt(LinkedList *l, ElType val, int idx){
    Address p = *l;
    int  i;
    Address new = newNode(val);
    if (new != NULL){
        if (idx == 0){
            NEXT(new) = p;
            *l = new;
        } else {
            for (i = 0; i < idx-1; i++){
                p = NEXT(p);
            }
            NEXT(new) = NEXT(p);
            NEXT(p) = new;
        }
    }
}
void deleteFirst(LinkedList *l, ElType *val){
    *val = INFO(*l);
    if (NEXT(*l) == NULL){
        *l = NULL;
    } else {
        *l = NEXT(*l);
    }
}

void deleteLast(LinkedList *l, ElType *val){
    Address p = *l;
    int len = LengthLinkedList(*l);
    int  i;
    if (len == 1) {
        *val = INFO(*l);
        *l = NULL;
    } else {
        p = *l;
        for (i = 0; i < len-2; i++){
            p = NEXT(p);
        }
        *val = INFO(NEXT(p));
        NEXT(p) = NULL;
    }
}

void deleteAt(LinkedList *l, int idx, ElType *val){
    Address p = *l;
    int  i;
    if (idx == 0){
        deleteFirst(l,val);
    } else {
        for (i = 0; i < idx-1; i++){
            p = NEXT(p);
        }
        *val = INFO(NEXT(p));
        NEXT(p) = NEXT(NEXT(p));
    }

}
void displayLinkedList(LinkedList l){
    Address p = l;
    int len = LengthLinkedList(l);
    int i;
    for (i = 0; i < len; i++){
        ShowKicau(INFO(p));
        p = NEXT(p);
    }
}

int length(LinkedList l){
    Address p = l;
    int length = 0;
    while (p != NULL){
        p = NEXT(p);
        length++;
    }
    return length;
}

