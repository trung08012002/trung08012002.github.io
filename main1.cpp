#include <string>
#include <iostream>
using namespace std;
#include "List.h"

main()
{
    Date ngay1 = Date(1, 1, 2021);
    Date ngay2 = Date(2, 1, 2021);
    ngay1 += 5;
    Book a("la", "la", "trinhtham", "hay", 1, true, 20);
    Book b("lao", "lao", "trinhtham", "hay", 1, true, 20);
    Book d("lau", "lau", "trinhtham", "hay", 1, true, 20);

    List new_List(10000);
    new_List.addBook(a);
    new_List.addBook(b);
    new_List.addBook(d);
    new_List.deleteBook("la", "la");
    new_List.Show();
    return 0;
}
