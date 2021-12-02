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
    void Update(string, string);
    void deleteBook(string, string);
    Book *Search(string, string);

    void addBook(Book);
    void addFromFile();

    bool any(const string &, const string &);
    void updateFile();
};
#endif _List_