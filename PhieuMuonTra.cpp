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
    this->ma_Phieu = 0;
    for (int i = 0; i < 4; i++)
        this->masach[i] = 0;
}
PhieuMuonTra::PhieuMuonTra(PhieuMuonTra &t)
{
    this->ma_Phieu = t.ma_Phieu;
    for (int i = 0; i < 4; i++)
    {
        if (this->masach[i] != 0)
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

PhieuMuonTra::PhieuMuonTra(int ma_Phieu,
                           int masach,
                           int ma_Member,
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
        this->masach[i] = 0;
    this->next = nullptr;
}
void PhieuMuonTra::Nhap_Thong_Tin_Phieu_Muon_Tra(List &l)
{
    // phiếu mượn trả chỉ cần nhập mã sách . ngày mượn sẽ được cập nhật từ hệ thống thời gian thực, trạng thái sẽ mặc định = 0 nghĩa là sách đó đang mượn
    cout << "\nNhap ma Phieu Muon Tra";
    cin >> this->ma_Phieu;
    cout << "\nNhap ma doc gia";
    cin >> this->ma_Member;
    int choice = 1;
    int i = 0;
    do
    {
        cout << "Nhap ma sach" << endl;
        cin >> this->masach[i];

        i++;
        cout << "0.ket thuc" << endl;
        cout << "1.Ma sach tiep theo" << endl;
        cout << "Nhap su lua chon cua ban" << endl;
        cin >> choice;

    } while (choice && i < 4);

    this->Ngay_Tra.Thoi_Gian_Thuc();

    Book *tempBook;
    for (int i = 0; i < 4; i++)
    {

        if (this->masach[i] != 0)
        {
            if (l.Search(this->masach[i]))
            {
                if (l.Search(this->masach[i])->tinhtrang == true)
                {
                    tempBook = (l.Search(this->masach[i]));
                    tempBook->doyeuthich++;
                    tempBook->tinhtrang = false;
                    this->TTien += tempBook->Giasach;
                }
                else
                    cout << "Sach da co doc gia muon" << endl;
            }
            else
                cout << "Sach khong co trong list" << endl;
        }
    }
    this->TTien += this->Tienphat();

    cout << "PhieuMuon:nhap 1" << endl;
    cout << "PhieuTra:nhap 0" << endl;
    cin >> this->Trang_Thai;
    this->next = nullptr;
    cout << "Nhap ngay muon" << endl;
    cin >> this->Ngay_Muon;
}

void PhieuMuonTra::Xuat_Thong_Tin_Phieu_Muon_Tra(PhieuMuonTra x)
{
    cout << "\nMa phieu:" << x.ma_Phieu << endl;
    cout << "\nTen sach: " << x.masach << endl;
    cout << "\nTen tac gia: " << x.ma_Member << endl;
    cout << "\nMa sach: " << endl;
    for (int i = 0; i < 4; i++)
    {
        if (x.masach[i] != 0)
            cout << x.masach[i] << endl;
    }
    cout << "\nNgay muon sach: " << x.Ngay_Muon << endl;
    cout << "\nNgay tra sach: " << x.Ngay_Tra << endl;
    cout << "\nPhieu Muon Tra: " << x.Trang_Thai << endl;
    cout << "\nTong tien:" << x.TTien << endl;
}
void PhieuMuonTra::Show()
{
    cout << "\nMa phieu:" << this->ma_Phieu << endl;
    cout << "\nMa doc gia: " << this->ma_Member << endl;
    cout << "\nMa sach: " << endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->masach[i] != 0)
        {
            cout << this->masach[i] << endl;
        }
    }
    cout << "\nNgay muon sach: " << this->Ngay_Muon << endl;
    cout << "\nNgay tra sach: " << this->Ngay_Tra << endl;
    cout << "\nPhieu Muon Tra: " << this->Trang_Thai << endl;
    cout << "\n Tong tien:" << this->TTien << endl;
}

int PhieuMuonTra::hash()
{
    unsigned long hash = 5381;
    for (auto c : to_string(this->ma_Phieu))
    {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash % 10000;
}
// hàm trả về số ngày quá hạn. Tính số ngày chênh lệch giữa 2 mốc thời gian
int PhieuMuonTra::So_Ngay_Qua_Han(Date x, Date y)
{
    int Tong_Ngay = 0;

    // tính số ngày theo độ chênh lệch giữa 2 năm
    while (x.nam < y.nam)
    {
        if (y.namnhuan(y.nam) == true) // là năm nhuận
        {
            Tong_Ngay += 366;
        }
        else
        {
            Tong_Ngay += 365;
        }
        y.nam--;
    }

    // tính số ngày theo độ chênh lệch giữa 2 tháng
    while (x.thang < y.thang)
    {
        if (x.thang == 4 || x.thang == 6 || x.thang == 9 || x.thang == 11)
        {
            Tong_Ngay += 30;
        }
        else if (x.thang == 2)
        {
            if (x.namnhuan(x.nam) == true)
            {
                Tong_Ngay += 29;
            }
            else
            {
                Tong_Ngay += 28;
            }
        }
        else
        {
            Tong_Ngay += 31;
        }
        x.thang++;
    }
    return (Tong_Ngay - x.ngay) + y.ngay;
}
void PhieuMuonTra::GiaHan(int songaythem)
{
    this->Ngay_Tra += songaythem;
    this->TTien += this->So_Ngay_Qua_Han(this->Ngay_Muon, this->Ngay_Tra);
}

int PhieuMuonTra::Tienphat()
{
    if (this->So_Ngay_Qua_Han(this->Ngay_Muon, this->Ngay_Tra) > 15)
        return (this->TTien * 50 / 100);
    else
        return 0;
}