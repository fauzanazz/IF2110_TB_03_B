#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pcolor.h"

int main() {
    while (1) {
        printColorfulLine(RED, "RED");
        printColorfulLine(GREEN, "GREEN");
        printColorfulLine(YELLOW, "YELLOW");
        printColorfulLine(BLUE, "BLUE");
        printColorfulLine(MAGENTA, "MAGENTA");
        printColorfulLine(CYAN, "CYAN");
    }
    return 0;
}

