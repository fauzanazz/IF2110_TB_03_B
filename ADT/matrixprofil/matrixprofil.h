#ifndef MATRIXPROFIL_H
#define MATRIXPROFIL_H

typedef struct {
    int pix[5][10];
} Foto;

#define PIXEL(F, i, j) (F).pix[(i)][(j)]

/**
 * Membuat foto profil baru.
 * 
 * Prosedur ini digunakan untuk membuat foto profil baru dengan menginisialisasi
 * semua atribut pada objek Foto.
 * 
 * @param F Pointer ke objek Foto yang akan dibuat.
 */
void createFotoProfil(Foto *F);

/**
 * Menampilkan foto profil.
 * 
 * Prosedur ini digunakan untuk menampilkan foto profil yang telah dibuat.
 * 
 * @param F Objek Foto yang akan ditampilkan.
 */
void displayFotoProfil(Foto F);

/**
 * Mengganti foto profil.
 * 
 * Prosedur ini digunakan untuk mengganti foto profil dengan foto baru.
 * 
 * @param F Pointer ke objek Foto yang akan diubah.
 */
void gantiFotoProfil(Foto *F);

#endif