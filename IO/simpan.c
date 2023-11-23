#include "simpan.h"
#include <sys/types.h>
#include <sys/stat.h>


int isDirectoryExists(const char *path) {
    struct stat st;
    return stat(path, &st) == 0 && S_ISDIR(st.st_mode);
}

int createDirectory(char *path) {
    // Use a loop to create parent directories if they don't exist
    char *temp = (char *) malloc (stringLength(path) + 1);
    char *tempIter = temp;
    const char *pathIter = path;

    while (*pathIter != '\0') {
        if (*pathIter == '/') {
            *tempIter = '\0';
            if (!isDirectoryExists(temp) && mkdir(temp, 0777) != 0) {
                free(temp);
                return 1;  // Return an error code
            }
            *tempIter = '/';
        } else {
            *tempIter = *pathIter;
        }

        tempIter++;
        pathIter++;
    }

    *tempIter = '\0';

    // Create the final directory
    if (mkdir(path, 0777) != 0) {
        free(temp);
        return 1;  // Return an error code
    }

    free(temp);
    return 0;  // Return success
}

int totalChild(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int total = 0;

    for (int i = 0; i < root->childCount; i++) {
        total += totalChild(root->child[i]);
    }

    return total + 1;
}

void writeBalasan(Node* root, int idx,  FILE *file) {
    if (root == NULL) {
        return;
    }

    if (idx != -2) {

        if (idx > -1){
            fprintf(file, "%d ", idx + 1);
        } else {
            fprintf(file, "%d ", idx);
        }
        
        fprintf(file, "%d\n", root->key.ID_balasan);
        fprintf(file, "%s\n", WordToString(root->key.TextBalasan));
        fprintf(file, "%s\n", WordToString(databasePengguna.user[root->key.ID_Author].Nama));
        fprintf(file, "%02d/%02d/%d %02d:%02d:%02d\n", root->key.DT.DD, root->key.DT.MM, root->key.DT.YYYY, root->key.DT.T.HH, root->key.DT.T.MM, root->key.DT.T.SS);
    }

    // Recursive case: traverse and print children
    for (int i = 0; i < root->childCount; i++) {
        writeBalasan(root->child[i], idx + 1, file);
    }
}

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
    int banyak = NBElmt(dataFriendRequest);
    fprintf(file, "%d\n", banyak);

    PrioQueueFriendRequest temp = dataFriendRequest;
    friendRequest tempFriendRequest;

    while (!IsEmpty(temp))
    {
        Dequeue(&temp, &tempFriendRequest);   
        fprintf(file, "%d %d %d\n", tempFriendRequest.id_user, tempFriendRequest.id_target, tempFriendRequest.popularity);
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

    fprintf(file, "%d\n", dataDraf.LUDNeff);

    int i;
    for(i = 0; i < dataDraf.LUDNeff; i++){
        StackDraft tempDataDraf = dataDraf.BufferUserDraft[i];
        writeWord(tempDataDraf.UserName, file, ' ');
        fprintf(file, "%d\n", tempDataDraf.DSTop + 1);

        StackDraft ReverseDraft;
        Draft tempReverse;
        CreateEmptyDraft(&tempReverse);
        CreateEmptyStackDraft(&ReverseDraft);

        while (!isEmptyStackDraft(tempDataDraf))
        {
            PopStackDraft(&tempDataDraf, &tempReverse);
            PushStackDraft(&ReverseDraft, tempReverse, tempDataDraf.UserName);   
        }

        int j = 0;
        while (j <= ReverseDraft.DSTop)
        {
            Draft tempDraf = ReverseDraft.Buffer[j++];
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

void SimpanBalasan(char *folder_path){
    FILE *file = fopen(concatString(folder_path, "/balasan.config"), "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int banyakKicauDenganBalasan = listBalasan.Neff;
    fprintf(file, "%d\n", banyakKicauDenganBalasan);

    int i;

    for ( i = 0; i < banyakKicauDenganBalasan; i++){
        fprintf(file, "%d\n", listBalasan.T[i].ID_Kicau);

        int banyakBalasan;
        banyakBalasan = totalChild(listBalasan.T[i].root)-1;

        fprintf(file, "%d\n", banyakBalasan);
        writeBalasan(listBalasan.T[i].root, -2, file);
    }

    fclose(file);
}

void Simpan(){
    printf("\nMasukkan folder tempat penyimpanan konfigurasi:\n");

    STARTWORD();

    char *folder_path = concatString("IO/Output/", WordToString(currentWord));

    if (createDirectory(folder_path) == 0) {
        printf("\nFolder %s berhasil dibuat.\n", folder_path);
    } else {
        printf("\nFolder %s sudah tersedia.\n", folder_path);
    }

    SimpanPengguna(folder_path);
    SimpanKicauan(folder_path);
    SimpanUtas(folder_path);
    SimpanDraf(folder_path);
    SimpanBalasan(folder_path);

    printf("Mohon tunggu...\n");
    printf("1..\n");
    printf("2..\n");
    printf("3..\n");

    printf("\nKonfigurasi berhasil disimpan di %s!\n", folder_path);
    
    return;
}