#include "kicauan.h"
#include <stdio.h>

DATETIME currentTime;
Word profile;
Word IsiKicauan;
Word tagar;
time_t current_time;


void Kicau(ListDin * listKicauan){
    //! database dummy profile & id
    int IdKicau = 11;
    int idProfile = 0;
    int disukai = 10;
    profile.TabWord[0] = 'H';
    profile.TabWord[1] = 'A';
    profile.TabWord[2] = 'L';
    profile.TabWord[3] = 'L';
    profile.TabWord[4] = 'O';
    profile.Length = 5;


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
    int i = 0;
    boolean blank = false;
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
        kicauan.IdKicau = IdKicau;
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
        insertLast(&listKicauan, kicauan);
    } else {
        printf("Kicauan tidak boleh hanya berisi spasi!\n");
    } 
}

void Kicauan(ListDin listKicau, int idPengguna){
    for(int i = 0; i < listKicau.nEff; i++){
        // Ubah ke global variable
        if (listKicau.buffer[i].IdProfile == idPengguna) {
            ShowKicau(listKicau.buffer[i]);
            printf("\n");
        }
    }
}

void Suka_Kicau(ListDin * ListKicauan, int idKicauan){
    boolean founded = false;
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
            STARTWORD();
            IsiKicauan = currentWord;
            while (!EndWord)
            {
                ADVWORD();
                MakeWord(&IsiKicauan);
            }
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



