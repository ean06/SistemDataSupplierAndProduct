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
void tambahSupplier(listSupplier &LS)
{
    string nama;
    cout << "\n--- Tambah Supplier ---\n";
    cout << "Nama Supplier: ";
    cin >> nama;

    adrSupplier p = newElmSupplier(nama);
    addSupplier(LS, p);
    cout << "Supplier berhasil ditambahkan\n";
}

void hapusSupplier(listSupplier &LS, listRelasi &LR, listProduk &LP)
{
    showSupplier(LS);
    string nama;
    int konfirmasi;

    cout << "\n--- Hapus Supplier ---\n";
    cout << "Nama Supplier yang akan dihapus: ";
    cin >> nama;
    cout << endl;

    if (findSupplier(LS, nama) != nullptr){
        if (checkRelasiSupplier(LR, nama)){
            cout << "Supplier Tersebut Memiliki Produk\n";
            cout << "Apakah anda ingin menghapus beserta produknya?\n";
            cout << "1. YA\n";
            cout << "0. TIDAK\n";
            cin >> konfirmasi;
            switch (konfirmasi)
            {
                case 1:
                    deleteSupplierWithProduk(LS, LP, nama);
                    cout << "Supplier Berhasil di delete\n";
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
            }
        else{
            deleteSupplier(LS, nama);
            cout << "Supplier Berhasil di delete\n";
            tungguEnter();
        }
    }else{
        cout << "Supplier tidak ditemukan\n";
        tungguEnter();
    }
}

void tampilkanSemuaSupplier(listSupplier LS)
{
    cout << "\n--- Daftar Semua Supplier ---\n";
    if (isEmptySupplier(LS)){
        cout << "Tidak ada supplier terdaftar\n";
    }else{
        showSupplier(LS);
    }
}

void cariSupplierMenu(listSupplier LS)
{
    string nama;
    cout << "\n--- Cari Supplier ---\n";
    cout << "Nama Supplier: ";
    cin >> nama;
    cout << endl;

    adrSupplier p = findSupplier(LS, nama);
    if (p != nullptr){
        cout << "\nSupplier ditemukan:\n";
        cout << p->namaSupplier << endl;
    }
    else{
        cout << "Supplier tidak ditemukan\n";
    }
}

// ===== KELOLA PRODUK =====

void tambahProduk(listProduk &LP)
{
    string nama, kategori;
    int harga, minOrder;

    cout << "\n--- Tambah Produk ---\n";
    cout << "Nama Produk: ";
    cin >> nama;
    cout << "Kategori: ";
    cin >> kategori;
    cout << "Harga: ";
    cin >> harga;
    cout << "Minimal Order: ";
    cin >> minOrder;

    adrProduk p = newElmProduk(nama, kategori, harga, minOrder);
    addProduk(LP, p);
    cout << "Produk berhasil ditambahkan!\n";
}

// void hapusProduk(listProduk &LP, listRelasi &LR)
// {
//     string kode;
//     cout << "\n--- Hapus Produk ---\n";
//     cout << "Kode Produk yang akan dihapus: ";
//     cin >> kode;

//     if (deleteProduk(LP, LR, kode))
//     {
//         cout << "Produk berhasil dihapus dari semua supplier!\n";
//     }
//     else
//     {
//         cout << "Produk tidak ditemukan!\n";
//     }
// }

void tampilkanSemuaProduk(listProduk LP)
{
    cout << "\n--- Daftar Semua Produk ---\n";
    if (isEmptyProduk(LP)){
        cout << "Tidak ada produk terdaftar\n";
    }else{
        showProduk(LP);
    }
}

void cariProdukMenu(listProduk LP)
{
    string nama;
    cout << "\n--- Cari Produk ---\n";
    cout << "Nama Produk: ";
    cin >> nama;
    cout << endl;

    adrProduk p = findProduk(LP, nama);
    if (p != nullptr){
        cout << "\nProduk ditemukan:\n";
        cout << p->namaProduk << endl;
    }
    else{
        cout << "Produk tidak ditemukan\n";
    }
}

// ===== KELOLA LAPORAN =====
void tampilkanSemuaSupplierProduk(listSupplier LS, listRelasi LR)
{
    adrSupplier s = LS.first;
    if (s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    }else{ 
        cout << "\n--- Seluruh Supplier dan Produk ---\n";
        showSupplierWithProduk(LS, LR);
    }
}

void tampilkanProdukBySupplier(listSupplier LS, listRelasi LR)
{
    string namaSupplier;
    adrSupplier s = findSupplier(LS, namaSupplier);

    cout << "Masukan Nama Supplier yang Ingin diTampilkan: ";
    cin >> namaSupplier;
    cout << endl;

    if (s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    }else{ 
        cout << "\n--- Produk By Supplier ---\n";
        showProdukBySupplier(LS, LR, namaSupplier);
    }
}

void hitungJumlahProdukPerSupplier(listSupplier LS, listRelasi LR)
{
    cout << "\n--- Jumlah Produk per Supplier ---\n";
    countProductsPerSupplier(LS, LR);
}

void tampilkanSupplierProdukTerbanyak(listSupplier LS, listRelasi LR)
{
    adrSupplier s = LS.first;
    if (s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    }else{
        cout << "\n--- Supplier dengan Produk Terbanyak ---\n";
        showMostSupplierProduk(LS, LR);
    }
}
void tampilkanSupplierProdukTerdikit(listSupplier LS, listRelasi LR)
{
    adrSupplier s = LS.first;
    if (s == nullptr) {
        cout << "Supplier tidak ada" << endl;
    }else{
        cout << "\n--- Supplier dengan Produk Terdikit ---\n";
        showFewstSupplierProduk(LS, LR);
    }
}

// =================== PROGRAM UTAMA ===================

int main()
{
    listSupplier LS;
    listProduk LP;
    listRelasi LR;

    createListSupplier(LS);
    createListProduk(LP);
    createListRelasi(LR);

    int pilihanUtama, pilihanSub;
    bool programBerjalan = true;

    while (programBerjalan)
    {
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

        switch (pilihanUtama)
        {
        // CASE 1: MENU SUPPLIER
        case 1:
        {
            bool kembaliKeMenuUtama = false;

            while (!kembaliKeMenuUtama)
            {
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

                switch (pilihanSub)
                {
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

            while (!kembaliKeMenuUtama)
            {
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

                switch (pilihanSub)
                {
                case 1:
                    tambahProduk(LP);
                    tungguEnter();
                    break;
                case 2:
                    // hapusProduk(LP, LR);
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

            while (!kembaliKeMenuUtama)
            {
                clearScreen();
                cout << "\n=== MENU LAPORAN ===" << endl;
                cout << "1. Lihat Semua Supplier dan Produknya" << endl;
                cout << "2. Lihat Produk Berdasarkan Suppliernya" << endl;
                cout << "3. Hitung Jumlah Produk per Supplier" << endl;
                cout << "4. Lihat Supplier dengan Produk Terbanyak" << endl;
                cout << "5. Lihat Supplier dengan Produk Terdikit" << endl;
                cout << "0. Kembali ke Menu Utama" << endl;
                cout << "====================" << endl;
                cout << "Masukkan pilihan Anda: ";
                cin >> pilihanSub;

                switch (pilihanSub)
                {
                case 1:
                    tampilkanSemuaSupplierProduk(LS, LR);
                    tungguEnter();
                    break;
                case 2:
                    tampilkanProdukBySupplier(LS, LR);
                    tungguEnter();
                    break;
                case 3:
                    hitungJumlahProdukPerSupplier(LS, LR);
                    tungguEnter();
                    break;
                case 4:
                    tampilkanSupplierProdukTerbanyak(LS, LR);
                    tungguEnter();
                    break;
                case 5:
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


