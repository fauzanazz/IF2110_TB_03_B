#include "../Database/database.h"

int idPengguna(char *nama){
    int i = 0;
    Word temp = createWordfromString(nama);
    while (i < databasePengguna.usercount){
        
        if (isWordEqual(databasePengguna.user[i].Nama, temp)){
            return i;
        }
        i++;
    }
    return -1;
}

//DONE
void BacaPengguna(){
    STARTFILE("IO/pengguna.config");

    databasePengguna.usercount = currentCharF - '0';

    ADVFILE();
    ADVFILE();

    int i = 0;
    while (i < databasePengguna.usercount){
        int j = 0;

        //Baca nama
        while (!EOPF && j < 20){
            databasePengguna.user[i].Nama.TabWord[j++] = currentCharF;
            databasePengguna.user[i].Nama.Length++;
            ADVFILE();
        }

        //Baca Password
        j = 0;
        ADVFILE();
        while (!EOPF && j < 20){
            databasePengguna.user[i].Pass.TabWord[j++] = currentCharF;
            ADVFILE();
        }

        //Baca Bio
        j = 0;
        ADVFILE();
        while (!EOPF && j < 135){
            databasePengguna.user[i].Bio.TabWord[j++] = currentCharF;
            ADVFILE();
        }

        //Baca NoHP
        j = 0;
        ADVFILE();
        while (!EOPF && j < 12){
            databasePengguna.user[i].Phone.TabWord[j++] = currentCharF;
            databasePengguna.user[i].Phone.Length++;
            ADVFILE();
        }

        //Baca Weton
        j = 0;
        ADVFILE();
        while (!EOPF && j < 12){
            databasePengguna.user[i].Weton.TabWord[j++] = currentCharF;
            databasePengguna.user[i].Weton.Length++;
            ADVFILE();
        }

        //Baca Jenis Akun
        char *temp = "";

        j = 0;
        ADVFILE();
        while (!EOPF && j < 12){
            temp = stringConcatChar(temp, currentCharF);
            ADVFILE();
        }
        
        if (stringCompare(temp, "Privat")){
            databasePengguna.user[i].Publik = false;
        } else {
            databasePengguna.user[i].Publik = true;
        }

        //Baca FotoProfil
        ADVFILE();
        j = 0;
        while (j < 5){
            int k = 0;
            while (k < 10){
                IgnoreSpace();
                databasePengguna.user[i].ProfilePic.pix[j][k] = (int) currentCharF;
                k++;
                ADVFILE();
            }

            ADVFILE();
            j++;
        }

        i++;
    }

    CreateGraf(&GFriend);

    int j;
    for (i = 0; i < databasePengguna.usercount; i++){
        for (j = 0; j < databasePengguna.usercount; j++){
            IgnoreSpace();
            GFriend.mat[i][j] = currentCharF - '0';
            ADVFILE();
        }
    }

    //Baca Permintaan Pertemanan
    IgnoreSpace();
    int k = currentCharF - '0';

    MakeEmpty(&dataFriendRequest, k);
    ADVFILE();
    for (i = 0; i < k; i++){
        friendRequest Temporary;
        IgnoreSpace();
        Temporary.id_target = currentCharF - '0';
        ADVFILE();
        IgnoreSpace();
        Temporary.id_user = currentCharF - '0';
        ADVFILE();
        IgnoreSpace();
        Temporary.popularity = currentCharF - '0';
        ADVFILE();

        Enqueue(&dataFriendRequest, Temporary);
    }

     CloseFile();
}

void PrintPengguna(){
    int i = 0;
    while (i < databasePengguna.usercount){
        printf("Nama : ");
        displayWord(databasePengguna.user[i].Nama);
        printf("\n");
        printf("Password : ");
        displayWord(databasePengguna.user[i].Pass);
        printf("\n");
        printf("Bio : ");
        displayWord(databasePengguna.user[i].Bio);
        printf("\n");
        printf("NoHP : ");
        displayWord(databasePengguna.user[i].Phone);
        printf("\n");
        printf("Weton : ");
        displayWord(databasePengguna.user[i].Weton);
        printf("\n");
        printf("Jenis Akun : ");
        if (databasePengguna.user[i].Publik){
            printf("Privat\n");
        } else {
            printf("Publik\n");
        }
        printf("Foto Profil : \n");
        displayFotoProfil(databasePengguna.user[i].ProfilePic);
        printf("\n");
        i++;
    }

    int j;
    for (i = 0; i < databasePengguna.usercount; i++){
        for (j = 0; j < databasePengguna.usercount; j++){
            printf("%d ", GFriend.mat[i][j]);
        }
        printf("\n");
    }
}

//DONE
void BacaKicauan(){
    STARTFILE("IO/kicauan.config");

    int k = currentCharF - '0';

    CreateListDinKicau(&dataKicau, k);

    ADVFILE();
    while (k > 0)
    {
        IgnoreSpace();
        //ID KICAU
        Kicau_struct kicauan;
        kicauan.IdKicau = currentCharF - '0';

        //ISI KICAU
        ADVFILE();
        IgnoreSpace();
        int j = 0;
        while (!EOPF && j < 280)
        {
            kicauan.IsiKicauan.TabWord[j++] = currentCharF;
            kicauan.IsiKicauan.Length++;
            ADVFILE();
        }

        //JUMLAH LIKE
        ADVFILE();
        IgnoreSpace();
        kicauan.JumlahLike = 0;
        while (!EOPF)
        {
            kicauan.JumlahLike *= 10;
            kicauan.JumlahLike += currentCharF - '0';
            ADVFILE();
        }

        //ID PROFILE
        IgnoreSpace();
        char *temp = "";
        while (!EOPF)
        {
            temp = stringConcatChar(temp, currentCharF);
            ADVFILE();
        }

        //Mencari id Pengguna berdasarkan nama
        kicauan.IdProfile = idPengguna(temp);

        //TAGAR
        ADVFILE();
        j = 0;
        char *temp2 = "";
        while (!EOPF && j < 50)
        {
            temp2 = stringConcatChar(temp2, currentCharF);
            ADVFILE();
        }

        kicauan.Tagar = createWordfromString(temp2);
        

        //DATE TIME
        ADVFILE();
        DATETIME currentTime;
        int DD = 0;
        while (currentCharF != '/')
        {
            DD *= 10;
            DD += currentCharF - '0';
            ADVFILE();
        }

        ADVFILE();
        int MM = 0;
        while (currentCharF != '/')
        {
            MM *= 10;
            MM += currentCharF - '0';
            ADVFILE();
        }

        ADVFILE();
        int YYYY = 0;
        while (currentCharF != ' ')
        {
            YYYY *= 10;
            YYYY += currentCharF - '0';
            ADVFILE();
        }

        ADVFILE();
        int hh = 0;
        while (currentCharF != ':')
        {
            hh *= 10;
            hh += currentCharF - '0';
            ADVFILE();
        }

        ADVFILE();
        int mm = 0;
        while (currentCharF != ':')
        {
            mm *= 10;
            mm += currentCharF - '0';
            ADVFILE();
        }

        ADVFILE();
        int ss = 0;
        while (!EOPF)
        {
            ss *= 10;
            ss += currentCharF - '0';
            ADVFILE();
        }

        CreateDATETIME(&currentTime, DD, MM, YYYY, hh, mm, ss);
        
        kicauan.TanggalTerbit = currentTime;

        //Masukkan kicauan ke List Dinamis Data Kicauan
        insertLastKicau(&dataKicau, kicauan);
        ADVFILE();

        k--;
    }
    
}

void BacaUtas(){
    
}
int main(){
    BacaPengguna();
    BacaKicauan();
    BuatUtas(1);
    cetakUtas(0);
    HapusUtas(0, 1);
    cetakUtas(0);
}