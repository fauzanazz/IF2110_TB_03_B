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


char *concatWordCharToString(Word str1, char *str2) {
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

char *concatString(char *str1, char *str2) {
    char *result;
    int len1 = 0;
    int len2 = 0;

    char *p;
    for (p = str1; *p != '\0'; p++, len1++);
    for (p = str2; *p != '\0'; p++, len2++);

    result = (char *)malloc(len1 + len2 + 1); 

    if (result != NULL) {
        char *pResult = result;

        while (*str1) {
            *pResult++ = *str1++;
        }
        while (*str2) {
            *pResult++ = *str2++;
        }
        *pResult = '\0';
    }

    return result;
}

char *stringConcatChar(char *str, char x){
    char *result;
    int len1 = stringLength(str);
    int len2 = 1;

    result = (char *)malloc(len1 + len2 + 1); 

    if (result != NULL) {
        char *pResult = result;

        int i = 0;
        while (i < len1) {
            *pResult++ = str[i++];
        }
        *pResult++ = x;
        *pResult = '\0';
    }

    return result;
}

void printString(char *str) {
    while (*str) {
        printf("%c", *str);
        str++;
    }
}

boolean stringCompare(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return false;
        }
        str1++;
        str2++;
    }
    return true;
}

char *concatWordToString(Word w1, Word w2){
    char *result;
    int len1 = w1.Length;
    int len2 = w2.Length;

    result = (char *)malloc(len1 + len2 + 1); 

    if (result != NULL) {
        char *pResult = result;

        int i = 0;
        while (i < w1.Length) {
            *pResult++ = w1.TabWord[i++];
        }
        
        i = 0;
        while (i < w2.Length) {
            *pResult++ = w2.TabWord[i++];
        }
        *pResult = '\0';
    }

    return result;
}

char *WordToString(Word w){
    char *result;
    int len1 = w.Length;

    result = (char *)malloc(len1 + 1); 

    if (result != NULL) {
        char *pResult = result;

        int i = 0;
        while (i < w.Length) {
            *pResult++ = w.TabWord[i++];
        }
        *pResult = '\0';
    }

    return result;
}