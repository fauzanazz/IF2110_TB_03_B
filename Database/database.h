#ifndef _DATABASE_H
#define _DATABASE_H

#include "../ADT/Pengguna/pengguna.h"
#include "../ADT/Graf/graf.h"
#include "../ADT/PrioQue/prioqueuefriendrequest.h"
#include "../ADT/Utas/utas.h"
#include "../ADT/Mesin-Kata/charmachine-file.h"
#include "../ADT/Function/string-function.h"
#include "../ADT/Mesin-Kata/wordmachine.h"
#include "../ADT/boolean.h"
#include "../ADT/Mesin-Kata/charmachine.h"
#include <stdio.h>
#include <stdlib.h>

extern ListPengguna databasePengguna;
extern Graf GFriend;
extern PrioQueueFriendRequest dataFriendRequest;
extern ListDin dataKicau;
// extern ListUserDraft dataDraf;
extern ListKicauanUtas dataUtas;
extern int ActiveUser;
extern boolean isLogin;

#endif