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
void tambahProduk(listProduk &L, adrProduk p);
void hapusProduk(listProduk &L, adrProduk p);
void showProduk(listProduk L);

#endif // PRODUK_H_INCLUDED
