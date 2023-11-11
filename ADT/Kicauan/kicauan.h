#ifndef __KICAUAN_H__
#define __KICAUAN_H__

#include "../boolean.h"
#include "../Mesin-Kata/wordmachine.h"
#include "../Mesin-Kata/charmachine.h"
#include "../Time/datetime.h"
#include "../Function/string-function.h"
#include "time.h"

typedef struct {
   int IdKicau;
   int IdProfile;
   DATETIME TanggalTerbit;
   Word IsiKicauan;
   int JumlahLike;
} Kicau_struct;

void Kicau(ListDin * listKicauan);
/* I.S. : list kicauan terdefinisi
   F.S. : Terbuat kicauan baru */

void Kicauan(ListDin listKicauan);
/* I.S. : list kicauan terdefinisi
   F.S. : Menampilkan semua kicauan yang sesuai dengan id Pengguna */

void Suka_Kicau(ListDin * ListKicauan, int idKicauan);
/* I.S. : list kicauan terdefinisi
   F.S. :  */

void Ubah_Kicau(ListDin * ListKicauan, int idKicauan, int idPengguna);
/* I.S. : list kicauan terdefinisi
   F.S. : kicauan dengan index tertentu telah berubah */

void ShowKicau(Kicau_struct kicauan);
/* I.S. : Kicauan terdefinisi
   F.S. : menampilkan kicauan */

int cariKicauan(ListDin ListKicauan, int idKicauan);
/* I.S. : list kicauan terdefinisi
   F.S. : mengembalikan index kicauan yang sesuai dengan idKicauan */
#endif