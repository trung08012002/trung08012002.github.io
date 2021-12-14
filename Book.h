#ifndef _Book_
#define _Book_
#include <string>
#include "Date.h"
#include <iostream>
using namespace std;

class Book
{

protected:
    int masach;
    string tensach;
    string tentacgia;
    string theloai;
    int doyeuthich;
    bool tinhtrang;
    int Giasach;
    Book *next;

public:
    Book(int = 0,
         string = "0",
         string = "0",
         string = "0",
         int = 0,
         bool = false,

         int = 0);
    Book(Book &);
    ~Book();
    void Show();
    int hash();
    friend ostream &operator<<(ostream &, Date &);
    friend istream &operator>>(istream &, Date &);
    void setBook(int = 0,
                 string = "0",
                 string = "0",
                 string = "0",
                 int = 0,
                 bool = false,
                 int = 0);
    friend class List;
    friend class PhieuMuonTra;
    Book operator=(const Book &);
    bool operator==(const Book &);
    bool operator!=(const Book &);
};
#endif _Book_