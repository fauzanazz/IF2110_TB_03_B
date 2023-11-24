#include "wordmachine-file.h"
#include <stdio.h>

void testSTARTWORDFILE() {
    STARTWORDFILE();
    if (EndWordF) {
        printf("STARTWORDFILE() test 1 passed.\n");
    } else {
        printf("STARTWORDFILE() test 1 failed.\n");
    }
}

void testADVWORDFILE() {
    STARTWORDFILE();
    ADVWORDFILE();
    if (EndWordF) {
        printf("ADVWORDFILE() test 1 passed.\n");
    } else {
        printf("ADVWORDFILE() test 1 failed.\n");
    }
}

int main() {
    testSTARTWORDFILE();
    testADVWORDFILE();

    return 0;
}