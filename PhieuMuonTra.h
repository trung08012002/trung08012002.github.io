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
    int ma_Phieu;
    int masach[4];
    int ma_Member;
    Date Ngay_Muon;
    Date Ngay_Tra;
    string Trang_Thai;
    int TTien;
    PhieuMuonTra *next;

public:
    PhieuMuonTra();
    PhieuMuonTra(
        int = 0,
        int = 0,
        int = 0,
        int = 0,
        Date = Date(1, 1, 1900),
        Date = Date(1, 1, 1900),
        string = "0");
    PhieuMuonTra(PhieuMuonTra &);
    ~PhieuMuonTra();
    int hash();
    void Nhap_Thong_Tin_Phieu_Muon_Tra(List &);
    friend ostream &operator<<(ostream &, Date &);
    friend istream &operator>>(istream &, Date &);
    friend class DanhSachPhieuMuonTra;
    friend class QuanLy;
    void Show();
    void Xuat_Thong_Tin_Phieu_Muon_Tra(PhieuMuonTra);
    void GiaHan(int);

    int Tienphat();
    int So_Ngay_Qua_Han(Date, Date);
    PhieuMuonTra operator=(const PhieuMuonTra &);
    bool operator==(const PhieuMuonTra &);
    bool operator!=(const PhieuMuonTra &);
};
#endif _PhieuMuonTra_