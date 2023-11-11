#include "../boolean.h"
#include "prioqueuefriendrequest.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty(PrioQueueFriendRequest Q) {
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}

boolean IsFull(PrioQueueFriendRequest Q) {
    return MaxEl(Q) == NBElmt(Q);
}

int NBElmt(PrioQueueFriendRequest Q) {    
    if (IsEmpty(Q)){
        return 0;
    }
    else {
        if ((Tail(Q) - Head(Q)) >= 0){
            return Tail(Q) - Head(Q) + 1;
        }
        else {
            return MaxEl(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }
}

void MakeEmpty(PrioQueueFriendRequest *Q, int Max) {
    (*Q).T = (infotype *)malloc((Max) * sizeof(infotype));
    if ((*Q).T == NULL) {
        MaxEl(*Q) = 0;
    }
    else {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }
}

void DeAlokasi(PrioQueueFriendRequest *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxEl(*Q) = 0;
    free((*Q).T);
}

void Enqueue(PrioQueueFriendRequest *Q, infotype X) {
    boolean found;
    int idx;
    int i, j;
    infotype temp;

    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    } else {
        Tail(*Q) = Tail(*Q) == MaxEl(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = i == 0 ? MaxEl(*Q) - 1 : i - 1;
        
        while (i != Head(*Q) && Popularity(Elmt(*Q, i)) < (Popularity(Elmt(*Q, j)))) {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = i == 0 ? MaxEl(*Q) - 1 : i - 1;
        }
    }
}

void Dequeue(PrioQueueFriendRequest *Q, infotype *X) {
    if (NBElmt(*Q) == 1) {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else {
        *X = InfoHead(*Q);
        Head(*Q) = (Head(*Q) == MaxEl(*Q) - 1) ? 0 : Head(*Q) + 1;
    }
}