#ifndef STRING_H_
#define STRING_H_

#include "../Mesin-Kata/wordmachine.h"

/**
 * Menghitung panjang string.
 *
 * @param str String yang akan dihitung panjangnya.
 * @return Panjang dari string.
 */
int stringLength(char *str);

/**
 * Menyalin isi string dari source ke destination.
 *
 * @param dest String tujuan.
 * @param src String sumber.
 */
void stringCopy(char *dest, char *src);

/**
 * Menggabungkan kata dengan karakter ke dalam string.
 *
 * @param str1 Kata yang akan digabungkan.
 * @param str2 Karakter yang akan digabungkan.
 * @return String hasil penggabungan.
 */
char *concatWordCharToString(Word str1, char *str2);

/**
 * Menggabungkan dua string menjadi satu.
 *
 * @param str1 String pertama.
 * @param str2 String kedua.
 * @return String hasil penggabungan.
 */
char *concatString(char *str1, char *str2);

/**
 * Menggabungkan karakter ke dalam string.
 *
 * @param str String yang akan ditambahkan karakter.
 * @param x Karakter yang akan ditambahkan.
 * @return String hasil penggabungan.
 */
char *stringConcatChar(char *str, char x);

/**
 * Mencetak string.
 *
 * @param str String yang akan dicetak.
 */
void printString(char *str);

/**
 * Membandingkan dua string.
 *
 * @param str1 String pertama.
 * @param str2 String kedua.
 * @return True jika kedua string sama, False jika berbeda.
 */
boolean stringCompare(char *str1, char *str2);

/**
 * Mengubah tipe data Word menjadi string.
 *
 * @param w Word yang akan diubah menjadi string.
 * @return String hasil konversi.
 */
char *WordToString(Word w);

#endif 
