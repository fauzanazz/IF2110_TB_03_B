/* File : prioqueuefriendrequest.h */
/* Definisi ADT Priority Queue POPULARITY dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen popularity */

#ifndef prioqueuefriendrequest_H
#define prioqueuefriendrequest_H

#include "../boolean.h"

#define Nil -1
#define MaxElPrioQueue 20
/* Konstanta untuk mendefinisikan index tak terdefinisi */

/* Definisi elemen */
typedef struct {
    int id_user;  /* id pengguna */
    int id_target;  /* id target */
    int popularity;  /* jumlah followers pengguna */
} friendRequest;

/* Contoh deklarasi variabel bertype PrioQueueFriendRequest : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    friendRequest *T;   /* tabel penyimpan elemen */
    int HEAD;  /* index penghapusan */
    int TAIL;  /* index penambahan */
    int MaxElement;     /* Max elemen queue */
} PrioQueueFriendRequest;
/* Definisi PrioQueueFriendRequest kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah friendRequest dan Q adalah PrioQueueFriendRequest, maka akses elemen : */
#define Popularity(e)     (e).popularity
#define User(e)     (e).id_user
#define Target(e)     (e).id_target
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElement(Q)    (Q).MaxElement
#define Elmt(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueFriendRequest Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueFriendRequest Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueFriendRequest Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueFriendRequest * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueFriendRequest * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueFriendRequest * Q, friendRequest X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan popularity */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueFriendRequest * Q, friendRequest * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */

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