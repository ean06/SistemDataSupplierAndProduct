#ifndef SUPPLIER_H_INCLUDED
#define SUPPLIER_H_INCLUDED
#include <iostream>
#include "produk.h"

using namespace std;

typedef struct Supplier *adrSupplier;

struct Supplier{
    string namaSupplier;
    adrSupplier next;
};

struct listSupplier{
    adrSupplier first;
};

void createListSupplier(listSupplier &L);
adrSupplier newElmSupplier(string nama);
bool isEmptySupplier(listSupplier L);
void addSupplier(listSupplier &L, adrSupplier p);
void deleteFirstSupplier(listSupplier &L, adrSupplier &p);
void deleteLastSupplier(listSupplier &L, adrSupplier &p);
void deleteAfterSupplier(listSupplier &L, adrSupplier &p, adrSupplier prec);
void deleteSupplier(listSupplier &L, string nama);
void deleteSupplierWithProduk(listSupplier &LS, listProduk &LP, string nama);
void showSupplier(listSupplier L);
adrSupplier findSupplier(listSupplier L, string nama);
void showSupplierProduk(listSupplier LS, listProduk LP);

#endif // SUPPLIER_H_INCLUDED
