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

void STARTFILE(char *filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADVFILE();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void ReadLine();

void IgnoreSpace();

void CloseFile();

#endif