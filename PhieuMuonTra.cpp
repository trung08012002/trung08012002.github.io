#include "PhieuMuonTra.h"
bool PhieuMuonTra::operator==(const PhieuMuonTra &t)
{
    if (this->ma_Phieu == t.ma_Phieu)
        return true;
    else
        return false;
}
bool PhieuMuonTra::operator!=(const PhieuMuonTra &t)
{
    if (this->ma_Phieu != t.ma_Phieu)
        return true;
    else
        return false;
}
PhieuMuonTra PhieuMuonTra::operator=(const PhieuMuonTra &t)
{
    this->ma_Phieu = t.ma_Phieu;
    return *this;
}
PhieuMuonTra::PhieuMuonTra()
{
    this->ma_Phieu = "0";
    for (int i = 0; i < 4; i++)
        this->masach[i] = "0";
}
PhieuMuonTra::PhieuMuonTra(PhieuMuonTra &t)
{
    this->ma_Phieu = t.ma_Phieu;
    for (int i = 0; i < 4; i++)
    {
        if (this->masach[i] != "0")
            this->masach[i] = t.masach[i];
        else
            break;
    }
    this->ma_Member = t.ma_Member;
    this->Ngay_Muon = t.Ngay_Muon;
    this->Ngay_Tra = t.Ngay_Tra;
    this->Trang_Thai = t.Trang_Thai;
    this->TTien = t.TTien;
    this->next = nullptr;
}

PhieuMuonTra::~PhieuMuonTra()
{
}

PhieuMuonTra::PhieuMuonTra(string ma_Phieu,
                           string masach,
                           string ma_Member,
                           int TTien,
                           Date Ngay_Muon,
                           Date Ngay_Tra,
                           string Trang_Thai)
    : ma_Phieu(ma_Phieu),

      ma_Member(ma_Member),
      TTien(TTien),
      Ngay_Muon(Ngay_Muon),
      Ngay_Tra(Ngay_Tra),
      Trang_Thai(Trang_Thai)
{
    for (int i = 0; i < 4; i++)
        this->masach[i] = "0";
    this->next = nullptr;
}
void PhieuMuonTra::Nhap_Thong_Tin_Phieu_Muon_Tra(List l)
{
    // phiếu mượn trả chỉ cần nhập mã sách . ngày mượn sẽ được cập nhật từ hệ thống thời gian thực, trạng thái sẽ mặc định = 0 nghĩa là sách đó đang mượn

    cin >> this->ma_Phieu;
    int choice = 1;
    int i = 0;
    do
    {
        cin >> this->masach[i];
        i++;
        cout << "0.ket thuc";
        cout << "1.Ma sach tiep theo";
        cin >> choice;
    } while (choice && i < 4);

    this->Ngay_Tra.Thoi_Gian_Thuc();
    cout << "nhap ngay muon" << endl;
    cin >> this->Ngay_Muon;
    Book *tempBook;
    for (int i = 0; i < 4; i++)
    {
        if (this->masach[i] != "0")
        {
            tempBook = (l.Search(this->masach[i]));
            tempBook->doyeuthich++;
            this->TTien += tempBook->Giasach;
        }
    }
    cout << "PhieuMuon:nhap 1";
    cout << "PhieuTra:nhap 0";
    cin >> this->Trang_Thai;
}
void PhieuMuonTra::Xuat_Thong_Tin_Phieu_Muon_Tra(PhieuMuonTra x)
{
    cout << "\nMa phieu:" << x.ma_Phieu << endl;
    cout << "\nTen sach: " << x.masach << endl;
    cout << "\nTen tac gia: " << x.ma_Member << endl;
    cout << "\nMa sach: " << endl;
    for (int i = 0; i < 4; i++)
    {
        if (x.masach[i] != "0")
            cout << x.masach[i] << endl;
    }
    cout << "\nNgay muon sach: " << x.Ngay_Muon << endl;
    cout << "\nNgay tra sach: " << x.Ngay_Tra << endl;
    cout << "\nTrang thai sach: " << x.Trang_Thai << endl;
    cout << "\nTong tien:" << x.TTien << endl;
}
void PhieuMuonTra::Show()
{
    cout << "\nMa phieu:" << this->ma_Phieu << endl;
    cout << "\nTen sach: " << this->masach << endl;
    cout << "\nTen tac gia: " << this->ma_Member << endl;
    cout << "\nMa sach: " << endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->masach[i] != "0")
            cout << this->masach[i] << endl;
    }
    cout << "\nNgay muon sach: " << this->Ngay_Muon << endl;
    cout << "\nNgay tra sach: " << this->Ngay_Tra << endl;
    cout << "\nTrang thai sach: " << this->Trang_Thai << endl;
    cout << "\n Tong tien:" << this->TTien << endl;
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
