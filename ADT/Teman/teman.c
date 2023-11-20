#include <stdio.h>
#include "teman.h"
#include "../../Database/database.h"

void daftarTeman(int UID){
/* I.S. UID adalah User ID yang valid */
/* F.S. Menampilkan daftar teman pengguna dengan User ID UID */

    /* KAMUS LOKAL */
    int i, cntFriend;

    /* ALGORITMA */
    cntFriend = hitungTeman(UID);

    if (cntFriend == 0){ // jika belum punya teman
        printf("User belum mempunyai teman\n");
    } else { // jika punya teman
        printf("User memiliki %d teman\n", cntFriend);
        printf("Daftar teman User\n");
        
        for (i = 0; i < NEFF(GFriend); i++){
        /* loop untuk menampilkan semua teman */
            if ((ELMTG(GFriend, UID, i) == 1) && (UID != i)){
                printf("| ");displayWord(databasePengguna.user[i].Nama);
            }
        }
    }

}

void hapusTeman(int UIDSelf){
/* I.S. Pengguna dengan User ID UIDSelf berteman dengan pengguna dengan User ID UIDFriend */
/* F.S. Pengguna dengan User ID UIDSelf tidak lagi berteman dengan pengguna dengan User ID UIDFriend, hubungan pada adjacency matrix GFriend berubah (1 -> 0) */

    /* KAMUS LOKAL */
    Word username, confirm, yes, no;
    int uidUser, uidFriend;

    /* ALGORITMA */
    /* Siapkan token yes dan no */
    yes.TabWord[0] = 'Y';
    yes.TabWord[1] = 'A';
    yes.Length = 2;
    no.TabWord[0] = 'T';
    no.TabWord[1] = 'I';
    no.TabWord[2] = 'D';
    no.TabWord[3] = 'A';
    no.TabWord[4] = 'K';
    no.Length = 5;

    /* Input nama user yang ingin dihapus */
    printf("Masukkan nama pengguna:\n");
    START();

    IgnoreBlanks();
    char *temp = "";
    while (!EOP){
        temp = stringConcatChar(temp, currentChar);
        ADV();
    }

    printf("%s \n", temp);
    username = createWordfromString(temp);

    // Mencari UID pengguna saat ini dan teman yang dimaksud
    uidUser = uidUsername(databasePengguna.user[ActiveUser].Nama);
    uidFriend = uidUsername(username);

    if ((isUserValid(username)) && (isConnected(GFriend, uidUser, uidFriend))){ // Jika username ada pada daftar pengguna dan merupakan teman current user
        /* Konfirmasi */
        printf("Apakah anda yakin ingin menghapus %s", WordToString(username));printf(" dari daftar teman anda? (YA/TIDAK)\n");
        STARTWORD();
        confirm = currentWord;
        if (isWordEqual(confirm, no)){ // jika TIDAK
            printf("Penghapusan teman dibatalkan.\n");
        } else if (isWordEqual(confirm, yes)) { // jika YA
            removeEdge(&GFriend, uidUser, uidFriend);
            printf("%s", WordToString(username));printf(" berhasil dihapus dari daftar teman Anda.\n");
        } else {
            printf("Input tidak valid.\n");
        }
    } else if ((isUserValid(username)) && (!isConnected(GFriend, uidUser, uidFriend))){ // Jika username ada pada daftar pengguna tetapi bukan teman current user
        printf("%s", WordToString(username));printf(" bukan teman Anda.\n");
    } else { // Jika tidak ada pengguna dengan nama yang dimasukkan
        printf("Tidak ada pengguna dengan nama ");printf("%s", WordToString(username));printf("!\n");
    }
}

int hitungTeman(int idx){
/* Mengembalikan banyak teman pengguna dengan User ID UID yang di-assign dengan index idx pada adjacency matrix Graf GFriend */

    /* KAMUS LOKAL */
    int i, count;

    /* ALGORITMA */
    count = 0;
    for (i = 0; i < NEFF(GFriend); i++){
        if ((ELMTG(GFriend, idx, i) == 1) && (idx != i)){
            count = count + 1;
        }
    }
    return count;
}

boolean isUserValid(Word UserName){
/* Mengembalikan true jika UserName adalah nama pengguna yang valid */

    /* KAMUS LOKAL */
    int i, cntUser;
    boolean valid;

    /* ALGORITMA */
    // cntUser sebagai variabel untuk menyimpan banyak pengguna
    cntUser = NEFF(GFriend);

    // Loop semua pengguna di database pengguna untuk mengecek apakah UserName valid
    valid = false;
    for (i = 0; i < cntUser; i++){
        if (isWordEqual(databasePengguna.user[i].Nama, UserName)){
            valid = true;
        }
    }

    return valid;
}

int uidUsername(Word UserName){
/* Mengembalikan UID pengguna dengan nama UserName */

    /* KAMUS LOKAL */
    int i, cntUser, uid;

    /* ALGORITMA */
    // Inisialisasi variabel uid;
    uid = -1;

    // cntUser sebagai variabel untuk menyimpan banyak pengguna
    cntUser = NEFF(GFriend);

    if (isUserValid(UserName)){ // Pengecekan apakah UserName merupakan nama pengguna yang valid atau tidak
        // Loop untuk mencari UID pengguna dengan nama UserName
        for (i = 0; i < cntUser; i++){
            if (isWordEqual(databasePengguna.user[i].Nama, UserName)){
                uid = i;
            }
        }
    }

    return uid;
}