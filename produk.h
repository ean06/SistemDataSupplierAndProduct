#ifndef PRODUK_H_INCLUDED
#define PRODUK_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct Produk *adrProduk;

struct Produk {
    string namaProduk;
    string kategori;
    int harga;
    int minOrder;

    adrProduk next;
    adrProduk prev;
};

struct listProduk {
    adrProduk first;
    adrProduk last;
};

void createListProduk(listProduk &L);
adrProduk newElmProduk(string nama, string kategori, int harga, int minOrder);
bool isEmptyProduk(listProduk L);
void addProduk(listProduk &L, adrProduk p);
void deleteFirstProduk(listProduk &L, adrProduk &p);
void deleteLastProduk(listProduk &L, adrProduk &p);
void deleteAfterProduk(listProduk &L, adrProduk &p, adrProduk prec);
void deleteProduk(listProduk &L, adrProduk p);
adrProduk findProduk(listProduk L, string nama);
void showProduk(listProduk L);

#endif // PRODUK_H_INCLUDED
