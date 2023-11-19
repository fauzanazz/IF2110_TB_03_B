#include "IO/muat.h"
#include "IO/simpan.h"

int main(){
    MuatPengguna("IO/Input/Dummy");
    MuatKicauan("IO/Input/Dummy");
    MuatUtas("IO/Input/Dummy");

    cetakUtas(0);
    cetakUtas(1);

    SimpanUtas("IO/Output/Dummy");

    return 0;
}