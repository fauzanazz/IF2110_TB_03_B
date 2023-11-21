#include "utas.h"
#include "../../IO/muat.h"

int main(){
    MuatPengguna("IO/Input/Dummy");
    MuatKicauan("IO/Input/Dummy");
    MuatUtas("IO/Input/Dummy");

    cetakUtas(0);
    BuatUtas(1);
    SambungUtas(0, 1);
    cetakUtas(0);
    HapusUtas(0, 1);
    cetakUtas(0);
}