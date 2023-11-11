/* File: PermintaanPertemanan.h */
/* Definisi PermintaanPertemanan */

#ifndef __PermintaanPertemanan_H__
#define __PermintaanPertemanan_H__

#include "../../ADT/PrioQue/prioqueuefriendrequest.h"

void TambahTeman(PrioQueueFriendRequest *Q);
/* I.S Q terdefinisi, mungkin kosong, mungkin penuh */
/* F.S Terdapat sebuah friend request dari user ke target */
/* Membuat sebuah request pertemanan */
/* Jika sudah ada maka tidak perlu dimasukkan */
/* Jika belum masukkan ke prioqueue tergantung jumlah popularitas*/

void BatalTambahTeman(PrioQueueFriendRequest *Q);
/* I.S Q terdefinisi, mungkin kosong, mungkin penuh */
/* F.S Terhapus sebuah friend request dari user ke target */
/* Mencari sebuah request pertemanan */
/* Jika ada maka dequeue */
/* Jika tidak ada, tidak lakukan apa apa */

void DaftarPermintaanPertemanan(PrioQueueFriendRequest Q);
/* I.S Q terdefinisi, mungkin kosong, mungkin penuh */
/* F.S Tercetak dilayar daftar permintaan pertemanan */
/* Jika kosong cetak Tidak ada permintaan pertemanan untuk Anda. */

void SetujuiPertemanan(PrioQueueFriendRequest *Q);
/* I.S Q terdefinisi, mungkin kosong, mungkin penuh */
/* F.S Terdapat sebuah friend request dari user lain ke current user yang diterima */

int CekQueuePermintaanPertemanan(PrioQueueFriendRequest Q, int id_pengguna, int id_target);
/* Mengirimkan index queue yang id pengguna dan id targetnya sama, jika tidak ada mengirimkan Nil*/

void PrintPrioQueueFriendRequest (PrioQueueFriendRequest Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
| Nama Peminta"
| Jumlah Teman : ...
*/

#endif