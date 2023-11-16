#ifndef PROFIL_H
#define PROFIL_H

#include "../pengguna/pengguna.h"
#include "../Mesin-Kata/charmachine.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../matrixprofil/matrixprofil.h"
#include "../boolean.h"

void gantiProfil(Pengguna *user);

void lihatProfil(Pengguna user);

void aturJenisAkun(Pengguna *user);

void UBAH_FOTO_PROFIL(Pengguna *user);

#endif