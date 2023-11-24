#include <stdio.h>
#include "charmachine-file.h"

void testSTARTFILE() {
    STARTFILE("input.txt");
    printf("STARTFILE() test passed.\n");
}

void testADVFILE() {
    ADVFILE();
    printf("ADVFILE() test passed.\n");
}

void testReadLine() {
    ReadLine();
    printf("ReadLine() test passed.\n");
}

void testIgnoreSpace() {
    IgnoreSpace();
    printf("IgnoreSpace() test passed.\n");
}

void testCloseFile() {
    CloseFile();
    printf("CloseFile() test passed.\n");
}

int main() {
    testSTARTFILE();
    testADVFILE();
    testReadLine();
    testIgnoreSpace();
    testCloseFile();

    return 0;
}