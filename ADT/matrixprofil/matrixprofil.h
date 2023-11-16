#ifndef MATRIXPROFIL_H
#define MATRIXPROFIL_H

typedef struct {
    int pix[5][10];
} Foto;

#define PIXEL(F, i, j) (F).pix[(i)][(j)]

void createFotoProfil(Foto *F);

void displayFotoProfil(Foto F);

void gantiFotoProfil(Foto *F);

#endif