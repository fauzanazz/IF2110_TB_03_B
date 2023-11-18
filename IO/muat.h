#ifndef _MUAT_H_
#define _MUAT_H_

#include "../Database/database.h"
#include <sys/stat.h>
#include <sys/types.h>

/**
 * Reads user data from a file.
 *
 * @param file_path The path to the file containing user data.
 */

void MuatPengguna(char* file_path);

void MuatKicauan(char* file_path);

void MuatUtas(char* file_path);

int Muat();

#endif