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

bool isEmptySupplier( listSupplier L){
    return (L.first == nullptr);
}

void addSupplier(listSupplier &L, adrSupplier p){
    if (L.first == nullptr) {
        L.first = p;
    }else{
        p->next = L.first;
        L.first = p;
    }
}

void deleteFirstSupplier(listSupplier &L, adrSupplier &p){
    if (L.first == nullptr){
        p = nullptr;
    }else{
        p = L.first;
        L.first = L.first->next;
        p->next = nullptr;
    }
}

void deleteLastSupplier(listSupplier &L, adrSupplier &p){
    adrSupplier prec;
    if (L.first == nullptr){
        p = nullptr;
    }else if (L.first->next == nullptr){
        p = L.first;
        L.first = nullptr;
    }else{
        prec = L.first;
        while (prec->next->next != nullptr){
            prec = prec->next;
        }
        p = prec->next;
        prec->next = nullptr;
    }
}

void deleteAfterSupplier(listSupplier &L, adrSupplier &p, adrSupplier prec){
    if (prec != nullptr && prec->next != nullptr){
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}
void deleteSupplier(listSupplier &L, string nama){
    adrSupplier prec;
    adrSupplier p = findSupplier(L, nama);
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

void deleteSupplierWithProduk(listSupplier &LS, listProduk &LP, string nama){
    adrSupplier p = findSupplier(LS, nama);
    
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

// void showSupplierProduk(listSupplier LS, listProduk LP){
//     adrSupplier s = LS.first;
//     adrProduk p = LP.first;
//     if ( s == nullptr) {
//         cout << "Supplier tidak ada" << endl;
//     } else {
//         while (s != nullptr) {
//             cout << s->namaSupplier << endl;
//             while (p != nullptr){
//                 cout << "Nama: " << p->namaProduk << endl;
//                 cout << "Katergori: " << p->kategori << endl;
//                 cout << "Harga: " << p->harga << endl;
//                 cout << "Minimal Order: " << p->minOrder << endl;
//                 p = p->next;
//             }
//             s = s->next;
//         }
//     }
// }

