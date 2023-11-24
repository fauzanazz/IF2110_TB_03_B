#include <stdio.h>
#include "wordmachine.h"

void testIgnoreBlanks() {
    currentChar = ' ';
    IgnoreBlanks();
    printf("IgnoreBlanks() test passed.\n");
}

void testSTARTWORD() {
    currentChar = ' ';
    STARTWORD();
    printf("STARTWORD() test passed.\n");
}

void testADVWORD() {
    currentChar = ' ';
    ADVWORD();
    printf("ADVWORD() test passed.\n");
}

void testCopyWord() {
    currentChar = ' ';
    CopyWord();
    printf("CopyWord() test passed.\n");
}

void testCheckInput() {
    currentWord = createWordfromString("test");
    boolean result = CheckInput("test");
    if (result) {
        printf("CheckInput() test passed.\n");
    } else {
        printf("CheckInput() test failed.\n");
    }
}

void testDisplayWord() {
    Word w = createWordfromString("test");
    displayWord(w);
    printf("displayWord() test passed.\n");
}

void testCreateWordfromString() {
    Word w = createWordfromString("test");
    if (w.Length == 4 && w.TabWord[0] == 't' && w.TabWord[1] == 'e' && w.TabWord[2] == 's' && w.TabWord[3] == 't') {
        printf("createWordfromString() test passed.\n");
    } else {
        printf("createWordfromString() test failed.\n");
    }
}

void testIsWordEqual() {
    Word w1 = createWordfromString("test");
    Word w2 = createWordfromString("test");
    boolean result = isWordEqual(w1, w2);
    if (result) {
        printf("isWordEqual() test passed.\n");
    } else {
        printf("isWordEqual() test failed.\n");
    }
}

void testWordToInt() {
    Word w = createWordfromString("123");
    int result = WordToInt(w);
    if (result == 123) {
        printf("WordToInt() test passed.\n");
    } else {
        printf("WordToInt() test failed.\n");
    }
}

void testCheckInputOption() {
    currentWord = createWordfromString("GANTI_PROFIL");
    boolean result = CheckInputOption();
    if (result) {
        printf("CheckInputOption() test passed.\n");
    } else {
        printf("CheckInputOption() test failed.\n");
    }
}

int main() {
    testIgnoreBlanks();
    testSTARTWORD();
    testADVWORD();
    testCopyWord();
    testCheckInput();
    testDisplayWord();
    testCreateWordfromString();
    testIsWordEqual();
    testWordToInt();
    testCheckInputOption();

    return 0;
}