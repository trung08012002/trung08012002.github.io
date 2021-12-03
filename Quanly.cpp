#include "QuanLy.h"
// hàm trả về số ngày quá hạn. Tính số ngày chênh lệch giữa 2 mốc thời gian
int QuanLy::So_Ngay_Qua_Han(Date x, Date y)
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

bool QuanLy::Kiem_Tra_Sach_Muon_Qua_Han(DanhSachPhieuMuonTra l, string madocgia, string masach)
{
    for (int i = 0; i < l.n; i++)
    {

        if (!l.hash_table_P[i])
            continue;
        else
        {
            PhieuMuonTra *current_pointer = l.hash_table_P[i];

            do
            {
                if (current_pointer->ma_Member == madocgia && HaveMaSach(current_pointer, masach))
                {
                    if (So_Ngay_Qua_Han(current_pointer->Ngay_Muon, current_pointer->Ngay_Tra) > 15)
                    {
                        return true;
                    }
                    return false;
                };
                current_pointer = current_pointer->next;
            } while (current_pointer);
        }
    }
}
bool QuanLy::HaveMaSach(PhieuMuonTra *l, string masach)
{
    for (int i = 0; i < 4; i++)
    {
        if (l->masach[i] == masach)
            return true;
    }
    return false;
}
// hàm tính tổng ngày quá hạn trả sách của  danh sách mượn sách của độc giả
int QuanLy::Tong_Ngay_Qua_Han(DanhSachPhieuMuonTra l, string madocgia)
{
    int Tong = 0;
    // duyệt vòng lặp những quyển sách của 1 độc giả đang mượn
    for (int i = 0; i < l.n; i++)
    {

        if (!l.hash_table_P[i])
            continue;
        else
        {
            PhieuMuonTra *current_pointer = l.hash_table_P[i];

            do
            {
                if (current_pointer->Trang_Thai == "1" && current_pointer->ma_Member == madocgia)
                { //Tổng số ngày trừ đi ngày mượn nếu như kết quả lớn hơn 15 ngày(số ngày tối đa cho mượn sách) thì số ngày quá hạn sẽ là : kết quả - 15
                    int x = So_Ngay_Qua_Han(current_pointer->Ngay_Muon, current_pointer->Ngay_Tra);
                    if (x > 15)
                    {
                        Tong += (x - 15); // tổng số ngày mượn quá hạn
                    }
                }
                current_pointer = current_pointer->next;
            } while (current_pointer);
        }
    }
    return Tong;
}