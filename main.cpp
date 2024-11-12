#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <string>
#include <tuple>
#include <utility>
#include <map>

using namespace std;
using namespace std::__fs::filesystem;
bool adm = false;
vector<pair<string, int>> library;
map<string, vector<pair<string,int>>> pinjaman;
int pinjam_buku;


string cap(string a)
{
    for (int i = 0; i < a.size(); i++)
    {
        
        a[i] = tolower(a[i]);
        
    }
    return a;
};



void signup()
{
    cout << "Enter your username: " << endl;
    string name;
    cin >> name;
    cout << "Make a password: " << endl;
    string pass;
    cin >> pass;
    string filename = cap(name) + ".txt";
    if (exists(filename))
    {
        cout << "Username already exists" << endl;
    }
    else
    {
        ofstream f(filename);
        f << pass;
        cout << "Signup successful" << endl;
    }
}
string name;
bool login()
{
    cout << "\033[2J\033[1;1H";
    cout << "Enter your username: " << endl;
    
    cin >> name;
    cout << "Make a password: " << endl;
    string pass;
    cin >> pass;
    string filename = cap(name) + ".txt";

    ifstream test(filename);
    string read;
    string admin = "admin";

    getline(test, read);
    if (exists(filename))
    {
        if (read == pass)
        {
            cout << "Welcome" << endl;
            return true;
        }
        else if (read == pass && filename.find(cap(admin)) != string::npos)
        {
            adm = true;
            return true;
        }
        else
        {
            cout << "Wrong password" << endl;
        }
    }
    else
    {
        cout << "Username does not exists" << endl;
    }
    return false;
}







void view(){
    cout << "\033[2J\033[1;1H";
    cout << "Library\n";
    if (library.size() == 0){
        cout << "Empty\n";
    }
    else{
        for (int i = 0;i < library.size();i++){
            cout << i+1 << ". " << library[i].first << " Status: " << (library[i].second == 1 ? "Availabe" : "Borrowed") << endl;
        }
    }
}



void pinjam(){
    cout << "\033[2J\033[1;1H";
    view();
    cout << "Which book would you like to borrow: \n";

    
    cin >> pinjam_buku;
    if (library[pinjam_buku-1].second == 0){
        cout << "Book is not available\n";
        cout << "Press Enter to continue...";
cin.ignore();
cin.get();
    }
    else{
    library[pinjam_buku-1].second -= 1;
    pinjaman[name].emplace_back(library[pinjam_buku-1].first,pinjam_buku-1);
    cout << "Book has been borrowed successfuly\n";
    cout << "Press Enter to continue...";
cin.ignore();
cin.get();
    }
}
void kembalikan() {
    cout << "\033[2J\033[1;1H";
    if (pinjaman[name].empty()) {
        cout << "No book has been borrowed\n";
        cout << "Press Enter to continue...";
cin.ignore();
cin.get();
        return;
    }

    for (int i = 0; i < pinjaman[name].size(); i++) {
        cout << i + 1 << ". " << pinjaman[name][i].first << endl;
    }

    cout << "Which book would you like to return: ";
    int kembali;
    cin >> kembali;

    if (kembali > 0 && kembali <= pinjaman[name].size()) {
        int book_idx = pinjaman[name][kembali - 1].second;
        library[book_idx].second += 1;
        pinjaman[name].erase(pinjaman[name].begin() + kembali - 1);
        cout << "Book returned successfully.\n";
        cout << "Press Enter to continue...";
cin.ignore();
cin.get();
    } else {
        cout << "Invalid choice.\n";
    }
}


void tambah(){
    cout << "\033[2J\033[1;1H";
    cout << "Enter the book title: \n";
    string title;
    cin >> title;
    library.push_back(make_pair(title,1));
    cout << "Book is successfuly added to the library\n";
    cout << "Press Enter to continue...";
cin.ignore();
cin.get();
}

void upd(){
    cout << "\033[2J\033[1;1H";
    view();
    cout << "Which book title do you want to update: \n";
    int choice;
    cin >> choice;
    if(choice > 0 && choice <= library.size()){
        cout << "Enter the new title\n";
        string title;
        cin >> title;
        library[choice-1].first = title;
        cout << "Title is updated sucessfuly";
        cout << "Press Enter to continue...";
cin.ignore();
cin.get();
    }
}

void ers(){
    cout << "\033[2J\033[1;1H";
    view();
    cout << "Which book title do you want to delete: \n";
    int choice;
    cin >> choice;
    if(choice > 0 && choice <= library.size()){
        library.erase(library.begin()+choice-1);
        cout << "Title is updated sucessfuly";
        cout << "Press Enter to continue...";
cin.ignore();
cin.get();
    }
}








void menu() {
    cout << "\033[2J\033[1;1H";
    while (true) {
        cout << "1. Signup\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            signup();
        } else if (choice == 2) {
            if (login()) {
                if (adm) {
                    
                    while (true) {
                        cout << "\nAdmin Menu:\n";
                        cout << "1. View Books\n";
                        cout << "2. Add New Book\n";
                        cout << "3. Delete Book\n";
                        cout << "4. Update Book Title\n";
                        cout << "5. Logout\n";
                        cout << "Choice: ";
                        cin >> choice;

                        if (choice == 1) view();
                        else if (choice == 2) tambah();
                        else if (choice == 3) ers();
                        else if (choice == 4) upd();
                        else if (choice == 5) break; 
                        else cout << "Invalid choice. Try again.\n";
                    }
                } else {
                   
                    while (true) {
                        cout << "\nUser Menu:\n";
                        cout << "1. View Books\n";
                        cout << "2. Borrow Book\n";
                        cout << "3. Return Book\n";
                        cout << "4. Logout\n";
                        cout << "Choice: ";
                        cin >> choice;

                        if (choice == 1) view();
                        else if (choice == 2) pinjam();
                        else if (choice == 3) kembalikan();
                        else if (choice == 4) break; 
                        else cout << "Invalid choice. Try again.\n";
                    }
                }
            }
        } else if (choice == 3) {
            cout << "Exiting the program. Goodbye!\n";
            break; 
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}






int main()
{
    library.push_back(make_pair("The Great Gatsby", 1));
    library.push_back(make_pair("1984", 1));
    library.push_back(make_pair("To Kill a Mockingbird", 1));
    library.push_back(make_pair("Moby Dick", 1));
    menu();
    return 0;
    

}