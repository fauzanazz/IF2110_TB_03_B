#include "simpan.h"
#include <sys/stat.h>

void writeWord(Word word, FILE *file, char End){
    int i = 0;
    while (i < word.Length)
    {
        fprintf(file, "%c", word.TabWord[i]);
        i++;
    }
    fprintf(file, "%c", End);
}

void SimpanPengguna(char *folder_path){

    FILE *file = fopen(concatString(folder_path, "/pengguna.config"), "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    //print banyak user
    fprintf(file, "%d\n", databasePengguna.usercount);

    int i;

    for (i = 0; i < databasePengguna.usercount; i++){
        writeWord(databasePengguna.user[i].Nama, file, '\n');
        writeWord(databasePengguna.user[i].Pass, file, '\n');
        writeWord(databasePengguna.user[i].Bio, file, '\n');
        writeWord(databasePengguna.user[i].Phone, file, '\n');
        writeWord(databasePengguna.user[i].Weton, file, '\n');

        if (databasePengguna.user[i].Publik){
            fprintf(file, "Publik\n");
        } else {
            fprintf(file, "Privat\n");
        }

        int j, k;
        Foto foto = databasePengguna.user[i].ProfilePic;

        for (j = 0; j < 5; j++){
            for (k = 0; k < 10; k++){
                fprintf(file, "%c", (char) foto.pix[j][k]);

                if (k != 10){
                    fprintf(file, " ");
                }
            }
            fprintf(file, "\n");
        }
    }

    //Graf Pertemanan
    int j, k;
    for (j = 0; j < databasePengguna.usercount; j++){
        for (k = 0; k < databasePengguna.usercount; k++){
            fprintf(file, "%d", GFriend.mat[j][k]);

            if (k != databasePengguna.usercount - 1){
                fprintf(file, " ");
            }
        }
        fprintf(file, "\n");
    }

    //Permintaan Pertemanan
    fprintf(file, "%d\n", dataFriendRequest.MaxElement);
    for (j = 0; j < dataFriendRequest.MaxElement; j++){
        fprintf(file, "%d %d %d\n", dataFriendRequest.T[j].id_target, dataFriendRequest.T[j].id_user, dataFriendRequest.T[j].popularity);
    }

    fclose(file);
}

void SimpanKicauan(char *folder_path){

    // Create folder if it doesn't exist

    FILE *file = fopen(concatString(folder_path, "/kicauan.config"), "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    //print banyak kicauan
    fprintf(file, "%d\n", dataKicau.nEff);

    int i;

    for (i = 0; i < dataKicau.nEff; i++){
        fprintf(file, "%d\n", dataKicau.buffer[i].IdKicau);
        
        writeWord(dataKicau.buffer[i].IsiKicauan, file, '\n');
        fprintf(file, "%d\n", dataKicau.buffer[i].JumlahLike);
        writeWord(databasePengguna.user[dataKicau.buffer[i].IdProfile].Nama, file, '\n');
        writeWord(dataKicau.buffer[i].Tagar, file, '\n');

        //DATE TIME
        DATETIME tempDate = dataKicau.buffer[i].TanggalTerbit;
        fprintf(file, "%02d/", tempDate.DD);
        fprintf(file, "%02d/", tempDate.MM);
        fprintf(file, "%d ", tempDate.YYYY);
        fprintf(file, "%02d:", tempDate.T.HH);
        fprintf(file, "%02d:", tempDate.T.MM);
        fprintf(file, "%02d\n", tempDate.T.SS);
    }

    fclose(file);
}

void SimpanUtas(char *folder_path){
    
    FILE *file = fopen(concatString(folder_path, "/utas.config"), "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    //print banyak utas
    fprintf(file, "%d\n", dataUtas.neff);
    int i;

    for (i = 0; i < dataUtas.neff; i++){
        fprintf(file, "%d\n", dataUtas.ListUtas[i].id_kicauan);
        fprintf(file, "%d\n", dataUtas.ListUtas[i].neff);

        AddressUtas P = dataUtas.ListUtas[i].Utas;

        while (P != NULL){
            int j = 0;
            while (j < P->info.IsiKicauan.Length)
            {
                fprintf(file, "%c", P->info.IsiKicauan.TabWord[j]);
                j++;
            }
            fprintf(file, "\n");
            writeWord(databasePengguna.user[P->info.IdProfile].Nama, file, '\n');

            DATETIME tempDate = P->info.TanggalTerbit;
            fprintf(file, "%02d/", tempDate.DD);
            fprintf(file, "%02d/", tempDate.MM);
            fprintf(file, "%d ", tempDate.YYYY);
            fprintf(file, "%02d:", tempDate.T.HH);
            fprintf(file, "%02d:", tempDate.T.MM);
            fprintf(file, "%02d\n", tempDate.T.SS);

            P = NEXTUtas(P);
        }
    }

    fclose(file);
}

void SimpanDraf(char *folder_path){
    FILE *file = fopen(concatString(folder_path, "/draf.config"), "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    printf("%d\n", dataDraf.LUDNeff);

    fprintf(file, "%d\n", dataDraf.LUDNeff);

    int i;
    for(i = 0; i < dataDraf.LUDNeff; i++){
        StackDraft tempDataDraf = dataDraf.BufferUserDraft[i];
        displayWord(tempDataDraf.UserName); 
        writeWord(tempDataDraf.UserName, file, ' ');
        fprintf(file, "%d\n", tempDataDraf.DSTop + 1);

        int j = 0;
        while (j <= tempDataDraf.DSTop)
        {
            Draft tempDraf = tempDataDraf.Buffer[j++];
            writeWord(tempDraf.DrafContent, file, '\n');

            DATETIME tempDate = tempDraf.dateLastEdited;
            fprintf(file, "%02d/", tempDate.DD);
            fprintf(file, "%02d/", tempDate.MM);
            fprintf(file, "%d ", tempDate.YYYY);
            fprintf(file, "%02d:", tempDate.T.HH);
            fprintf(file, "%02d:", tempDate.T.MM);
            fprintf(file, "%02d\n", tempDate.T.SS);
        }
    }

    fclose(file);
}

void Simpan(){
    printf("\nMasukkan folder tempat penyimpanan konfigurasi:\n");

    STARTWORD();

    char *folder_path = concatString("IO/Output/", WordToString(currentWord));

    printf("%s\n", folder_path);

    if (mkdir(folder_path, 0777) != 0) {
        printf("\nFolder sudah tersedia.\n");
    } else {
        printf("\nFolder %s berhasil dibuat.\n", folder_path);
    }

    SimpanPengguna(folder_path);
    SimpanKicauan(folder_path);
    SimpanUtas(folder_path);
    SimpanDraf(folder_path);

    printf("Mohon tunggu...\n");
    printf("1..\n");
    printf("2..\n");
    printf("3..\n");

    printf("\nKonfigurasi berhasil disimpan! di IO/Output/%s\n", folder_path);
    
    return;
}