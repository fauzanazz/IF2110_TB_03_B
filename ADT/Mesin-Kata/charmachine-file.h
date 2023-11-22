/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_FILE_H_
#define __MESIN_KAR_FILE_H_

#include "../boolean.h"
#include <stdio.h>

#define MARKF '\n'
#define SPACE ' '
/* State Mesin */
extern char currentCharF;
extern boolean EOPF;

/**
 * Memulai mesin karakter dari file.
 * Pita disiapkan untuk dibaca.
 * Karakter pertama yang ada pada pita posisinya adalah pada jendela.
 * 
 * I.S. : sembarang
 * F.S. : currentChar adalah karakter pertama pada pita
 *        Jika currentChar != MARK maka EOP akan padam (false)
 *        Jika currentChar = MARK maka EOP akan menyala (true)
 * 
 * @param filename Nama file yang akan dibaca
 */
void STARTFILE(char *filename);

/**
 * Memajukan pita satu karakter.
 * 
 * I.S. : Karakter pada jendela = currentChar, currentChar != MARK
 * F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
 *        currentChar mungkin = MARK
 *        Jika  currentChar = MARK maka EOP akan menyala (true)
 */
void ADVFILE();

/**
 * Membaca satu baris teks dari pita.
 * Baris teks yang dibaca akan disimpan dalam buffer.
 */
void ReadLine();

/**
 * Mengabaikan spasi pada pita.
 * Jika karakter pada jendela adalah spasi, maka karakter tersebut akan diabaikan
 * hingga ditemukan karakter selain spasi.
 */
void IgnoreSpace();

/**
 * Menutup file yang sedang dibaca.
 */
void CloseFile();


#endif