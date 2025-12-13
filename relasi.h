#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include <iostream>
#include "supplier.h"
#include "produk.h"

using namespace std;
typedef struct Relasi *adrRelasi;

struct Relasi{
    adrSupplier up;
    adrProduk down;
    adrRelasi next;
};

struct listRelasi {
    adrRelasi first;
};

void createListRelasi(listRelasi &L);
adrRelasi newElmRelasi(adrSupplier LS, adrProduk LP);
void addRelasi(listRelasi LR, listSupplier LS, listProduk LP, adrRelasi r);
void deleteRelasi(listRelasi LR, listSupplier LS, listProduk LP);

#endif // RELASI_H_INCLUDED
