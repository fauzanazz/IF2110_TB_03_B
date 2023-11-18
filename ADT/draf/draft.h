#ifndef DRAFT_H
#define DRAFT_H

#include "stackDraft.h"

void buatDraft();
/* I.S. Stack draft user tidak penuh, user mungkin pengguna draft, mungkin tidak */
/* F.S. Membuat sebuah draft baru dan mem-push ke SDUser, jika user sebelumnya bukan pengguna draft, ditambahkan ke list pengguna draft LUD */

void lihatDraft();
/* I.S. User merupakan pengguna draft */
/* F.S. Draft terbaru User tampil pada layar */

void editDraft();
/* I.S. User merupakan pengguna draft */
/* F.S. Draft terakhir yang dibuat user dapat diedit, dapat batal diedit */

void hapusDraft();
/* I.S. User merupakan pengguna draft */
/* F.S. Draft terakhir yang dibuat user dihapus (di-pop dari stack draft), jika setelah penghapusan draftnya menjadi kosong, user dihapus dari list pengguna draft */

void terbitDraft();
/* I.S. User merupakan pengguna draft */
/* F.S. Draft terakhir yang dibuat user diterbitkan (di-pop dari stack draft), jika setelah penghapusan draftnya menjadi kosong, user dihapus dari list pengguna draft */

#endif