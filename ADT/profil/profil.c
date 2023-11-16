#include "profil.h"
#include <stdio.h>

void gantiProfil(Pengguna *user){
    int i,j=0;
    boolean Valid,flagVal;
    Valid=false;
    Word Temp;
    lihatProfil(*user);
    
    while(!Valid){
        printf("Masukkan Bio:\n");
        START();
        i=0;
        while (currentChar != MARK /* && currentChar != LINEFEED */){
            if(currentChar != LINEFEED){
                currentWord.TabWord[i]=currentChar;
            }
            ADV();
            i++;
        }
        ADV();
        
        if(i>135){
            printf("Bio Terlalu Panjang!\n");
        }
        else{
            Valid=true;
            currentWord.Length=i;
        }
    }
    for (i=0;i<currentWord.Length;i++){
        (*user).Bio.TabWord[i]=currentWord.TabWord[i];
    }
    (*user).Bio.Length=currentWord.Length;
    printf("\n");
    Valid=false;
    printf("Masukkan No. HP:\n");
    while (!Valid){
        START();
        i=0;
        while (currentChar != MARK /* && currentChar != LINEFEED */){
            if(currentChar != LINEFEED){
                currentWord.TabWord[i]=currentChar;
            }
            ADV();
            i++;
        }
        ADV();
        currentWord.Length=i;
        if (i>15){
            printf("No. HP terlalu panjang!\n");
        }
        else{
            flagVal=true;
            for(i=0;i<currentWord.Length;i++){
                if (currentWord.TabWord[i]<'0' || currentWord.TabWord[i]>'9'){
                    flagVal=false;
                }
            }
            if(!flagVal){
                printf("No HP tidak valid. Masukkan lagi yuk!\n");
            }
            else{
                Valid=true;
            }
        }
    }
    (*user).Phone.Length=i;
    for(i=0;i<(*user).Phone.Length;i++){
        (*user).Phone.TabWord[i]=currentWord.TabWord[i];
    }
    printf("\n");

    Valid=false;
    Word pon,wage,legi,kliwon,pahing;
    pon.TabWord[0]='p';
    pon.TabWord[1]='o';
    pon.TabWord[2]='n';
    pon.Length=3;

    wage.TabWord[0]='w';
    wage.TabWord[1]='a';
    wage.TabWord[2]='g';
    wage.TabWord[3]='e';
    wage.Length=4;

    legi.TabWord[0]='l';
    legi.TabWord[1]='e';
    legi.TabWord[2]='g';
    legi.TabWord[3]='i';
    legi.Length=4;

    kliwon.TabWord[0]='k';
    kliwon.TabWord[1]='l';
    kliwon.TabWord[2]='i';
    kliwon.TabWord[3]='w';
    kliwon.TabWord[4]='o';
    kliwon.TabWord[5]='n';
    kliwon.Length=6;

    kliwon.TabWord[0]='p';
    kliwon.TabWord[1]='a';
    kliwon.TabWord[2]='h';
    kliwon.TabWord[3]='i';
    kliwon.TabWord[4]='n';
    kliwon.TabWord[5]='g';
    kliwon.Length=6;

    while (!Valid){
        printf("Masukkan Weton:\n");
        START();
        i=0;
        while (currentChar != MARK /* && currentChar != LINEFEED */){
            if(currentChar != LINEFEED){
                currentWord.TabWord[i]=currentChar;
            }
            ADV();
            i++;
        }
        ADV();
        currentWord.Length=i;
        Temp.Length=i;
        for (j=0;j<i;j++){
            Temp.TabWord[j]=currentWord.TabWord[j];
        }
        convertLower(&Temp);
        displayWord(Temp);

        if (identik(Temp,pon) || identik(Temp,wage) || identik(Temp,legi) || identik(Temp,pahing) || identik(Temp,kliwon) || Temp.Length==0){
            Valid=true;
        }
        else{
            printf("Weton tidak valid. Masukkan lagi yuk!\n");
        }
    }
    (*user).Weton.Length=currentWord.Length;
    for(i=0;i<(*user).Weton.Length;i++){
        (*user).Weton.TabWord[i]=currentWord.TabWord[i];
    }
    printf("Profil Anda sudah berhasil diperbarui!\n");
}
void lihatProfil(Pengguna user){
    int i;
    if (user.Publik){
        printf("| Nama: ");
        for (i=0;i<user.Nama.Length;i++){
            printf("%c", user.Nama.TabWord[i]);
        }
        printf("\n");
        printf("| Bio Akun: ");
        for(i=0;i<user.Bio.Length;i++){
            printf("%c", user.Bio.TabWord[i]);
        }
        printf("\n");
        printf("| No HP: ");
        for (i=0;i<user.Phone.Length;i++){
            printf("%c", user.Phone.TabWord[i]);
        }
        printf("\n");
        printf("| Weton: ");
        for (i=0;i<user.Weton.Length;i++){
            printf("%c", user.Weton.TabWord[i]);
        }
        printf("\n");
        printf("Foto profil:\n");
        displayFotoProfil(user.ProfilePic);
        printf("\n");
    }
    else{
        printf("Wah, akun ");
        for (i=0;i<user.Nama.Length;i++){
            printf("%c", user.Nama.TabWord[i]);
        }
        printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil");
        for (i=0;i<user.Nama.Length;i++){
            printf("%c", user.Nama.TabWord[i]);
        }
        printf("!\n");
    }
}

void aturJenisAkun(Pengguna *user){
    boolean Valid=false;
    if ((*user).Publik){
        while (!Valid){
            printf("Saat ini, akun Anda adalah akun Publik.\n");
            printf("Ingin mengubah ke akun Privat?\n");
            printf("(YA/TIDAK)\n");
            STARTWORD();
            convertLower(&currentWord);
            if(currentWord.TabWord[0]=='y' && currentWord.TabWord[1]=='a' && currentWord.Length==2){
                (*user).Publik=false;
                printf("Akun anda sudah diubah menjadi akun Privat.\n");
                Valid=true;
            }
            else if (currentWord.TabWord[0]=='t' && currentWord.TabWord[1]=='i' && currentWord.TabWord[2]=='d' && currentWord.TabWord[3]=='a' && currentWord.TabWord[4]=='k' && currentWord.Length==2){
                printf("Akun anda tetap menjadi akun Publik.\n");
                Valid=true;
            }
            else{
                printf("Input tidak valid.\n");
            }
        }
    }
    else{
        while (!Valid){
            printf("Saat ini, akun Anda adalah akun Privat.\n");
            printf("Ingin mengubah ke akun Publik?\n");
            printf("(YA/TIDAK)\n");
            STARTWORD();
            convertLower(&currentWord);
            if(currentWord.TabWord[0]=='y' && currentWord.TabWord[1]=='a' && currentWord.Length==2){
                (*user).Publik=true;
                printf("Akun anda sudah diubah menjadi akun Publik.\n");
                Valid=true;
            }
            else if (currentWord.TabWord[0]=='t' && currentWord.TabWord[1]=='i' && currentWord.TabWord[2]=='d' && currentWord.TabWord[3]=='a' && currentWord.TabWord[4]=='k' && currentWord.Length==2){
                printf("Akun anda tetap menjadi akun Privat.\n");
                Valid=true;
            }
            else{
                printf("Input tidak valid.\n");
            }
        }
    }
}

void UBAH_FOTO_PROFIL(Pengguna *user){
    printf("Foto profil Anda saat ini adalah\n");
    displayFotoProfil((*user).ProfilePic);
    printf("Masukkan foto profil yang baru\n");
    readFotoProfil(&(*user).ProfilePic);
    printf("Foto profil anda sudah berhasil diganti!\n");
}