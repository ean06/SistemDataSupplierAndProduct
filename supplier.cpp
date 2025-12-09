#include "supplier.h"
#include "produk.h"

void createListSupplier(listSupplier &L) {
    L.first = nullptr;
}

adrSupplier newElmSupplier(string nama) {
    adrSupplier p = new Supplier;

    p->namaSupplier = nama;
    p->next = nullptr;
    return p;
}

void addSupplier(listSupplier &L, adrSupplier p){
    if (L.first == nullptr) {
        L.first = p;
    }else{
        p->next = L.first;
        L.first = p;
    }
}

void deleteSupplier(listSupplier &L, string nama, adrSupplier p){
    adrSupplier s = new Supplier;

    s = findSupplier(L, nama);
    if (s == nullptr){
        cout << "data tidak ditemukan";
    }else if (s->next->next == nullptr){
        p = s->next;
        s->next = nullptr;
    }else{
        p = s->next;
        s->next = p->next;
        p->next = nullptr;
    }
}

adrSupplier findSupplier(listSupplier L, string nama){
    adrSupplier p = L.first;
    while (p != nullptr) {
        if (p->namaSupplier == nama) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void showSupplier(listSupplier L){
    adrSupplier p = L.first;
    if (p == nullptr) {
        cout << "Supplier tidak ada" << endl;
    } else {
        while (p != nullptr) {
            cout << p->namaSupplier << endl;
            p = p->next;
        }
    }
}

void showSupplierProduk(listSupplier LS, listProduk LP){
    adrSupplier s = LS.first;
    adrProduk p = LP.first;
    if ( s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    } else {
        while (s != nullptr) {
            cout << s->namaSupplier << endl;
            while (p != nullptr){
                cout << "Nama: " << p->namaProduk << endl;
                cout << "Katergori: " << p->kategori << endl;
                cout << "Harga: " << p->harga << endl;
                cout << "Minimal Order: " << p->minOrder << endl;
                p = p->next;
            }
            s = s->next;
        }
    }
}

