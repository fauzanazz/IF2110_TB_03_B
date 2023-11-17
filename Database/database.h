#ifndef _DATABASE_H
#define _DATABASE_H

#include "../ADT/pengguna/pengguna.h"
#include "../ADT/Graf/graf.h"
#include "../ADT/PrioQue/prioqueuefriendrequest.h"
#include "../ADT/Kicauan/kicauan.h"
#include "../ADT/draf/draf.h"
#include "../ADT/Kicauan/kicauan.h"
#include "../ADT/Utas/utas.h"
#include "../IO/charmachine-file.h"
#include "../ADT/Function/string-function.h"
#include "../ADT/Mesin-Kata/wordmachine.h"
#include "../ADT/pengguna/pengguna.h"
#include "../ADT/Utas/utas.h"
#include <stdio.h>

extern ListPengguna databasePengguna;
extern Graf GFriend;
extern PrioQueueFriendRequest dataFriendRequest;
extern ListDin dataKicau;
extern ListPenggunaDraf dataDraf;
extern ListKicauanUtas dataUtas;
extern int ActiveUser;
extern boolean isLogin;

#endif