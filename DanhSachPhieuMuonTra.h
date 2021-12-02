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
    void Update(string);
    void deletePhieuMuonTra(string);
    PhieuMuonTra *Search(string);
    void addPhieuMuonTra(PhieuMuonTra);
    void addFromFile();
    void GiaHan(string, int);
    bool any(string);
    void updateFile();
};
#endif _DanhSachPhieuMuonTra_