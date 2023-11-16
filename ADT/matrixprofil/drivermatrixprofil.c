#include <stdio.h>
#include "matrixProfil.h"
#include "matrixProfil.c"
#include "../Pcolor/pcolor.h"
#include "../Pcolor/pcolor.c"
#include "../Mesin-Kata/charmachine.h"
#include "../Mesin-Kata/charmachine.c"
#include "../Mesin-Kata/wordmachine.h"
#include "../Mesin-Kata/wordmachine.c"

int main(){
    Foto myfoto;
    createFotoProfil(&myfoto);
    displayFotoProfil(myfoto);
    readFotoProfil(&myfoto);
    displayFotoProfil(myfoto);
    return 0;
}