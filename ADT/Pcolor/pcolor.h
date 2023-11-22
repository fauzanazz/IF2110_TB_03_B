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

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"

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
