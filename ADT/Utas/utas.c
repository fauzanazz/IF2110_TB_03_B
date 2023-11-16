#include "utas.h"

void CreateListUtas(ListKicauanUtas *l, int capacity){
    LISTUTAS(*l) = (ListUtas *) malloc (capacity * sizeof(ListUtas));
    CAPACITYUtas(*l) = capacity;
    NEFFUtas(*l) = 0;
}

void dealocateListUtas(ListKicauanUtas *l){
    free(LISTUTAS(*l));
    CAPACITYUtas(*l) = 0;
    NEFFUtas(*l) = 0;
}

int lisUtastLength(ListKicauanUtas l){
    return NEFFUtas(l);
}

int getFirstIdxUtas(ListKicauanUtas l){
    return IDX_MIN;
}

int getLastIdxUtas(ListKicauanUtas l){
    return NEFFUtas(l) - 1;
}

boolean isIdxUtasValid(ListKicauanUtas l, int i){
    return (i >= IDX_MIN && i < CAPACITYUtas(l));
}

boolean isIdxUtasEff(ListKicauanUtas l, int i){
    return (i >= IDX_MIN && i < NEFFUtas(l));
}

boolean isListUtasEmpty(ListKicauanUtas l){
    return (NEFFUtas(l) == 0);
}

boolean isListUtasFull(ListKicauanUtas l){
    return (NEFFUtas(l) == CAPACITYUtas(l));
}

void insertLastListUtas(ListKicauanUtas *l, ListUtas val){
    if (isListUtasFull(*l)){
        expandListUtas(l, 1);
    }

    ELMTUtas(*l, NEFFUtas(*l)) = val;
    NEFFUtas(*l)++;
}
void expandListUtas(ListKicauanUtas *l, int num){
    ListUtas *newBuffer = (ListUtas *) malloc ((CAPACITYUtas(*l) + num) * sizeof(ListUtas));
    int i;
    for (i = 0; i < CAPACITYUtas(*l); i++){
        newBuffer[i] = ELMTUtas(*l, i);
    }
    free(LISTUTAS(*l));
    LISTUTAS(*l) = newBuffer;
    CAPACITYUtas(*l) += num;
}

void compressListUtas(ListKicauanUtas *l){
    ListUtas *newBuffer = (ListUtas *) malloc (NEFFUtas(*l) * sizeof(ListUtas));
    int i;
    for (i = 0; i < NEFFUtas(*l); i++){
        newBuffer[i] = ELMTUtas(*l, i);
    }
    free(LISTUTAS(*l));
    LISTUTAS(*l) = newBuffer;
    CAPACITYUtas(*l) = NEFFUtas(*l);
}

AddressUtas newUtas(Kicau_struct val){
    AddressUtas p;

    p = (AddressUtas) malloc (sizeof(NodeUtas));

    if (p != NULL){
        INFOUtas(p) = val;
        NEXTUtas(p) = NULL;
    }
    return p;
}

void CreateUtas(ListUtas *l, int id_kicauan){
    (*l).id_kicauan = id_kicauan;
    (*l).neff = 1;
    (*l).Utas= NULL;
}

boolean isEmptyUtas(AddressUtas l){
    return (l == NULL);
}

void insertLastUtas(AddressUtas *l, Kicau_struct val){
    AddressUtas p = *l;
    AddressUtas new = newUtas(val);
    if (new != NULL){
        if (p == NULL){
            *l = new;
        } else {
            while (NEXTUtas(p) != NULL){
                p = NEXTUtas(p);
            }
            NEXTUtas(p) = new;
        }
    }
}

void deleteAt(AddressUtas *l, int idx){
    AddressUtas p = *l;
    int  i;
    if (idx == 0){
        *l = NEXTUtas(p);
        free(p);
    } else {
        for (i = 0; i < idx-1; i++){
            p = NEXTUtas(p);
        }
        AddressUtas temp = NEXTUtas(p);
        NEXTUtas(p) = NEXTUtas(temp);
        free(temp);
    }

}

void cetakUtas(AddressUtas l);
