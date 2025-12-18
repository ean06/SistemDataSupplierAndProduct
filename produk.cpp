#include "produk.h"

void createListProduk(listProduk &LP){
    LP.first = nullptr;
    LP.last = nullptr;
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

bool isEmptyProduk(listProduk LP){
    return (LP.first == nullptr && LP.last == nullptr);
}

void addProduk(listProduk &LP, adrProduk p){
    if (LP.first == nullptr && LP.last == nullptr){
        LP.first = p;
        LP.last = p;
    }else{
        LP.last->next = p;
        p->prev = LP.last;
        LP.last = p;
    }
}

void deleteFirstProduk(listProduk &LP, adrProduk &p){
    p = LP.first;
    if (isEmptyProduk(LP)){
        p = nullptr;
    }else if (p->next == nullptr){
        LP.first = nullptr;
        LP.last = nullptr;
    }else{
        LP.first = p->next;
        p->next = nullptr;
        LP.first->prev = nullptr;
}
}

void deleteLastProduk(listProduk &LP, adrProduk &p){
    p = LP.last;
    if (isEmptyProduk(LP)){
        p = nullptr;
    }else if (p->prev == nullptr){
        LP.first = nullptr;
        LP.last = nullptr;
    }else{
        LP.last = p->prev;
        p->prev = nullptr;
        LP.last->next = nullptr;
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

void deleteProduk(listProduk &LP, adrProduk p){
    if (p != nullptr){
        if (p == LP.first){
            deleteFirstProduk(LP, p);
        }else if (p == LP.last){
            deleteLastProduk(LP, p);
        }else{  
            deleteAfterProduk(LP, p, p->prev);
        }
    }
}

adrProduk findProduk(listProduk LP, string nama){
    adrProduk p = LP.first;
    while (p != nullptr) {
        if (p->namaProduk == nama) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void showProduk(listProduk LP){
    adrProduk p = LP.first;
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
