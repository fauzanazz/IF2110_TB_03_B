#include "matrixprofil.h"
#include "../Pcolor/pcolor.h"
#include "../Mesin-Kata/wordmachine.h"
#include <stdio.h>

void createFotoProfil(Foto *F){
    int i,j;
    for (i=0;i<5;i++){
        for (j=0;j<10;j+=2){
            PIXEL(*F,i,j)=82;   
            PIXEL(*F,i,j+1)=42;
        }
    }
    int h,k;
    for (h=1;h<4;h++){
        for(k=2;k<8;k+=2){
            PIXEL(*F,h,k)=71;
            PIXEL(*F,h,k+1)=64;
        }
    }
    PIXEL(*F,1,4)=66;
    PIXEL(*F,1,5)=42;
    PIXEL(*F,3,4)=66;
    PIXEL(*F,3,5)=42;
}

void displayFotoProfil(Foto F){
    int i,j;
    for (i=0;i<5;i++){
        for (j=1;j<10;j+=2){
            if (PIXEL(F,i,j-1)==82){
                print_red(PIXEL(F,i,j));
                //printf("%d",F.pix[i][j]);
            }
            else if (PIXEL(F,i,j-1)==71){
                print_green(PIXEL(F,i,j));
                //printf("%d",F.pix[i][j]);
            }
            else{
                print_blue(PIXEL(F,i,j));
                //printf("%d",F.pix[i][j]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

void gantiFotoProfil(Foto *F){
    int i,j,numt;
    char t;
    STARTWORD();
    for (i=0;i<5;i++){
        for (j=0;j<10;j++){
            t=currentWord.TabWord[0];
            numt=(int) t;
            PIXEL(*F,i,j)=numt;
            ADVWORD();
        }
    }
}