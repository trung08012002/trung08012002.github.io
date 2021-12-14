#ifndef _List_
#define _List_
#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
class Book;
class List
{
public:
    Book **hash_table;
    int n;

public:
    List();
    List(int);
    ~List();
    void Show();
    Book *addToHashTable(Book, Book *) const;
    void Update(int);
    void deleteBook(int);
    void deleteAllBook();
    Book *Search(int);

    void addBook(Book);
    void addFromFile();
    void Top_10_Sach_Muon_Nhieu_Nhat();
    bool any(int);
    void updateFile();
};
#endif _List_