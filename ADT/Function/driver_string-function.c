#include "string-function.h"
#include <stdio.h>

int main(){
    char *s1 = "Hello";

    printf("Panjang dari %s adalah %d\n", s1, stringLength(s1));

    char *s2 = "Hello";

    printf("Apakah %s sama dengan %s? %d\n", s1, s2, stringCompare(s1, s2));

    printf("Gabungan dari %s dan %s adalah %s\n", s1, s2, concatString(s1, s2));

    return 0;
}