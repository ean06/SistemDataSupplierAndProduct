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


#endif // RELASI_H_INCLUDED
