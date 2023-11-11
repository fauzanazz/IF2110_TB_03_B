#include <stdio.h>
#include <stdlib.h>
#include "../Mesin-Kata/wordmachine.h"
#include "string-function.h"

int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}


char *stringConcat(Word str1, char *str2) {
    char *result;
    int len1 = str1.Length;
    int len2 = 0;

    char *p;
    for (p = str2; *p != '\0'; p++, len2++);

    result = (char *)malloc(len1 + len2 + 1); 

    if (result != NULL) {
        char *pResult = result;

        int i = 0;
        while (i < str1.Length) {
            *pResult++ = str1.TabWord[i++];
        }
        while (*str2) {
            *pResult++ = *str2++;
        }
        *pResult = '\0';
    }


    return result;
}