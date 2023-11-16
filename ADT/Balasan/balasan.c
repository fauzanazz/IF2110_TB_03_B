#include <stdio.h>
#include <stdlib.h>
#include "balasan.h"

/* ********** KONSTRUKTOR ListBalasan ********** */
/* Konstruktor : create list kosong  */
void CreateListBalasan(ListDinBalasan *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi KICAUAN */
{
    NEFFBalasan(*l) = 0;
    ContentBalasan(*l) = (BALASAN *)malloc(capacity * sizeof(BALASAN));
    CAPACITYBalasan(*l) = capacity;
}

void dealocateBalasan(ListDinBalasan *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(ContentBalasan(*l));
    NEFFBalasan(*l) = 0;
    CAPACITYBalasan(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int LengthListBalasan(ListDinBalasan l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFFBalasan(l);
}

/* ********** OPERASI LAIN ********** */
void copyListDinBalasan(ListDinBalasan lIn, ListDinBalasan *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    int i;
    dealocateBalasan(lOut);
    CreateListBalasan(lOut, CAPACITYBalasan(lIn));
    NEFFBalasan(*lOut) = NEFFBalasan(lIn);
    for (i = 0; i < NEFFBalasan(lIn); i++)
    {
        ELMTBalasan(*lOut, i) = ELMTBalasan(lIn, i);
    }
}

BALASAN getBalasan(ListDinListB *lb, int IDKicauan, int IDBalasan) {

    ListDinBalasan l = getListDinBalasan(lb, IDKicauan);

    for (int i = 0; i < NEFFBalasan(l); i++) {
        if (IDBalasan(ELMTBalasan(l, i)) == IDBalasan) {
            return ELMTBalasan(l,i);
        }
    }
    
    printf("Tidak terdapat Balasan dengan ID tersebut.\n");

}

void printBalasan(BALASAN B) {
    /*
    | ID = 6
    | John Doe
    | 14/10/2023 11:09:18
    | Hello BurBir!
    */

    printf("| ID = %d\n", IDBalasan(B));
    printf("| ");printWord(AuthorBalasan(B));printf("\n");
    printf("| ");TulisDATETIME(DatetimeBalasan(B));printf("\n");
    printf("| ");printWord(TxtBalasan(B));printf("\n");
}

/* ********** BOOLEAN ********** */
boolean isFullBalasan(ListDinBalasan l)
/* return true jika penuh */
{
    return (NEFFBalasan(l) == CAPACITYBalasan(l));
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinBalasan(ListDinBalasan *l, BALASAN val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yanDg baru */
/* ********** MENGHAPUS ELEMEN ********** */
{
    if (NEFFBalasan(*l)++ >= CAPACITYBalasan(*l)) {
        expandListDinBalasan(l, 4);
    }
    ELMTBalasan(*l, LengthListBalasan(*l)) = val;
    NEFFBalasan(*l) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinBalasan(ListDinBalasan *l, BALASAN *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMTBalasan(*l, LengthListBalasan(*l) - 1);
    NEFFBalasan(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinBalasan(ListDinBalasan *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    ListDinBalasan temp;
    CreateListBalasan(&temp, CAPACITYBalasan(*l) + num);
    CAPACITYBalasan(*l) += num;
    copyListDinBalasan(*l, &temp);
    free(ContentBalasan(*l));
    ContentBalasan(*l) = (BALASAN *)malloc(CAPACITYBalasan(temp) * sizeof(BALASAN));
    copyListDinBalasan(temp, l);
    dealocateBalasan(&temp);
}

void shrinkListDinBalasan(ListDinBalasan *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    ListDinBalasan temp;
    CreateListBalasan(&temp, CAPACITYBalasan(*l) - num);
    CAPACITYBalasan(*l) -= num;
    copyListDinBalasan(*l, &temp);
    dealocateBalasan(l);
    CreateListBalasan(l, CAPACITYBalasan(temp));
    copyListDinBalasan(temp, l);
    dealocateBalasan(&temp);
}

/* ********** KONSTRUKTOR ListDinBalasan ********** */
/* Konstruktor : create list kosong  */
void CreateListDinB(ListDinListB *lb, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi KICAUAN */
{
    NEFFListB(*lb) = 0;
    ContentListB(*lb) = (ListDinBalasan *)malloc(capacity * sizeof(ListDinBalasan));
    CAPACITYListB(*lb) = capacity;
}

void dealocateListDinB(ListDinListB *lb)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(ContentListB(*lb));
    NEFFListB(*lb) = 0;
    CAPACITYListB(*lb) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int LengthListB(ListDinListB l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFFListB(l);
}

/* ********** OPERASI LAIN ********** */
void copyListDinB(ListDinListB lIn, ListDinListB *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    int i;
    dealocateListDinB(lOut);
    CreateListDinB(lOut, CAPACITYListB(lIn));
    NEFFListB(*lOut) = NEFFListB(lIn);
    for (i = 0; i < NEFFListB(lIn); i++)
    {
        ELMTListB(*lOut, i) = ELMTListB(lIn, i);
    }
}

ListDinBalasan getListDinBalasan(ListDinListB *lb, int IDKicauan) {
    
    for (int i = 0; i < NEFFListB(*lb); i++) {
        if (IDKicauB(ELMTListB(*lb,i)) == IDKicauan) {
            return ELMTListB(*lb,i);
        }
    }

    printf("Tidak terdapat Kicauan dengan ID tersebut.\n");
}

/* ********** BOOLEAN ********** */
boolean isFullListDinB(ListDinListB lb)
/* return true jika penuh */
{
    return (NEFFListB(lb) == CAPACITYListB(lb));
}

boolean isKicauanInList(ListDinListB lb, int IDKicauan) {

    for(int i = 0; i < NEFFListB(lb); i++) {
        if(IDKicauB(ELMTListB(lb, i)) == IDKicauan) {
            return true;
        }
    }
    return false;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinB(ListDinListB *l, ListDinBalasan val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yanDg baru */
{
    if (NEFFListB(*l)++ >= CAPACITYListB(*l)) {
        expandListDinB(l, 4);
    }
    
    ELMTListB(*l, LengthListB(*l)) = val;
    NEFFListB(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinB(ListDinListB *l, ListDinBalasan *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMTListB(*l, LengthListB(*l) - 1);
    NEFFListB(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinB(ListDinListB *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    ListDinListB temp;
    CreateListDinB(&temp, CAPACITYListB(*l) + num);
    CAPACITYListB(*l) += num;
    copyListDinB(*l, &temp);
    free(ContentListB(*l));
    ContentListB(*l) = (ListDinBalasan *)malloc(CAPACITYListB(temp) * sizeof(ListDinBalasan));
    copyListDinB(temp, l);
    dealocateListDinB(&temp);
}

void shrinkListDinB(ListDinListB *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    ListDinListB temp;
    CreateListDinB(&temp, CAPACITYListB(*l) - num);
    CAPACITYListB(*l) -= num;
    copyListDinB(*l, &temp);
    dealocateListDinB(l);
    CreateListDinB(l, CAPACITYListB(temp));
    copyListDinB(temp, l);
    dealocateListDinB(&temp);
}

void addBalasanKeListDin(ListDinListB *lb, ListDinBalasan B){
    
}

/* ********* CONFIGS ********* */
void loadBalasanConfig(char filename[], ListDinListB *lb)
/* I.S. l kosong; */
/* F.S. l diisi sesuai config */
{
    // Kamus Lokal
    int i, j, CapListB, CapB, IDKicauan;


    // ALGORITMA
    STARTWORDFILE(filename);
    CapListB = wordToInt(currentWord);
    CreateListDinB(lb, CapListB);

    for ( i = 0; i < CAPACITYListB(*lb); i++) {
        ListDinBalasan l;
        ADVWORDFILE();
        IDKicauan = wordToInt(currentWord);
        ADVWORDFILE();
        CapB = wordToInt(currentWord);
        CreateListBalasan(&l, CapB);
        IDKicauB(l) = IDKicauan;

        for (j = 0; j < CAPACITYBalasan(l); j++) {
            ADVWORDFILE();
            // Membaca ID BALASAN dan ID KICAUAN
            Word ID = currentWord;
            int currentResult = 0;
            boolean isNegative = false;  
            for (int i = 0; i < ID.Length; i++) {
                if (ID.TabWord[i] == '-') {
                    isNegative = true;  
                } else if (ID.TabWord[i] == ' ') {
                    if (isNegative) {
                        currentResult = -currentResult;  
                        isNegative = false;  
                    }
                    IDKicauan(ELMTBalasan(l, j)) = currentResult;
                    currentResult = 0;
                } else {
                    currentResult = currentResult * 10 + (ID.TabWord[i] - '0');
                }
            }
            if (isNegative) {
                currentResult = -currentResult;  
            }
            IDBalasan(ELMTBalasan(l, j)) = currentResult;
            ADVWORDFILE();
            TxtBalasan(ELMTBalasan(l, j)) = currentWord;
            ADVWORDFILE();
            AuthorBalasan(ELMTBalasan(l, j)) = currentWord;
            ADVWORDFILE();
            // Membaca DateTime lalu mengubanya ke typdef struct DATETIME
            DATETIME t;
            Word temp = currentWord;
            int DD = (int)(temp.TabWord[0] % 48) * 10 + (int)(temp.TabWord[1] % 48);
            int MM = (int)(temp.TabWord[3] % 48) * 10 + (int)(temp.TabWord[4] % 48);
            int YY = (int)(temp.TabWord[6] % 48) * 1000 + (int)(temp.TabWord[7] % 48) * 100 + (int)(temp.TabWord[8] % 48) * 10 + (int)(temp.TabWord[9] % 48);
            int hh = (int)(temp.TabWord[11] % 48) * 10 + (int)(temp.TabWord[12] % 48);
            int mm = (int)(temp.TabWord[14] % 48) * 10 + (int)(temp.TabWord[15] % 48);
            int ss = (int)(temp.TabWord[17] % 48) * 10 + (int)(temp.TabWord[18] % 48);
            CreateDATETIME(&t, DD, MM, YY, hh, mm, ss);
            DatetimeBalasan(ELMTBalasan(l, j)) = t;
        }
        NEFFBalasan(l) = CAPACITYBalasan(l);
        ELMTListB(*lb, i) = l;
    }
    NEFFListB(*lb) = CAPACITYListB(*lb);
    }

void displayConfigBalasan(ListDinBalasan B)
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    printf("%d\n",IDKicauB(B));
    printf("%d\n",CAPACITYBalasan(B));
    for (i = 0; i < CAPACITYBalasan(B); i++) {
        printf("%d %d\n", IDKicauan(ELMTBalasan(B,i)), IDBalasan(ELMTBalasan(B,i)));
        printWord(TxtBalasan(ELMTBalasan(B, i)));
        printf("\n");
        printWord(AuthorBalasan(ELMTBalasan(B, i)));
        printf("\n");
        TulisDATETIME(DatetimeBalasan(ELMTBalasan(B, i)));
        printf("\n");
    }
}

void displayListB(ListDinListB lb)
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    printf("%d\n", CAPACITYListB(lb));
    for (i = 0; i < CAPACITYListB(lb); i++)
    {
        displayConfigBalasan(ELMTListB(lb, i));
    }
}

int wordToInt(Word kata)
{
    int res = 0;
    int i = 0;
    while (kata.TabWord[i] >= '0' && kata.TabWord[i] <= '9' && i < kata.Length) 
    // memeriksa jika char di antara kedua bilangan tersebut (Jika ditambah komen di kanan angka), dan i lebih kecil dari panjang (Jika tidak ada, karena tidak tahu mengapa begitu keluaran 24 untuk ID 2)
    {
        res = res * 10 + (kata.TabWord[i] - '0');
        i++;
    }
    return res;
}

/* ********* FITUR BALASAN ********* */
void BalasKicauan(ListDinKicauan *lk, int IDKicauan, int IDBalasan, currentUser* CU, ListUserStatik* LU, ListTree *lt, ListDinListB *lb, Graph* graph, ListDinBalasan* lB) {
    
    //KAMUS LOKAL
    int idx = IDX_UNDEF, UserIDCurrent, UserID;

    // Mencari kicauan dengan IDKicauan 
    for (int i = 0; i < CAPACITYKICAUAN(*lk); i++) {
        if (IDKICAUAN(ELMTKICAUAN(*lk, i)) == IDKicauan) {
            idx = i;
            break;
        }
    }   

    // Jika tidak ada kicauan dengan IDKicauan tersebut return tidak terdapat kicauan
    if (idx == IDX_UNDEF) {
        return(printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n"));
    }
    TreeNode* KicauSkrg = SearchTree(lt, IDKicauan);

    // Jika tidak ada balasan dengan IDBalasan return tidak terdapat balasan
    if (!IsValidID(KicauSkrg, IDBalasan)) {
        return(printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n"));
    }

    // Mencari ID user untuk validasi pembalasan       
    if (IDBalasan == -1) {
        Word nama = AUTHORKICAUAN(ELMTKICAUAN(*lk, idx));
        UserID = getUserId(nama, *LU);
    } else {
        BALASAN balasanT = getBalasan(lb, IDKicauan, IDBalasan);
        Word nama = AuthorBalasan(balasanT);
        UserID = getUserId(nama, *LU);
    }
    UserIDCurrent = getUserIdCurrent(*CU, *LU);
    //Jika bukan teman dan akun tersebut privat 
    if (isTeman(graph, UserIDCurrent, UserID) == false && JENIS_USER(*LU,UserID) == 0) {
        return(printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n"));
    }

    // Semua error telah dilalui dan dilanjuti dengan melakukan input balasan
    BALASAN newBalasan;
    DATETIME TimeNow;
    CreateDATETIME(&TimeNow, 10, 10, 2023, 19, 39, 13); // Waktu sementara

    // Melalakukan input balasan
    printf("Masukkan balasan:\n");
    STARTWORDINPUT();

    // Menyimpan data balasan;
    IDKicauan(newBalasan) = IDKicauan;
    TxtBalasan(newBalasan) = currentWord;
    // Mendapatkan nama author dengan ID current user
    Word namaAuthor = NAMA_USER(*LU, UserIDCurrent);
    AuthorBalasan(newBalasan) = namaAuthor;
    DatetimeBalasan(newBalasan) = TimeNow;

    // Jika Kicuan belum pernah dibalas maka membuat ListDinBalasan baru
    if(!isKicauanInList(*lb, IDKicauan)) {
        ListDinBalasan LDB;
        CreateListBalasan(&LDB,10);
        IDBalasan(newBalasan) = 1; // IDBalasan akan menjadi 1 karena baru saja di balas kicauannya
        insertLastListDinBalasan(&LDB, newBalasan);  // Insert Balasan ke ListDinBalasan
        insertLastListDinB(lb, LDB); // Insert ListDinBalasan ke ListDinB
        dealocateBalasan(&LDB);
 
    } else { // Jika sudah maka mencari ListDinBalasan dengan IDKicauan lalu insert balasan baru
        ListDinBalasan LDB;
        LDB = getListDinBalasan(lb, IDKicauan);
        IDBalasan(newBalasan) = NEFFBalasan(LDB);
        insertLastListDinBalasan(&LDB, newBalasan);  // Insert Balasan ke ListDinBalasan
        dealocateBalasan(&LDB);
    }

    printf("Selamat! balasan telah diterbitkan!\nDetil balasan:\n");
    printBalasan(newBalasan);


}