
/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine-file.h"

char currentCharF;
boolean EOPF;

static FILE *pitaF;
static int retvalF;

void STARTFILE(char *filename)
{      
       pitaF = fopen(filename, "r");

       if (pitaF == NULL)
       {
              perror("Error opening file");
       }
       ADVFILE();
}

void ADVFILE(){
       retvalF = fscanf(pitaF, "%c", &currentCharF);

       while (currentCharF == '\r')
       {
              retvalF = fscanf(pitaF, "%c", &currentCharF);
       }
       
       EOPF = (currentCharF == MARKF) || feof(pitaF) || currentCharF == '\r';
}

void ReadLine(){
    while (currentCharF != MARKF && !EOPF){
       printf("%c", currentCharF); // Ganti ini sesuai dengan kebutuhan Anda
       ADVFILE();
    }
    printf("\n");
}

void IgnoreSpace(){
       while (currentCharF == SPACE || currentCharF == '\n')
       {
              ADVFILE();

              if (feof(pitaF)) break;
       }
       
}

void CloseFile(){
       fclose(pitaF);
}