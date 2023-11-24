/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

/**
Details

print_xxx(c) will print c with xxx color. Import this header to use the declared functions.
We only provide 8 colors. Feel free to modify/add colors if you want to.
**/

#define RESET_COLOR "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"


/**
 * Mencetak karakter dengan warna merah.
 *
 * @param c Karakter yang akan dicetak.
 */
void print_red(char c);

/**
 * Mencetak karakter dengan warna hijau.
 *
 * @param c Karakter yang akan dicetak.
 */
void print_green(char c);

/**
 * Mencetak karakter dengan warna biru.
 *
 * @param c Karakter yang akan dicetak.
 */
void print_blue(char c);

/**
 * Mencetak karakter dengan warna kuning.
 *
 * @param c Karakter yang akan dicetak.
 */
void print_yellow(char c);

/**
 * Mencetak karakter dengan warna magenta.
 *
 * @param c Karakter yang akan dicetak.
 */
void print_magenta(char c);

/**
 * Mencetak karakter dengan warna cyan.
 *
 * @param c Karakter yang akan dicetak.
 */
void print_cyan(char c);

/**
 * Mencetak karakter dengan warna putih.
 *
 * @param c Karakter yang akan dicetak.
 */
void print_white(char c);

/**
 * Mencetak karakter dengan warna yang dipilih.
 *
 * @param c string yang akan dicetak.
 */
void printColorfulLine(const char* color, char* input);

/**
 * Suspends the execution of the program for the specified number of seconds.
 *
 * @param seconds The number of seconds to wait.
 */
void awaitColor(int seconds);

/**
 * Prints a neon string.
 *
 * This function takes a string as input and prints it in interval rainbow color.
 *
 * @param input The string to be printed.
 */
void printNeonString(char* input);