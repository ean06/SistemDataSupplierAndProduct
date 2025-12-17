#include "relasi.h"
#include "supplier.h"
#include "produk.h"

void createListRelasi(listRelasi &L){
    L.first = nullptr;
}

adrRelasi newElmRelasi(adrSupplier LS, adrProduk LP){
    adrRelasi p = new Relasi;
    p->up = LS;
    p->down = LP;
    p->next = nullptr;
    return p;
}

bool checkRelasiSupplier(listRelasi LR, string namaSupplier){
    adrRelasi R = LR.first;
    while(R != nullptr){
        if (R->up != nullptr && R->up->namaSupplier == namaSupplier){
            return true;
        }
        R = R->next;
    }
    return false;
}

void addRelasi(listRelasi LR, listSupplier LS, listProduk LP, adrRelasi r){

}

void deleteRelasi(listRelasi LR, listSupplier LS, listProduk LP){

}

void showSupplierWithProduk(listSupplier LS, listRelasi LR){
    adrSupplier s = LS.first;
    while (s != nullptr) {
        cout << "\nSupplier: " << s->namaSupplier << endl;
        cout << "Produk-produk:\n";
            
        adrRelasi r = LR.first;
        bool adaProduk = false;
            
        while (r != nullptr) {
            if (r->up == s) {
                adrProduk produk = r->down;
                cout << " - Nama Produk   : " << produk->namaProduk << endl;
                cout << " - Kategori      : " << produk->kategori << endl;
                cout << " - Harga         : Rp " << produk->harga << endl;
                cout << " - Minimal Order : " << produk->minOrder << endl;
                adaProduk = true;
            }
            r = r->next;
        }
        if (!adaProduk) {
            cout << "Supplier ini Belum memiliki Produk\n";
        }
        s = s->next;
    }
}

void showProdukBySupplier(listSupplier LS, listRelasi LR, string namaSupplier){
    adrSupplier supplierDicari = findSupplier(LS, namaSupplier);
    
    cout << "Supplier: " << supplierDicari->namaSupplier << endl;
    
    adrRelasi r = LR.first;
    bool adaProduk = false;
    
    while (r != nullptr) {
        if (r->up == supplierDicari) {
            adaProduk = true;
            adrProduk produk = r->down;
            cout << " - Nama Produk   : " << produk->namaProduk << endl;
            cout << " - Kategori      : " << produk->kategori << endl;
            cout << " - Harga         : Rp " << produk->harga << endl;
            cout << " - Minimal Order : " << produk->minOrder << endl;
        }
        r = r->next;
    }
    if (!adaProduk) {
        cout << "Supplier ini Belum memiliki Produk\n";
    }
}

void countProductsPerSupplier(listSupplier LS, listRelasi LR){
    adrSupplier s = LS.first;
    
    if (s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    }else{    
        while (s != nullptr) {
            cout << "\nSupplier: " << s->namaSupplier << endl;            
            adrRelasi r = LR.first;
            bool adaProduk = false;
            int totalProduk;
            
            while (r != nullptr) {
                if (r->up == s) {
                    totalProduk++;
                    adaProduk = true;
                }
                r = r->next;
            }
            if (!adaProduk) {
                cout << "Belum ada produk\n";
            }
            s = s->next;
        }
    }
}

void showMostSupplierProduk(listSupplier LS, listRelasi LR) {
    adrSupplier s = LS.first;
    
    string namaSupplierTerbanyak;
    int maxProduk = 0;
    bool adaProduk = false;
    
    while (s != nullptr) {
        int totalProduk = 0;
        adrRelasi r = LR.first;
        
        while (r != nullptr) {
            if (r->up == s) {
                totalProduk++;
            }
            r = r->next;
        }
        if (totalProduk > maxProduk) {
            maxProduk = totalProduk;
            namaSupplierTerbanyak = s->namaSupplier;
            adaProduk = true;
        }
        s = s->next;
    }
    
    if (!adaProduk) {
        cout << "\nBelum ada produk di semua supplier\n";
    } else {
        cout << "\nSupplier dengan produk terbanyak:\n";
        cout << "Nama Supplier  : " << namaSupplierTerbanyak << endl;
        cout << "Jumlah Produk  : " << maxProduk << endl;
    }
}


void showFewstSupplierProduk(listSupplier LS, listRelasi LR){
    adrSupplier s = LS.first;
    string namaSupplierTerbanyak;
    int maxProduk = 0;
    bool adaProduk = false;
    
    while (s != nullptr) {
        int totalProduk = 0;
        adrRelasi r = LR.first;
        
        while (r != nullptr) {
            if (r->up == s) {
                totalProduk++;
            }
            r = r->next;
        }
        if (totalProduk > maxProduk) {
            maxProduk = totalProduk;
            namaSupplierTerbanyak = s->namaSupplier;
            adaProduk = true;
        }
        s = s->next;
    }
    
    if (!adaProduk) {
        cout << "\nBelum ada produk di semua supplier\n";
    } else {
        cout << "\nSupplier dengan produk terbanyak:\n";
        cout << "Nama Supplier  : " << namaSupplierTerbanyak << endl;
        cout << "Jumlah Produk  : " << maxProduk << endl;
    }
}



