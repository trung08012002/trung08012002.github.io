#include "ListMember.h"

ListMember::ListMember()
{
    this->n = 0;
    this->hash_table_M = nullptr;
}

ListMember::ListMember(int n)
{
    this->n = n;
    this->hash_table_M = new Member *[n];
    for (int i = 0; i < n; i++)
        this->hash_table_M[i] = nullptr;
}

ListMember::~ListMember()
{
    delete[] this->hash_table_M;
}

void ListMember::Show()
{
    int number_of_word = 0;
    system("clear");
    cout << "********    VIEW ListMember    *********";
    for (int i = 0; i < this->n; i++)
    {
        if (!this->hash_table_M[i])
            continue;
        else
        {
            Member *current_pointer = this->hash_table_M[i];

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
Member *ListMember::addToHashTable(Member temp_Member, Member *ptr) const
{
    if (!ptr) //check co phai la null
    {
        ptr = new Member(temp_Member);
        return ptr;
    }
    ptr->next = addToHashTable(temp_Member, ptr->next);
    return ptr;
}
void ListMember::addMember(Member temp_Member)
{

    this->hash_table_M[temp_Member.hash()] = addToHashTable(temp_Member, this->hash_table_M[temp_Member.hash()]);
}
bool ListMember::any(int Ma_member)
{
    Member temp_Member(Ma_member);
    Member *current_ptr = this->hash_table_M[temp_Member.hash()];
    while (current_ptr)
    {
        if (current_ptr->ma_Member == temp_Member.ma_Member)
            return 1;
        current_ptr = current_ptr->next;
    }
    return 0;
}

Member *ListMember::Search(int Ma_member)
{
    Member temp_Member(Ma_member);
    Member *current_ptr = this->hash_table_M[temp_Member.hash()];
    while (current_ptr)
    {
        return current_ptr;
        current_ptr = current_ptr->next;
    }

    return current_ptr;
}
void ListMember::addFromFile() //doc tu file
{
    ifstream file_stream("ListMember.txt");
    string current_line;
    while (getline(file_stream, current_line))
    {
        string delimiter = "--";
        string token;
        int pos = 0;
        int ma_Member;
        string Ho;
        string Ten;
        Date ngaysinh;
        string Phai;
        bool Trang_Thai;
        pos = current_line.find(delimiter);
        ma_Member = atoi(current_line.substr(0, pos).c_str());
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        Ho = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        Ten = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        if (current_line.substr(0, pos) == "true")
            Trang_Thai = true;
        else
            Trang_Thai = false;
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        int ngay;
        int thang;
        int nam;
        ngay = atoi(current_line.substr(0, 1).c_str());
        thang = atoi(current_line.substr(2, 3).c_str());
        nam = atoi(current_line.substr(4, pos).c_str());
        ngaysinh = Date(ngay, thang, nam);
        current_line.erase(0, pos + delimiter.length());

        pos = current_line.find(delimiter);
        Phai = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        Member new_Member(ma_Member,
                          Ho,
                          Ten,
                          ngaysinh,
                          Phai,
                          Trang_Thai);
        this->addMember(new_Member);
    }
    file_stream.close();
}
bool ListMember::deleteMember(int Ma_member)
{
    if (this->any(Ma_member) == 0)
    {
        return 0;
    }
    Member temp_Member(Ma_member);
    int hash_key = temp_Member.hash();
    Member *current_pointer = this->hash_table_M[hash_key];
    if (current_pointer->ma_Member == temp_Member.ma_Member)
    {
        this->hash_table_M[hash_key] = current_pointer->next;
        return 1;
    }
    while (current_pointer->next->next)
    {
        if (current_pointer->ma_Member == temp_Member.ma_Member)
        {
            current_pointer->next = current_pointer->next->next;
            break;
        }
        current_pointer = current_pointer->next;
    }
    if (*(current_pointer->next) == temp_Member)
        current_pointer->next = nullptr;
    return 1;
}
void ListMember::deleteAllMember()
{
    for (int i = 0; i < n; i++)
    {
        if (!this->hash_table_M[i])
            continue;
        else
        {
            Member *current_pointer = this->hash_table_M[i];
            Member *next_of_current_pointer = nullptr;
            while (current_pointer != nullptr)
            {
                next_of_current_pointer = current_pointer->next;
                current_pointer = nullptr;
                current_pointer = next_of_current_pointer;
            }
            this->hash_table_M[i] = nullptr;
        }
    }
}
void ListMember::Update(int Ma_member)
{
    while (1)
    {
        int dung = 1;
        Member *tempMember = Search(Ma_member);

        cout << "Thong tin can nhap" << endl;
        cout << "0.thoat" << endl;
        cout << "1.ma_Member" << endl;
        cout << "2.Ho" << endl;
        cout << "3.Ten" << endl;
        cout << "4.ngaysinh" << endl;
        cout << "5.Phai" << endl;
        cout << "6.Trang_Thai" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> (this->hash_table_M[tempMember->hash()])->ma_Member;
            break;
        case 2:
            cin >> (this->hash_table_M[tempMember->hash()])->Ho;
            break;
        case 3:
            cin >> (this->hash_table_M[tempMember->hash()])->Ten;
            break;
        case 4:
            cin >> (this->hash_table_M[tempMember->hash()])->ngaysinh;
            break;
        case 5:
            cin >> (this->hash_table_M[tempMember->hash()])->Phai;
            break;
        case 6:
            cin >> (this->hash_table_M[tempMember->hash()])->Trang_Thai;
            break;

        case 0:
        {
            dung = 0;
            return;
        }
        }
    }
}
void ListMember::updateFile()
{
    ofstream os("newfile.txt");
    this->Show();
    os.close();
    remove("ListMember.txt");
    rename("newfile.txt", "List.txt");
}