#include "Database/database.h"
#include "IO/muat.h"
#include "IO/simpan.h"
#include "ADT/Tree/tree.h"

int main(){
    MuatPengguna("IO/Input/Dummy");
    MuatKicauan("IO/Input/Dummy");
    MuatUtas("IO/Input/Dummy");

    printListKicau(dataKicau);


    return 0;
}