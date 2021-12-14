#include "DanhSachPhieuMuonTra.h"
#include "List.h"
#include "ListMember.h"
#include <iostream>

using namespace std;
class QuanLy : public DanhSachPhieuMuonTra, public List, public ListMember
{

    bool Kiem_Tra_Sach_Muon_Qua_Han(DanhSachPhieuMuonTra, int, int);
    bool HaveMaSach(PhieuMuonTra *, int);
    int Tong_Ngay_Qua_Han(DanhSachPhieuMuonTra, int);
};