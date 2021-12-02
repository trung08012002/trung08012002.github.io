#include "Date.h"
#include <iostream>
using namespace std;
int Date::songay[] = {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31};
Date::Date(int ngay, int thang, int nam)
{
    setDate(ngay, thang, nam);
}
Date::~Date()
{
}

void Date::setDate(int d, int m, int y)
{
    this->thang = (m >= 1 && m <= 12) ? m : 1;
    this->nam = (y > 1900 && y <= 2100) ? y : 1900;
    if (m == 2 && namnhuan(y))
        this->ngay = (d >= 1 && d <= 29) ? d : 1;
    else
        this->ngay = (d >= 1 && d <= songay[m - 1]) ? d : 1;
}
ostream &operator<<(ostream &o, Date &i)
{
    o << "ngay=" << i.ngay << "thang =" << i.thang << "nam= " << i.nam << endl;
    return o;
}
istream &operator>>(istream &i, Date &t)
{
    i >> t.ngay >> t.thang >> t.nam;
    return i;
}
Date Date::operator++()
{
    tangngay();
    return *this;
}
Date Date::operator++(int)
{
    Date Temp = *this;
    tangngay();
    return Temp;
}
Date Date::operator+=(int songaythem)
{
    for (int i = 1; i <= songaythem; i++)
        tangngay();
    return *this;
}
bool Date::operator==(Date t)
{
    if (this->ngay == t.ngay && this->thang == t.thang && this->nam == t.nam)
        return true;
    else
        return false;
}
bool Date::operator!=(Date t)
{
    if (this->ngay != t.ngay || this->thang != t.thang || this->nam != t.nam)
        return true;
    else
        return false;
}
bool Date::namnhuan(int y)
{
    if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
        return true;
    return false;
}
bool Date::cuoithang(int m)
{
    if (this->thang == 2 && namnhuan(this->nam))
    {
        return m == 29;
    }
    return m == songay[this->thang - 1];
}
void Date::tangngay()
{
    if (cuoithang(this->ngay) && this->thang == 12)
    {
        this->ngay = 1;
        this->thang = 1;
        ++this->nam;
    }
    else if (cuoithang(this->ngay))
    {
        this->ngay = 1;
        ++this->thang;
    }
    else
        ++this->ngay;
}
Date Date::Thoi_Gian_Thuc()
{
    time_t t = time(0);
    struct tm *now = localtime(&t);
    this->ngay = now->tm_mday;
    this->thang = now->tm_mon + 1;
    this->nam = now->tm_year + 1900;
    return *this;
}