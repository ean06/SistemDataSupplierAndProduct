#include <iostream>
#include "supplier.h"
#include "produk.h"
#include "relasi.h"

using namespace std;

void tungguEnter(){
    cout << "\nTekan Enter untuk melanjutkan";
    cin.ignore();
    cin.get();
}

void clearScreen(){
    system("cls");
}

// =================== FUNGSI IMPLEMENTASI ===================

// ===== KELOLA SUPPLIER =====  
void tambahSupplier(listSupplier &LS){
    string nama;
    adrSupplier s;
    cout << "\n--- Tambah Supplier ---\n";
    cout << "Nama Supplier: ";
    cin >> nama;
    s = findSupplier(LS, nama);
    if(s != nullptr){
        cout << "Supplier dengan nama tersebut sudah ada";
    }else{
        s = newElmSupplier(nama);
        addSupplier(LS, s);
        cout << "Supplier berhasil ditambahkan\n";
    }
}

void hapusSupplier(listSupplier &LS, listRelasi &LR, listProduk &LP){
    cout << endl;
    showSupplier(LS);
    string namaSupplier;
    int konfirmasi;

    cout << "\n--- Hapus Supplier ---\n";
    cout << "Nama Supplier yang akan dihapus: ";
    cin >> namaSupplier;
    cout << endl;

    if (findSupplier(LS, namaSupplier) != nullptr){
        if (checkRelasiSupplier(LR, namaSupplier)){
            cout << "Supplier Tersebut Memiliki Produk\n";
            cout << "Apakah anda ingin menghapus semua relasi dengan Produknya?\n";
            cout << "1. YA\n";
            cout << "0. TIDAK\n";
            cin >> konfirmasi;
            switch (konfirmasi) {
                case 1:
                    deleteAllProdukFromSupplier(LR, LS, namaSupplier);
                    deleteSupplier(LS, namaSupplier);
                    cout << "Supplier beserta relasi Berhasil di delete\n";
                    tungguEnter();
                    break;
                case 0:
                    cout << "Penghapusan Supplier dibatalkan\n";
                    tungguEnter();
                    break;
                default:
                    cout << "Pilihan tidak valid Silakan masukkan angka 0-1" << endl;
                    tungguEnter();
                    break;
                }
        }else {
            deleteSupplier(LS, namaSupplier);
            cout << "Supplier Berhasil di delete\n";
            tungguEnter();
        }
    }else {
        cout << "Supplier tidak ditemukan\n";
        tungguEnter();
    }
}

void tampilkanSemuaSupplier(listSupplier LS){
    cout << "\n--- Daftar Semua Supplier ---\n";
    if (isEmptySupplier(LS)){
        cout << "Tidak ada supplier terdaftar\n";
    }else{
        showSupplier(LS);
    }
}

void cariSupplierMenu(listSupplier LS){
    string nama;
    adrSupplier s;
    cout << "\n--- Cari Supplier ---\n";
    cout << "Nama Supplier: ";
    cin >> nama;
    cout << endl;

    s = findSupplier(LS, nama);
    if (s != nullptr){
        cout << "\nSupplier ditemukan:\n";
        cout << s->namaSupplier << endl;
    }
    else{
        cout << "Supplier tidak ditemukan\n";
    }
}

// ===== KELOLA PRODUK =====

void tambahProduk(listProduk &LP){
    adrProduk p;
    string nama, kategori;
    int harga, minOrder;

    cout << "\n--- Tambah Produk ---\n";
    cout << "Nama Produk: ";
    cin >> nama;
    p = findProduk(LP, nama);
    if(p != nullptr){
        cout << "Produk dengan nama tersebut sudah ada";
    }else{
        cout << "Kategori: ";
        cin >> kategori;
        cout << "Harga: ";
        cin >> harga;
        cout << "Minimal Order: ";
        cin >> minOrder;
    
        p = newElmProduk(nama, kategori, harga, minOrder);
        addProduk(LP, p);
        cout << "Produk berhasil ditambahkan!\n";
    }
}

void hapusProduk(listSupplier &LS, listRelasi &LR, listProduk &LP){
    cout << endl;
    showProduk(LP);
    string namaProduk;
    int konfirmasi;

    cout << "\n--- Hapus Produk ---\n";
    cout << "Nama Produk yang akan dihapus: ";
    cin >> namaProduk;
    cout << endl;
    adrProduk p = findProduk(LP, namaProduk);

    if (p != nullptr){
        if (checkRelasiProduk(LR, namaProduk)){
            cout << "Produk Tersebut Memiliki Supplier\n";
            cout << "Apakah anda ingin menghapus semua relasi dengan Suppliernya?\n";
            cout << "1. YA\n";
            cout << "0. TIDAK\n";
            cin >> konfirmasi;
            switch (konfirmasi) {
                case 1:
                    deleteAllSupplierFromProduk(LR, LP, namaProduk);
                    deleteProduk(LP, p);
                    cout << "Produk beserta relasi Berhasil di delete\n";
                    tungguEnter();
                    break;
                case 0:
                    cout << "Penghapusan Produk dibatalkan\n";
                    tungguEnter();
                    break;
                default:
                    cout << "Pilihan tidak valid Silakan masukkan angka 0-1" << endl;
                    tungguEnter();
                    break;
                }
        }else {
            deleteProduk(LP, p);
            cout << "Produk Berhasil di delete\n";
            tungguEnter();
        }
    }else {
        cout << "Produk tidak ditemukan\n";
        tungguEnter();
    }
}

void tampilkanSemuaProduk(listProduk LP){
    cout << "\n--- Daftar Semua Produk ---\n";
    if (isEmptyProduk(LP)){
        cout << "Tidak ada produk terdaftar\n";
    }else{
        showProduk(LP);
    }
}

void cariProdukMenu(listProduk LP){
    string nama;
    adrProduk p;
    cout << "\n--- Cari Produk ---\n";
    cout << "Nama Produk: ";
    cin >> nama;
    cout << endl;

    p = findProduk(LP, nama);
    if (p != nullptr){
        cout << "\nProduk ditemukan:\n";
        cout << " - Nama Produk   : " << p->namaProduk << endl;
        cout << " - Kategori      : " << p->kategori << endl;
        cout << " - Harga         : " << p->harga << endl;
        cout << " - Minimal Order : " << p->minOrder << endl;
        cout << "  --------------------------" << endl;
    }
    else{
        cout << "Produk tidak ditemukan\n";
    }
}


// ===== KELOLA LAPORAN =====
void tampilkanSemuaSupplierProduk(listSupplier LS, listRelasi LR){
    adrSupplier s = LS.first;
    if (s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    }else{ 
        cout << "\n--- Seluruh Supplier dan Produk ---\n";
        showSupplierWithProduk(LS, LR);
    }
}

void tampilkanProdukBySupplier(listSupplier LS, listRelasi LR){
    string namaSupplier;
    adrSupplier s;

    cout << "Masukan Nama Supplier yang Ingin diTampilkan: ";
    cin >> namaSupplier;
    cout << endl;

    s = findSupplier(LS, namaSupplier);
    
    if (s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    }else{ 
        cout << "\n--- Produk By Supplier ---\n";
        showProdukBySupplier(LS, LR, namaSupplier);
    }
}

void tambahRelasiProduk(listSupplier LS, listProduk LP, listRelasi &LR){
    string namaSupplier, namaProduk;
    adrSupplier s;
    adrProduk p;
    adrRelasi r;
    cout << "\n--- Menghubungkan Produk ke Supplier ---\n";
    cout << "Nama Supplier: ";
    cin >> namaSupplier;
    cout << "Nama Produk: ";
    cin >> namaProduk;

    s = findSupplier(LS, namaSupplier);
    p = findProduk(LP, namaProduk);
    r = findRelasi(LR, namaSupplier, namaProduk);
    
    if (s == nullptr || p == nullptr){
        cout << "Supplier atau Produk tersebut tidak ada";
    }else {
        if(r != nullptr){
            cout << "Produk Telah dihubungkan Ke Supplier tersebut";
        }else{
            r = newElmRelasi(s, p);
            addRelasi(LR, r);
            cout << "Relasi berhasil ditambahkan\n";
        }
    }
}

void hapusRelasiProduk(listSupplier LS, listProduk LP, listRelasi &LR){
    string namaSupplier, namaProduk;
    adrSupplier s;
    adrProduk p;
    adrRelasi r;
    cout << "\n--- Hapus hubungan Produk ke Supplier ---\n";
    cout << "Nama Supplier: ";
    cin >> namaSupplier;
    cout << "Nama Produk: ";
    cin >> namaProduk;

    s = findSupplier(LS, namaSupplier);
    p = findProduk(LP, namaProduk);
    r = findRelasi(LR, namaSupplier, namaProduk);
    
    if (s == nullptr || p == nullptr){
        cout << "Supplier atau Produk tersebut tidak ada";
    }else {
        if(r != nullptr){
            deleteRelasi(LR, r);
            cout << "Relasi Berhasil di delete";
        }else{
            cout << "Supplier dan Produk Tersebut Tidak memiliki Hubungan\n";
        }
    }
}

void hitungJumlahProdukPerSupplier(listSupplier LS, listRelasi LR){
    cout << "\n--- Jumlah Produk per Supplier ---\n";
    countProductsPerSupplier(LS, LR);
}

void tampilkanSupplierProdukTerbanyak(listSupplier LS, listRelasi LR){
    adrSupplier s = LS.first;
    if (s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    }else{
        cout << "\n--- Supplier dengan Produk Terbanyak ---\n";
        showMostSupplierProduk(LS, LR);
    }
}
void tampilkanSupplierProdukTerdikit(listSupplier LS, listRelasi LR){
    adrSupplier s = LS.first;
    if (s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    }else{
        cout << "\n--- Supplier dengan Produk Terdikit ---\n";
        showFewstSupplierProduk(LS, LR);
    }
}

// =================== PROGRAM UTAMA ===================

int main(){
    listSupplier LS;
    listProduk LP;
    listRelasi LR;

    createListSupplier(LS);
    createListProduk(LP);
    createListRelasi(LR);

    int pilihanUtama, pilihanSub;
    bool programBerjalan = true;

    while (programBerjalan){
        clearScreen();
        cout << "========================================\n";
        cout << "     SISTEM MANAJEMEN SUPPLIER\n";
        cout << "========================================\n";

        // MENU UTAMA
        cout << "\n=== MENU UTAMA ===" << endl;
        cout << "1. Kelola Supplier" << endl;
        cout << "2. Kelola Produk" << endl;
        cout << "3. Laporan" << endl;
        cout << "0. Keluar Program" << endl;
        cout << "==================" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihanUtama;

        switch (pilihanUtama) {
        // CASE 1: MENU SUPPLIER
        case 1:
        {
            bool kembaliKeMenuUtama = false;

            while (!kembaliKeMenuUtama) {
                clearScreen();
                cout << "\n=== MENU KELOLA SUPPLIER ===" << endl;
                cout << "1. Tambah Supplier Baru" << endl;
                cout << "2. Hapus Supplier" << endl;
                cout << "3. Lihat Semua Supplier" << endl;
                cout << "4. Cari Supplier" << endl;
                cout << "0. Kembali ke Menu Utama" << endl;
                cout << "============================" << endl;
                cout << "Masukkan pilihan Anda: ";
                cin >> pilihanSub;

                switch (pilihanSub) {
                    case 1:
                        tambahSupplier(LS);
                        tungguEnter();
                        break;
                    case 2:
                        hapusSupplier(LS, LR, LP);
                        break;
                    case 3:
                        tampilkanSemuaSupplier(LS);
                        tungguEnter();
                        break;
                    case 4:
                        cariSupplierMenu(LS);
                        tungguEnter();
                        break;
                    case 0:
                        kembaliKeMenuUtama = true;
                        break;
                    default:
                        cout << "Pilihan tidak valid! Silakan masukkan angka 0-4." << endl;
                        tungguEnter();
                }
            }
            break;
        }

        // CASE 2: MENU PRODUK
        case 2:
        {
            bool kembaliKeMenuUtama = false;

            while (!kembaliKeMenuUtama) {
                clearScreen();
                cout << "\n=== MENU KELOLA PRODUK ===" << endl;
                cout << "1. Tambah Produk Baru" << endl;
                cout << "2. Hapus Produk" << endl;
                cout << "3. Lihat Semua Produk" << endl;
                cout << "4. Cari Produk" << endl;
                cout << "0. Kembali ke Menu Utama" << endl;
                cout << "=========================" << endl;
                cout << "Masukkan pilihan Anda: ";
                cin >> pilihanSub;

                switch (pilihanSub) {
                    case 1:
                        tambahProduk(LP);
                        tungguEnter();
                        break;
                    case 2:
                        hapusProduk(LS, LR, LP);
                        tungguEnter();
                        break;
                    case 3:
                        showProduk(LP);
                        tungguEnter();
                        break;
                    case 4:
                        cariProdukMenu(LP);
                        tungguEnter();
                        break;
                    case 0:
                        kembaliKeMenuUtama = true;
                        break;
                    default:
                        cout << "Pilihan tidak valid! Silakan masukkan angka 0-4." << endl;
                        tungguEnter();
                }
            }
            break;
        }

        // CASE 3: MENU LAPORAN
        case 3:
        {
            bool kembaliKeMenuUtama = false;

            while (!kembaliKeMenuUtama){
                clearScreen();
                cout << "\n=== MENU LAPORAN ===" << endl;
                cout << "1. Lihat Semua Supplier dan Produknya" << endl;
                cout << "2. Cari Produk Berdasarkan Suppliernya" << endl;
                cout << "3. Tambah Hubungkan Produk Ke Supplier" << endl;
                cout << "4. Hapus Hubungkan Produk Ke Supplier" << endl;
                cout << "5. Hitung Jumlah Produk per Supplier" << endl;
                cout << "6. Lihat Supplier dengan Produk Terbanyak" << endl;
                cout << "7. Lihat Supplier dengan Produk Terdikit" << endl;
                cout << "0. Kembali ke Menu Utama" << endl;
                cout << "====================" << endl;
                cout << "Masukkan pilihan Anda: ";
                cin >> pilihanSub;

                switch (pilihanSub) {
                    case 1:
                        tampilkanSemuaSupplierProduk(LS, LR);
                        tungguEnter();
                        break;
                    case 2:
                        tampilkanProdukBySupplier(LS, LR);
                        tungguEnter();
                        break;
                    case 3:
                        tambahRelasiProduk(LS, LP, LR);
                        tungguEnter();
                        break;
                    case 4:
                        hapusRelasiProduk(LS, LP, LR);
                        tungguEnter();
                        break;
                    case 5:
                        hitungJumlahProdukPerSupplier(LS, LR);
                        tungguEnter();
                        break;
                    case 6:
                        tampilkanSupplierProdukTerbanyak(LS, LR);
                        tungguEnter();
                        break;
                    case 7:
                        tampilkanSupplierProdukTerdikit(LS, LR);
                        tungguEnter();
                        break;
                    case 0:
                        kembaliKeMenuUtama = true;
                        break;
                    default:
                        cout << "Pilihan tidak valid! Silakan masukkan angka 0-3." << endl;
                        tungguEnter();
                }
            }
            break;
        }

        case 0:
            programBerjalan = false;
            cout << "\nTerima kasih telah menggunakan sistem manajemen supplier dan produk" << endl;
            tungguEnter();
            break;

        default:
            cout << "Pilihan tidak valid Silakan masukkan angka 0-3" << endl;
            tungguEnter();
        }
    }
    return 0;
}


