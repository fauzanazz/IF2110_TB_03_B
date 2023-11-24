#ifndef _DATABASE_H
#define _DATABASE_H

#include "../ADT/Pengguna/pengguna.h"
#include "../ADT/profil/profil.h"
#include "../ADT/Graf/graf.h"
#include "../ADT/PrioQue/prioqueuefriendrequest.h"
#include "../ADT/Utas/utas.h"
#include "../ADT/Mesin-Kata/charmachine-file.h"
#include "../ADT/Function/string-function.h"
#include "../ADT/Mesin-Kata/wordmachine.h"
#include "../ADT/boolean.h"
#include "../ADT/Mesin-Kata/charmachine.h"
#include "../ADT/draf/draft.h"
#include "../ADT/Teman/teman.h"
#include "../IO/muat.h"
#include "../ADT/Balasan/balasan.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * File: database.h
 * 
 * Deskripsi:
 * File ini berisi deklarasi variabel-variabel yang digunakan dalam database pengguna.
 * Variabel-variabel tersebut meliputi:
 * - databasePengguna: ListPengguna, menyimpan data pengguna.
 * - GFriend: Graf, menyimpan hubungan pertemanan antar pengguna.
 * - dataFriendRequest: PrioQueueFriendRequest, menyimpan antrian permintaan pertemanan.
 * - dataKicau: ListDin, menyimpan data kicauan pengguna.
 * - dataDraf: ListUserDraft, menyimpan data draf kicauan pengguna.
 * - dataUtas: ListKicauanUtas, menyimpan data kicauan utas pengguna.
 * - listBalasan: BalasanList, menyimpan data balasan pada kicauan pengguna.
 * - ActiveUser: int, menyimpan indeks pengguna yang sedang aktif.
 * - isLogin: boolean, menandakan apakah pengguna sudah login atau belum.
 */

extern ListPengguna databasePengguna;
extern Graf GFriend;
extern PrioQueueFriendRequest dataFriendRequest;
extern ListDin dataKicau;
extern ListUserDraft dataDraf;
extern ListKicauanUtas dataUtas;
extern BalasanList listBalasan;
extern int ActiveUser;
extern boolean isLogin;

#endif