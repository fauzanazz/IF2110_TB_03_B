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
    if (depth > 0 && !databasePengguna.user[root->key.ID_Author].Publik){
        printIndent(depth-1);
        printf("| PRIVATE\n");
        printIndent(depth-1);
        printf("| PRIVATE\n");
        printIndent(depth-1);
        printf("| PRIVATE\n");
        printIndent(depth-1);
        printf("| PRIVATE\n");
        printf("\n");
        return;
    } else if (depth > 0) {
        printIndent(depth-1);
        printf("| ID = %d\n", root->key.ID_balasan);
        printIndent(depth-1);
        printf("| ");
        displayWord(databasePengguna.user[root->key.ID_Author].Nama);
        printIndent(depth-1);
        printf("| ");
        printf("| %d-%02d-%02d %02d:%02d:%02d\n", root->key.DT.YYYY, root->key.DT.MM, root->key.DT.DD, root->key.DT.T.HH, root->key.DT.T.MM, root->key.DT.T.SS);
        printIndent(depth-1);
        printf("| ");
        displayWord(root->key.TextBalasan);
        printf("\n");
    }

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
        listBalasan.LastID++;
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
void deleteNodeHelper(Node* root, int ID_balasan, Node** parent, int childIndex) {
    if (root == NULL) {
        return;
    }

    // Check if the current node matches the deletion criteria
    if (root->key.ID_balasan == ID_balasan) {
        // Delete the node and adjust the child pointers of the parent
        free(root);
        if (parent != NULL) {
            (*parent)->child[childIndex] = NULL;
            (*parent)->childCount--;
        }
        return;
    }

    // Recurse for each child
    for (int i = 0; i < root->childCount; i++) {
        deleteNodeHelper(root->child[i], ID_balasan, &root, i);
    }
}

void deleteNode(Tree* tree, int ID_balasan) {
    if (tree == NULL || tree->root == NULL) {
        return;
    }

    deleteNodeHelper(tree->root, ID_balasan, NULL, -1);
}


void Balas(int ID_kicau, int IDBalasan){
    int idxKicauan = cariKicauan(dataKicau, ID_kicau);

    if (idxKicauan == IDX_UNDEF){
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }

    if (!isConnected(GFriend , ActiveUser , dataKicau.buffer[cariKicauan(dataKicau, ID_kicau)].IdProfile)){
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
        return;
    }
    

    int idxKicauanDalamList = FindKicauan(ID_kicau);
    if (idxKicauanDalamList == IDX_UNDEF){

        Tree newTree;
        createEmptyTree(&newTree, ID_kicau);
        insertLastBalasan(&listBalasan, newTree);
        idxKicauanDalamList = listBalasan.Neff - 1;
        BalasanStruct tempRootBalasan;
        tempRootBalasan.ID_balasan = -1;
        tempRootBalasan.ID_Author = -1;
        tempRootBalasan.TextBalasan = createWordfromString("");
        DATETIME dummy;
        CreateDATETIME(&dummy, 0, 0, 0, 0, 0, 0);
        tempRootBalasan.DT = dummy;
        listBalasan.T[idxKicauanDalamList].root = newNodeBalasan(tempRootBalasan);

    }

    if (IDBalasan != -1){
        Node* idxBalasan = findNode(listBalasan.T[idxKicauanDalamList].root, IDBalasan);
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
        addChild(listBalasan.T[idxKicauanDalamList].root, newNodeBalasan(newBalasan));
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

    if (!isConnected(GFriend , ActiveUser , dataKicau.buffer[cariKicauan(dataKicau, idKicau)].IdProfile)){
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
        return;
    }
    printf("%d", listBalasan.T[Idxkicauan].root->childCount);

    printBalasan(listBalasan.T[Idxkicauan].root, 0);
}

void HapusBalasan(int ID_kicauan, int ID_balasan){
    int idxKicauan = FindKicauan(ID_kicauan);
    if (idxKicauan == IDX_UNDEF){
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return;
    }

    

    if (ID_balasan != -1){
        Node* idxBalasan = findNode(listBalasan.T[idxKicauan].root, ID_balasan);
        if (idxBalasan == NULL){
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            return;
        } else if (ActiveUser != idxBalasan->key.ID_Author ){
            printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
            return;
        } else {
            deleteNode(&listBalasan.T[idxKicauan], ID_balasan);
        }
    } else {
        deleteNode(&listBalasan.T[idxKicauan], ID_balasan);
    }

    printf("Balasan berhasil dihapus!\n");

    if (listBalasan.T[idxKicauan].root->childCount == 0){
        deleteLastBalasan(&listBalasan);
    }
}