#include <stdio.h>
#include "charmachine.h"
#include "charmachine-file.h"
#include "wordmachine.h"

int main() {
    printf("Masukkan kalimat: ");
    START();

    while (currentChar != '\n') {
        printf("%c", currentChar);
        ADV();
    }

    printf("\n");
    printf("Masukkan kata: ");
    STARTWORD();
    while (currentChar != '\n') {
        printf("%c", currentChar);
        ADVWORD();
    }

    printf("\n");
    printf("Isi dari file testfile.txt adalah: \n");
    STARTFILE("ADT/Mesin-Kata/testfile.txt");

    while (!EOPF) {
        printf("%c", currentCharF);
        ADVFILE();
    }

    return 0;
}
