#ifndef _PhieuMuonTra_
#define _PhieuMuonTra_

#include "Date.h"
#include "List.h"
#include <string>
#include <iostream>
using namespace std;

class PhieuMuonTra
{
protected:
    string ma_Phieu;
    string masach[4];
    string ma_Member;
    Date Ngay_Muon;
    Date Ngay_Tra;
    string Trang_Thai;
    int TTien;
    PhieuMuonTra *next;

public:
    PhieuMuonTra();
    PhieuMuonTra(
        string = "0",
        string = "0",
        string = "0",
        int TTien = 0,
        Date = Date(1, 1, 1900),
        Date = Date(1, 1, 1900),
        string = "0");
    PhieuMuonTra(PhieuMuonTra &);
    ~PhieuMuonTra();
    int hash();
    void Nhap_Thong_Tin_Phieu_Muon_Tra(List);
    friend ostream &operator<<(ostream &, Date &);
    friend istream &operator>>(istream &, Date &);
    friend class DanhSachPhieuMuonTra;
    friend class QuanLy;
    void Show();
    void Xuat_Thong_Tin_Phieu_Muon_Tra(PhieuMuonTra);

    PhieuMuonTra operator=(const PhieuMuonTra &);
    bool operator==(const PhieuMuonTra &);
    bool operator!=(const PhieuMuonTra &);
};
#endif _PhieuMuonTra_