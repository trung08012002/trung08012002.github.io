#ifndef _Book_
#define _Book_
#include <string>
#include "Date.h"
#include <iostream>
using namespace std;

class Book
{

protected:
    string tensach;
    string tentacgia;
    string theloai;
    string mota;
    int doyeuthich;
    bool tinhtrang;

    int Giasach;
    Book *next;

public:
    Book();
    Book(string = "0",
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

    friend class List;

    Book operator=(const Book &);
    bool operator==(const Book &);
    bool operator!=(const Book &);
};
#endif _Book_