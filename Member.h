#ifndef _Member_
#define _Member_
#include <string>
#include "Book.h"
#include <iostream>
#include "Date.h"
using namespace std;

class Member
{

protected:
    int ma_Member;
    string Ho;
    string Ten;
    Date ngaysinh;
    string Phai;
    bool Trang_Thai;
    Member *next;

public:
    Member();
    Member(int ma_Member,
           string Ho = "Nguyen",
           string Ten = "A",
           Date ngaysinh = Date(1, 1, 2021),
           string Phai = "nam",
           bool Trang_Thai = true);
    Member(Member &);
    ~Member();
    void Show();
    int hash();

    friend ostream &operator<<(ostream &, Date &);
    friend istream &operator>>(istream &, Date &);

    friend class ListMember;
    Member operator=(const Member &);
    bool operator==(const Member &);
    bool operator!=(const Member &);
};

#endif _Member_