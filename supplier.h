#ifndef SUPPLIER_H_INCLUDED
#define SUPPLIER_H_INCLUDED
#include <iostream>

using namespace std;
typedef struct Supplier *adrSupplier;

struct Supplier{
    string namaSupplier;
    adrSupplier next;
};

struct listSupplier{
    adrSupplier first;
};

void createListSupplier(listSupplier &LS);
adrSupplier newElmSupplier(string nama);
bool isEmptySupplier(listSupplier LS);
void addSupplier(listSupplier &LS, adrSupplier p);
void deleteFirstSupplier(listSupplier &LS, adrSupplier &p);
void deleteLastSupplier(listSupplier &LS, adrSupplier &p);
void deleteAfterSupplier(listSupplier &LS, adrSupplier &p, adrSupplier prec);
void deleteSupplier(listSupplier &L, string nama);
adrSupplier findSupplier(listSupplier LS, string nama);
void showSupplier(listSupplier LS);

#endif // SUPPLIER_H_INCLUDED
