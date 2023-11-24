#include "../boolean.h"
#include "prioqueuefriendrequest.h"
#include <stdio.h>

void testIsEmpty() {
    PrioQueueFriendRequest Q;
    MakeEmpty(&Q, 5);

    // Test when queue is empty
    if (IsEmpty(Q)) {
        printf("IsEmpty() test 1 passed.\n");
    } else {
        printf("IsEmpty() test 1 failed.\n");
    }

    // Test when queue is not empty
    friendRequest X;
    X.id_target = 2;
    X.id_user = 1;
    X.popularity = 2;
    Enqueue(&Q, X);
    if (!IsEmpty(Q)) {
        printf("IsEmpty() test 2 passed.\n");
    } else {
        printf("IsEmpty() test 2 failed.\n");
    }
}

void testIsFull() {
    PrioQueueFriendRequest Q;
    MakeEmpty(&Q, 5);

    // Test when queue is not full
    if (!IsFull(Q)) {
        printf("IsFull() test 1 passed.\n");
    } else {
        printf("IsFull() test 1 failed.\n");
    }

    // Test when queue is full
    friendRequest X;
    X.id_target = 2;
    X.id_user = 1;
    X.popularity = 2;
    for (int i = 0; i < 5; i++) {
        Enqueue(&Q, X);
    }
    if (IsFull(Q)) {
        printf("IsFull() test 2 passed.\n");
    } else {
        printf("IsFull() test 2 failed.\n");
    }
}

void testNBElmt() {
    PrioQueueFriendRequest Q;
    MakeEmpty(&Q, 5);

    // Test when queue is empty
    if (NBElmt(Q) == 0) {
        printf("NBElmt() test 1 passed.\n");
    } else {
        printf("NBElmt() test 1 failed.\n");
    }

    // Test when queue is not empty
    friendRequest X;
    X.id_target = 2;
    X.id_user = 1;
    X.popularity = 2;
    Enqueue(&Q, X);
    if (NBElmt(Q) == 1) {
        printf("NBElmt() test 2 passed.\n");
    } else {
        printf("NBElmt() test 2 failed.\n");
    }
}

void testEnqueue() {
    PrioQueueFriendRequest Q;
    MakeEmpty(&Q, 5);

    // Test enqueueing one element
    friendRequest X;
    X.id_target = 2;
    X.id_user = 1;
    X.popularity = 2;
    Enqueue(&Q, X);
    if (NBElmt(Q) == 1 && (InfoTail(Q).id_target == X.id_target && InfoTail(Q).id_user == X.id_user && InfoTail(Q).popularity == X.popularity)) {
        printf("Enqueue() test 1 passed.\n");
    } else {
        printf("Enqueue() test 1 failed.\n");
    }

    // Test enqueueing multiple elements
    friendRequest Y;
    Y.id_target = 2;
    Y.id_user = 1;
    Y.popularity = 2;
    Enqueue(&Q, Y);
    if (NBElmt(Q) == 2 && (InfoTail(Q).id_target == Y.id_target && InfoTail(Q).id_user == Y.id_user && InfoTail(Q).popularity == Y.popularity)) {
        printf("Enqueue() test 2 passed.\n");
    } else {
        printf("Enqueue() test 2 failed.\n");
    }
}

void testDequeue() {
    PrioQueueFriendRequest Q;
    MakeEmpty(&Q, 5);

    // Test dequeueing one element
    friendRequest X;
    X.id_target = 2;
    X.id_user = 1;
    X.popularity = 2;
    Enqueue(&Q, X);
    friendRequest Y;
    Y.id_target = 1;
    Y.id_user = 2;
    Y.popularity = 1;
    Enqueue(&Q, Y);
    friendRequest Z;
    Z.id_target = 1;
    Z.id_user = 3;
    Z.popularity = 1;
    Enqueue(&Q, Z);

    friendRequest result;
    Dequeue(&Q, &result);
    if (NBElmt(Q) == 2 && (result.id_target == X.id_target && result.id_user == X.id_user && result.popularity == X.popularity)) {
        printf("Dequeue() test 1 passed.\n");
    } else {
        printf("Dequeue() test 1 failed.\n");
    }

    // Test dequeueing multiple elements
    Dequeue(&Q, &result);
    if (NBElmt(Q) == 1 && (result.id_target == Y.id_target && result.id_user == Y.id_user && result.popularity == Y.popularity)) {
        printf("Dequeue() test 2 passed.\n");
    } else {
        printf("Dequeue() test 2 failed.\n");
    }
}

int main() {
    testIsEmpty();
    testIsFull();
    testNBElmt();
    testEnqueue();
    testDequeue();

    return 0;
}