#include "PhieuMuonTra.h"
#include "DanhSachPhieuMuonTra.h"
#include "List.h"
#include "ListMember.h"
#include <iostream>
using namespace std;
int console()
{
    system("clear");
    int choose;
    do
    {
        cout << "\n================ Library ================\n";
        cout << "|   1. View library                        |\n";
        cout << "|   2. Import from text file               |\n";
        cout << "|   3. Search Book                         |\n";
        cout << "|   4. Add new Book to Library             |\n";
        cout << "|   5. Delete Book in Library              |\n";
        cout << "|   6. Edit Book                           |\n";
        cout << "|   1. View DanhSachPhieuMuonTra           |\n";
        cout << "|   2. Import from text file               |\n";
        cout << "|   3. Search PhieuMuonTra                 |\n";
        cout << "|   4. Add new PhieuMuonTra to Library     |\n";
        cout << "|   5. tra sach                            |\n";
        cout << "|   6. Edit PhieuMuonTra                   |\n";
        cout << "|   7. Gia han                             |\n";
        cout << "|   7. Exit game!                          |\n";
        cout << "=============================================\n";
    } while (choose);
    return choose;
}
int toContinue()
{
    char yes;
    cout << "\n\nPress y to continue!\nPress b to back to menu!\nPress any key to exit!\nInput: ";
    yes = getchar();
    getchar();
    if (yes == 'y')
        return 1;
    else if (yes == 'b')
        return 2;
    else
    {
        return 3;
    }
}
void run()
{
    List new_List(10000);
    new_List.addFromFile();
    int choose = console();
    while (1)
    {
        switch (choose)
        {
        case 0:
        {
            choose = console();
            break;
        }
        case 1:
        {
            system("clear");
            new_List.Show();
            int check = toContinue();
            if (check == 1)
                choose = 1;
            else
                choose = 0;
            break;
        }
        case 2:
        {
            system("clear");
            cout << "********  IMPORT FROM FILE  *********";
            cout << "\nEnter file name you want to import: ";
            string s;
            getline(cin, s);
            new_List.importFromFile(s);
            cout << "\nSuccess!";
            int check = toContinue();
            if (check == 1)
                choose = 2;
            else if (check == 2)
                choose = 0;
            else
                choose = 7;
            break;
        }
        case 3:
        {
            system("clear");
            cout << "********  SEARCHING  *********";
            cout << "\nEnter the word you want to find: ";
            string s;
            cout << "\nInput word: ";
            getline(cin, s);
            if (new_List.any(s))
            {
                Word temp_word = *(new_List.search(s));
                cout << "\nWORD\t\tTYPE\t\tMEAN\n";
                cout << temp_word;
            }
            else
            {
                cout << "\nThis word is not in the dictionary!";
            }
            int check = toContinue();
            if (check == 1)
                choose = 3;
            else if (check == 2)
                choose = 0;
            else
                choose = 7;
            break;
        }
        case 4:
        {
            system("clear");
            cout << "********  ADD A NEW WORD  *********";
            cout << "\nEnter a word: ";
            string data;
            string type;
            string meaning;
            getline(cin, data);
            if (new_List.any(data))
                cout << "This word has been in the dictionary!";
            else
            {
                cout << "\nEnter its type: ";
                getline(cin, type);
                cout << "\nEnter its meaning: ";
                getline(cin, meaning);
                new_List.addWord(Word(data, type, meaning));
            }
            int check = toContinue();
            if (check == 1)
                choose = 4;
            else if (check == 2)
                choose = 0;
            else
                choose = 7;
            break;
        }
        case 5:
        {
            system("clear");
            cout << "********  DELETE  *********";
            cout << "\nEnter the word you want to delete: ";
            string s;
            getline(cin, s);
            if (!new_List.any(s))
            {
                cout << "\nThis word is not in the dictionary";
            }
            else
            {
                new_List.deleteWord(s);
                cout << "\nSuccess!";
            }
            int check = toContinue();
            if (check == 1)
                choose = 5;
            else if (check == 2)
                choose = 0;
            else
                choose = 7;
            break;
        }
        case 6:
        {
            system("clear");
            cout << "********    EDIT    *********";
            cout << "\nEnter the word you want to edit: ";
            string data;
            string type;
            string meaning;
            getline(cin, data);
            if (!new_List.any(data))
            {
                cout << "\nThis word is not in the dictionary";
            }
            else
            {
                cout << "\nInput word: " << data;
                Word temp_word = *new_List.search(data);
                cout << "\nWORD\t\tTYPE\t\tMEAN\n";
                cout << temp_word;
                cout << "\nPress\n1. To edit word\n2. To edit type\n3. To edit meaning\nPress any keys else to exit!\nInput: ";
                int edit_what;
                cin >> edit_what;
                getchar();
                switch (edit_what)
                {
                case 1:
                {
                    cout << "\n\nEnter edited word: ";
                    new_List.deleteWord(data);
                    getline(cin, data);
                    temp_word.edit(1, data);
                    new_List.addWord(temp_word);
                    break;
                }
                case 2:
                {
                    cout << "\n\nEnter edited type: ";
                    new_List.deleteWord(data);
                    getline(cin, type);
                    temp_word.edit(2, type);
                    new_List.addWord(temp_word);
                    break;
                }
                case 3:
                {
                    cout << "\n\nEnter edited meaning: ";
                    new_List.deleteWord(data);
                    getline(cin, meaning);
                    temp_word.edit(3, meaning);
                    new_List.addWord(temp_word);
                    break;
                }
                }
            }
            int check = toContinue();
            if (check == 1)
                choose = 6;
            else if (check == 2)
                choose = 0;
            else
                choose = 7;
            break;
        }
        case 7:
        {
            new_List.updateFile();
            cout << "\nGOOD BYE AND SEE YOU LATER!";
            getchar();
            exit(0);
        }
        }
    }
}
