#include "stackDraft.h"

void CreateEmptyDraft(Draft *D){
/* I.S. sembarang */
/* F.S. terbentuk Draft kosong */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    DCONTENT(*D).Length = 0;
}

void CreateEmptyStackDraft(StackDraft *SD){
/* I.S. sembarang */
/* F.S. terbentuk Stack Draft kosong berkapasitas MaxElS */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    ADDR_TOPSD(*SD) = NilS;
    // UNAME(*SD).TabWord = databasePengguna[activeUser].Nama.TabWord;
}

void CreateEmptyListUserDraft(ListUserDraft *LUD){
/* I.S. sembarang */
/* F.S. terbentuk List User Draft kosong berkapasitas 20 */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    NEFFUD(*LUD) = 0;
}

boolean isEmptyDraft(Draft D){
/* Mengirimkan true jika D kosong, false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (DCONTENT(D).Length == 0);
}

boolean isFUllDraft(Draft D){
/* Mengirimkan true jika D penuh, false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (DCONTENT(D).Length == NMax);
}

boolean isEmptyStackDraft(StackDraft SD){
/* Mengirimkan true jika SD kosong, false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return ADDR_TOPSD(SD) == NilS;
}

boolean isFullStackDraft(StackDraft SD){
/* Mengirimkan true jika SD penuh, false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (ADDR_TOPSD(SD) == MaxElS - 1);
}

boolean isEmptyListUserDraft(ListUserDraft LUD){
/* Mengirimkan true jika LUD kosong, false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (NEFFUD(LUD) == 0);
}

boolean isFullListUserDraft(ListUserDraft LUD){
/* Mengirimkan true jika LUD penuh, false jika tidak */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    return (NEFFUD(LUD) == 20);
}

boolean isUserDraft(ListUserDraft LUD, Word UserName){
/* Mengirimkan true jika user dengan nama UserName adalah pengguna draft, false jika tidak */

    /* KAMUS LOKAL */
    int len, i;

    /* ALGORITMA */
    len = NEFFUD(LUD);
    for (i = 0; i < len; i++){
        if (isWordEqual(UNAME(LUD_IDX(LUD, i)), UserName)){
            return true;
        }
    }
    return false;
}

void PushStackDraft(StackDraft *SD, Draft D, Word UserName){
/* I.S. SD tidak penuh, mungkin kosong */
/* F.S. Draft D dimasukkan ke dalam StackDraft SD dan menjadi TOPSD yang baru */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    UNAME(*SD) = UserName;
    ADDR_TOPSD(*SD)++;
    TOPSD(*SD) = D;
}

void PopStackDraft(StackDraft *SD, Draft *D){
/* I.S. SD tidak kosong, mungkin penuh */
/* F.S. TOPSD StackDraft SD disimpan ke Draft D, ADDR_TOPSD berkurang 1 */

    /* KAMUS LOKAL */

    /* ALGORITMA */
    *D = TOPSD(*SD);
    ADDR_TOPSD(*SD)--;
}

void insertNewUserDraft(ListUserDraft *LUD, StackDraft SD){
/* I.S. LUD tidak penuh, mungkin kosong */
/* F.S. SD menjadi elemen dari List User Draft */

    /* KAMUS LOKAL */

    /* ALGORIRTMA */
    LUD_IDX(*LUD, NEFFUD(*LUD)) = SD;
    NEFFUD(*LUD)++;
}

void deleteDraftUser(ListUserDraft *LUD, Word UserName){
/* I.S. LUD tidak kosong, mungkin penuh */
/* F.S. StackDraft pengguna dengan nama UserName dihapus, LUDNeff berkurang 1 */

    /* KAMUS LOKAL */
    int len, i, idx;

    /* ALGORITMA */
    // Ambil nilai efektif LUD
    len = NEFFUD(*LUD);

    // Loop untuk menjadi index pengguna draft dengan nama UserName
    for (i = 0; i < len; i++){
        if (isWordEqual(UNAME(LUD_IDX(*LUD, i)), UserName)){
            idx = i;
        }
    }

    // Loop untuk menggeser LUD agar rata kiri
    for (i = idx; i < len; i++){
        if (i != len - 1){
            LUD_IDX(*LUD, i) = LUD_IDX(*LUD, i+1);
        }
    }

    // Penyesuaian nilai efektif LUD
    NEFFUD(*LUD)--;
}

int indexInLUD(ListUserDraft LUD, Word UserName){
/* Mengirimkan index pengguna dengan nama UserName pada LUD */

    /* KAMUS LOKAL */
    int i, len;

    /* ALGORITMA */
    len = NEFFUD(LUD);
    for (i = 0; i < len; i++){
        if (isWordEqual(UNAME(LUD_IDX(LUD, i)), UserName)){
            return i;
        }
    }
    return NilS;
}