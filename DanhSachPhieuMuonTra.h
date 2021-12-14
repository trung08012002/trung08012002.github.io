#ifndef _DanhSachPhieuMuonTra_
#define _DanhSachPhieuMuonTra_
#include "PhieuMuonTra.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;
class PhieuMuonTra;
class DanhSachPhieuMuonTra
{
public:
    PhieuMuonTra **hash_table_P;
    int n;

public:
    DanhSachPhieuMuonTra();
    DanhSachPhieuMuonTra(int);
    ~DanhSachPhieuMuonTra();
    void Show();
    PhieuMuonTra *addToHashTable(PhieuMuonTra, PhieuMuonTra *) const;
    void Update(int);
    void deletePhieuMuonTra(int);
    void deleteAllPhieuMuonTra();
    PhieuMuonTra *Search(int);
    void addPhieuMuonTra(PhieuMuonTra);
    void addFromFile();
    void Kiem_Tra_Phieu_Muon_Tra_Qua_Han();
    bool any(int);
    void updateFile();
};
#endif _DanhSachPhieuMuonTra_