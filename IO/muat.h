#ifndef _MUAT_H_
#define _MUAT_H_

#include "../Database/database.h"
#include "../ADT/draf/stackDraft.h"
#include "../ADT/Mesin-Kata/wordmachine-file.h"
#include <sys/stat.h>
#include <sys/types.h>

/**
 * Membaca data pengguna dari sebuah file.
 *
 * @param file_path Path ke file yang berisi data pengguna.
 */
 
int idPengguna(char *nama);

/**
 * Memuat data pengguna dari file.
 *
 * @param file_path Path ke file yang berisi data pengguna.
 */
void MuatPengguna(char* file_path);

/**
 * Memuat data kicauan dari file.
 *
 * @param file_path Path ke file yang berisi data kicauan.
 */
void MuatKicauan(char* file_path);

/**
 * Memuat data utas dari file.
 *
 * @param file_path Path ke file yang berisi data utas.
 */
void MuatUtas(char* file_path);

/**
 * Memuat data draf dari file.
 *
 * @param file_path Path ke file yang berisi data draf.
 */
void MuatDraf(char* file_path);

/**
 * Memuat data balasan dari file.
 *
 * @param file_path Path ke file yang berisi data balasan.
 */
void MuatBalasan(char* file_path);

/**
 * Memuat data dari file.
 *
 * @return 0 jika berhasil memuat data, -1 jika gagal.
 */
int Muat();

#endif