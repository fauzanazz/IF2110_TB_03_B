#include "draft.h"
#include "../../Database/database.h"
#include "../Kicauan/kicauan.h"

void buatDraft(){
/* I.S. Stack draft user tidak penuh, user mungkin pengguna draft, mungkin tidak */
/* F.S. Membuat sebuah draft baru dan mem-push ke SDUser, jika user sebelumnya bukan pengguna draft, ditambahkan ke list pengguna draft LUD */

    /* KAMUS LOKAL */
    Draft content;
    Word draftContent, hapus, simpan, terbit, input;
    int draftLength, idxInLUD;
    boolean blank, valid;
    time_t currentTime;
    DATETIME currentDate;
    StackDraft stackDraft;

    /* ALGORITMA */
    // Siapkan Word hapus, simpan, terbit
    hapus = createWordfromString("HAPUS");
    simpan = createWordfromString("SIMPAN");
    terbit = createWordfromString("TERBIT");

    // Pengecekan Stack Draft penuh atau tidak
    if ((isUserDraft(dataDraf, databasePengguna.user[ActiveUser].Nama)) && (ADDR_TOPSD(LUD_IDX(dataDraf, ActiveUser)) == MaxElS - 1)){ // Jika Stack Draft penuh
        printf("Draf Anda penuh.\n");
        return;
    }

    printf("Masukkan draf:\n");
    CreateEmptyDraft(&content);

    // Mesin kata untuk menyimpan input draf
    blank = false;
    draftLength = 0;
    START();
    IgnoreBlanks();
    ignoreNewLine();
    while (currentChar != MARK){
        if (currentChar != BLANK){
            blank = true;
        }
        if ((blank) && (draftLength < NMax)){
            draftContent.TabWord[draftLength] = currentChar;
        }
        draftLength++;
        ADV();
    }
    if (draftLength >= 280){
        draftLength = 280;
    }
    draftContent.Length = draftLength;

    if (draftLength == 0){
        printf("Draf tidak boleh kosong!\n");
        return;
    }
    DCONTENT(content) = draftContent;

    // Konfirmasi apa yang ingin dilakukan dengan draf
    valid = false;
    while (!valid){
        printf("Apakah anda ingin menghapus (HAPUS), menyimpan (SIMPAN), atau menerbitkan (TERBIT) draf ini?\n");
        STARTWORD();
        input = currentWord;
        
        if (isWordEqual(input, hapus)){ // Jika ingin dihapus
            // Karena belum di push ke stack, tidak perlu di apa-apakan.
            printf("Draf telah berhasil dihapus!\n");
            valid = true;
        } else if ((isWordEqual(input, simpan)) || (isWordEqual(input, terbit))){ // Jika ingin disimpan atau diterbitkan
            // Menyimpan datetime saat disimpan
            time(&currentTime);
            ConvertTimeTtoDATETIME(currentTime, &currentDate);
            DDATE(content) = currentDate;

            // Pengecekan apakah current user adalah pengguna draft atau bukan
            if (!isUserDraft(dataDraf, databasePengguna.user[ActiveUser].Nama)){ // Jika awalnya bukan pengguna draft
                // Buat stack baru untuk user
                CreateEmptyStackDraft(&stackDraft);
                UNAME(stackDraft) = databasePengguna.user[ActiveUser].Nama;
                ADDR_TOPSD(stackDraft)++;
                TOPSD(stackDraft) = content;

                // Masukkan user ke list pengguna draft
                insertNewUserDraft(&dataDraf, stackDraft);
            } else { // Jika memang pengguna draft
                // Ambil index user pada list pengguna draft
                idxInLUD = indexInLUD(dataDraf, databasePengguna.user[ActiveUser].Nama);

                // Push draft ke stack pengguna
                PushStackDraft(&LUD_IDX(dataDraf, idxInLUD), content, databasePengguna.user[ActiveUser].Nama);
            }

            if (isWordEqual(input, terbit)){ // Jika ingin diterbitkan
                terbitDraft();
                printf("Draf telah berhasil diterbitkan\n");
                // print detail kicauan
            } else { // Jika hanya ingin disimpan
                printf("Draf telah berhasil disimpan!\n");
            }
            valid = true;
        }  else { // Input tidak valid
            printf("Input tidak valid, silakan masukkan ulang!\n");
        }
    }
}


void lihatDraft(){
/* I.S. User merupakan pengguna draft */
/* F.S. Draft terbaru User tampil pada layar */

    /* KAMUS LOKAL */
    int idxInLUD;
    Draft content;
    Word input, hapus, ubah, terbit, kembali;
    boolean valid;

    /* ALGORITMA */
    // Siapkan Word hapus, ubah, terbit, kembali
    hapus = createWordfromString("HAPUS");
    ubah = createWordfromString("UBAH");
    terbit = createWordfromString("TERBIT");
    kembali = createWordfromString("KEMBALI");

    if (!isUserDraft(dataDraf, databasePengguna.user[ActiveUser].Nama)){ // Jika bukan pengguna draft, artinya tidak memiliki draft
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    } else { // Jika pengguna draft
        // Ambil index user pada list pengguna draft dan isi top pada stack draft
        idxInLUD = indexInLUD(dataDraf, databasePengguna.user[ActiveUser].Nama);
        content = TOPSD(LUD_IDX(dataDraf, idxInLUD));
        
        // Tampilkan draft terakhir yang dibuat
        printf("Ini draf terakhir Anda:\n");
        printf("| %02d/%02d/%d %02d:%02d:%02d\n", DDATE(content).DD, DDATE(content).MM, DDATE(content).YYYY, DDATE(content).T.HH,DDATE(content).T.MM, DDATE(content).T.SS);
        printf("| ");
        displayWord(DCONTENT(content));

        // Konfirmasi apa yang ingin dilakukan dengan draf
        valid = false;
        while (!valid){
            printf("Apakah Anda ingin mengubah (UBAH), menghapus (HAPUS), atau menerbitkan (TERBIT) draf ini? (KEMBALI jika ingin kembali)\n");
            STARTWORD();
            input = currentWord;

            if (isWordEqual(input, hapus)){ // Jika draft ingin dihapus
                hapusDraft();
                valid = true;
            } else if (isWordEqual(input, ubah)){ // Jika draft ingin diedit
                editDraft();
                valid = true;
            } else if (isWordEqual(input, terbit)){ // Jika draft ingin diterbitkan
                terbitDraft();
                valid = true;
            } else if (isWordEqual(input, kembali)){ // Jika ingin kembali
                // Tidak mengubah apa-apa
                valid = true;
            } else { // Input tidak valid
                printf("Input tidak valid, silakan masukkan ulang!\n");
            }
        }

    }
}

void editDraft(){
/* I.S. User merupakan pengguna draft */
/* F.S. Draft terakhir yang dibuat user dapat diedit, dapat batal diedit */

    /* KAMUS LOKAL */
    int idxInLUD, draftNewLength;
    Word draftNewContent, input, hapus, simpan, terbit;
    Draft newContent; //content
    boolean blank, valid;
    time_t currentTime;
    DATETIME currentDate;

    /* ALGORITMA */
    // Siapkan Word hapus, simpan, terbit
    hapus = createWordfromString("HAPUS");
    simpan = createWordfromString("SIMPAN");
    terbit = createWordfromString("TERBIT");

    // Data index user pada list pengguna draft dan draft pada top stack
    idxInLUD = indexInLUD(dataDraf, databasePengguna.user[ActiveUser].Nama);
    // content = TOPSD(LUD_IDX(dataDraf, idxInLUD));

    // Membuat perubahan pada draft
    printf("Masukkan draf yang baru:\n");
    blank = false;
    draftNewLength = 0;
    START();
    while (currentChar != MARK){
        if (currentChar != BLANK){
            blank = true;
        }
        if ((blank) && (draftNewLength < NMax)){
            draftNewContent.TabWord[draftNewLength] = currentChar;
        }
        draftNewLength++;
        ADV();
    }
    if (draftNewLength >= 280){
        draftNewLength = 280;
    }
    draftNewContent.Length = draftNewLength;
    DCONTENT(newContent) = draftNewContent;

    // Konfirmasi apa yang ingin dilakukan dengan draf
    valid = false;
    while (!valid){
        printf("Apakah anda ingin menghapus (HAPUS), menyimpan (SIMPAN), atau menerbitkan (TERBIT) draf ini?\n");
        STARTWORD();
        input = currentWord;

        if (isWordEqual(input, hapus)){ // Jika ingin dihapus
            hapusDraft();
            printf("Draf telah berhasil dihapus!\n");
            valid = true;
        } else if ((isWordEqual(input, simpan)) || (isWordEqual(input, terbit))){ // Jika ingin disimpan atau diterbitkan
            // Menyimpan datetime saat disimpan
            time(&currentTime);
            ConvertTimeTtoDATETIME(currentTime, &currentDate);
            DDATE(newContent) = currentDate;

            // Mengganti top menjadi draft yang baru
            TOPSD(LUD_IDX(dataDraf, idxInLUD)) = newContent;

            if (isWordEqual(input, terbit)){ // Jika ingin diterbitkan
                terbitDraft();
                // print detail kicauan
            } else { // Jika hanya ingin disimpan
                printf("Perubahan draf telah berhasil disimpan!\n");
            }
            valid = true;
        } else { //  Input tidak valid
            printf("\nInput tidak valid, silakan masukkan ulang!\n");
        }
    }

}

void hapusDraft(){
/* I.S. User merupakan pengguna draft */
/* F.S. Draft terakhir yang dibuat user dihapus (di-pop dari stack draft), jika setelah penghapusan draftnya menjadi kosong, user dihapus dari list pengguna draft */

    /* KAMUS LOKAL */
    int idxInLUD;
    Draft content;

    /* ALGORITMA */
    // Data index user pada list pengguna draft dan draft pada top stack
    idxInLUD = indexInLUD(dataDraf, databasePengguna.user[ActiveUser].Nama);
    content = TOPSD(LUD_IDX(dataDraf, idxInLUD));

    // Pop stack draft dari Stack Draft
    PopStackDraft(&LUD_IDX(dataDraf, idxInLUD), &content);

    if (ADDR_TOPSD(LUD_IDX(dataDraf, idxInLUD)) == NilS){ // Jika stack draft menjadi kosong, artinya user tidak lagi menjadi pengguna draft dan dihapus dari list pengguna draft
        deleteDraftUser(&dataDraf, databasePengguna.user[ActiveUser].Nama);
    }

    printf("\nDraf telah berhasil dihapus!\n");
}

void terbitDraft(){
/* I.S. User merupakan pengguna draft */
/* F.S. Draft terakhir yang dibuat user diterbitkan (di-pop dari stack draft), jika setelah penghapusan draftnya menjadi kosong, user dihapus dari list pengguna draft */

    /* KAMUS LOKAL */
    int idxInLUD;
    Draft content;
    Word draftContent;
    Kicau_struct draftKicau;
    time_t currentTime;
    DATETIME currentDate;

    /* ALGORITMA */
    // Data index user pada list pengguna draft dan draft pada top stack
    idxInLUD = indexInLUD(dataDraf, databasePengguna.user[ActiveUser].Nama);
    content = TOPSD(LUD_IDX(dataDraf, idxInLUD));
    draftContent = DCONTENT(content);

    // Menyimpan datetime saat akan dikicaukan
    time(&currentTime);
    ConvertTimeTtoDATETIME(currentTime, &currentDate);

    // Menerbitkan draf
    draftKicau.IdKicau = (dataKicau).buffer[getLastIdxKicau(dataKicau)].IdKicau + 1;
    draftKicau.IdProfile = ActiveUser;
    draftKicau.TanggalTerbit = currentDate;
    draftKicau.IsiKicauan = draftContent;
    // draftKicau.Tagar = tagar;
    draftKicau.JumlahLike = 0;
    insertLastKicau(&dataKicau, draftKicau);

    // Tampilkan kicauan
    printf("Selamat! Draf kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    ShowKicau(draftKicau);

    // Menghapus draf yang diterbitkan dari stack draft
    hapusDraft();
}