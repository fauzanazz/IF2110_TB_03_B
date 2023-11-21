#include "../../Database/database.h"
#include "balasan.h"

/*
    List dinamis Berisi kicauan dengan balasan
    Berisi Root dari node balasan
    Node Balasan berisi ID balasan, ID Author, Tanggal, dan Text Balasan

*/

void CreateListBalasan(BalasanList *listBalasan){
    listBalasan->T = (Tree*) malloc(listBalasan->Capacity * sizeof(Tree));
    listBalasan->Neff = 0;
    listBalasan->Capacity = 50;
    listBalasan->LastID = 0;
}

void dealocateListBalasan(BalasanList *l){
    free(l->T);
    l->Capacity = 0;
    l->Neff = 0;
}

void insertLastBalasan(BalasanList *l, Tree val){
    l->T[l->Neff] = val;
    l->Neff++;
}

void deleteLastBalasan(BalasanList *l){
    l->Neff--;
}

void expandListBalasan(BalasanList *l, int num){
    l->Capacity += num;
}

void shrinkListBalasan(BalasanList *l, int num){
    l->Capacity -= num;
}

void compressListBalasan(BalasanList *l){
    l->Capacity = l->Neff;
}

void createEmptyTree(Tree *T, int ID_Kicau){
    T->ID_Kicau = ID_Kicau;
    T->root = NULL;
}


void displayBalasan(BalasanStruct key) {
    printf("| ID = %d\n", key.ID_balasan);
    printf("| ");
    displayWord(databasePengguna.user[key.ID_Author].Nama);
    printf("| ");
    printf("| %d-%02d-%02d %02d:%02d:%02d\n", key.DT.YYYY, key.DT.MM, key.DT.DD, key.DT.T.HH, key.DT.T.MM, key.DT.T.SS);
    printf("| ");
    displayWord(key.TextBalasan);
    printf("\n");
}

void addChild(Node* parent, Node* child) {
    parent->childCount++;
    parent->child = realloc(parent->child, sizeof(Node*) * parent->childCount);
    parent->child[parent->childCount - 1] = child;
}

void printIndent(int depth){
    for (size_t i = 0; i < depth; i++){
        printf("    ");
    }
}

Node* newNodeBalasan(BalasanStruct key) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->childCount = 0;
    temp->child = NULL;
    return temp;
}

void printBalasan(Node* root, int depth) {
    if (root == NULL) {
        return;
    }

    printIndent(depth);
    printf("| ID = %d\n", root->key.ID_balasan);
    printIndent(depth);
    printf("| ");
    displayWord(databasePengguna.user[root->key.ID_Author].Nama);
    printIndent(depth);
    printf("| ");
    printf("| %d-%02d-%02d %02d:%02d:%02d\n", root->key.DT.YYYY, root->key.DT.MM, root->key.DT.DD, root->key.DT.T.HH, root->key.DT.T.MM, root->key.DT.T.SS);
    printIndent(depth);
    printf("| ");
    displayWord(root->key.TextBalasan);
    printf("\n");

    // Recursive case: traverse and print children
    for (int i = 0; i < root->childCount; i++) {
        printBalasan(root->child[i], depth + 1);
    }
}

void ReadBalasan(BalasanStruct *newBalasan){
    printf("Masukkan balasan:\n");
        START();
        IgnoreBlanks();
        ignoreNewLine();
        int i = 0;
        while (currentChar != MARK){
            if(currentChar != LINEFEED) {
                currentWord.TabWord[i]=currentChar;
            }
            ADV();
            i++;
        }
        currentWord.Length = i;
        
        // Ambil waktu sekarang
        time_t current_time;
        time(&current_time);
        ConvertTimeTtoDATETIME(current_time, &newBalasan->DT);

        newBalasan->ID_balasan = listBalasan.LastID + 1;
        newBalasan->ID_Author = ActiveUser;
        newBalasan->TextBalasan = currentWord;
}

Node* findNode(Node* root, int ID_balasan) {
    if (root == NULL || root->key.ID_balasan == ID_balasan) {
        return root;
    }

    for (int i = 0; i < root->childCount; i++) {
        Node* result = findNode(root->child[i], ID_balasan);
        if (result != NULL) {
            return result;
        }
    }
    return NULL;
}


int FindKicauan(int ID_kicau){
    for (int i = 0; i < listBalasan.Neff; i++){
        if (listBalasan.T[i].ID_Kicau == ID_kicau){
            return i;
        }
    }
    return IDX_UNDEF;
}

void deleteNode(Node* node) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < node->childCount; i++) {
        deleteNode(node->child[i]);
    }

    free(node->child);

    free(node);
}

void Balas(int ID_kicau, int IDBalasan){
    int idxKicauan = FindKicauan(ID_kicau);
    if (idxKicauan == IDX_UNDEF){
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }

    if (isConnected(GFriend , ActiveUser , dataKicau.buffer[cariKicauan(dataKicau, ID_kicau)].IdProfile )){
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
        return;
    }

    if (IDBalasan != -1){
        Node* idxBalasan = findNode(listBalasan.T[idxKicauan].root, IDBalasan);
        if (idxBalasan == NULL){
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            return;
        } else {
            BalasanStruct newBalasan;
            ReadBalasan(&newBalasan);
            addChild(idxBalasan, newNodeBalasan(newBalasan));
            printf("Balasan berhasil ditambahkan!\n");
            displayBalasan(newBalasan);
        }
    } else {
        BalasanStruct newBalasan;
        ReadBalasan(&newBalasan);
        addChild(listBalasan.T[idxKicauan].root, newNodeBalasan(newBalasan));
        printf("Balasan berhasil ditambahkan!\n");
        displayBalasan(newBalasan);
    }
}


void Balasan(int idKicau){
    int idxKicauan = cariKicauan(dataKicau, idKicau);

    if (idxKicauan == IDX_UNDEF){
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }

    int Idxkicauan = FindKicauan(idKicau);
    if (Idxkicauan == IDX_UNDEF){
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        return;
    }

    if (isConnected(GFriend , ActiveUser , dataKicau.buffer[cariKicauan(dataKicau, idKicau)].IdProfile )){
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
        return;
    }

    printBalasan(listBalasan.T[Idxkicauan].root, 0);
}

void HapusBalasan(int ID_kicauan, int ID_balasan){
    int idxKicauan = FindKicauan(ID_kicauan);
    if (idxKicauan == IDX_UNDEF){
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }

    if (isConnected(GFriend , ActiveUser , dataKicau.buffer[cariKicauan(dataKicau, ID_kicauan)].IdProfile )){
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebu!\n");
        return;
    }

    if (ID_balasan != -1){
        Node* idxBalasan = findNode(listBalasan.T[idxKicauan].root, ID_balasan);
        if (idxBalasan == NULL){
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            return;
        } else {
            deleteNode(idxBalasan);
        }
    } else {
        deleteNode(listBalasan.T[idxKicauan].root);
    }
}