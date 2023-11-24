#include "teman.h"
#include "../../IO/muat.h"

int main(){
    MuatPengguna("IO/Input/Dummy");
    displayGraf(GFriend);
    daftarTeman(0);
    daftarTeman(1);
    daftarTeman(2);

    hapusTeman(0);
    daftarTeman(0);
    daftarTeman(2);
}