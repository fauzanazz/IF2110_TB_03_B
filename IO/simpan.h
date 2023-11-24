#ifndef _SIMPAN_H_
#define _SIMPAN_H_

#include "../Database/database.h"

/**
 * Fungsi untuk memeriksa apakah direktori dengan path yang diberikan ada atau tidak.
 * 
 * @param path Path direktori yang akan diperiksa keberadaannya.
 */
int isDirectoryExists(const char *path);

/**
 * Menyimpan data pengguna ke dalam file.
 *
 * @param file_path Path file untuk menyimpan data.
 */
void SimpanPengguna(char* file_path);

/**
 * Menyimpan data kicauan ke dalam file.
 *
 * @param file_path Path file untuk menyimpan data.
 */
void SimpanKicauan(char* file_path);

/**
 * Menyimpan data utas ke dalam file.
 *
 * @param file_path Path file untuk menyimpan data.
 */
void SimpanUtas(char* file_path);

/**
 * Menyimpan data draf ke dalam folder.
 *
 * @param folder_path Path folder untuk menyimpan data.
 */
void SimpanDraf(char* folder_path);

/**
 * Menyimpan data.
 */
void Simpan();

#endif
