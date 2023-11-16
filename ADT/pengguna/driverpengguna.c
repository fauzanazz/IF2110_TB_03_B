#include <stdio.h>
#include "pengguna.h"
#include "pengguna.c"
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
    logged=false;
    currentId=-1;
    ListPengguna lp;
    int i;
    printf("don\n");
    createListPengguna(&lp);
    printf("don\n");
    for (int a=0;a<20;a++){
        inisialisasiPengguna(&(lp).user[a]);
    }
    printf("don\n");
    Daftar(&lp);
    printf("JUMLAH PENGGUNA SEKARANG ADALAH: %d", lp.usercount);
    printf("\npassword:");
    for (int i=0;i<(lp).user[0].Pass.Length;i++){
        printf("%c", (lp).user[0].Pass.TabWord[i]);
    }
    printf("\npanjang password: %d\n", (lp).user[0].Pass.Length);
    Daftar(&lp);
    printf("JUMLAH PENGGUNA SEKARANG ADALAH: %d", lp.usercount);
    printf("\npassword:");
    printf("\n");
    lihatProfil(lp.user[0]);
    Masuk(&lp);
    Keluar();
}