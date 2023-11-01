#include <stdio.h>
#include <math.h>
#include "time.h"

const double EPSILON = 1e-6;
boolean IsTIMEValid (int H, int M, int S){
   return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS){
   Hour(*T) = HH;
   Minute(*T) = MM;
   Second(*T) = SS;
}
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T){
   int HH, MM, SS;
   scanf("%d %d %d", &HH, &MM, &SS);
   while (!IsTIMEValid(HH, MM, SS)){
      printf("Jam tidak valid\n");
      scanf("%d %d %d", &HH, &MM, &SS);
   }
   CreateTime(T, HH, MM, SS);
}

   
void TulisTIME (TIME T){
   printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T){
   if (IsTIMEValid(Hour(T), Minute(T), Second(T))){
      return (3600*Hour(T) + 60*Minute(T) + Second(T));
   }
}
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

TIME DetikToTIME (volatile long N){
   int N1;
   TIME T;
   if (N < 0){
      N = 86400 + N;
   }
   N1 = N % 86400;
   Hour(T) = N1 / 3600;
   N1 = N1 % 3600;
   Minute(T) = N1 / 60;
   Second(T) = N1 % 60;
   return T;
}
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */

/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2){
   return fabs(TIMEToDetik(T1)-TIMEToDetik(T2)) < EPSILON;
}
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ (TIME T1, TIME T2){
   return (!TEQ(T1,T2));
}
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT (TIME T1, TIME T2){
   return (TIMEToDetik(T1) - TIMEToDetik(T2) < 0);
}
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (TIME T1, TIME T2){
   return (TIMEToDetik(T1) - TIMEToDetik(T2) > 0);
}
/* Mengirimkan true jika T1>T2, false jika tidak */

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T){
   return DetikToTIME(TIMEToDetik(T) + 1);
}
/* Mengirim 1 detik setelah T dalam bentuk TIME */
TIME NextNDetik (TIME T, int N){
   return DetikToTIME(TIMEToDetik(T) + N);
}
/* Mengirim N detik setelah T dalam bentuk TIME */
TIME PrevDetik (TIME T){
   return DetikToTIME(TIMEToDetik(T) - 1);
}
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
TIME PrevNDetik (TIME T, int N){
   return DetikToTIME(TIMEToDetik(T) - N);
}
/* Mengirim N detik sebelum T dalam bentuk TIME */

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh){
   if (TIMEToDetik(TAw) > TIMEToDetik(TAkh)){
      return 86400 + TIMEToDetik(TAkh) - TIMEToDetik(TAw);
   }
   return (TIMEToDetik(TAkh) - TIMEToDetik(TAw));
}
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */