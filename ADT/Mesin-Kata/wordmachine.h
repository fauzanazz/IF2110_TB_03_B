/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "charmachine.h"

#define NMax 280
#define BLANK ' '
#define LINEFEED '\n'


typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

/**
 * Fungsi CheckInput digunakan untuk memeriksa apakah string input valid.
 * 
 * @param s Pointer ke string yang akan diperiksa.
 * @return Mengembalikan nilai true jika string input valid, dan false jika tidak valid.
 */
boolean CheckInput(char *s);

/**
 * Prosedur displayWord digunakan untuk menampilkan kata ke layar.
 * 
 * @param s Kata yang akan ditampilkan.
 */
void displayWord(Word s);

/**
 * Fungsi createWordfromString digunakan untuk membuat objek Word dari string.
 * 
 * @param s Pointer ke string yang akan diubah menjadi Word.
 * @return Objek Word yang dibuat dari string.
 */
Word createWordfromString(char *s);

/**
 * Fungsi isWordEqual digunakan untuk membandingkan dua objek Word.
 * 
 * @param s1 Objek Word pertama.
 * @param s2 Objek Word kedua.
 * @return Mengembalikan nilai true jika kedua objek Word sama, dan false jika berbeda.
 */
boolean isWordEqual(Word s1, Word s2);

/**
 * Fungsi WordToInt digunakan untuk mengubah objek Word menjadi bilangan integer.
 * 
 * @param w1 Objek Word yang akan diubah menjadi bilangan integer.
 * @return Bilangan integer yang dihasilkan dari objek Word.
 */
int WordToInt(Word w1);

/**
 * Fungsi CheckInputOption digunakan untuk memeriksa apakah opsi input valid.
 * 
 * @return Mengembalikan nilai true jika opsi input valid, dan false jika tidak valid.
 */
boolean CheckInputOption();

#endif