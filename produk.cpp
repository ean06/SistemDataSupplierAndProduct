#include "produk.h"

void createListProduk(listProduk &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrProduk newElmProduk(string nama, string kategori, int harga, int minOrder){
    adrProduk p = new Produk;
    p->namaProduk = nama;
    p->kategori = kategori;
    p->harga = harga;
    p->minOrder = minOrder;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void tambahProduk(listProduk &L, adrProduk p){

}
void hapusProduk(listProduk &L, adrProduk p){

}
void showProduk(listProduk L){
    adrProduk p = L.first;
    if (p == nullptr) {
        cout << "Data produk tidak ada" << endl;
    } else {
        while (p != nullptr) {
            cout << "Nama: " << p->namaProduk << endl;
            cout << "Katergori: " << p->kategori << endl;
            cout << "Harga: " << p->harga << endl;
            cout << "Minimal Order: " << p->minOrder << endl;
            p = p->next;
        }
    }
}
