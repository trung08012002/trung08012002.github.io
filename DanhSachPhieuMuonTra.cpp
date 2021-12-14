#include "DanhSachPhieuMuonTra.h"
#define N 10000
DanhSachPhieuMuonTra::DanhSachPhieuMuonTra()
{
    this->n = 0;
    this->hash_table_P = nullptr;
}

DanhSachPhieuMuonTra::DanhSachPhieuMuonTra(int n)
{
    this->n = n;
    this->hash_table_P = new PhieuMuonTra *[n];
    for (int i = 0; i < n; i++)
        this->hash_table_P[i] = nullptr;
}

DanhSachPhieuMuonTra::~DanhSachPhieuMuonTra()
{
    delete[] this->hash_table_P;
}

void DanhSachPhieuMuonTra::Show()
{
    int number_of_Phieu_Muon_Tra = 0;
    system("clear");
    cout << "********    VIEW DanhSachPhieuMuonTra    *********";
    for (int i = 0; i < this->n; i++)
    {
        if (!this->hash_table_P[i])
            continue;
        else
        {
            PhieuMuonTra *current_pointer = this->hash_table_P[i];

            do
            {
                current_pointer->Show();
                number_of_Phieu_Muon_Tra++;
                current_pointer = current_pointer->next;
            } while (current_pointer);
        }
    }
    cout << "\n\nNumber of Phieu Muon Tra in dictionary: " << number_of_Phieu_Muon_Tra;
}
PhieuMuonTra *DanhSachPhieuMuonTra::addToHashTable(PhieuMuonTra temp_PhieuMuonTra, PhieuMuonTra *ptr) const
{
    if (!ptr) //check co phai la null
    {
        ptr = new PhieuMuonTra(temp_PhieuMuonTra);
        return ptr;
    }
    ptr->next = addToHashTable(temp_PhieuMuonTra, ptr->next);
    return ptr;
}
void DanhSachPhieuMuonTra::addPhieuMuonTra(PhieuMuonTra temp_PhieuMuonTra)
{

    this->hash_table_P[temp_PhieuMuonTra.hash()] = addToHashTable(temp_PhieuMuonTra, this->hash_table_P[temp_PhieuMuonTra.hash()]);
}
bool DanhSachPhieuMuonTra::any(int Ma_PhieuMuonTra)
{
    PhieuMuonTra temp_PhieuMuonTra(Ma_PhieuMuonTra);
    PhieuMuonTra *current_ptr = this->hash_table_P[temp_PhieuMuonTra.hash()];
    while (current_ptr)
    {
        if (current_ptr->ma_Phieu == temp_PhieuMuonTra.ma_Phieu)
            return 1;
        current_ptr = current_ptr->next;
    }
    return 0;
}

PhieuMuonTra *DanhSachPhieuMuonTra::Search(int Ma_PhieuMuonTra)
{
    PhieuMuonTra temp_PhieuMuonTra(Ma_PhieuMuonTra);
    PhieuMuonTra *current_ptr = this->hash_table_P[temp_PhieuMuonTra.hash()];
    while (current_ptr)
    {
        return current_ptr;
        current_ptr = current_ptr->next;
    }

    return current_ptr;
}
void DanhSachPhieuMuonTra::addFromFile() //doc tu file
{
    ifstream file_stream("DanhSachPhieuMuonTra.txt");
    string current_line;
    while (getline(file_stream, current_line))
    {
        string delimiter = "--";
        string token;
        int pos = 0;
        int ma_Phieu;

        int masach;
        int ma_Member;
        int TTien;
        Date Ngay_Muon;
        Date Ngay_Tra;
        string Trang_Thai;
        pos = current_line.find(delimiter);
        ma_Phieu = atoi(current_line.substr(0, pos).c_str());
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        masach = atoi(current_line.substr(0, pos).c_str());
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        ma_Member = atoi(current_line.substr(0, pos).c_str());
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);

        int ngay;
        int thang;
        int nam;
        ngay = atoi(current_line.substr(0, 1).c_str());
        thang = atoi(current_line.substr(2, 3).c_str());
        nam = atoi(current_line.substr(4, pos).c_str());
        Ngay_Muon = Date(ngay, thang, nam);
        current_line.erase(0, pos + delimiter.length());
        ngay = atoi(current_line.substr(0, 1).c_str());
        thang = atoi(current_line.substr(2, 3).c_str());
        nam = atoi(current_line.substr(4, pos).c_str());
        Ngay_Tra = Date(ngay, thang, nam);
        current_line.erase(0, pos + delimiter.length());

        pos = current_line.find(delimiter);
        Trang_Thai = current_line.substr(0, pos);
        current_line.erase(0, pos + delimiter.length());
        pos = current_line.find(delimiter);
        TTien = atoi(current_line.substr(0, pos).c_str());
        current_line.erase(0, pos + delimiter.length());

        PhieuMuonTra new_PhieuMuonTra(ma_Phieu,
                                      masach,
                                      ma_Member,
                                      TTien,
                                      Ngay_Muon,
                                      Ngay_Tra,
                                      Trang_Thai);
        this->addPhieuMuonTra(new_PhieuMuonTra);
    }
    file_stream.close();
}
void DanhSachPhieuMuonTra::deletePhieuMuonTra(int Ma_PhieuMuonTra)
{
    if (this->any(Ma_PhieuMuonTra) == 0)
    {
        return;
    }
    PhieuMuonTra temp_PhieuMuonTra(Ma_PhieuMuonTra);
    int hash_key = temp_PhieuMuonTra.hash();
    PhieuMuonTra *current_pointer = this->hash_table_P[hash_key];
    if (current_pointer->ma_Phieu == temp_PhieuMuonTra.ma_Phieu)
    {
        this->hash_table_P[hash_key] = current_pointer->next;
        return;
    }
    while (current_pointer->next->next)
    {
        if (current_pointer->next->ma_Phieu == temp_PhieuMuonTra.ma_Phieu)
        {
            current_pointer->next = current_pointer->next->next;
            break;
        }
        current_pointer = current_pointer->next;
    }
    if (*(current_pointer->next) == temp_PhieuMuonTra)
        current_pointer->next = nullptr;
    return;
}
void DanhSachPhieuMuonTra::deleteAllPhieuMuonTra()
{
    for (int i = 0; i < n; i++)
    {
        if (!this->hash_table_P[i])
            continue;
        else
        {
            PhieuMuonTra *current_pointer = this->hash_table_P[i];
            PhieuMuonTra *next_of_current_pointer = nullptr;
            while (current_pointer != nullptr)
            {
                next_of_current_pointer = current_pointer->next;
                current_pointer = nullptr;
                current_pointer = next_of_current_pointer;
            }
            this->hash_table_P[i] = nullptr;
        }
    }
}

void DanhSachPhieuMuonTra::Update(int Ma_PhieuMuonTra)
{
    while (1)
    {
        int dung = 1;
        PhieuMuonTra *tempPhieuMuonTra = Search(Ma_PhieuMuonTra);

        cout << "Thong tin can nhap" << endl;
        cout << "0.thoat" << endl;
        cout << "1.ma Phieu Muon Tra" << endl;
        cout << "2.masach" << endl;
        cout << "3.ma nguoi doc" << endl;
        cout << "4.Ngay muon" << endl;
        cout << "5.Ngay tra" << endl;
        cout << "6.Phieu muon tra" << endl;
        cout << "7.Tong tien" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> (this->hash_table_P[tempPhieuMuonTra->hash()])->ma_Phieu;
            break;
        case 2:
            for (int i = 0; i < 4; i++)
            {
                if ((this->hash_table_P[tempPhieuMuonTra->hash()])->masach[i] != 0)
                    cin >> (this->hash_table_P[tempPhieuMuonTra->hash()])->masach[i];
                else
                    break;
            }
            break;
        case 3:
            cin >> (this->hash_table_P[tempPhieuMuonTra->hash()])->ma_Member;
            break;
        case 4:
            cin >> (this->hash_table_P[tempPhieuMuonTra->hash()])->Ngay_Muon;
            break;
        case 5:
            cin >> (this->hash_table_P[tempPhieuMuonTra->hash()])->Ngay_Tra;
            break;
        case 6:
            cin >> (this->hash_table_P[tempPhieuMuonTra->hash()])->Trang_Thai;
            break;
        case 7:
            cin >> (this->hash_table_P[tempPhieuMuonTra->hash()])->TTien;
            break;
        case 0:
        {
            dung = 0;
            return;
        }
        }
    }
}

void DanhSachPhieuMuonTra::updateFile()
{
    ofstream os("newfile.txt");
    this->Show();
    os.close();
    remove("DanhSachPhieuMuonTra.txt");
    rename("newfile.txt", "List.txt");
}
void DanhSachPhieuMuonTra::Kiem_Tra_Phieu_Muon_Tra_Qua_Han()
{
    int number_of_Phieu_Muon_Tra = 0;
    system("clear");
    cout << "********    VIEW DanhSachPhieuMuonTraDaQuaHan    *********";
    for (int i = 0; i < this->n; i++)
    {
        if (!this->hash_table_P[i])
            continue;
        else
        {
            PhieuMuonTra *current_pointer = this->hash_table_P[i];

            do
            {

                if (current_pointer->So_Ngay_Qua_Han(current_pointer->Ngay_Muon, current_pointer->Ngay_Tra) > 15)
                {
                    current_pointer->Show();
                    number_of_Phieu_Muon_Tra++;
                    current_pointer = current_pointer->next;
                }
            } while (current_pointer);
        }
    }
    cout << "\n\nNumber of Phieu Muon Tra Da Qua Han in dictionary: " << number_of_Phieu_Muon_Tra;
}