#ifndef PROFIL_H
#define PROFIL_H

#include "../Pengguna/pengguna.h"
#include "../Mesin-Kata/charmachine.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../matrixprofil/matrixprofil.h"
#include "../boolean.h"

/**
 * Fungsi untuk mengganti profil pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diubah profilnya.
 */
void gantiProfil(Pengguna *user);

/**
 * Fungsi untuk melihat profil pengguna.
 * 
 * @param user Objek Pengguna yang akan ditampilkan profilnya.
 */
void lihatProfil(Pengguna user);

/**
 * Fungsi untuk mengatur jenis akun pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diatur jenis akunnya.
 */
void aturJenisAkun(Pengguna *user);

/**
 * Fungsi untuk mengubah foto profil pengguna.
 * 
 * @param user Pointer ke objek Pengguna yang akan diubah fotonya.
 */
void UBAH_FOTO_PROFIL(Pengguna *user);

#endif