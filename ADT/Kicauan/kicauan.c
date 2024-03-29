#include "kicauan.h"
#include "../../Database/database.h"

void CreateListDinKicau(ListDin *l, int capacity){
    BUFFER(*l) = (Kicau_struct *) malloc (capacity * sizeof(Kicau_struct));
    CAPACITY(*l) = capacity;
    NEFFKicau(*l) = 0;
}
void dealocateListKicau(ListDin *l){
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFFKicau(*l) = 0;
}

int listLengthKicau(ListDin l){
    return NEFFKicau(l);
}

IdxType getFirstIdxKicau(ListDin l){
    return IDX_MIN;
}

IdxType getLastIdxKicau(ListDin l){
    return NEFFKicau(l) - 1;
}

boolean isIdxValidKicau(ListDin l, IdxType i){
    return (i >= IDX_MIN && i < CAPACITY(l));
}

boolean isIdxEffKicau(ListDin l, IdxType i){
    return (i >= IDX_MIN && i <= NEFFKicau(l));
}

boolean isEmptyKicau(ListDin l){
    return (NEFFKicau(l) == 0);
}

boolean isFullKicau(ListDin l){
    return (NEFFKicau(l) == CAPACITY(l));
}


void printListKicau(ListDin l){
    int i;
    for (i = 0; i < NEFFKicau(l); i++){
        ShowKicau(ELMT(l, i));
        if (i != NEFFKicau(l) - 1){
            printf("\n");
        }
    }
}

void copyListKicau(ListDin lIn, ListDin *lOut){
    CreateListDinKicau(lOut, CAPACITY(lIn));
    NEFFKicau(*lOut) = NEFFKicau(lIn);
    int i;
    for (i = 0; i < NEFFKicau(lIn); i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

void insertLastKicau(ListDin *l, Kicau_struct val){
    NEFFKicau(*l)++;
    ELMT(*l, getLastIdxKicau(*l)) = val;
}

void deleteLastKicau(ListDin *l, Kicau_struct *val){
    *val = ELMT(*l, getLastIdxKicau(*l));
    NEFFKicau(*l)--;
}

void expandListKicau(ListDin *l, int num){
    CAPACITY(*l) += num;
}

void shrinkListKicau(ListDin *l, int num){
    CAPACITY(*l) -= num;
}

void compressListKicau(ListDin *l){
    CAPACITY(*l) = NEFFKicau(*l);
}

// Kicauan -------------------------------------
DATETIME currentTime;
Word profile;
Word IsiKicauan;
Word tagar;
time_t current_time;
int disukai;


void Kicau(ListDin * listKicauan){

    printf("Masukkan kicauan: \n");
    START();
    IgnoreBlanks();
    ignoreNewLine();
    int i=0;
    while (currentChar != MARK ){
        if(currentChar != LINEFEED && i < 280) {
            currentWord.TabWord[i]=currentChar;
        }
        ADV();
        i++;
    }
    
    currentWord.Length = (i > 280) ? 280 : i;

    if (i == 0){
        printf("Kicauan tidak boleh kosong!\n");
        return;
    }

    IsiKicauan = currentWord;
    
    // printf("Masukkan tagar: \n");
    // START();
    // IgnoreBlanks();
    // ignoreNewLine();
    // i = 0;
    // while (currentChar != MARK){
    //     if(currentChar != LINEFEED) {
    //         currentWord.TabWord[i]=currentChar;
    //     }
    //     ADV();
    //     i++;
    // }
    // currentWord.Length = i;
    // tagar = currentWord;

    // Cek apakah kicauan kosong
    if (IsiKicauan.Length > 0) {

        // Ambil waktu local
        time(&current_time);
        ConvertTimeTtoDATETIME(current_time, &currentTime);

        Kicau_struct kicauan;
        kicauan.IdKicau = (*listKicauan).buffer[getLastIdxKicau(*listKicauan)].IdKicau + 1;
        kicauan.IdProfile = ActiveUser;
        kicauan.TanggalTerbit = currentTime;
        kicauan.IsiKicauan = IsiKicauan;
        // kicauan.Tagar = tagar;
        kicauan.JumlahLike = disukai;


        // Tampilkan kicauan
        printf("\n\n");
        printf("Selamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        ShowKicau(kicauan);

        // Tambahkan ke list kicauan
        insertLastKicau(listKicauan, kicauan);
    } else {
        printf("Kicauan tidak boleh hanya berisi spasi!\n");
    } 
}

void Kicauan(ListDin listKicau){
    int count = 0;
    for(int i = listKicau.nEff-1; i > -1; i--){
        if (listKicau.buffer[i].IdProfile == ActiveUser || isConnected(GFriend, ActiveUser, listKicau.buffer[i].IdProfile)) {
            ShowKicau(listKicau.buffer[i]);
            count++;
            printf("\n");
        }
    }

    if (count == 0){
        printf("Belum ada kicauan yang dapat ditampilkan.\n");
    }
}

void Suka_Kicau(ListDin * ListKicauan, int idKicauan){
    int indexKicau = cariKicauan(*ListKicauan, idKicauan);

    if (indexKicau == -1 ){
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicauan);
        return;
    }

    int IdPengguna = (*ListKicauan).buffer[indexKicau].IdProfile;
    if (!isConnected(GFriend, ActiveUser, IdPengguna) &&  IdPengguna != ActiveUser && !databasePengguna.user[IdPengguna].Publik) {
        printf("Anda tidak dapat menyukai kicauan ini\n");
        return;
    }
    
    ListKicauan->buffer[indexKicau].JumlahLike++;
    printf("Selamat! kicauan telah disukai!\n");
    printf("Detil kicauan:\n");
    ShowKicau(ListKicauan->buffer[indexKicau]);

    printf("\n");
}

void Ubah_Kicau(ListDin * ListKicauan, int idKicauan, int idPengguna){
    int indexkicau = cariKicauan(*ListKicauan, idKicauan);
    if (indexkicau != -1) {
        if (ListKicauan->buffer[indexkicau].IdProfile == idPengguna) {
            printf("Masukkan kicauan: \n");

            START();
            int i = 0;
            IgnoreBlanks();
            while (currentChar != MARK && i < 280) {
                currentWord.TabWord[i++] = currentChar;
                currentWord.Length++;
                ADV();
            }

            IsiKicauan = currentWord;
            ListKicauan->buffer[indexkicau].IsiKicauan = IsiKicauan;
            time(&current_time);
            ConvertTimeTtoDATETIME(current_time, &currentTime);
            ListKicauan->buffer[indexkicau].TanggalTerbit = currentTime;

            printf("Selamat! kicauan telah diterbitkan!\n");
            printf("Detil kicauan:\n");
            ShowKicau(ListKicauan->buffer[indexkicau]);
        } else {
            printf("Anda tidak dapat mengubah kicauan ini\n");
        }
    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicauan);
    }
}

void ShowKicau(Kicau_struct kicauan){
    printf("| ID = %d\n", kicauan.IdKicau);
    printf("| ");
    displayWord(databasePengguna.user[kicauan.IdProfile].Nama);
    printf("| %d-%02d-%02d %02d:%02d:%02d\n", kicauan.TanggalTerbit.YYYY, kicauan.TanggalTerbit.MM, kicauan.TanggalTerbit.DD, kicauan.TanggalTerbit.T.HH, kicauan.TanggalTerbit.T.MM, kicauan.TanggalTerbit.T.SS);
    printf("| ");
    displayWord(kicauan.IsiKicauan);
    printf("| Disukai: %d\n", kicauan.JumlahLike);
}

int cariKicauan(ListDin ListKicauan, int idKicauan){
    boolean founded = false;
    int i = 0;
    while (!founded && i < ListKicauan.nEff) {
        if (ListKicauan.buffer[i].IdKicau == idKicauan)
        {
            founded = true;   
        }
        i++;
    }
    if (founded) return i - 1;
    else return -1;
}
void ignoreNewLine(){
    while (currentChar == LINEFEED) {
        ADV();
    }
}



