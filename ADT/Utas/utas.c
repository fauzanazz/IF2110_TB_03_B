#include "utas.h"

void CreateListUtas(ListUtas *l, int capacity);

void dealocateListUtas(ListUtas *l);

int lisUtastLength(ListUtas l);

int getFirstIdxUtas(ListUtas l);

int getLastIdxUtas(ListUtas l);

boolean isIdxUtasValid(ListUtas l, int i);

boolean isIdxUtasEff(ListUtas l, int i);

boolean isListUtasEmpty(ListUtas l);

boolean isListUtasFull(ListUtas l);

void printListUtas(ListUtas l);

void copyListUtas(ListUtas lIn, ListUtas *lOut);

void insertLastListUtas(ListUtas *l, Kicau_struct val);

void deleteLastUtas(ListUtas *l, Kicau_struct *val);

void expandListUtas(ListUtas *l, int num);

void shrinkListUtas(ListUtas *l, int num);

void compressListUtas(ListUtas *l);

void CreateUtas(AddressUtas *l);

boolean isEmptyUtas(AddressUtas l);

void insertLastUtas(AddressUtas *l, NodeUtas val);

void deleteAt(AddressUtas *l, int idx, NodeUtas *val);

void displayUtas(AddressUtas l);
