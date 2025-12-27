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

void createListProduk(listProduk &LP);
adrProduk newElmProduk(string nama, string kategori, int harga, int minOrder);
bool isEmptyProduk(listProduk LP);
void addProduk(listProduk &LP, adrProduk p);
void deleteFirstProduk(listProduk &LP, adrProduk &p);
void deleteLastProduk(listProduk &LP, adrProduk &p);
void deleteAfterProduk(listProduk &LP, adrProduk &p, adrProduk prec);
void deleteProduk(listProduk &LP, adrProduk p);
adrProduk findProduk(listProduk LP, string nama);
void showProduk(listProduk LP);

#endif // PRODUK_H_INCLUDED
