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

void addProduk(listProduk &L, adrProduk p){
    if (L.first == nullptr && L.last == nullptr){
        L.first = p;
        L.last = p;
    }else{
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}
void deleteProduk(listProduk &L, adrProduk p){
    
}

adrProduk findProduk(listProduk L, string nama){
    adrProduk p = L.first;
    while (p != nullptr) {
        if (p->namaProduk == nama) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
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
