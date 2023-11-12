#include <stdio.h>
#include "pcolor.h"
#include "pcolor.c"
#include "matrixProfil.h"
#include "matrixProfil.c"
#include "charmachine.h"
#include "charmachine.c"
#include "wordmachine.h"
#include "wordmachine.c"

int main(){
    Foto myfoto;
    createFotoProfil(&myfoto);
    displayFotoProfil(myfoto);
    gantiFotoProfil(&myfoto);
    displayFotoProfil(myfoto);
    return 0;
}