#include "wordmachine-file.h"
#include "charmachine-file.h"

boolean EndWordF;
Word currentWordF;

void STARTWORDFILE()

/* I.S. : currentCharF sembarang
   F.S. : EndWordF = true, dan currentCharF = MARKF;
          atau EndWordF = false, currentWordF adalah kata yang sudah diakuisisi,
          currentCharF karakter pertama sesudah karakter terakhir kata */

{
   IgnoreSpace();
   if (currentCharF == MARKF){
      EndWordF = true;
   }
   else{
      EndWordF = false;
      CopyWordFILE();
   }
}

void ADVWORDFILE()

/* I.S. : currentCharF adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWordF adalah kata terakhir yang sudah diakuisisi,
          currentCharF adalah karakter pertama dari kata berikutnya, mungkin MARKF
          Jika currentCharF = MARKF, EndWordF = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
   IgnoreSpace();
   if (currentCharF == MARKF){
      EndWordF = true;
   }
   else{
      CopyWordFILE();
      IgnoreSpace();
   }
}

void CopyWordFILE()
/* Mengakuisisi kata, menyimpan dalam currentWordF
   I.S. : currentCharF adalah karakter pertama dari kata
   F.S. : currentWordF berisi kata yang sudah diakuisisi;
          currentCharF = BLANK atau currentCharF = MARKF;
          currentCharF adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   currentWordF = createWordfromString("");
   
   int i = 0;
   while (currentCharF != MARKF && currentCharF != BLANK){
      currentWordF.TabWord[i] = currentCharF;
      ADVFILE();
      i++;
   }

   if (i > NMax){
      currentWordF.Length = NMax;
   }

   else{
      currentWordF.Length = i;
   }
}