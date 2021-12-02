#include "Book.h"

bool Book::operator==(const Book &t)
{
    if (this->tensach == t.tensach &&
        this->tentacgia == t.tentacgia &&
        this->theloai == t.theloai &&
        this->doyeuthich == t.doyeuthich &&
        this->Giasach == t.Giasach &&
        this->mota == t.mota &&
        this->tinhtrang == t.tinhtrang)
        return true;
    else
        return false;
}
bool Book::operator!=(const Book &t)
{
    if (this->tensach != t.tensach ||
        this->tentacgia != t.tentacgia ||
        this->theloai != t.theloai ||
        this->doyeuthich != t.doyeuthich ||
        this->Giasach != t.Giasach ||
        this->mota != t.mota ||
        this->tinhtrang != t.tinhtrang)
        return true;
    else
        return false;
}
Book Book::operator=(const Book &t)
{
    this->tensach = t.tensach;
    this->tentacgia = t.tentacgia;

    this->theloai = t.theloai;
    this->doyeuthich = t.doyeuthich;
    this->Giasach = t.Giasach;
    this->mota = t.mota;
    this->tinhtrang = t.tinhtrang;
    return *this;
}
Book::Book()
{
}
void Book::Show()
{
    cout << "tensach:" << this->tensach << endl;
    cout << "tentacgia:" << this->tentacgia << endl;
    cout << "tinhtrang:" << this->tinhtrang << endl;
    cout << "theloai:" << this->theloai << endl;
    cout << "mota:" << this->mota << endl;
    cout << "doyeuthich:" << this->doyeuthich << endl;
    cout << "Giasach:" << this->Giasach << endl;
}

Book::Book(string tensach,
           string tentacgia,
           string theloai,
           string mota,
           int doyeuthich,
           bool tinhtrang,

           int Giasach)
    : tensach(tensach),
      tentacgia(tentacgia),
      theloai(theloai),
      mota(mota),
      doyeuthich(doyeuthich),
      tinhtrang(tinhtrang),

      Giasach(Giasach)
{
    this->next = nullptr;
}
Book::Book(Book &t)
{

    this->tensach = t.tensach;

    this->tentacgia = t.tentacgia;

    this->theloai = t.theloai;
    this->doyeuthich = t.doyeuthich;
    this->Giasach = t.Giasach;
    this->mota = t.mota;
    this->tinhtrang = t.tinhtrang;
    this->next = nullptr;
}
Book::~Book()
{
}

int Book::hash()
{

    unsigned long hash = 5381;
    for (auto c : this->tensach)
    {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash % 10000;
}