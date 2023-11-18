#ifndef _SIMPAN_H_
#define _SIMPAN_H_

#include "../Database/database.h"

/**
 * Saves the user data to a file.
 *
 * @param file_path The path of the file to save the data to.
 */

void SimpanPengguna(char* file_path);

void SimpanKicauan(char* file_path);

void SimpanUtas(char* file_path);

void Simpan();

#endif
