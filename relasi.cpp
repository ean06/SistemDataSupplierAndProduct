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

void addRelasi(listRelasi &LR, adrRelasi r){
    if (LR.first == nullptr){
        LR.first = r;
    }else {
        r->next = LR.first;
        LR.first = r;
    }
}

void deleteFirstRelasi(listRelasi &LR, adrRelasi &p){
    p = LR.first;
    if (LR.first == nullptr){
        p = nullptr;
    }else if (p->next == nullptr){
        LR.first = nullptr;
    }else{
        LR.first = p->next;
        p->next = nullptr;
    }
}

void deleteLastRelasi(listRelasi &LR, adrRelasi &p){
    adrRelasi prec;
    if (LR.first == nullptr){
        p = nullptr;
    }else if (LR.first->next == nullptr){
        p = LR.first;
        LR.first = nullptr;
    }else{
        prec = LR.first;
        while (prec->next->next != nullptr){
            prec = prec->next;
        }
        p = prec->next;
        prec->next = nullptr;
    }
}

void deleteAfterRelasi(listRelasi &LR, adrRelasi &p, adrRelasi prec){
    if (LR.first == nullptr){
        p = nullptr;
    }else if (prec == nullptr || prec->next == nullptr){
        p = nullptr;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void deleteRelasi(listRelasi &LR, adrRelasi &p){
    adrRelasi prec;
    if (p != nullptr){
         if (p == LR.first){
            deleteFirstRelasi(LR, p);
        }else if (p->next == nullptr){
            deleteLastRelasi(LR, p);
        }else{  
            prec = LR.first;
            while (prec != nullptr && prec->next != p){
                prec = prec->next;
            }
            if (prec != nullptr){
            deleteAfterRelasi(LR, p, prec);
            }
        }
    }
}

adrRelasi findRelasi(listRelasi LR, string namaSupplier, string namaProduk){
    adrRelasi r = LR.first;
    while (r != nullptr){
        if (r->up != nullptr && r->down != nullptr && r->up->namaSupplier == namaSupplier && r->down->namaProduk == namaProduk){
            return r;
        }
        r = r->next;
    }
    return nullptr;
}

void deleteProdukFromSupplier(listRelasi &LR){
    string namaSupplier, namaProduk;

    cout << "Masukkan nama supplier: ";
    cin >> namaSupplier;
    cout << "Masukkan nama produk: ";
    cin >> namaProduk;

    adrRelasi r = findRelasi(LR, namaSupplier, namaProduk);

    if (r != nullptr){
        deleteRelasi(LR, r);
        cout << "Produk berhasil dihapus dari supplier." << endl;
    }else{
        cout << "Relasi tidak ditemukan." << endl;
    }
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








