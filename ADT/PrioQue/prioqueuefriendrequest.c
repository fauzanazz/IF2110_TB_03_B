#include "../boolean.h"
#include "prioqueuefriendrequest.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty(PrioQueueFriendRequest Q) {
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}

boolean IsFull(PrioQueueFriendRequest Q) {
    return MaxElement(Q) == NBElmt(Q);
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
            return MaxElement(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }
}

void MakeEmpty(PrioQueueFriendRequest *Q, int Max) {
    (*Q).T = (friendRequest *) malloc ((Max) * sizeof(friendRequest));
    if ((*Q).T == NULL) {
        MaxElement(*Q) = 0;
    }
    else {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxElement(*Q) = Max;
    }
}

void DeAlokasi(PrioQueueFriendRequest *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxElement(*Q) = 0;
    free((*Q).T);
}

void Enqueue(PrioQueueFriendRequest *Q, friendRequest X) {
    boolean found;
    int idx;
    int i, j;
    friendRequest temp;

    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    } else {
        Tail(*Q) = Tail(*Q) == MaxElement(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = i == 0 ? MaxElement(*Q) - 1 : i - 1;
        
        while (i != Head(*Q) && Popularity(Elmt(*Q, i)) < (Popularity(Elmt(*Q, j)))) {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = i == 0 ? MaxElement(*Q) - 1 : i - 1;
        }
    }
}

void Dequeue(PrioQueueFriendRequest *Q, friendRequest *X) {
    if (NBElmt(*Q) == 1) {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else {
        *X = InfoHead(*Q);
        Head(*Q) = (Head(*Q) == MaxElement(*Q) - 1) ? 0 : Head(*Q) + 1;
    }
}
