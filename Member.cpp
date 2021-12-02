#include "Member.h"
#include <typeinfo>

bool Member::operator==(const Member &t)
{
    if (this->ma_Member == t.ma_Member &&
        this->Ho == t.Ho &&
        this->Ten == t.Ten &&

        this->ngaysinh == t.ngaysinh &&
        this->Phai == t.Phai &&
        this->Trang_Thai == t.Trang_Thai)
        return true;
    else
        return false;
}

bool Member::operator!=(const Member &t)
{
    if (this->ma_Member == t.ma_Member &&
        this->Ho != t.Ho &&
        this->Ten != t.Ten &&

        this->ngaysinh != t.ngaysinh &&
        this->Phai != t.Phai &&
        this->Trang_Thai != t.Trang_Thai)
        return true;
    else
        return false;
}
Member Member::operator=(const Member &t)
{
    this->ma_Member = t.ma_Member;
    this->Ho = t.Ho;
    this->Ten = t.Ten;

    this->ngaysinh = t.ngaysinh;
    this->Phai = t.Phai;
    this->Trang_Thai = t.Trang_Thai;
    return *this;
}
Member::Member()
{
}

void Member::Show()
{
    cout << "ma nguoi doc" << this->ma_Member << endl;
    cout << "ho:" << this->Ho << endl;
    cout << "ten:" << this->Ten << endl;
    cout << "ngaysinh:" << this->ngaysinh << endl;
    cout << "Phai:" << this->Phai << endl;
    cout << "Trang_Thai:" << this->Trang_Thai << endl;
}

Member::Member(int ma_Member,
               string Ho,
               string Ten,
               Date ngaysinh,
               string Phai,
               bool Trang_Thai)
    : ma_Member(ma_Member),
      Ho(Ho),
      Ten(Ten),
      ngaysinh(ngaysinh),
      Phai(Phai),
      Trang_Thai(Trang_Thai)
{
    this->next = nullptr;
}
Member::Member(Member &t)
{

    this->ma_Member = t.ma_Member;
    this->Ho = t.Ho;
    this->Ten = t.Ten;

    this->ngaysinh = t.ngaysinh;
    this->Phai = t.Phai;
    this->Trang_Thai = t.Trang_Thai;
    this->next = nullptr;
}

Member::~Member()
{
}

int Member::hash()
{

    unsigned long hash = 5381;
    for (auto c : to_string(this->ma_Member))
    {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash % 10000;
}