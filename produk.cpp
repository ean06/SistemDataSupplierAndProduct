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

bool isEmptyProduk( listProduk L){
    return (L.first == nullptr && L.last == nullptr);
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

void deleteFirstProduk(listProduk &L, adrProduk &p){
    p = L.first;
    if (L.first != nullptr){
        if (L.first == L.last){
            L.first = nullptr;
            L.last = nullptr;
        }else{
            L.first = L.first->next;
            L.first->prev = nullptr;
            p->next = nullptr;
        }
    }
}

void deleteLastProduk(listProduk &L, adrProduk &p){
    p = L.last;
    if (L.last != nullptr){
        if (L.first == L.last){
            L.first = nullptr;
            L.last = nullptr;
        }else{
            L.last = L.last->prev;
            L.last->next = nullptr;
            p->prev = nullptr;
        }
    }
}

void deleteAfterProduk(listProduk &L, adrProduk &p, adrProduk prec){
    p = prec->next;
    if (p != nullptr){
        if (p == L.last){
            L.last = prec;
            prec->next = nullptr;
            p->prev = nullptr;
        }else{
            prec->next = p->next;
            p->next->prev = prec;
            p->next = nullptr;
            p->prev = nullptr;
        }
    }
}

void deleteProduk(listProduk &L, adrProduk p){
    adrProduk prec;
    if (p != nullptr){
        if (p == L.first){
            deleteFirstProduk(L, p);
        }else if (p == L.last){
            deleteLastProduk(L, p);
        }else{  
            prec = L.first;
            while (prec->next != p){
                prec = prec->next;
            }
            deleteAfterProduk(L, p, prec);
        }
    }
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
            cout << endl;
            cout << "Nama           : " << p->namaProduk << endl;
            cout << "Katergori      : " << p->kategori << endl;
            cout << "Harga          : " << p->harga << endl;
            cout << "Minimal Order  : " << p->minOrder << endl;
            cout << "----------------------------" << endl;
            p = p->next;
        }
    }
}
