#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "listdin.h"


void CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (ElType *) malloc (capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}
void dealocateList(ListDin *l){
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int listLength(ListDin l){
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l){
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l){
    return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, IdxType i){
    return (i >= IDX_MIN && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
    return (i >= IDX_MIN && i <= NEFF(l));
}

boolean isEmpty(ListDin l){
    return (NEFF(l) == 0);
}

boolean isFull(ListDin l){
    return (NEFF(l) == CAPACITY(l));
}


void printList(ListDin l){
    int i;
    printf("[");
    for (i = 0; i < NEFF(l); i++){
        ShowKicau(ELMT(l, i));
        if (i != NEFF(l) - 1){
            printf(", ");
        }
    }
    printf("]");
}

void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    int i;
    for (i = 0; i < NEFF(lIn); i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

void insertLast(ListDin *l, ElType val){
    NEFF(*l)++;
    ELMT(*l, getLastIdx(*l)) = val;
}

void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--;
}

void expandList(ListDin *l, int num){
    CAPACITY(*l) += num;
}

void shrinkList(ListDin *l, int num){
    CAPACITY(*l) -= num;
}

void compressList(ListDin *l){
    CAPACITY(*l) = NEFF(*l);
}

// Kicauan -------------------------------------
DATETIME currentTime;
Word profile;
Word IsiKicauan;
Word tagar;
time_t current_time;
int disukai;
int idProfile;


void Kicau(ListDin * listKicauan){

    printf("Masukkan kicauan: \n");
    START();
    int i = 0;
    boolean blank = false;
    while (currentChar != MARK) {
        if (currentChar != BLANK){
            blank = true;
        }
        if (blank) currentWord.TabWord[i] = currentChar;
    }
    IsiKicauan = currentWord;

    printf("Masukkan tagar: ");
    START();
    blank = false;
    while (currentChar != MARK) {
        if (currentChar != BLANK){
            blank = true;
        }

        if (blank) currentWord.TabWord[i] = currentChar;
    }
    tagar = currentWord;
    
    currentWord = IsiKicauan;
    // Cek apakah kicauan kosong
    if (!CheckInput("")) {

        // Ambil waktu local
        time(&current_time);
        ConvertTimeTtoDATETIME(current_time, &currentTime);

        Kicau_struct kicauan;
        kicauan.IdKicau = getLastIdx(*listKicauan) + 1;
        kicauan.IdProfile = idProfile;
        kicauan.TanggalTerbit = currentTime;
        kicauan.IsiKicauan = IsiKicauan;
        kicauan.Tagar = tagar;
        kicauan.JumlahLike = disukai;


        // Tampilkan kicauan
        printf("Selamat! kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        ShowKicau(kicauan);

        // Tambahkan ke list kicauan
        insertLast(listKicauan, kicauan);
    } else {
        printf("Kicauan tidak boleh hanya berisi spasi!\n");
    } 
}

void Kicauan(ListDin listKicau){
    for(int i = 0; i < listKicau.nEff; i++){
        // Ubah ke global variable
        if (listKicau.buffer[i].IdProfile == idProfile) {
            ShowKicau(listKicau.buffer[i]);
            printf("\n");
        }
    }
}

void Suka_Kicau(ListDin * ListKicauan, int idKicauan){
    int indexKicau = cariKicauan(*ListKicauan, idKicauan);
    
    if (indexKicau != -1) {
        ListKicauan->buffer[indexKicau].JumlahLike++;
        printf("Selamat! kicauan telah disukai!\n");
        printf("Detil kicauan:\n");
        ShowKicau(ListKicauan->buffer[indexKicau]);
    } else {
        printf("Tidak ditemukan kicauan dengan ID = %d!\n", idKicauan);
    }
    printf("\n");
}

void Ubah_Kicau(ListDin * ListKicauan, int idKicauan, int idPengguna){
    int indexkicau = cariKicauan(*ListKicauan, idKicauan);
    if (indexkicau != -1) {
        if (ListKicauan->buffer[indexkicau].IdProfile == idPengguna) {
            printf("Masukkan kicauan: \n");
            START();
            int i = 0;
            boolean blank = false;
            while (currentChar != MARK) {
                if (currentChar != BLANK){
                    blank = true;
                }

                if (blank) currentWord.TabWord[i] = currentChar;
            }
            IsiKicauan = currentWord;
            ListKicauan->buffer[indexkicau].IsiKicauan = IsiKicauan;
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
    printf("| %d\n",kicauan.IdProfile);
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
    if (founded) return i;
    else return -1;
}



