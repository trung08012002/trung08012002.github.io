#ifndef _ListMember_
#define _ListMember_
#include "Member.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
class Member;
class ListMember
{
public:
    Member **hash_table_M;
    int n;

public:
    ListMember();
    ListMember(int);
    ~ListMember();
    void Show();
    Member *addToHashTable(Member, Member *) const;
    void Update(int, string, string);
    void deleteMember(int, string, string);
    Member *Search(int, string, string);
    void addBook(Book);
    void addMember(Member);
    void addFromFile();

    bool any(int, string, string);
    void updateFile();
};
#endif _ListMember_