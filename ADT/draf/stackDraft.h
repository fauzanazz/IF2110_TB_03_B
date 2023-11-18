#ifndef STACKD_H
#define STACKD_H

#include "../boolean.h"
#include "../Mesin-Kata/charmachine.c"
#include "../Mesin-Kata/wordmachine.c"
#include <datetime.h>
#include "../Time/datetime.h"

#define NilS -1
#define MaxElS 100

typedef struct {
    Word DrafContent;
    DATETIME dateLastEdited;
} Draft;

#define DCONTENT(D) (D).DrafContent
#define DDATE(D) (D).dateLastEdited

typedef int AddressS;

typedef struct {
    Word UserName;
    Draft Buffer[MaxElS];
    AddressS DSTop;
} StackDraft;

#define UNAME(SD) (SD).UserName
#define ADDR_TOPSD(SD) (SD).DSTop
#define TOPSD(SD) (SD).Buffer[(SD).DSTop]

typedef struct {
    StackDraft BufferUserDraft[20];
    int LUDNeff;
} ListUserDraft;

#define LUD_IDX(LUD, idx) (LUD).BufferUserDraft[(idx)]
#define NEFFUD(LUD) (LUD).LUDNeff

void CreateEmptyDraft(Draft *D);
/* I.S. sembarang */
/* F.S. terbentuk Draft kosong */

void CreateEmptyStackDraft(StackDraft *SD);
/* I.S. sembarang */
/* F.S. terbentuk Stack Draft kosong berkapasitas MaxElS */

void CreateEmptyListUserDraft(ListUserDraft *LUD);
/* I.S. sembarang */
/* F.S. terbentuk List User Draft kosong berkapasitas 20 */

boolean isEmptyDraft(Draft D);
/* Mengirimkan true jika D kosong, false jika tidak */

boolean isFUllDraft(Draft D);
/* Mengirimkan true jika D penuh, false jika tidak */

boolean isEmptyStackDraft(StackDraft SD);
/* Mengirimkan true jika SD kosong, false jika tidak */

boolean isFullStackDraft(StackDraft SD);
/* Mengirimkan true jika SD penuh, false jika tidak */

boolean isEmptyListUserDraft(ListUserDraft LUD);
/* Mengirimkan true jika LUD kosong, false jika tidak */

boolean isFullListUserDraft(ListUserDraft LUD);
/* Mengirimkan true jika LUD penuh, false jika tidak */

boolean isUserDraft(ListUserDraft LUD, Word UserName);
/* Mengirimkan true jika user dengan nama UserName adalah pengguna draft, false jika tidak */

void PushStackDraft(StackDraft *SD, Draft D, Word UserName);
/* I.S. SD tidak penuh, mungkin kosong */
/* F.S. Draft D dimasukkan ke dalam StackDraft SD dan menjadi TOPSD yang baru */

void PopStackDraft(StackDraft *SD, Draft *D);
/* I.S. SD tidak kosong, mungkin penuh */
/* F.S. TOPSD StackDraft SD disimpan ke Draft D, ADDR_TOPSD berkurang 1 */

void insertNewUserDraft(ListUserDraft *LUD, StackDraft SD);
/* I.S. LUD tidak penuh, mungkin kosong */
/* F.S. SD menjadi elemen dari List User Draft */

void deleteDraftUser(ListUserDraft *LUD, Word UserName);
/* I.S. LUD tidak kosong, mungkin penuh */
/* F.S. StackDraft pengguna dengan nama UserName dihapus, LUDNeff berkurang 1 */

int indexInLUD(ListUserDraft LUD, Word UserName);
/* Mengirimkan index pengguna dengan nama UserName pada LUD */

#endif