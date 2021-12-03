#include "DanhSachPhieuMuonTra.h"
#include "List.h"
#include "ListMember.h"
#include <iostream>

using namespace std;
class QuanLy : public DanhSachPhieuMuonTra, public List, public ListMember
{
    int So_Ngay_Qua_Han(Date, Date);
    bool Kiem_Tra_Sach_Muon_Qua_Han(DanhSachPhieuMuonTra, string, string);
    bool HaveMaSach(PhieuMuonTra *, string);
    int Tong_Ngay_Qua_Han(DanhSachPhieuMuonTra, string);
};