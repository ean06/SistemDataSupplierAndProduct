#include "relasi.h"
#include "supplier.h"
#include "produk.h"

void createListRelasi(listRelasi &L){
// 
    L.first = nullptr;
}

adrRelasi newElmRelasi(adrSupplier LS, adrProduk LP){
    adrRelasi p = new Relasi;
    p->up = LS;
    p->down = LP;
    p->next = nullptr;
    return p;
}

void addRelasi(listRelasi &LR, adrRelasi r){
    if (LR.first == nullptr)    {
        LR.first = r;
    }else {
        r->next = LR.first;
        LR.first = r;
    }
}

bool checkRelasiSupplier(listRelasi LR, string namaSupplier){
    adrRelasi R = LR.first;
    while (R != nullptr) {
        if (R->up != nullptr && R->up->namaSupplier == namaSupplier) {
            return true;
        }
        R = R->next;
    }
    return false;
}

bool checkRelasiProduk(listRelasi LR, string namaProduk){
    adrRelasi R = LR.first;
    while (R != nullptr) {
        if (R->up != nullptr && R->down->namaProduk == namaProduk) {
            return true;
        }
        R = R->next;
    }
    return false;
}

void deleteFirstRelasi(listRelasi &LR, adrRelasi &p){
    p = LR.first;
    if (LR.first == nullptr) {
        p = nullptr;
    }else if (p->next == nullptr) {
        LR.first = nullptr;
    }else {
        LR.first = p->next;
        p->next = nullptr;
    }
}

void deleteLastRelasi(listRelasi &LR, adrRelasi &p){
    adrRelasi prec;
    if (LR.first == nullptr) {
        p = nullptr;
    }else if (LR.first->next == nullptr) {
        p = LR.first;
        LR.first = nullptr;
    }else {
        prec = LR.first;
        while (prec->next->next != nullptr) {
            prec = prec->next;
        }
        p = prec->next;
        prec->next = nullptr;
    }
}

void deleteAfterRelasi(listRelasi &LR, adrRelasi &p, adrRelasi prec){
    if (LR.first == nullptr) {
        p = nullptr;
    }else if (prec == nullptr || prec->next == nullptr) {
        p = nullptr;
    }else {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void deleteRelasi(listRelasi &LR, adrRelasi &p){
    adrRelasi prec;
    if (p != nullptr) {
        if (p == LR.first) {
            deleteFirstRelasi(LR, p);
        }else if (p->next == nullptr) {
            deleteLastRelasi(LR, p);
        }else {
            prec = LR.first;
            while (prec != nullptr && prec->next != p) {
                prec = prec->next;
            } 
            if(prec != nullptr) {
                deleteAfterRelasi(LR, p, prec);
            }
        }
    }
}

void deleteProdukFromSupplier(listRelasi &LR, string namaSupplier, string namaProduk){
    adrRelasi r = findRelasi(LR, namaSupplier, namaProduk);

    if (r != nullptr) {
        deleteRelasi(LR, r);
    }
}

void deleteAllProdukFromSupplier(listRelasi &LR, listSupplier &LS, string namaSupplier){
    adrRelasi r = LR.first;
    adrSupplier s = findSupplier(LS, namaSupplier);

    while (r != nullptr) {
        adrRelasi next = r->next;
        if (r->up == s){
            deleteRelasi(LR, r);
        }
        r = next;
    }
}

void deleteAllSupplierFromProduk(listRelasi &LR, listProduk &LP, string namaProduk){
    adrRelasi r = LR.first;
    adrProduk p = findProduk(LP, namaProduk);

    while (r != nullptr) {
        adrRelasi next = r->next;
        if (r->down == p){
            deleteRelasi(LR, r);
        }
        r = next;
    }
}

adrRelasi findRelasi(listRelasi LR, string namaSupplier, string namaProduk){
    adrRelasi r = LR.first;
    while (r != nullptr) {
        if (r->up != nullptr && r->down != nullptr && r->up->namaSupplier == namaSupplier && r->down->namaProduk == namaProduk)        {
            return r;
        }
        r = r->next;
    }
    return nullptr;
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
                cout << " - Harga         : " << produk->harga << endl;
                cout << " - Minimal Order : " << produk->minOrder << endl;
                cout << "  --------------------------" << endl;
                adaProduk = true;
            }
            r = r->next;
        }
        if (!adaProduk){
            cout << "Supplier ini Belum memiliki Produk\n";
        }
        s = s->next;
    }
}

void showProdukBySupplier(listSupplier LS, listRelasi LR, string namaSupplier){
    adrSupplier s = findSupplier(LS, namaSupplier);

    cout << "Supplier: " << s->namaSupplier << endl;

    adrRelasi r = LR.first;
    bool adaProduk = false;

    while (r != nullptr) {
        if (r->up == s){
            adaProduk = true;
            adrProduk produk = r->down;
            cout << " - Nama Produk   : " << produk->namaProduk << endl;
            cout << " - Kategori      : " << produk->kategori << endl;
            cout << " - Harga         : " << produk->harga << endl;
            cout << " - Minimal Order : " << produk->minOrder << endl;
            cout << "  --------------------------" << endl;
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
            adrRelasi r = LR.first;
            bool adaProduk = false;
            int totalProduk = 0;

            while (r != nullptr) {
                if (r->up == s) {
                    totalProduk++;
                    adaProduk = true;
                }
                r = r->next;
            }
            cout << "\nSupplier: " << s->namaSupplier << endl;
            if (!adaProduk) {
                cout << "Belum ada produk\n";
            }else{
                cout << "Jumlah Produk  : " << totalProduk << endl;
            }
            s = s->next;
        }
    }
}

void showMostSupplierProduk(listSupplier LS, listRelasi LR) {
    adrSupplier s = LS.first;
    int maxProduk = 0;

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
        }
        s = s->next;
    }

    if (maxProduk == 0) {
        cout << "\nBelum ada produk di semua supplier\n";
        return;
    }
    cout << "\nSupplier dengan produk terbanyak:\n";

    s = LS.first;
    while (s != nullptr) {
        int totalProduk = 0;
        adrRelasi r = LR.first;

        while (r != nullptr) {
            if (r->up == s) {
                totalProduk++;
            }
            r = r->next;
        }

        if (totalProduk == maxProduk) {
            cout << "Nama Supplier  : " << s->namaSupplier << endl;
            cout << "Jumlah Produk  : " << totalProduk << endl;
            cout << "-----------------------------\n";
        }
        s = s->next;
    }
}


void showFewstSupplierProduk(listSupplier LS, listRelasi LR) {
    adrSupplier s = LS.first;
    int minProduk;
    bool adaSupplier = false;

    if (s != nullptr) {
        minProduk = INT_MAX;
    }

    while (s != nullptr) {
        int totalProduk = 0;
        adrRelasi r = LR.first;

        while (r != nullptr) {
            if (r->up == s) {
                totalProduk++;
            }
            r = r->next;
        }

        if (totalProduk < minProduk) {
            minProduk = totalProduk;
            adaSupplier = true;
        }
        s = s->next;
    }

    if (!adaSupplier) {
        cout << "\nBelum ada supplier\n";
        return;
    }
    cout << "\nSupplier dengan produk tersedikit:\n";

    s = LS.first;
    while (s != nullptr) {
        int totalProduk = 0;
        adrRelasi r = LR.first;

        while (r != nullptr) {
            if (r->up == s) {
                totalProduk++;
            }
            r = r->next;
        }

        if (totalProduk == minProduk) {
            cout << "Nama Supplier  : " << s->namaSupplier << endl;
            cout << "Jumlah Produk  : " << totalProduk << endl;
            cout << "-----------------------------\n";
        }
        s = s->next;
    }
}

