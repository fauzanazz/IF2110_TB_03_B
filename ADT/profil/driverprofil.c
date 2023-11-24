#include "profil.h"
#include "profil.c"
#include <stdio.h>
#include "../Pengguna/pengguna.h"
#include "../Pengguna/pengguna.c"
#include "../Pcolor/pcolor.h"
#include "../Pcolor/pcolor.c"
#include "../matrixprofil/matrixprofil.h"
#include "../matrixprofil/matrixprofil.c"
#include "../Mesin-Kata/charmachine.h"
#include "../Mesin-Kata/charmachine.c"
#include "../Mesin-Kata/wordmachine.h"
#include "../Mesin-Kata/wordmachine.c"
#include "../boolean.h"

int main(){
    ListPengguna lp;
    createListPengguna(&lp);
    Daftar(&lp);
    Masuk(&lp);
    gantiProfil(&(lp).user[0]);
    aturJenisAkun(&(lp).user[0]);
    lihatProfil((lp).user[0]);
    aturJenisAkun(&(lp).user[0]);
    lihatProfil((lp).user[0]);
    UBAH_FOTO_PROFIL(&(lp).user[0]);
    lihatProfil((lp).user[0]);
}