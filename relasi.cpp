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



