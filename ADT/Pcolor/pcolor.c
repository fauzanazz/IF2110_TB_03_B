/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

#include <stdio.h>
#include "pcolor.h"
#include <time.h>

void print_red(char c)
{
    printf("%s%c", RED, c);
    printf("%s", RESET_COLOR);
}

void print_green(char c)
{
    printf("%s%c", GREEN, c);
    printf("%s", RESET_COLOR);
}

void print_blue(char c)
{
    printf("%s%c", BLUE, c);
    printf("%s", RESET_COLOR);
}

void print_yellow(char c)
{
    printf("%s%c", YELLOW, c);
    printf("%s", RESET_COLOR);
}

void print_magenta(char c)
{
    printf("%s%c", MAGENTA, c);
    printf("%s", RESET_COLOR);
}

void print_cyan(char c)
{
    printf("%s%c", CYAN, c);
    printf("%s", RESET_COLOR);
}

void printColorfulLine(const char* color, char* input) {
    printf("%s\r", color);
    printf("%s", input);
    printf("%s", RESET_COLOR);
    fflush(stdout); 
}

void printNeonString(char* input) {
    while(1){
        printColorfulLine(RED, input);
        awaitColor(1);
        printColorfulLine(GREEN, input);
        awaitColor(1);
        printColorfulLine(YELLOW, input);
        awaitColor(1);
        printColorfulLine(BLUE, input);
        awaitColor(1);
        printColorfulLine(MAGENTA, input);
        awaitColor(1);
        printColorfulLine(CYAN, input);
        awaitColor(1);
    }
}

void awaitColor(int seconds){
    time_t start_time = time(NULL);
    time_t current_time = time(NULL);
    while (current_time - start_time < seconds){
        current_time = time(NULL);
    }
}