#include "List.h"
#include <iomanip>
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
bool List::any(int masach)
{
    Book temp_Book(masach);
    Book *current_ptr = this->hash_table[temp_Book.hash()];

    while (current_ptr)
    {

        if (current_ptr->masach == temp_Book.masach)
        {

            return 1;
        }

        current_ptr = current_ptr->next;
    }
    return 0;
}

Book *List::Search(int masach)
{
    Book temp_Book(masach);
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

        string delimiter = ",";
        string token;
        int pos = 0;
        int masach;
        string tensach;
        string tentacgia;
        string theloai;
        int doyeuthich;
        bool tinhtrang;
        int Giasach;
        pos = current_line.find(delimiter);
        tensach = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        tentacgia = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        theloai = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        masach = atoi(current_line.substr(0, pos).c_str());
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        doyeuthich = atoi(current_line.substr(0, pos).c_str());
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        if (current_line.substr(0, pos) == "true")
            tinhtrang = true;
        else
            tinhtrang = false;
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        Giasach = atoi(current_line.c_str());
        Book new_Book(masach,
                      tensach,
                      tentacgia,
                      theloai,
                      doyeuthich,
                      tinhtrang,
                      Giasach);
        this->addBook(new_Book);
    }
    file_stream.close();
}
void List::deleteBook(int masach)
{
    if (this->any(masach) == 0)
    {
        return;
    }
    Book temp_Book(masach);
    int hash_key = temp_Book.hash();
    Book *current_pointer = this->hash_table[hash_key];
    if (current_pointer->masach == temp_Book.masach)
    {
        this->hash_table[hash_key] = current_pointer->next;
        return;
    }
    while (current_pointer->next->next)
    {
        if (current_pointer->next->masach == temp_Book.masach)
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
void List::deleteAllBook()
{
    for (int i = 0; i < n; i++)
    {
        if (!this->hash_table[i])
            continue;
        else
        {
            Book *current_pointer = this->hash_table[i];
            Book *next_of_current_pointer = nullptr;
            while (current_pointer != nullptr)
            {
                next_of_current_pointer = current_pointer->next;
                current_pointer = nullptr;
                current_pointer = next_of_current_pointer;
            }
            this->hash_table[i] = nullptr;
        }
    }
}
void List::Update(int masach)
{
    while (1)
    {
        int dung = 1;
        Book *tempBook = Search(masach);

        cout << "Thong tin can nhap" << endl;
        cout << "1.tensach" << endl;
        cout << "2.tentacgia" << endl;
        cout << "3.tinhtrang" << endl;

        cout << "4.Giasach" << endl;
        cout << "5.Masach" << endl;
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
            cin >> (this->hash_table[tempBook->hash()])->masach;
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
void List::Top_10_Sach_Muon_Nhieu_Nhat()
{
    int *luot_muon = new int[10];
    int *ma_Sach = new int[10];
    for (int j = 0; j < 10; j++)
    {
        luot_muon[j] = 0;
        ma_Sach[j] = 0;
    }
    int max = 0;
    int index = 0;
    for (int i = 0; i < this->n; i++)
    {
        if (!this->hash_table[i])
            continue;
        else
        {
            Book *current_pointer = this->hash_table[i];

            do
            {
                for (int j = 0; j < 10; j++)
                {
                    if (luot_muon[j] <= max)
                    {
                        max = luot_muon[j];
                        index = j;
                    }
                }
                if (current_pointer->doyeuthich > max)
                {
                    luot_muon[index] = current_pointer->doyeuthich;
                    ma_Sach[index] = current_pointer->masach;
                }
                current_pointer = current_pointer->next;

            } while (current_pointer);
        }
    }
    cout << setw(30) << "Ma so Sach" << setw(30) << "So luot muon";
    cout << "\n***********************************************" << endl;
    for (int j = 0; j < 10; j++)
    {
        cout << setw(30) << ma_Sach[j] << setw(30) << luot_muon[j] << endl;
    }
}