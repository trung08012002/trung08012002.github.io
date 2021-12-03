#ifndef _date_
#define _date_
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
class Date
{
public:
    int ngay;
    int thang;
    int nam;
    void tangngay();
    static int songay[];

public:
    Date(int = 0, int = 0, int = 0);
    ~Date();
    void setDate(int, int, int);
    Date operator++();
    Date operator++(int);
    Date operator+=(int);
    bool namnhuan(int);
    bool cuoithang(int);
    bool operator==(Date);
    bool operator!=(Date);
    Date Thoi_Gian_Thuc();
    friend class List;
    friend class Book;
    friend class PhieuMuonTra;
    friend class Function;
};

ostream &operator<<(ostream &, Date &);
istream &operator>>(istream &, Date &);

#endif _date_