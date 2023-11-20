#ifndef _TEMAN_H
#define _TEMAN_H

#include "../Mesin-Kata/wordmachine.h"

void daftarTeman(int UID);
/* I.S. UID adalah User ID yang valid */
/* F.S. Menampilkan daftar teman pengguna dengan User ID UID */

void hapusTeman(int UIDSelf, int UIDFriend);
/* I.S. Pengguna dengan User ID UIDSelf berteman dengan pengguna dengan User ID UIDFriend */
/* F.S. Pengguna dengan User ID UIDSelf tidak lagi berteman dengan pengguna dengan User ID UIDFriend, hubungan pada adjacency matrix GFriend berubah (1 -> 0) */

int hitungTeman(int UID);
/* Mengembalikan banyak teman pengguna dengan User ID UID */

boolean isUserValid(Word UserName);
/* Mengembalikan true jika UserName adalah nama pengguna yang valid */

int uidUsername(Word UserName);
/* Mengembalikan UID pengguna dengan nama UserName */

#endif