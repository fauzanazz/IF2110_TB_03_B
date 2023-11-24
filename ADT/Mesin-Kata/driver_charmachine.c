#include "charmachine.h"
#include <stdio.h>

void testSTART() {
    START();
    if (!EOP) {
        printf("START() test 1 passed.\n");
    } else {
        printf("START() test 1 failed.\n");
    }
}

void testADV() {
    START();
    ADV();
    if (!EOP) {
        printf("ADV() test 1 passed.\n");
    } else {
        printf("ADV() test 1 failed.\n");
    }
}

int main() {
    testSTART();
    testADV();

    return 0;
}