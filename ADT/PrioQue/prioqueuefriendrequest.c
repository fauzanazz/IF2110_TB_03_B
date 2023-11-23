#include "../boolean.h"
#include "prioqueuefriendrequest.h"
#include "../../Database/database.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty(PrioQueueFriendRequest Q) {
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}

boolean IsFull(PrioQueueFriendRequest Q) {
    return MaxElement(Q) == NBElmt(Q);
}

int NBElmt(PrioQueueFriendRequest Q) {    
    if (IsEmpty(Q)){
        return 0;
    }
    else {
        if ((Tail(Q) - Head(Q)) >= 0){
            return Tail(Q) - Head(Q) + 1;
        }
        else {
            return MaxElement(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }
}

void MakeEmpty(PrioQueueFriendRequest *Q, int Max) {
    (*Q).T = (friendRequest *) malloc ((Max) * sizeof(friendRequest));
    if ((*Q).T == NULL) {
        MaxElement(*Q) = 0;
    }
    else {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxElement(*Q) = Max;
    }
}

void DeAlokasi(PrioQueueFriendRequest *Q) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxElement(*Q) = 0;
    free((*Q).T);
}

void Enqueue(PrioQueueFriendRequest *Q, friendRequest X) {
    int i, j;
    friendRequest temp;

    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    } else {
        Tail(*Q) = (Tail(*Q) + 1) % MaxElement(*Q);
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = i == 0 ? MaxElement(*Q) - 1 : i - 1;

        while (i != Head(*Q) && Popularity(Elmt(*Q, i)) > Popularity(Elmt(*Q, j))) {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = (i == 0) ? MaxElement(*Q) - 1 : i - 1;
        }
    }
}

void Dequeue(PrioQueueFriendRequest *Q, friendRequest *X) {
    if (NBElmt(*Q) == 1) {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else {
        *X = InfoHead(*Q);
        Head(*Q) = (Head(*Q) == MaxElement(*Q) - 1) ? 0 : Head(*Q) + 1;
    }
}

void TambahTeman(PrioQueueFriendRequest *Q){
    //* Variabel
    // char input; gakepake -maulvi

    // Sambungkan dengan database
    int id_pengguna = ActiveUser;
    int popularity = 0;
    int id_target = -1;

    // Inisialiasi penyimpanan queue
    PrioQueueFriendRequest Qtemp;
    Qtemp = *Q;
    friendRequest temp;
    char *tempUser = "";
    //* Algoritma
    do {
        printf("Masukkan nama pengguna:\n");

        START();
        IgnoreBlanks();
        while (!EOP)
        {
            tempUser = stringConcatChar(tempUser, currentChar);
            ADV();
        }

        id_target = idPengguna(tempUser);

        if (id_target == -1) {
            printf("Pengguna tidak ditemukan. Silakan coba lagi.\n");
        }

    } while (id_target == -1);
    
    // Cek Pengguna dengan id ke berapa dalam database

    // Jika id ke berapa cek ada atau tidak

    // Jika sudah ada, maka tidak perlu dimasukkan
    if (CekQueuePermintaanPertemanan(Qtemp, id_pengguna, id_target)) {
        //! Belum di implementasikan karena belum ada database
        printf("Anda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.\n", tempUser);
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
    // char input; gakepake -maulvi
    int index;
    int count = 0;

    // Sambungkan dengan database
    int id_pengguna = 0;
    int id_target = 2;
    // int popularity = 0; gakepake -maulvi

    // Inisialiasi penyimpanan queue
    PrioQueueFriendRequest Qtemp;
    Qtemp = *Q;
    friendRequest temp;


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
    int id_pengguna = ActiveUser;

    // Inisialiasi penyimpanan queue
    PrioQueueFriendRequest Qtemp;
    PrioQueueFriendRequest Quser;
    MakeEmpty(&Quser, MaxElement(Q));

    Qtemp = Q;
    friendRequest temp;

    //* Algoritma
    // Buat queue berisi friend request milik user
    while (!IsEmpty(Qtemp))
    {
        Dequeue(&Qtemp, &temp);

        if (Target(temp) == id_pengguna)
        {
            Enqueue(&Quser, temp);
        }
    }

    // Cetak queue
    PrintPrioQueueFriendRequest(Quser);
}

void SetujuiPertemanan(PrioQueueFriendRequest *Q) {
    //* Variabel
    // char input; gakepake -maulvi 3 3 nya
    // int index;
    // int count = 0;

    // Sambungkan dengan database
    int id_pengguna = ActiveUser;
    // int id_target = 2; gakepake

    // Inisialiasi penyimpanan queue
    PrioQueueFriendRequest Qtemp;
    PrioQueueFriendRequest Quser;
    MakeEmpty(&Quser, MaxElement(*Q));
    MakeEmpty(&Qtemp, MaxElement(*Q));
    friendRequest temp;

    //* Algoritma
    // Buat queue berisi friend request milik user
    while (Target(temp) != id_pengguna && !IsEmpty(*Q))
    {
        Dequeue(Q, &temp);
        if (Target(temp) == id_pengguna)
        {
            Enqueue(&Quser, temp);
        } else {
            Enqueue(&Qtemp, temp);
        }
    }
    // Ambil dari data base data peminta
    if (!IsEmpty(Quser)){
        Dequeue(&Quser, &temp);
        char *Namapeminta = WordToString(databasePengguna.user[User(temp)].Nama);
        int popularity = Popularity(temp);

        printf("Permintaan pertemanan teratas dari %s.\n", Namapeminta);
        //! Sambungkan dengan database
        
        // char Jumlah teman = ....
        printf("| %s\n", Namapeminta);
        printf("| Jumlah teman: %d\n", popularity);
        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini?\n");
        
        //! Mesin kata
        STARTWORD();
        while (!CheckInput("TIDAK") && !CheckInput("YA")){
            ADVWORD();
        }     
        

        if (CheckInput("YA")) {
            printf("Permintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.", Namapeminta, Namapeminta);

            addEdge(&GFriend, id_pengguna, User(temp));
        } else {
            printf("Permintaan pertemanan dari %s telah ditolak.", Namapeminta);
        }

    } else {
        printf("Tidak ada yang mau berteman anda HAHAHAHA");
    }

    while (!IsEmpty(Qtemp))
    {
        Dequeue(&Qtemp, &temp);
        Enqueue(Q, temp);
    }
    
    printf("\n");
}


//* Fungsi tambahan DRY
int CekQueuePermintaanPertemanan(PrioQueueFriendRequest Q, int id_pengguna, int id_target){
    friendRequest temp;
    int ditemukan = Nil;
    int count = Nil;
    while (!IsEmpty(Q))
    {
        Dequeue(&Q, &temp);
        count += 1;
        if (User(temp) == id_pengguna && Target(temp) == id_target)
        {   
            ditemukan = count;
        }
    }
    return ditemukan;
}

void PrintPrioQueueFriendRequest(PrioQueueFriendRequest Q) {
    friendRequest val;
    PrioQueueFriendRequest temp;
    temp = Q;

    if (!IsEmpty(Q)) {
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", NBElmt(Q));
        while (!IsEmpty(temp)) {
            Dequeue(&temp, &val);
            //! Sambungkan dengan database
            char *Namapeminta = WordToString(databasePengguna.user[User(val)].Nama);
            int JumlahTeman = Popularity(val);

            printf("| %s\n", Namapeminta);
            printf("| Jumlah teman: %d\n\n", JumlahTeman);
        }
    } else {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }
}
