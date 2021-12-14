#include "Book.h"

bool Book::operator==(const Book &t)
{
    if (this->tensach == t.tensach &&
        this->tentacgia == t.tentacgia &&
        this->theloai == t.theloai &&
        this->doyeuthich == t.doyeuthich &&
        this->Giasach == t.Giasach &&
        this->masach == t.masach &&
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
        this->masach != t.masach ||
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
    this->masach = t.masach;
    this->tinhtrang = t.tinhtrang;
    return *this;
}

void Book::Show()
{
    cout << "\nmasach:" << this->masach << endl;
    cout << "tensach:" << this->tensach << endl;
    cout << "tentacgia:" << this->tentacgia << endl;
    cout << "tinhtrang:" << this->tinhtrang << endl;
    cout << "theloai:" << this->theloai << endl;

    cout << "doyeuthich:" << this->doyeuthich << endl;
    cout << "Giasach:" << this->Giasach << endl;
}

Book::Book(int masach,
           string tensach,
           string tentacgia,
           string theloai,
           int doyeuthich,
           bool tinhtrang,
           int Giasach)
    : masach(masach),
      tensach(tensach),
      tentacgia(tentacgia),
      theloai(theloai),
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
    this->masach = t.masach;
    this->tinhtrang = t.tinhtrang;
    this->next = nullptr;
}
Book::~Book()
{
}
void Book::setBook(int masach,
                   string tensach,
                   string tentacgia,
                   string theloai,
                   int doyeuthich,
                   bool tinhtrang,
                   int Giasach)
{
    this->tensach = tensach;

    this->tentacgia = tentacgia;

    this->theloai = theloai;
    this->doyeuthich = doyeuthich;
    this->Giasach = Giasach;
    this->masach = masach;
    this->tinhtrang = tinhtrang;
    this->next = nullptr;
}
int Book::hash()
{

    unsigned long hash = 5381;
    for (auto c : to_string(this->masach))
    {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash % 10000;
}