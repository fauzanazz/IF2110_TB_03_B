
#include "../Database/database.h"

void SimpanPengguna(char *folder_path){

    // Create folder if it doesn't exist
    if (mkdir(folder_path, 0777) != 0) {
        printf("Folder already exist.");
    }

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
        fprintf(file, "%s\n", databasePengguna.user[i].Nama.TabWord);
        fprintf(file, "%s\n", databasePengguna.user[i].Pass.TabWord);
        fprintf(file, "%s\n", databasePengguna.user[i].Bio.TabWord);
        fprintf(file, "%s\n", databasePengguna.user[i].Phone.TabWord);
        fprintf(file, "%s\n", databasePengguna.user[i].Weton.TabWord);

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
    if (mkdir(folder_path, 0777) != 0) {
        printf("Folder already exist.");
    }

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
        fprintf(file, "%s\n", dataKicau.buffer[i].IsiKicauan.TabWord);
        fprintf(file, "%d\n", dataKicau.buffer[i].JumlahLike);
        fprintf(file, "%s\n", databasePengguna.user[dataKicau.buffer[i].IdProfile].Nama.TabWord);
        fprintf(file, "%d\n", dataKicau.buffer[i].IdKicau);

        //DATE TIME
        DATETIME tempDate = dataKicau.buffer[i].TanggalTerbit;
        fprintf(file, "%d/", tempDate.DD);
        fprintf(file, "%d/", tempDate.MM);
        fprintf(file, "%d ", tempDate.YYYY);
        fprintf(file, "%d:", tempDate.T.HH);
        fprintf(file, "%d:", tempDate.T.MM);
        fprintf(file, "%d\n", tempDate.T.SS);
    }

    fclose(file);
}

void SimpanUtas(char *folder_path){

    // Create folder if it doesn't exist
    if (mkdir(folder_path, 0777) != 0) {
        printf("Folder already exist.");
    }

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

        while (P != Nil){
            fprintf(file, "%s\n", P->info.IsiKicauan.TabWord);
            fprintf(file, "%s\n", databasePengguna.user[P->info.IdProfile].Nama.TabWord);

            DATETIME tempDate = P->info.TanggalTerbit;
            fprintf(file, "%d/", tempDate.DD);
            fprintf(file, "%d/", tempDate.MM);
            fprintf(file, "%d ", tempDate.YYYY);
            fprintf(file, "%d:", tempDate.T.HH);
            fprintf(file, "%d:", tempDate.T.MM);
            fprintf(file, "%d\n", tempDate.T.SS);
        }
    }

    fclose(file);
}