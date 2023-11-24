#include "kicauan.h"
#include <stdio.h>

Kicau_struct createKicau() {
    Kicau_struct kicau;
    time_t current;
    kicau.IdKicau = 1;
    kicau.IdProfile = 1;
    time(&current);
    DATETIME date;
    ConvertTimeTtoDATETIME(current, &date);
    kicau.TanggalTerbit = date;
    kicau.JumlahLike = 1;
    kicau.IsiKicauan.Length = 5;
    kicau.IsiKicauan.TabWord[0] = 'H';
    kicau.IsiKicauan.TabWord[1] = 'e';
    kicau.IsiKicauan.TabWord[2] = 'l';
    kicau.IsiKicauan.TabWord[3] = 'l';
    kicau.IsiKicauan.TabWord[4] = 'o';
    kicau.Tagar.Length = 5;
    kicau.Tagar.TabWord[0] = 'b';
    kicau.Tagar.TabWord[1] = 'r';
    kicau.Tagar.TabWord[2] = 'o';
    kicau.Tagar.TabWord[3] = 'o';
    kicau.Tagar.TabWord[4] = 'o';
    return kicau;
}

void testCreateListDinKicau() {
    ListDin l;
    CreateListDinKicau(&l, 5);

    // Test capacity
    if (CAPACITY(l) == 5) {
        printf("CreateListDinKicau() test 1 passed.\n");
    } else {
        printf("CreateListDinKicau() test 1 failed.\n");
    }

    // Test NEFF
    if (NEFFKicau(l) == 0) {
        printf("CreateListDinKicau() test 2 passed.\n");
    } else {
        printf("CreateListDinKicau() test 2 failed.\n");
    }
}

void testIsEmptyKicau() {
    ListDin l;
    CreateListDinKicau(&l, 5);

    // Test when list is empty
    if (isEmptyKicau(l)) {
        printf("isEmptyKicau() test 1 passed.\n");
    } else {
        printf("isEmptyKicau() test 1 failed.\n");
    }

    // Test when list is not empty
    Kicau_struct kicau = createKicau();
    insertLastKicau(&l, kicau);
    if (!isEmptyKicau(l)) {
        printf("isEmptyKicau() test 2 passed.\n");
    } else {
        printf("isEmptyKicau() test 2 failed.\n");
    }
}

void testIsFullKicau() {
    ListDin l;
    CreateListDinKicau(&l, 5);

    // Test when list is not full
    if (!isFullKicau(l)) {
        printf("isFullKicau() test 1 passed.\n");
    } else {
        printf("isFullKicau() test 1 failed.\n");
    }

    // Test when list is full
    for (int i = 0; i < 5; i++) {
        Kicau_struct kicau = createKicau();
        insertLastKicau(&l, kicau);
    }
    if (isFullKicau(l)) {
        printf("isFullKicau() test 2 passed.\n");
    } else {
        printf("isFullKicau() test 2 failed.\n");
    }
}

void testInsertLastKicau() {
    ListDin l;
    CreateListDinKicau(&l, 5);

    // Test inserting one element
    Kicau_struct kicau = createKicau();
    insertLastKicau(&l, kicau);
    if (NEFFKicau(l) == 1 && ELMT(l, getLastIdxKicau(l)).IdKicau == kicau.IdKicau) {
        printf("insertLastKicau() test 1 passed.\n");
    } else {
        printf("insertLastKicau() test 1 failed.\n");
    }

    // Test inserting multiple elements
    Kicau_struct kicau2 = createKicau();
    insertLastKicau(&l, kicau2);
    if (NEFFKicau(l) == 2 && ELMT(l, getLastIdxKicau(l)).IdKicau == kicau2.IdKicau) {
        printf("insertLastKicau() test 2 passed.\n");
    } else {
        printf("insertLastKicau() test 2 failed.\n");
    }
}

void testDeleteLastKicau() {
    ListDin l;
    CreateListDinKicau(&l, 5);

    // Test deleting one element
    Kicau_struct kicau = createKicau();
    insertLastKicau(&l, kicau);
    Kicau_struct result;
    deleteLastKicau(&l, &result);
    if (NEFFKicau(l) == 0 && result.IdKicau == kicau.IdKicau) {
        printf("deleteLastKicau() test 1 passed.\n");
    } else {
        printf("deleteLastKicau() test 1 failed.\n");
    }

    // Test deleting multiple elements
    Kicau_struct kicau2 = createKicau();
    insertLastKicau(&l, kicau);
    insertLastKicau(&l, kicau2);
    deleteLastKicau(&l, &result);
    if (NEFFKicau(l) == 1 && result.IdKicau == kicau2.IdKicau) {
        printf("deleteLastKicau() test 2 passed.\n");
    } else {
        printf("deleteLastKicau() test 2 failed.\n");
    }
}

int main() {
    testCreateListDinKicau();
    testIsEmptyKicau();
    testIsFullKicau();
    testInsertLastKicau();
    testDeleteLastKicau();

    return 0;
}