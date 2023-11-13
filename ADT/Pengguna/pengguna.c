#include "pengguna.h"
#include <stdio.h>

long long int stringToInt(Word word){
    int i;
    long long int sum;
    sum=0;
    for (i=0;i<word.Length;i++){
        sum=sum*10+(word[i]-48);
    }
    return sum;
}

boolean cekAngka(Word word){
    int i;
    boolean valid;
    for (i=0;i<word.Length;i++){
        if(word.TabWord[i]<"0" || word.Tabword[i]>"9"){
            valid=false;
        }
    }
}

boolean cekWeton(Word weton){
    int i,j;
    boolean valid;
    Word temp;
    temp=weton;
    valid = true;
    convertLower(temp);

    if (temp.length==7){

        for(i=0;i<temp.Length;i++){
            if (temp.TabWord[i]!=pahing[i]){
                valid=false;
            }
        }

        for(i=0;i<temp.Length;i++){
            if (temp.TabWord[i]!=kliwon[i]){
                valid=false;
            }
        }

    }

    if (temp.length==5){

        for(i=0;i<temp.Length;i++){
            if (temp.TabWord[i]!=wage[i]){
                valid=false;
            }
        }

        for(i=0;i<temp.Length;i++){
            if (temp.TabWord[i]!=legi[i]){
                valid=false;
            }
        }

    }

    if (temp.length==4){
        for(i=0;i<temp.Length;i++){
            if (temp.TabWord[i]!=pon[i]){
                valid=false;
            }
        }
    }
    return valid;
}

void convertLower(Word word){
    int i;
    for (i=0;i<word.Length;i++){
        if (word.TabWord[i]>="A" || word.TabWord[i]<="Z"){
            word.TabWord[i]=word.TabWord[i]+32;
        }
    }
}

boolean cekLengthUsername(Word name){
    return (name.Length<21);
}

boolean cekLengthBio(Word bio){
    return(bio.Length<136);
}

void writePengguna(Word word){
    FILE *f = fopen("...\\output/Config\\pengguna.config","a");
    if (f==NULL){
        printf("file tidak ditemukan");
    }
    else{
        fprintf(f,word);
        fprintf(f,"\n");
    }
    fclose(f);
}

int getJumlahPengguna(){
    FILE *f = fopen("...\\output/Config\\pengguna.config","r");
    if (f==NULL){
        printf("file tidak ditemukan");
        return 0;
        fclose(f);
    }
    else{
        int i;
        char[2] temp;
        fgets(temp,2,f);
        i=stringToInt(temp)
        fclose(f);
        return i;
    }
}

