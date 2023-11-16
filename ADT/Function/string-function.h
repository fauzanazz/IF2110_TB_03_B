#ifndef STRING_H_
#define STRING_H_

#include "../Mesin-Kata/wordmachine.h"

int stringLength(char *str);
void stringCopy(char *dest, char *src);
char *stringConcat(Word str1, char *str2);
char *stringConcatChar(char *str, char x);
void printString(char *str);
boolean stringCompare(char *str1, char *str2);

#endif 
