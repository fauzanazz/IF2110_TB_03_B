#include <stdio.h>
#include "../boolean.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
   while (currentChar == BLANK || currentChar == LINEFEED) {
      ADV();
   }
}
void STARTWORD()

/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

{
   START();
   IgnoreBlanks();
   if (currentChar == MARK){
      EndWord = true;
   }
   else{
      EndWord = false;
      CopyWord();
   }
}

void ADVWORD()

/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
   IgnoreBlanks();
   if (currentChar == MARK){
      EndWord = true;
   }
   else{
      CopyWord();
      IgnoreBlanks();
   }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i = 0;
   while (currentChar != MARK && currentChar != BLANK && currentChar != LINEFEED){
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }

   if (i > NMax){
      currentWord.Length = NMax;
   }

   else{
      currentWord.Length = i;
   }
}

boolean CheckInput(char *s){
   int length = 0;
   while (s[length] != '\0')
   {
      length++;
   }

   if (currentWord.Length != length){
      return false;
   }

   int i;
   for ( i = 0; i < length; i++){
      if (currentWord.TabWord[i] != s[i]){
         return false;
      }
   }

   return true;
}

void displayWord (Word s){
   int i;
   for (i = 0; i < s.Length; i++){
      printf("%c", s.TabWord[i]);
   }
   printf("\n");
}

Word createWordfromString(char *s){
   Word w;
   int i = 0;
   while (s[i] != '\0'){
      w.TabWord[i] = s[i];
      i++;
   }
   w.Length = i;
   
   return w;
}

boolean isWordEqual(Word s1, Word s2){
   if (s1.Length != s2.Length){
      return false;
   }

   int i;
   for (i = 0; i < s1.Length; i++){
      if (s1.TabWord[i] != s2.TabWord[i]){
         return false;
      }
   }

   return true;
}

