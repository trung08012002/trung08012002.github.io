#include <string>
#include <iostream>
using namespace std;
#include "List.h"
#include "ListMember.h"
#include "DanhSachPhieuMuonTra.h"

main()
{
    int chucnangmenu;
    bool flagmenu = true;
    bool flagmenucon;
    int chucnangmenucon;
    ListMember new_List_Member(10000);
    new_List_Member.addFromFile();
    DanhSachPhieuMuonTra new_List_MuonTra(10000);
    new_List_MuonTra.addFromFile();
    List new_List_Book(10000);
    new_List_Book.addFromFile();
    cout << "Chuong trinh quan ly thu vien ....... " << endl;
    do
    {
        cout << "\n1.Quan ly doc gia" << endl;
        cout << "2.Quan ly sach" << endl;
        cout << "3.Lap Phieu Muon Tra Sach" << endl;
        cout << "4.Thong ke" << endl;
        cout << "5.Thoat" << endl;
        cout << "Chon chuc nang:";
        cin >> chucnangmenu;
        switch (chucnangmenu)
        {
        case 1:
            cout << "\nchuc nang quan ly doc gia" << endl;
            flagmenucon = true;

            do
            {
                cout << "1.Xem danh sach doc gia trong thu vien" << endl;
                cout << "2.Them doc gia" << endl;
                cout << "3.Chinh sua thong tin doc gia" << endl;
                cout << "4.Xoa thong tin 1 doc gia" << endl;
                cout << "5.Xoa thong tin tat ca doc gia" << endl;
                cout << "6.Tim kiem doc gia theo ma doc gia" << endl;
                cout << "7.Quay lai..." << endl;
                cout << "Chon chuc nang:";
                cin >> chucnangmenucon;
                switch (chucnangmenucon)
                {
                case 1:
                {
                    system("clear");
                    cout << "Chuc nang xem danh sach doc gia trong thu vien" << endl;

                    new_List_Member.Show();
                    break;
                }
                case 2:
                {
                    system("clear");
                    cout << "Chuc nang them doc gia";
                    int ma_Member;
                    string Ho;
                    string Ten;
                    Date ngaysinh;
                    string Phai;
                    bool Trang_Thai;
                    cout << "\nNhap ma doc gia";
                    cin >> ma_Member;
                    if (new_List_Member.any(ma_Member))
                        cout << "\nDoc gia nay da co trong thu vien";
                    else
                    {
                        cout << "\nNhap ho\n";
                        std::cin.ignore(32767, '\n');
                        getline(cin, Ho);
                        cout << "\nNhap ten\n";
                        getline(cin, Ten);
                        cout << "\nPhai\n";
                        getline(cin, Phai);
                        cout << "\nNgaysinh";
                        cin >> ngaysinh;

                        Trang_Thai = 1;
                        Member temp(ma_Member, Ho, Ten, ngaysinh, Phai, Trang_Thai);
                        new_List_Member.addMember(temp);
                    }
                    break;
                }

                case 3:
                {
                    system("clear");
                    cout << "Chuc nang chinh sua thong tin doc gia";
                    cout << "\nNhap ma doc gia muon chinh sua:";
                    int ma_Member;

                    cin >> ma_Member;
                    if (!new_List_Member.any(ma_Member))
                    {
                        cout << "\nDoc gia nay khong co trong thu vien";
                    }
                    else
                    {
                        new_List_Member.Update(ma_Member);
                    }
                    break;
                }
                case 4:
                {
                    system("clear");
                    cout << "Chuc nang xoa thong tin 1 doc gia";
                    cout << "\nNhap ma doc gia muon xoa:";
                    int ma_Member;
                    cin >> ma_Member;
                    if (!new_List_Member.any(ma_Member))
                    {
                        cout << "\nDoc gia nay khong co trong thu vien";
                    }
                    else
                    {
                        new_List_Member.deleteMember(ma_Member);
                        cout << "\nSuccess!";
                    }
                    break;
                }

                case 5:
                {
                    system("clear");
                    cout << "\nChuc nang xoa thong tin tat ca sach";
                    new_List_Member.deleteAllMember();
                    cout << "\nDa xoa thanh cong";
                }

                case 6:
                {
                    system("clear");
                    cout << "Chuc nang tim kiem doc gia theo ma doc gia";
                    cout << "Nhap ma doc gia muon tim kiem";
                    int ma_Member;
                    cin >> ma_Member;
                    if (new_List_Member.any(ma_Member))
                    {
                        Member *temp_Member = (new_List_Member.Search(ma_Member));
                        temp_Member->Show();
                    }
                    else
                    {
                        cout << "\nDoc gia nay khong co tron thu vien";
                    }
                    break;
                }
                case 7:
                    flagmenucon = false;
                    break;
                }
            } while (flagmenucon);

            break;
        case 2:
            cout << "\nchuc nang quan ly sach" << endl;
            flagmenucon = true;

            do
            {
                cout << "\n1.Xem danh sach sach trong thu vien" << endl;
                cout << "2.Them sach" << endl;
                cout << "3.Chinh sua thong tin sach" << endl;
                cout << "4.Xoa thong tin 1 sach" << endl;
                cout << "5.Xoa toan bo sach" << endl;
                cout << "6.Tim kiem sach theo ma sach" << endl;
                cout << "7.Quay lai..." << endl;
                cout << "Chon chuc nang:";
                cin >> chucnangmenucon;
                switch (chucnangmenucon)
                {
                case 1:
                {
                    system("clear");
                    cout << "\nChuc nang xem danh sach sach trong thu vien" << endl;

                    new_List_Book.Show();
                    break;
                }
                case 2:
                {
                    system("clear");
                    cout << "\nChuc nang them sach";
                    cout << "\n1.Them bang cach nhap";
                    cout << "\n2.Them bang file";
                    int luachon;
                    cin >> luachon;
                    if (luachon == 1)
                    {

                        int masach;
                        string tensach;
                        string tentacgia;
                        string theloai;
                        int doyeuthich;
                        bool tinhtrang;
                        int Giasach;
                        cout << "\nnhap ma sach";

                        cin >> masach;
                        if (new_List_Book.any(masach))
                            cout << "sach nay da co trong thu vien";
                        else
                        {
                            std::cin.ignore(32767, '\n');
                            cout << "\nNhap ten sach";
                            getline(cin, tensach);
                            cout << "\nNhap ten tac gia";
                            getline(cin, tentacgia);
                            cout << "\nNhap the loai";
                            getline(cin, theloai);
                            doyeuthich = 0;
                            tinhtrang = 1;
                            cout << "\nNhap gia sach";
                            cin >> Giasach;
                            Book tempBook(masach, tensach, tentacgia, theloai, doyeuthich, tinhtrang, Giasach);
                            new_List_Book.addBook(tempBook);
                        }
                    }
                    else
                    {
                        new_List_Book.addFromFile();
                    }

                    break;
                }

                case 3:
                {
                    system("clear");
                    cout << "\nChuc nang chinh sua thong tin sach";
                    cout << "\nNhap ma sach muon chinh sua:";
                    int masach;

                    cin >> masach;
                    if (!new_List_Book.any(masach))
                    {
                        cout << "\nsach nay khong co trong thu vien";
                    }
                    else
                    {
                        new_List_Book.Update(masach);
                    }
                    break;
                }
                case 4:
                {
                    system("clear");
                    cout << "\nChuc nang xoa thong tin 1 sach";
                    cout << "\nNhap ma sach muon xoa:";
                    int masach;
                    cin >> masach;
                    if (!new_List_Book.any(masach))
                    {
                        cout << "\nsach nay khong co trong thu vien";
                    }
                    else
                    {
                        new_List_Book.deleteBook(masach);
                    }
                    break;
                }
                case 5:
                {
                    system("clear");
                    cout << "\nChuc nang xoa thong tin tat ca sach";
                    new_List_Book.deleteAllBook();
                    cout << "\nDa xoa thanh cong";
                }
                case 6:
                {
                    system("clear");
                    cout << "\nChuc nang tim kiem sach theo ma sach";
                    cout << "\nNhap ma sach muon tim kiem";
                    int masach;
                    cin >> masach;
                    if (new_List_Book.any(masach))
                    {
                        Book *temp_Member = (new_List_Book.Search(masach));
                        temp_Member->Show();
                    }
                    else
                    {
                        cout << "\nsach nay khong co tron thu vien";
                    }
                    break;
                }
                case 7:
                    flagmenucon = false;
                    break;
                }

            } while (flagmenucon);

            break;
        case 3:
            cout << "chuc nang quan ly danh sach phieu muon tra" << endl;
            flagmenucon = true;

            do
            {
                cout << "\n1.Xem Danh Sach Phieu Muon Tra trong thu vien" << endl;
                cout << "2.Them phieu muon tra" << endl;
                cout << "3.Chinh sua thong tin phieu muon tra" << endl;
                cout << "4.Xoa thong tin 1 phieu muon tra" << endl;
                cout << "5.Xoa toan bo Phieu Muon Tra" << endl;
                cout << "6.Tim kiem phieu muon tra theo ma phieu muon tra" << endl;
                cout << "7.Gia han" << endl;
                cout << "8.Quay lai..." << endl;
                cout << "Chon chuc nang:";
                cin >> chucnangmenucon;
                switch (chucnangmenucon)
                {
                case 1:
                {

                    cout << "\nChuc nang xem danh sach phieu muon tra trong thu vien" << endl;

                    new_List_MuonTra.Show();
                    break;
                }
                case 2:
                {
                    system("clear");
                    cout << "\nChuc nang them phieu muon tra ";
                    int maphieumuontra;
                    cout << "\nNhap ma Phieu muon tra";
                    cin >> maphieumuontra;
                    if (new_List_MuonTra.any(maphieumuontra))
                        cout << "\nPhieu nay da co trong thu vien";
                    else
                    {
                        PhieuMuonTra tempPhieuMuonTra(0);
                        tempPhieuMuonTra.Nhap_Thong_Tin_Phieu_Muon_Tra(new_List_Book);
                        new_List_MuonTra.addPhieuMuonTra(tempPhieuMuonTra);
                    }
                    break;
                }

                case 3:
                {
                    system("clear");
                    cout << "\nChuc nang chinh sua thong tin phieu muon tra";
                    cout << "\nNhap ma Phieu muon tra muon chinh sua:";
                    int maPhieuMuonTra;

                    cin >> maPhieuMuonTra;
                    if (!new_List_MuonTra.any(maPhieuMuonTra))
                    {
                        cout << "\nPhieu muon tra nay khong co trong thu vien";
                    }
                    else
                    {
                        new_List_MuonTra.Update(maPhieuMuonTra);
                    }
                    break;
                }
                case 4:
                {
                    system("clear");
                    cout << "\nChuc nang xoa thong tin 1 phieu muon tra";
                    cout << "\nNhap ma phieu muon tra muon xoa:";
                    int maPhieuMuonTra;
                    cin >> maPhieuMuonTra;
                    if (!new_List_MuonTra.any(maPhieuMuonTra))
                    {
                        cout << "\nphieu muon tra nay khong co trong thu vien";
                    }
                    else
                    {
                        new_List_MuonTra.deletePhieuMuonTra(maPhieuMuonTra);
                    }
                    break;
                }
                case 5:
                {
                    system("clear");
                    cout << "\nChuc nang xoa thong tin tat ca Phieu Muon Tra";
                    new_List_MuonTra.deleteAllPhieuMuonTra();
                    cout << "\nDa xoa thanh cong";
                }
                case 6:
                {
                    system("clear");
                    cout << "\nChuc nang tim kiem Phieu muon tra theo ma phieu muon tra" << endl;
                    cout << "Nhap ma phieu muon tra muon tim kiem";
                    int maPhieuMuonTra;
                    cin >> maPhieuMuonTra;
                    if (new_List_MuonTra.any(maPhieuMuonTra))
                    {
                        PhieuMuonTra *temp_Member = (new_List_MuonTra.Search(maPhieuMuonTra));
                        temp_Member->Show();
                    }
                    else
                    {
                        cout << "\nPhieu nay khong co tron thu vien";
                    }
                    break;
                }
                case 7:
                {
                    int maPhieuMuonTra;
                    cout << "\nNhap ma Phieu Muon Tra";
                    cin >> maPhieuMuonTra;
                    int songaythem;
                    cout << "\nNhap so ngay gia han";
                    cin >> songaythem;
                    PhieuMuonTra *tempPhieuMuonTra = new_List_MuonTra.Search(maPhieuMuonTra);
                    tempPhieuMuonTra->GiaHan(songaythem);
                    break;
                }
                case 8:
                    flagmenucon = false;
                    break;
                }
            } while (flagmenucon);

            break;
        case 4:
            cout << "\nchuc nang thong ke" << endl;
            flagmenucon = true;
            do
            {
                cout << "\n1.Xem Danh Sach Phieu Muon Tra Da Qua Han  trong thu vien";
                cout << "\n2.Xem Danh Sach Sach Co Luot Doc Cao Nhat Trong Thu Vien";
                cout << "\n3.Quay lai...";
                cout << "\nChon chuc nang:";
                cin >> chucnangmenucon;
                switch (chucnangmenucon)
                {
                case 1:
                {

                    cout << "\nChuc Nang Xem Danh Sach Phieu Muon Tra Da Qua Han trong thu vien" << endl;
                    new_List_MuonTra.Kiem_Tra_Phieu_Muon_Tra_Qua_Han();
                    break;
                }
                case 2:
                {
                    cout << "\nChuc Nang Xem Danh Sach 10 Sach Co So Luot Xem Cao Nhat trong thu vien" << endl;
                    new_List_Book.Top_10_Sach_Muon_Nhieu_Nhat();
                    break;
                }
                case 3:
                    flagmenucon = false;
                    break;
                }
            } while (flagmenucon);

            break;
        case 5:
            flagmenu = false;
            break;
        }
    } while (flagmenu);

    return 0;
}
