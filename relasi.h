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

void createListRelasi(listRelasi &LR);
adrRelasi newElmRelasi(adrSupplier LS, adrProduk LP);
bool checkRelasiSupplier(listRelasi LR, string namaSupplier);
void addRelasi(listRelasi LR, listSupplier LS, listProduk LP, adrRelasi r);
void deleteRelasi(listRelasi LR, listSupplier LS, listProduk LP);
void showSupplierWithProduk(listSupplier LS, listRelasi LR);
void showProdukBySupplier(listSupplier LS, listRelasi LR, string namaSupplier);
void countProductsPerSupplier(listSupplier LS, listRelasi LR);
void showMostSupplierProduk(listSupplier LS, listRelasi LR);
void showFewstSupplierProduk(listSupplier LS, listRelasi LR);

#endif // RELASI_H_INCLUDED
