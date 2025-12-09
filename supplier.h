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
void addSupplier(listSupplier &L, adrSupplier p);
void deleteSupplier(listSupplier &L, string nama, adrSupplier p);
void showSupplier(listSupplier L);
adrSupplier findSupplier(listSupplier L, string nama);
void showSupplierProduk(listSupplier LS, listProduk LP);

#endif // SUPPLIER_H_INCLUDED
