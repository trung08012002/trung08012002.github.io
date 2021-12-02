#include "PhieuMuonTra.h"
bool PhieuMuonTra::operator==(const PhieuMuonTra &t)
{
    if (this->ma_Phieu == t.ma_Phieu &&
        this->tensach == t.tensach &&
        this->ma_Member == t.ma_Member &&
        this->Ngay_Muon == t.Ngay_Muon &&
        this->Ngay_Tra == t.Ngay_Tra &&
        this->Trang_Thai == t.Trang_Thai)
        return true;
    else
        return false;
}
bool PhieuMuonTra::operator!=(const PhieuMuonTra &t)
{
    if (this->ma_Phieu != t.ma_Phieu &&
        this->tensach != t.tensach &&
        this->ma_Member != t.ma_Member &&
        this->Ngay_Muon != t.Ngay_Muon &&
        this->Ngay_Tra != t.Ngay_Tra &&
        this->Trang_Thai != t.Trang_Thai)
        return true;
    else
        return false;
}
PhieuMuonTra PhieuMuonTra::operator=(const PhieuMuonTra &t)
{
    this->ma_Phieu = t.ma_Phieu;
    this->tensach = t.tensach;
    this->ma_Member = t.ma_Member;
    this->Ngay_Muon = t.Ngay_Muon;
    this->Ngay_Tra = t.Ngay_Tra;
    this->Trang_Thai = t.Trang_Thai;
    return *this;
}
PhieuMuonTra::PhieuMuonTra()
{
}
PhieuMuonTra::PhieuMuonTra(PhieuMuonTra &t)
{

    this->tensach = t.tensach;
    this->ma_Member = t.ma_Member;
    this->Ngay_Muon = t.Ngay_Muon;
    this->Ngay_Tra = t.Ngay_Tra;
    this->Trang_Thai = t.Trang_Thai;
    this->next = nullptr;
}

PhieuMuonTra::~PhieuMuonTra()
{
}

PhieuMuonTra::PhieuMuonTra(string ma_Phieu,
                           string tensach,
                           string ma_Member,
                           Date Ngay_Muon,
                           Date Ngay_Tra,
                           string Trang_Thai)
    : ma_Phieu(ma_Phieu),
      tensach(tensach),
      ma_Member(ma_Member),
      Ngay_Muon(Ngay_Muon),
      Ngay_Tra(Ngay_Tra),
      Trang_Thai(Trang_Thai)
{
    this->next = nullptr;
}
void PhieuMuonTra::Nhap_Thong_Tin_Phieu_Muon_Tra(PhieuMuonTra &x)
{
    // phiếu mượn trả chỉ cần nhập mã sách . ngày mượn sẽ được cập nhật từ hệ thống thời gian thực, trạng thái sẽ mặc định = 0 nghĩa là sách đó đang mượn
    x.Ngay_Tra.Thoi_Gian_Thuc();
    cin >> x.Ngay_Muon;
    x.Trang_Thai = '0';
}
void PhieuMuonTra::Xuat_Thong_Tin_Phieu_Muon_Tra(PhieuMuonTra x)
{
    cout << "\nMa phieu:" << x.ma_Phieu << endl;
    cout << "\nTen sach: " << x.tensach << endl;
    cout << "\nTen tac gia: " << x.ma_Member << endl;
    cout << "\nNgay muon sach: " << x.Ngay_Muon << endl;
    cout << "\nNgay tra sach: " << x.Ngay_Tra << endl;
    cout << "\nTrang thai sach: " << x.Trang_Thai << endl;
}
void PhieuMuonTra::Show()
{
    cout << "\nMa phieu:" << this->ma_Phieu << endl;
    cout << "\nTen sach: " << this->tensach << endl;
    cout << "\nTen tac gia: " << this->ma_Member << endl;
    cout << "\nNgay muon sach: " << this->Ngay_Muon << endl;
    cout << "\nNgay tra sach: " << this->Ngay_Tra << endl;
    cout << "\nTrang thai sach: " << this->Trang_Thai << endl;
}
int PhieuMuonTra::hash()
{

    unsigned long hash = 5381;
    for (auto c : this->ma_Phieu)
    {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash % 10000;
}