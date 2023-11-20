#include "profil.h"
#include "../../Database/database.h"
#include <stdio.h>

void gantiProfil(Pengguna *user){
    int i,j=0;
    boolean Valid,flagVal;
    Valid=false;
    Word Temp;
    lihatProfil(*user);
    
    while(!Valid){
        int i = 0;
        printf("Masukkan Bio:\n");
        START();
        while (currentChar != MARK /* && currentChar != LINEFEED */){
            if(currentChar != LINEFEED){
                currentWord.TabWord[i]=currentChar;
            }
            ADV();
            i++;
        }
        ADV();
        currentWord.Length=i;
        if(i>135){
            printf("Bio Terlalu Panjang!\n");
        }
        else{
            Valid=true;
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
    printf("Masukkan Weton:\n");
    while (!Valid){
        START();
        i=0;
        flagVal=true;
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

        if (currentWord.Length==0){
            Valid=true;
        }
        else if (currentWord.Length==3){
            for (j=0;j<3;j++){
                if (Temp.TabWord[j]!=pon[j]){
                    flagVal=false;
                }
            }
        }
        else if (currentWord.Length==4){
            if (Temp.TabWord[0] == 'w'){
                for (j=1;j<4;j++){
                    if (Temp.TabWord[j]!=wage[j]){
                        flagVal=false;
                    }
                }
            }
            else{
                for (j=1;j<4;j++){
                    if (Temp.TabWord[j]!=legi[j]){
                        flagVal=false;
                    }
                }
            }
        }
        else if (currentWord.Length==6){
            if (Temp.TabWord[0]=='p'){
                for (j=1;j<6;j++){
                    if (Temp.TabWord[j]!=pahing[j]){
                        flagVal=false;
                    }
                }
            }
            else{
                for (j=1;j<6;j++){
                    if (Temp.TabWord[j]!=kliwon[j]){
                        flagVal=false;
                    }
                }
            }
        }
        else {
            flagVal=false;
        }
        if(!flagVal){
            printf("Weton tidak valid. Masukkan lagi yuk!\n");
        }
        else{
            Valid=true;
        }
    }
    (*user).Weton.Length=i;
    for(i=0;i<(*user).Weton.Length;i++){
        (*user).Weton.TabWord[i]=currentWord.TabWord[i];
    }
    printf("Profil Anda sudah berhasil diperbarui!\n");
}
void lihatProfil(Pengguna user){
    int i;

    char *tempUser = WordToString(user.Nama);
    if (user.Publik || isWordEqual(databasePengguna.user[ActiveUser].Nama,user.Nama) || isConnected(GFriend,ActiveUser,idPengguna(tempUser))){
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
    gantiFotoProfil(&(*user).ProfilePic);
    printf("Foto profil anda sudah berhasil diganti!\n");
}