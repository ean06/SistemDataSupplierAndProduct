#include "supplier.h"
#include "produk.h"
#include "relasi.h"

void createListSupplier(listSupplier &LS) {
    LS.first = nullptr;
}

adrSupplier newElmSupplier(string nama) {
    adrSupplier p = new Supplier;

    p->namaSupplier = nama;
    p->next = nullptr;
    return p;
}

bool isEmptySupplier(listSupplier LS){
    return (LS.first == nullptr);
}

void addSupplier(listSupplier &LS, adrSupplier p){
    if (isEmptySupplier(LS)){
        LS.first = p;
    }else{
        p->next = LS.first;
        LS.first = p;
    }
}

void deleteFirstSupplier(listSupplier &LS, adrSupplier &p){
    p = LS.first;
    if (isEmptySupplier(LS)){
        p = nullptr;
    }else if (p->next == nullptr){
        LS.first = nullptr;    
    }else{
        LS.first = p->next;
        p->next = nullptr;
    }
}

void deleteLastSupplier(listSupplier &LS, adrSupplier &p){
    adrSupplier prec;
    if (isEmptySupplier(LS)){
        p = nullptr;
    }else if (LS.first->next == nullptr){
        p = LS.first;
        LS.first = nullptr;
    }else{
        prec = LS.first;
        while (prec->next->next != nullptr){
            prec = prec->next;
        }
        p = prec->next;
        prec->next = nullptr;
    }
}

void deleteAfterSupplier(listSupplier &L, adrSupplier &p, adrSupplier prec){
    if (isEmptySupplier(L)){
        p = nullptr;
    }else if (prec->next == nullptr){
        p = nullptr;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}
void deleteSupplier(listSupplier &L, string nama){
    adrSupplier prec, p;
    p = findSupplier(L, nama);
    if (p != nullptr){
        if (p == L.first){
            deleteFirstSupplier(L, p);
        }else if (p->next == nullptr){
            deleteLastSupplier(L, p);
        }else{
            prec = L.first;
            while (prec->next != p){
                prec = prec->next;
            }
            deleteAfterSupplier(L, p, prec);
        }
    }
}

void deleteSupplierWithProduk(listSupplier &LS, listRelasi &LR, string nama){
    adrSupplier p = findSupplier(LS, nama);

    if (p == nullptr){
        cout << "Supplier tidak ditemukan." << endl;
    }else{
    adrRelasi r = LR.first;
        while(r != nullptr){
            adrRelasi nextR = r->next; 
            if (r->up == p){
            deleteRelasi(LR, r);
            }
            r = nextR;
        }
    deleteSupplier(LS, nama);
    }
}

adrSupplier findSupplier(listSupplier LS, string nama){
    adrSupplier p = LS.first;
    while (p != nullptr) {
        if (p->namaSupplier == nama) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void showSupplier(listSupplier LS){
    adrSupplier p = LS.first;
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

