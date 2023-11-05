#include <stdio.h>
#include "../boolean.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
   while (currentChar == BLANK) {
      ADV();
   }
}
void STARTWORD()
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
{
   int i = 0;
   while (currentChar != MARK && currentChar != BLANK){
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