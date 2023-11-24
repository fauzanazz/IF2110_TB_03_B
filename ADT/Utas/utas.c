#include "utas.h"
#include "../../Database/database.h"

void CreateListUtas(ListKicauanUtas *l, int capacity){
    LISTUTAS(*l) = (ListUtas *) malloc (capacity * sizeof(ListUtas));
    CAPACITYUtas(*l) = capacity;
    NEFFUtas(*l) = 0;
}

void dealocateListUtas(ListKicauanUtas *l){
    free(LISTUTAS(*l));
    CAPACITYUtas(*l) = 0;
    NEFFUtas(*l) = 0;
}

int lisUtastLength(ListKicauanUtas l){
    return NEFFUtas(l);
}

int getFirstIdxUtas(ListKicauanUtas l){
    return IDX_MIN;
}

int getLastIdxUtas(ListKicauanUtas l){
    return NEFFUtas(l) - 1;
}

boolean isIdxUtasValid(ListKicauanUtas l, int i){
    return (i >= IDX_MIN && i < CAPACITYUtas(l));
}

boolean isIdxUtasEff(ListKicauanUtas l, int i){
    return (i >= IDX_MIN && i < NEFFUtas(l));
}

boolean isListUtasEmpty(ListKicauanUtas l){
    return (NEFFUtas(l) == 0);
}

boolean isListUtasFull(ListKicauanUtas l){
    return (NEFFUtas(l) == CAPACITYUtas(l));
}

void insertLastListUtas(ListKicauanUtas *l, ListUtas val){
    if (isListUtasFull(*l)){
        expandListUtas(l, 10);
    }

    ELMTUtas(*l, NEFFUtas(*l)) = val;
    NEFFUtas(*l)++;
}
void expandListUtas(ListKicauanUtas *l, int num){
    ListUtas *newBuffer = (ListUtas *) malloc ((CAPACITYUtas(*l) + num) * sizeof(ListUtas));
    int i;
    for (i = 0; i < CAPACITYUtas(*l); i++){
        newBuffer[i] = ELMTUtas(*l, i);
    }
    free(LISTUTAS(*l));
    LISTUTAS(*l) = newBuffer;
    CAPACITYUtas(*l) += num;
}

void compressListUtas(ListKicauanUtas *l){
    ListUtas *newBuffer = (ListUtas *) malloc (NEFFUtas(*l) * sizeof(ListUtas));
    int i;
    for (i = 0; i < NEFFUtas(*l); i++){
        newBuffer[i] = ELMTUtas(*l, i);
    }
    free(LISTUTAS(*l));
    LISTUTAS(*l) = newBuffer;
    CAPACITYUtas(*l) = NEFFUtas(*l);
}

AddressUtas newUtas(Kicau_struct val){
    AddressUtas p;

    p = (AddressUtas) malloc (sizeof(NodeUtas));

    if (p != NULL){
        INFOUtas(p) = val;
        NEXTUtas(p) = NULL;
    }

    return p;
}

void CreateUtas(ListUtas *l, int id_kicauan){
    (*l).id_kicauan = id_kicauan;
    (*l).neff = 0;
    (*l).Utas= NULL;
}

boolean isEmptyUtas(AddressUtas l){
    return (l == NULL);
}

void displayUtas(AddressUtas l){
    while (l != NULL)
    {
        ShowKicau(l->info);
        l = NEXTUtas(l);
    }
    
}

void insertLastUtas(ListUtas *l, Kicau_struct val){
    AddressUtas p = (*l).Utas;
    AddressUtas new = newUtas(val);
    if (new != NULL){
        if (p == NULL){
            (*l).Utas = new;
            (*l).neff++;
        } else {
            while (NEXTUtas(p) != NULL){
                p = NEXTUtas(p);
            }
            NEXTUtas(p) = new;
            (*l).neff++;
        }
    }
}

void insertAtUtas(ListUtas *l, Kicau_struct val, int idx){
    AddressUtas p = (*l).Utas;
    AddressUtas new = newUtas(val);
    if (new != NULL){
        if (idx == 0){
            NEXTUtas(new) = (*l).Utas;
            (*l).Utas = new;
            (*l).neff++;
        } else {
            int i;
            for (i = 0; i < idx-1; i++){
                p = NEXTUtas(p);
            }
            NEXTUtas(new) = NEXTUtas(p);
            NEXTUtas(p) = new;
            (*l).neff++;
        }
    }
}

void deleteAt(AddressUtas *l, int idx){
    AddressUtas p = *l;
    int  i;
    if (idx == 0){
        *l = NEXTUtas(p);
        free(p);
    } else {
        for (i = 0; i < idx-1; i++){
            p = NEXTUtas(p);
        }
        AddressUtas temp = NEXTUtas(p);
        NEXTUtas(p) = NEXTUtas(temp);
        free(temp);
    }

}

boolean findUtasWithIdKicau(ListKicauanUtas l, int idKicau, int *idx){
    int i = 0;
    while (i < NEFFUtas(l) && ELMTUtas(l, i).id_kicauan != idKicau){
        i++;
    }

    if (i == NEFFUtas(l)){
        return false;
    } else {
        *idx = i;
        return true;
    }
}

//TODO Handle Akun Private
void cetakUtas(int idUtas){
    if (!isIdxUtasEff(dataUtas, idUtas)){
        printf("\nUtas dengan Id %d tidak ditemukan\n", idUtas);
        return;
    }

    int idxKicau = cariKicauan(dataKicau, dataUtas.ListUtas[idUtas].id_kicauan);

    int idPemilikUtas = dataKicau.buffer[idxKicau].IdProfile;
    if (idPemilikUtas != ActiveUser && !isConnected(GFriend,ActiveUser, idPemilikUtas) && !databasePengguna.user[idPemilikUtas].Publik){
         printf("\nAkun author private, silahkan follow terlebih dahulu untuk bisa melihat utas.\n");
        return;
    }

    ListUtas tempUtas = dataUtas.ListUtas[idUtas];
    Word user =  databasePengguna.user[tempUtas.Utas->info.IdProfile].Nama;

    int idxKicauan = cariKicauan(dataKicau, tempUtas.id_kicauan);

    printf("| ID = %d\n", tempUtas.id_kicauan);
    printf("| ");
    displayWord(user);
    printf("| ");
    TulisDATETIME(dataKicau.buffer[idxKicauan].TanggalTerbit);
    printf("\n");
    printf("| ");
    displayWord(dataKicau.buffer[idxKicauan].IsiKicauan);
    printf("\n");
    
    AddressUtas p = tempUtas.Utas;
    int i = 1;
    while (p != NULL){
        printf("    | INDEX = %d\n", i++);
        printf("    | ");
        displayWord(user);
        printf("    | ");
        TulisDATETIME(p->info.TanggalTerbit);
        printf("\n");
        printf("    | ");
        displayWord(p->info.IsiKicauan);
        printf("\n\n");
         
        p = NEXTUtas(p);
    }
};

void BuatUtas(int idKicau){
    if (cariKicauan(dataKicau, idKicau) == -1){
        printf("\nTidak ada kicauan dengan Id %d, silahkan masukkan Id yang lain.\n", idKicau);
        return;
    }

    int idxIdKicau = cariKicauan(dataKicau, idKicau);
    if (dataKicau.buffer[idxIdKicau].IdProfile != ActiveUser){
        printf("\nKicauan ini bukan milik Anda, utas tidak bisa dibuat.\n");
        return;
    }

    int idxUtas;
    if (findUtasWithIdKicau(dataUtas, idKicau, &idxUtas)){
        printf("\nUtas sudah dibuat dengan Id %d!\n", idxUtas);
        return;
    }

    printf("\nUtas berhasil dibuat dengan Id %d!\n", dataUtas.neff);

    ListUtas tempUtas;
    CreateUtas(&tempUtas, idKicau);

    do {
        printf("\nMasukkan kicauan:\n");

        Kicau_struct tempKicauan;
        Word isi = createWordfromString("");

        int i;
        do {
            START();
            IgnoreBlanks();
            i = 0;
            while (currentChar != MARK ){
                if(currentChar != LINEFEED && i < 280) {
                    currentWord.TabWord[i]=currentChar;
                }
                ADV();
                i++;
            }
            
            currentWord.Length = (i > 280) ? 280 : i;

            if (i == 0){
                printf("Kicauan dalam utas tidak boleh kosong!\n");
                printf("\nMasukkan kicauan:\n");
            }
            
        } while (i == 0);
        
        isi = currentWord;

        time_t current_time;
        DATETIME current_time2;
        time(&current_time);
        ConvertTimeTtoDATETIME(current_time, &current_time2);

        tempKicauan.IdKicau = -1;
        tempKicauan.IdProfile = ActiveUser;
        tempKicauan.TanggalTerbit = current_time2;
        tempKicauan.IsiKicauan = isi;
        // tempKicauan.Tagar = dataKicau.buffer[idxIdKicau].Tagar;
        tempKicauan.JumlahLike = 0;

        insertLastUtas(&tempUtas, tempKicauan);

        printf("\nApakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");

        STARTWORD();

        while (! (CheckInput("TIDAK") || CheckInput("YA")) )
        {
            printf("\nInput tidak valid.\n");
            printf("\nApakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
            STARTWORD();
        }

    } while (CheckInput("YA"));

    printf("\nUtas selesai!\n");

    insertLastListUtas(&dataUtas, tempUtas);
}

void SambungUtas(int idUtas, int idx){
    if (!isIdxUtasEff(dataUtas, idUtas)){
        printf("\nUtas dengan Id %d tidak ditemukan.\n", idUtas);
        return;
    }

    if (dataUtas.ListUtas[idUtas].Utas->info.IdProfile != ActiveUser){
        printf("\nUtas ini bukan milik Anda, sambung utas tidak bisa dilakukan\n");
        return;
    }

    if (idx - 1 > dataUtas.ListUtas[idUtas].neff || idx < 0){
        printf("\nIndex tidak valid\n");
        return;
    }



    printf("\nMasukkan kicauan: \n");
    Word isi = createWordfromString("");

    int i;
    do {
        START();
        IgnoreBlanks();
        i = 0;
        while (currentChar != MARK ){
            if(currentChar != LINEFEED && i < 280) {
                currentWord.TabWord[i]=currentChar;
            }
            ADV();
            i++;
        }
        
        currentWord.Length = (i > 280) ? 280 : i;

        if (i == 0){
            printf("Kicauan dalam utas tidak boleh kosong!\n");
            printf("\nMasukkan kicauan:\n");
        }
        
    } while (i == 0);

    isi = currentWord;

    Kicau_struct tempKicauan;

    time_t current_time;
    DATETIME current_time2;
    time(&current_time);
    ConvertTimeTtoDATETIME(current_time, &current_time2);

    tempKicauan.IdKicau = -1;
    tempKicauan.IdProfile = ActiveUser;
    tempKicauan.TanggalTerbit = current_time2;
    tempKicauan.IsiKicauan = isi;
    tempKicauan.Tagar = createWordfromString("");
    tempKicauan.JumlahLike = 0;

    if (idx == 0){
        idx = 1;
    }

    insertAtUtas(&dataUtas.ListUtas[idUtas], tempKicauan, idx - 1);

}

void HapusUtas(int idUtas, int idx){
    if (!isIdxUtasEff(dataUtas, idUtas)){
        printf("\nUtas dengan Id %d tidak ditemukan.\n", idUtas);
        return;
    }

    if (idx == 0){
        printf("\nTidak dapat menghapus kicauan utama.\n");
        return;
    }

    if (dataUtas.ListUtas[idUtas].Utas->info.IdProfile != ActiveUser){
        printf("\nAnda tidak bisa menghapus kicauan dalam utas ini karena Anda bukan pemilik utas.\n");
        return;
    }

    if (idx > dataUtas.ListUtas[idUtas].neff || idx < 0){
        printf("\nIndex tidak valid.\n");
        return;
    }

    deleteAt(&dataUtas.ListUtas[idUtas].Utas, idx - 1);
    dataUtas.ListUtas[idUtas].neff--;

    printf("\nKicauan sambungan berhasil dihapus.\n");
}
