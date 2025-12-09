#include "supplier.h"
#include "produk.h"

void createListSupplier(ListSupplier &L) {
    L.first = nullptr;
}

adrSupplier newElmSupplier(string nama) {
    adrSupplier p = new Supplier;

    p->info.namaSupplier = nama;
    p->next = nullptr;
    return p;
}

void tambahSupplier(listSupplier &L, adrSupplier p){
    if (L.first == nullptr) {
        L.first = p;
    }else{
        p->next = L.first;
        L.first = p;
    }
}

void hapusSupplier(listSupplier &L, string nama, adrSupplier p){
    adrSupplier q = new Supplier;

    q = findSupplier(L, nama);
    if (q == nullptr){
        cout << "data tidak ditemukan";
    }else if (q->next->next == nullptr){
        p = q->next;
        q->next = nullptr;
    }else{
        p = q->next;
        q->next = p->next;
        p->next = nullptr;
    }
}

adrSupplier findSupplier(listSupplier L, string nama){
    adrSupplier p = L.first;
    while (p != nullptr) {
        if (p->info.namaSupplier == nama) {
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
            cout << p->info.namaSupplier << endl;
            p = p->next;
        }
    }
}

void showSupplierProduk(listSupplier LS, listProduk LP){
    adrSupplier s = L.first;
    adrProduk p = L.first;
    if ( s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    } else {
        while (s != nullptr) {
            cout << p->info.namaSupplier << endl;
            while (p != nullptr){
                cout << "Nama: " << p->namaProduk << endl;
                cout << "Katergori: " << p->info.kategori << endl;
                cout << "Harga: " << p->info.harga << endl;
                cout << "Minimal Order: " << p->info.minOrder << endl;
                p = p->next;
            }
            s = s->next;
        }
    }
}

