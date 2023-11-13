#include <stdio.h>
#include "PermintaanPertemanan.h"


void TambahTeman(PrioQueueFriendRequest *Q){
    //* Variabel
    char input;

    // Sambungkan dengan database
    int id_pengguna = 0;
    int id_target = 2;
    int popularity = 0;

    // Inisialiasi penyimpanan queue
    PrioQueueFriendRequest Qtemp;
    Qtemp = *Q;
    infotype temp;


    //* Algoritma
    printf("Masukkan nama pengguna:\n");
    // Mesin kata
    
    // Cek Pengguna dengan id ke berapa dalam database

    // Jika id ke berapa cek ada atau tidak

    // Jika sudah ada, maka tidak perlu dimasukkan
    if (CekQueuePermintaanPertemanan(Qtemp, id_pengguna, id_target)) {
        //! Belum di implementasikan karena belum ada database
        printf("Anda sudah mengirimkan permintaan pertemanan kepada ... . Silakan tunggu hingga permintaan Anda disetujui.\n");
    } else {
        // Buat infotypenya
        User(temp) = id_pengguna;
        Target(temp) = id_target;
        Popularity(temp) = popularity;
        // Jika tidak ada, maka masukkan ke prioqueue
        Enqueue(Q,temp);
    }
}

void BatalTambahTeman(PrioQueueFriendRequest *Q){
    //* Variabel
    char input;
    int index;
    int count = 0;

    // Sambungkan dengan database
    int id_pengguna = 0;
    int id_target = 2;
    int popularity = 0;

    // Inisialiasi penyimpanan queue
    PrioQueueFriendRequest Qtemp;
    Qtemp = *Q;
    infotype temp;


    //* Algoritma
    printf("Masukkan nama pengguna:\n");
    // Mesin kata
    
    // Cek Pengguna dengan id ke berapa dalam database

    // Jika id ke berapa cek ada atau tidak

    index = CekQueuePermintaanPertemanan(Qtemp, id_pengguna, id_target);
    // Jika ada maka hapus
    if (index != Nil) {
        //! Belum di implementasikan karena belum ada database
        while (!IsEmpty(Qtemp))
        {
            Dequeue(&Qtemp, &temp);
            if (count != index)
            {
                Enqueue(Q, temp);
            }
            count += 1;
        }
    } else {
        printf("Anda sudah mengirimkan permintaan pertemanan kepada ... . Silakan tunggu hingga permintaan Anda disetujui.\n");
    }
}

void DaftarPermintaanPertemanan(PrioQueueFriendRequest Q){
    //* Variabel

    // Sambungkan dengan database
    int id_pengguna = 0;

    // Inisialiasi penyimpanan queue
    PrioQueueFriendRequest Qtemp;
    PrioQueueFriendRequest Quser;
    MakeEmpty(&Quser, MaxEl(Q));

    Qtemp = Q;
    infotype temp;

    //* Algoritma
    // Buat queue berisi friend request milik user
    while (!IsEmpty(Qtemp))
    {
        Dequeue(&Qtemp, &temp);
        if (user(temp) == id_pengguna)
        {
            Enqueue(&Quser, temp);
        }
    }

    // Cetak queue
    PrintPrioQueueFriendRequest(Quser);
}

void SetujuiPertemanan(PrioQueueFriendRequest *Q) {
    //* Variabel
    char input;
    int index;
    int count = 0;

    // Sambungkan dengan database
    int id_pengguna = 0;
    int id_target = 2;

    // Inisialiasi penyimpanan queue
    PrioQueueFriendRequest Qtemp;
    PrioQueueFriendRequest Quser;
    MakeEmpty(&Quser, MaxEl(*Q));
    Qtemp = *Q;
    infotype temp;

    //* Algoritma
    // Buat queue berisi friend request milik user
    while (!IsEmpty(Qtemp))
    {
        Dequeue(&Qtemp, &temp);
        if (user(temp) == id_pengguna)
        {
            Enqueue(&Quser, temp);
        }
    }
    // Ambil dari data base data peminta
    if (!IsEmpty(Quser)){
        Enqueue(&Quser, temp);
        printf("Permintaan pertemanan teratas dari ...\n");
        //! Sambungkan dengan database
        // char Namapeminta = ....
        // char Jumlah teman = ....
        // printf("| %s\n", #Nama peminta);
        // printf("| Jumlah teman: %d\n", #Jumlah teman);
        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini?\n");
        
        //! Mesin kata
        
        if (true) {
            printf("Permintaan pertemanan dari Bob telah disetujui. Selamat! Anda telah berteman dengan Bob.");
        }

    } else {
        printf("Tidak ada yang mau berteman anda HAHAHAHA");
    }
    printf("\n");
}


//* Fungsi tambahan DRY
int CekQueuePermintaanPertemanan(PrioQueueFriendRequest Q, int id_pengguna, int id_target){
    infotype temp;
    int ditemukan = Nil;
    int count = Nil;
    while (!IsEmpty(Q))
    {
        Dequeue(&Q, &temp);
        count += 1;
        if (user(temp) == id_pengguna && target(temp) == id_target)
        {   
            ditemukan = count;
        }
    }
    return ditemukan;
}

void PrintPrioQueueFriendRequest(PrioQueueFriendRequest Q) {
    infotype val;
    PrioQueueFriendRequest temp;
    temp = Q;
    if (!IsEmpty(Q)) {
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", MaxEl(Q));
        while (!IsEmpty(temp)) {
            Dequeue(&temp, &val);
            //! Sambungkan dengan database
            // char Namapeminta = ....
            // char Jumlah teman = ....
            // printf("| %s\n", #Nama peminta);
            // printf("| Jumlah teman: %d\n", #Jumlah teman);
        }
    } else {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }
    printf("\n");
}