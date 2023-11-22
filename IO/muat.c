#include "muat.h"
#include "../ADT/draf/stackDraft.h"
#include <sys/stat.h>

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

void MuatPengguna(char* file_path){
    createListPengguna(&databasePengguna);
    STARTFILE(concatString(file_path, "/pengguna.config"));

    STARTWORDFILE();
    databasePengguna.usercount = WordToInt(currentWordF);

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
            databasePengguna.user[i].Pass.Length++;
            ADVFILE();
        }

        //Baca Bio
        j = 0;
        ADVFILE();
        while (!EOPF && j < 135){
            databasePengguna.user[i].Bio.TabWord[j++] = currentCharF;
            databasePengguna.user[i].Bio.Length++;
            ADVFILE();
        }

        //Baca NoHP
        j = 0;
        ADVFILE();
        while (!EOPF && j < 15){
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

    GFriend.NEff = databasePengguna.usercount;

    //Baca Permintaan Pertemanan
    ADVWORDFILE();
    int k = WordToInt(currentWordF);

    MakeEmpty(&dataFriendRequest, k);
    for (i = 0; i < k; i++){
        friendRequest Temporary;
        ADVWORDFILE();
        Temporary.id_user = WordToInt(currentWordF);
        ADVWORDFILE();
        Temporary.id_target = WordToInt(currentWordF);

        int temp = 0;
        while (!EOPF)
        {
            temp *= 10;
            temp += currentCharF - '0';
            ADVFILE();
        }
        Temporary.popularity = temp;

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

void MuatKicauan(char *file_path){
    STARTFILE(concatString(file_path, "/kicauan.config"));

    STARTWORDFILE();
    int k = WordToInt(currentWordF);

    CreateListDinKicau(&dataKicau, k);

    ADVFILE();
    while (k > 0)
    {
        IgnoreSpace();
        //ID KICAU
        Kicau_struct kicauan;
        ADVWORDFILE();
        kicauan.IdKicau = WordToInt(currentWordF);

        //ISI KICAU
        IgnoreSpace();

        Word isi = createWordfromString("");

        int j = 0;
        while (!EOPF && j < 280)
        {
            isi.TabWord[j++] = currentCharF;
            isi.Length++;
            ADVFILE();
        }

        kicauan.IsiKicauan = isi;

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

    CloseFile();
}

void MuatUtas(char *file_path){
    CreateListUtas(&dataUtas, 10);

    STARTFILE(concatString(file_path, "/utas.config"));

    int i = currentCharF - '0';

    ADVFILE();
    ADVFILE(); 

    while (i > 0){

        // ID KICAUAN
        ListUtas tempUtas;

        int idKicau = 0;

        while (!EOPF)
        {
            idKicau *= 10;
            idKicau += currentCharF - '0';
            ADVFILE();
        }
        
        CreateUtas(&tempUtas, idKicau);

        ADVFILE();
        IgnoreSpace();

        //BANYAK UTAS
        int j = currentCharF - '0';

        ADVFILE();
        while (j > 0){
            IgnoreSpace(); 

            Kicau_struct tempKicauan;
            Word isi = createWordfromString("");

            //ISI UTAS
            int k = 0;
            while (!EOPF){
                isi.TabWord[k++] = currentCharF;
                isi.Length++;
                ADVFILE();
            }
            tempKicauan.IsiKicauan = isi;

            IgnoreSpace();
            char *temp = "";
            while (!EOPF){
                temp = stringConcatChar(temp, currentCharF);
                ADVFILE();
            }

            //Mencari id Pengguna berdasarkan nama
            tempKicauan.IdProfile = idPengguna(temp);

            IgnoreSpace();

            //DATE TIME
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

            tempKicauan.IdKicau = -1;
            tempKicauan.TanggalTerbit = currentTime;
            tempKicauan.Tagar = createWordfromString("");
            tempKicauan.JumlahLike = 0;

            insertLastUtas(&tempUtas, tempKicauan);
            j--;
        }
        
        insertLastListUtas(&dataUtas, tempUtas);

        ADVFILE();
        i--;
    }

    CloseFile();
}

void MuatDraf(char *file_path){
    CreateEmptyListUserDraft(&dataDraf);
    STARTFILE(concatString(file_path, "/draf.config"));

    STARTWORDFILE();

    //Banyak Pengguna Draft
    int i = WordToInt(currentWordF);

    while (i > 0){
        ADVFILE();
        //Mengambil 1 line yang berisi username dan banyak draft
        char *temp = "";

        while (!EOPF){
            temp = stringConcatChar(temp, currentCharF);
            ADVFILE();
        }

        //Ambil banyak draft dari belakang
        int j = stringLength(temp) - 1;
        int banyakDraf = 0;
        int multiplier = 1;
        while (temp[j] != ' ')
        {
            banyakDraf += (temp[j] - '0') * multiplier;
            multiplier *= 10;
            j--;
        }

        int k = 0;
        char *userName = "";
        while ( k < j)
        {
            userName = stringConcatChar(userName, temp[k]);
            k++;
        }

        StackDraft EmptyStack;
        CreateEmptyStackDraft(&EmptyStack);

        while (banyakDraf > 0)
        {
            ADVFILE();
            Draft temp;
            CreateEmptyDraft(&temp);

            Word isi = createWordfromString("");

            //Isi
            int l = 0;
            while (!EOPF && l < 280)
            {
                isi.TabWord[l++] = currentCharF;
                isi.Length++;
                ADVFILE();
            }

            temp.DrafContent = isi;


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

            temp.dateLastEdited = currentTime;

            PushStackDraft(&EmptyStack, temp, createWordfromString(userName));

            banyakDraf--;
        }

        StackDraft ReverseDraft;
        Draft tempReverse;
        CreateEmptyDraft(&tempReverse);
        CreateEmptyStackDraft(&ReverseDraft);

        while (!isEmptyStackDraft(EmptyStack))
        {
            PopStackDraft(&EmptyStack, &tempReverse);
            PushStackDraft(&ReverseDraft, tempReverse, EmptyStack.UserName);   
        }

        insertNewUserDraft(&dataDraf, ReverseDraft);
        i--;
    }    

    CloseFile();
}

void MuatBalasan(char* file_path){
    CreateListBalasan(&listBalasan);
    STARTFILE(concatString(file_path, "/balasan.config"));

    STARTWORDFILE();

    int loopKicau = WordToInt(currentWordF);
    for (int i = 0; i < loopKicau; i++ ){

        ADVWORDFILE();
        int id_kicauan = WordToInt(currentWordF);

        Tree temptree;
        createEmptyTree(&temptree, id_kicauan);
        insertLastBalasan(&listBalasan, temptree);

        BalasanStruct tempRootBalasan;
        tempRootBalasan.ID_balasan = -1;
        tempRootBalasan.ID_Author = -1;
        tempRootBalasan.TextBalasan = createWordfromString("");

        DATETIME dummy;
        CreateDATETIME(&dummy, 0, 0, 0, 0, 0, 0);
        tempRootBalasan.DT = dummy;

        listBalasan.T[i].root = newNodeBalasan(tempRootBalasan);

    

        ADVWORDFILE();
        int loopBalasan = WordToInt(currentWordF);
        for (int j = 0; j < loopBalasan; j++){

            BalasanStruct tempBalasan;

            // Parent Root
            ADVWORDFILE();
            int idTarget_ = WordToInt(currentWordF);

            // ID Balasan
            ADVWORDFILE();
            if (i == 0 && j == 0){
                listBalasan.LastID = WordToInt(currentWordF);
            } else if (listBalasan.LastID < WordToInt(currentWordF)){
                listBalasan.LastID = WordToInt(currentWordF);
            }
            int id_balasan = WordToInt(currentWordF);
            tempBalasan.ID_balasan = id_balasan;

            Word isi = createWordfromString("");
            int j = 0;
            while (!EOPF && j < 280)
            {
                isi.TabWord[j++] = currentCharF;
                isi.Length++;
                ADVFILE();
            }

            tempBalasan.TextBalasan = isi;

            // ID Author
            ADVFILE();
            IgnoreSpace();
            char *tempChar = "";
            while (!EOPF)
            {
                tempChar = stringConcatChar(tempChar, currentCharF);
                ADVFILE();
            }

            //Mencari id Pengguna berdasarkan nama
            tempBalasan.ID_Author = idPengguna(tempChar);

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

            tempBalasan.DT = currentTime;

            if (idTarget_ == -1){
                if (listBalasan.T[i].root == NULL){
                    listBalasan.T[i].root = newNodeBalasan(tempBalasan);
                } else {
                    addChild(listBalasan.T[i].root, newNodeBalasan(tempBalasan));
                }

            } else {
                Node* temp = findNode(listBalasan.T[i].root, idTarget_);
                if (temp == NULL){
                    printf("Tidak ditemukan node dengan ID = %d\n", idTarget_);
                }
                addChild(temp, newNodeBalasan(tempBalasan));
            }
        }
    }

    CloseFile();
}

int Muat(){
    printf("\nMasukkan folder konfigurasi untuk dimuat:\n");

    STARTWORD();

    struct stat st;
    
    // Use stat to check if the folder exists
    char *inputFolder = concatWordCharToString(currentWord, "");
    if (stat(inputFolder, &st) == 0 && S_ISDIR(st.st_mode)) {
        printf("\nAnda akan melakukan pemuatan dari folder %s\n", inputFolder);

        MuatPengguna(inputFolder);
        MuatKicauan(inputFolder);
        MuatUtas(inputFolder);
        MuatDraf(inputFolder);
        MuatBalasan(inputFolder);

        printf("Mohon tunggu...\n");
        printf("1..\n");
        printf("2..\n");
        printf("3..\n");

        printf("\nFolder konfigurasi berhasil dimuat!\n");

        return 1;
    } else {
        printf("Folder tidak ditemukan.\n");
    }
    return 0;
}