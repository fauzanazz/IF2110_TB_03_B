#include "balasan.h"

int main(){
    BalasanList listBalasan;
    CreateListBalasan(&listBalasan);

    Tree T;
    createEmptyTree(&T, 1);
    insertLastBalasan(&listBalasan, T);

    for (int i  = 0; i < 3; i++){
        BalasanStruct newBalasan;
        ReadBalasan(&newBalasan);
        Node* newNode = newNodeBalasan(newBalasan);
        if (listBalasan.T[0].root == NULL){
            BalasanStruct tempRootBalasan;
            tempRootBalasan.ID_balasan = -1;
            tempRootBalasan.ID_Author = -1;
            tempRootBalasan.TextBalasan = createWordfromString("");
            DATETIME dummy;
            CreateDATETIME(&dummy, 0, 0, 0, 0, 0, 0);
            tempRootBalasan.DT = dummy;
            listBalasan.T[0].root = newNodeBalasan(tempRootBalasan);
            addChild(listBalasan.T[0].root, newNode);
        } else{
            addChild(listBalasan.T[0].root, newNode);
        }
    }

    if (listBalasan.T[0].root != NULL) {
        printBalasan(listBalasan.T[0].root, 0);
    }

    //  Membalas ke balasan
    for (int i  = 0; i < 3; i++){
        printf("Masukkan ID balasan yang ingin Anda balas: ");
        int IDBalasan;
        scanf("%d", &IDBalasan);
        BalasanStruct newBalasan;
        ReadBalasan(&newBalasan);
        Node* idxBalasan = findNode(listBalasan.T[0].root, IDBalasan);
        if (idxBalasan == NULL){
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            return 0;
        } else {
            addChild(idxBalasan, newNodeBalasan(newBalasan));
        }
    }
    
    if (listBalasan.T[0].root != NULL) {
        printBalasan(listBalasan.T[0].root, 0);
    }

    return 0;
}