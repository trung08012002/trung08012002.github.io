#include "List.h"

List::List()
{
    this->n = 0;
    this->hash_table = nullptr;
}

List::List(int n)
{
    this->n = n;
    this->hash_table = new Book *[n];
    for (int i = 0; i < n; i++)
        this->hash_table[i] = nullptr;
}

List::~List()
{
    delete[] this->hash_table;
}

void List::Show()
{
    int number_of_word = 0;
    system("clear");
    cout << "********    VIEW List    *********";
    for (int i = 0; i < this->n; i++)
    {
        if (!this->hash_table[i])
            continue;
        else
        {
            Book *current_pointer = this->hash_table[i];

            do
            {
                current_pointer->Show();
                number_of_word++;
                current_pointer = current_pointer->next;
            } while (current_pointer);
        }
    }
    cout << "\n\nNumber of word in dictionary: " << number_of_word;
}
Book *List::addToHashTable(Book temp_Book, Book *ptr) const
{
    if (!ptr) //check co phai la null
    {
        ptr = new Book(temp_Book);
        return ptr;
    }
    ptr->next = addToHashTable(temp_Book, ptr->next);
    return ptr;
}
void List::addBook(Book temp_Book)
{

    this->hash_table[temp_Book.hash()] = addToHashTable(temp_Book, this->hash_table[temp_Book.hash()]);
}
bool List::any(const string &tensach, const string &tentacgia)
{
    Book temp_Book(tensach, tentacgia);
    Book *current_ptr = this->hash_table[temp_Book.hash()];
    while (current_ptr)
    {
        if (current_ptr->tensach == temp_Book.tensach && current_ptr->tentacgia == temp_Book.tentacgia)
            return 1;
        current_ptr = current_ptr->next;
    }
    return 0;
}

Book *List::Search(string tensach, string tentacgia)
{
    Book temp_Book(tensach, tentacgia);
    Book *current_ptr = this->hash_table[temp_Book.hash()];
    while (current_ptr)
    {
        return current_ptr;
        current_ptr = current_ptr->next;
    }

    return current_ptr;
}
void List::addFromFile() //doc tu file
{
    ifstream file_stream("List.txt");
    string current_line;
    while (getline(file_stream, current_line))
    {
        string delimiter = "--";
        string token;
        int pos = 0;
        string tensach;
        string tentacgia;
        string theloai;
        string mota;
        int doyeuthich;
        bool tinhtrang;
        Date Ngaythuesach;
        Date Ngaytrasach;
        int Giasach;
        pos = current_line.find(delimiter);
        tensach = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        tentacgia = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        theloai = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        mota = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        doyeuthich = atoi(current_line.substr(0, pos).c_str());
        current_line.erase(0, pos + delimiter.length());
        if (current_line.substr(0, pos) == "true")
            tinhtrang = true;
        else
            tinhtrang = false;
        current_line.erase(0, pos + delimiter.length());
        int ngay;
        int thang;
        int nam;
        ngay = atoi(current_line.substr(0, 1).c_str());
        thang = atoi(current_line.substr(2, 3).c_str());
        nam = atoi(current_line.substr(4, pos).c_str());
        Ngaythuesach = Date(ngay, thang, nam);
        current_line.erase(0, pos + delimiter.length());
        ngay = atoi(current_line.substr(0, 1).c_str());
        thang = atoi(current_line.substr(2, 3).c_str());
        nam = atoi(current_line.substr(4, pos).c_str());
        Ngaytrasach = Date(ngay, thang, nam);
        current_line.erase(0, pos + delimiter.length());
        Giasach = atoi(current_line.c_str());
        Book new_Book(tensach,
                      tentacgia,
                      theloai,
                      mota,
                      doyeuthich,
                      tinhtrang,

                      Giasach);
        this->addBook(new_Book);
    }
    file_stream.close();
}
void List::deleteBook(string tensach, string tentacgia)
{
    if (this->any(tensach, tentacgia) == 0)
    {
        return;
    }
    Book temp_Book(tensach, tentacgia);
    int hash_key = temp_Book.hash();
    Book *current_pointer = this->hash_table[hash_key];
    if (current_pointer->tensach == temp_Book.tensach && current_pointer->tentacgia == temp_Book.tentacgia)
    {
        this->hash_table[hash_key] = current_pointer->next;
        return;
    }
    while (current_pointer->next->next)
    {
        if (current_pointer->next->tensach == temp_Book.tensach && current_pointer->next->tentacgia == temp_Book.tentacgia)
        {
            current_pointer->next = current_pointer->next->next;
            break;
        }
        current_pointer = current_pointer->next;
    }
    if (*(current_pointer->next) == temp_Book)
        current_pointer->next = nullptr;
    return;
}

void List::Update(string tensach, string tentacgia)
{
    while (1)
    {
        int dung = 1;
        Book *tempBook = Search(tensach, tentacgia);

        cout << "Thong tin can nhap" << endl;
        cout << "1.tensach" << endl;
        cout << "2.tentacgia" << endl;
        cout << "3.tinhtrang" << endl;

        cout << "4.Giasach" << endl;
        cout << "5.mota" << endl;
        cout << "6.doyeuthich" << endl;
        cout << "7.theloai" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> (this->hash_table[tempBook->hash()])->tensach;
            break;
        case 2:
            cin >> (this->hash_table[tempBook->hash()])->tentacgia;
            break;
        case 3:
            cin >> (this->hash_table[tempBook->hash()])->tinhtrang;
            break;

        case 4:
            cin >> (this->hash_table[tempBook->hash()])->Giasach;
            break;
        case 5:
            cin >> (this->hash_table[tempBook->hash()])->mota;
            break;
        case 6:
            cin >> (this->hash_table[tempBook->hash()])->doyeuthich;
            break;
        case 7:
            cin >> (this->hash_table[tempBook->hash()])->theloai;
            break;
        case 0:
        {
            dung = 0;
            return;
        }
        }
    }
}
void List::updateFile()
{
    ofstream os("newfile.txt");
    this->Show();
    os.close();
    remove("List.txt");
    rename("newfile.txt", "List.txt");
}