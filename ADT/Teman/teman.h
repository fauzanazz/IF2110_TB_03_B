#include "../ADT/Graf/graf.c"
#include "../ADT/ListVertex/listvertex.c"

void daftarTeman(Graf GFriend, ListVertex LVertex, int UID);
/* I.S. UID adalah User ID yang valid */
/* F.S. Menampilkan daftar teman pengguna dengan User ID UID */

void hapusTeman(Graf *GFriend, ListVertex LVertex,  int UIDSelf, int UIDFriend);
/* I.S. Pengguna dengan User ID UIDSelf berteman dengan pengguna dengan User ID UIDFriend */
/* F.S. Pengguna dengan User ID UIDSelf tidak lagi berteman dengan pengguna dengan User ID UIDFriend, hubungan pada adjacency matrix GFriend berubah (1 -> 0) */

int hitungTeman(Graf GFriend, int UID);
/* Mengembalikan banyak teman pengguna dengan User ID UID */

int idxToUID(ListVertex LVertex, int idx);
/* Mengembalikan UID user yang di-assign dengan index idx pada adjacency matrix graf GFriend */

int uidtoIdx(ListVertex LVertex, int UID);
/* Mengembalikan index user dengan User ID UID yang di-assign pada adjacency matrix graf GFriend */