#include "pengguna.h"
#include "../../Database/database.h"
#include <stdio.h>

void convertLower(Word *word){
    int i;
    for (i=0;i<(*word).Length;i++){
        if ((*word).TabWord[i]>='A' && (*word).TabWord[i]<='Z'){
            (*word).TabWord[i]=(char) ((int)(*word).TabWord[i]+32);
        }
    }
}

boolean identik(Word word1, Word word2){
    boolean persis;
    persis=true;
    if (word1.Length==word2.Length){
        int i;
        for (i=0;i<word1.Length;i++){
            if (word1.TabWord[i]!=word2.TabWord[i]){
                persis=false;
            }
        }
    }
    else{
        persis=false;
    }
    return persis;
}

void createListPengguna(ListPengguna *lp){
    (*lp).usercount=0;
    for (int a=0;a<20;a++){
        inisialisasiPengguna(&(*lp).user[a]);
    }
}

void inisialisasiNamaPengguna(Pengguna *user){
    (*user).Nama.Length=0;
    int i;
    for (i=0;i<20;i++){
        (*user).Nama.TabWord[i]=' ';
    }
    (*user).Nama.Length=0;
}

void inisialisasiPassPengguna(Pengguna *user){
    (*user).Pass.Length=0;
    int i;
    for (i=0;i<20;i++){
        (*user).Pass.TabWord[i]=' ';
    }
    (*user).Pass.Length=0;
}

void inisialisasiBioPengguna(Pengguna *user){
    int i;
    for (i=0;i<135;i++){
        (*user).Bio.TabWord[i]=' ';
    }
    (*user).Bio.Length=0;
}
void inisialisasiPhonePengguna(Pengguna *user){
    (*user).Phone.Length=0;
    int i;
    for (i=0;i<15;i++){
        (*user).Phone.TabWord[i]=' ';
    }
    (*user).Phone.Length=0;
}

void inisialisasiWetonPengguna(Pengguna *user){
    int i;
    for (i=0;i<10;i++){
        (*user).Weton.TabWord[i]=' ';
    }
    (*user).Weton.Length=0;
}

void inisialisasiStatusPengguna(Pengguna *user){
    (*user).Publik=true;
}

void inisialisasiFotoPengguna(Pengguna *user){
    createFotoProfil(&(*user).ProfilePic);
}

void inisialisasiPengguna(Pengguna *user){
    inisialisasiNamaPengguna(user);
    inisialisasiPassPengguna(user);
    inisialisasiBioPengguna(user);
    inisialisasiPhonePengguna(user);
    inisialisasiWetonPengguna(user);
    inisialisasiStatusPengguna(user);
    inisialisasiFotoPengguna(user);
}

void Daftar(ListPengguna *lp){
    if (!isLogin && (*lp).usercount < 20){
        int i;
        boolean Valid=false;
        int cnt = COUNT(*lp);
        while (!Valid){
            printf("Masukkan nama:\n");
            START();
            i=0;
            char *temp = "";
            while (currentChar != MARK /* && currentChar != LINEFEED */){
                if(currentChar != LINEFEED){
                    temp = stringConcatChar(temp, currentChar);
                }
                ADV();
                i++;
            }
            ADV();
            if (i > 20){
                // currentWord.Length = i;
                printf("Nama Terlalu Panjang!\n");
            }
            else{
                currentWord= createWordfromString(temp);
                i=0;
                while(i<COUNT(*lp) && identik(currentWord,USER(*lp, i).Nama)==false){
                    i++;
                }
                if (i<COUNT(*lp)){
                    printf("Wah, sayang sekali nama tersebut telah diambil.\n");
                }
                else{
                    Valid=true;
                }
            }
        }  
        for (i=0;i<currentWord.Length;i++){
            USER(*lp, cnt).Nama.TabWord[i]=currentWord.TabWord[i];
        }
        USER(*lp, cnt).Nama.Length=currentWord.Length;

        Valid=false;
        while (!Valid){
            printf("Masukkan kata sandi:\n");
            i=0;
            START();
            char *temp = "";
            while (currentChar != MARK /* && currentChar != LINEFEED */){
                if(currentChar != LINEFEED){
                    temp = stringConcatChar(temp, currentChar);
                }
                ADV();
                i++;
            }
            ADV();
            if (i > 20){
                // currentWord.Length = NMax;
                printf("Password Terlalu Panjang!\n");
            }
            else{
                currentWord= createWordfromString(temp);
                Valid=true;
            }   
        }

        for (i=0;i<currentWord.Length;i++){
            USER(*lp, cnt).Pass.TabWord[i]=currentWord.TabWord[i];
        }
        USER(*lp, cnt).Pass.Length=currentWord.Length;
        COUNT(*lp)++;
        addEdge(&GFriend, cnt, cnt);
        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
    }

    else if (isLogin){
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
    }
        
    else{
        printf("Jumlah pengguna sudah 20.\n");
    }
}

void Masuk(ListPengguna *lp){
    if (!isLogin){
        int i = 0;
        boolean Valid = false;
        int cnt = COUNT(*lp);
        while (!Valid){
            printf("Masukkan nama:\n");
            START();

            char *tempInputNama = "";
            while (currentChar != MARK /* && currentChar != LINEFEED */){
                if(currentChar != LINEFEED){
                    tempInputNama = stringConcatChar(tempInputNama, currentChar);
                }
                ADV();
                i++;
            }
            currentWord = createWordfromString(tempInputNama);

            ADV();
            if (i > 20){
                printf("Nama Terlalu Panjang!\n");
            }
            else{
                i=0;
                while(i<cnt && identik(currentWord,USER(*lp, i).Nama)==false){
                    i++;
                }
                if (i<cnt){
                    Valid=true;
                }
                else{
                    printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
                }
            }
        }
        ActiveUser=i;
        Valid=false;

        while (!Valid){
            printf("Masukkan kata sandi:\n");
            i=0;
            // STARTWORD();

            char *tempInputPass = "";
            while (currentChar != MARK /* && currentChar != LINEFEED */){
                if(currentChar != LINEFEED){
                    tempInputPass = stringConcatChar(tempInputPass, currentChar);
                }
                ADV();
                i++;
            }
            currentWord = createWordfromString(tempInputPass);
            // ADV();
            i = currentWord.Length;
            if (i > 20){
                printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            }
            else{
                if (identik(currentWord,USER(*lp, ActiveUser).Pass)){
                    Valid=true;
                }
                else{
                    printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
                }
            }   
        }
        printf("Anda telah berhasil masuk dengan nama pengguna ");
        for (i=0;i<USER(*lp, ActiveUser).Nama.Length;i++){
            printf("%c",USER(*lp, ActiveUser).Nama.TabWord[i]);
        }
        printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
        isLogin=true;
    }
    else{
        printf("\nWah Anda sudah masuk. Keluar dulu yuk!\n");
    }
}

void Keluar(){
    if (!isLogin){
        printf("Anda belum login!\n");
        printf("Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
    else{
        printf("Anda telah keluar dari program BurBir.\n");
        printf("Sampai jumpa di penjelajahan berikutnya.\n");
        isLogin=false;
        ActiveUser = -1;
    }
}
