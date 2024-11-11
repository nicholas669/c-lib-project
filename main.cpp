#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <string>
#include <tuple>
#include <utility>

using namespace std;
using namespace std::__fs::filesystem;
bool adm = false;


string cap(string a){
  for(int i = 0; i < a.size();i++){
    if (i == 0){
      a[i] = toupper(a[i]);
    }
  }
  return a;
};

vector<pair<string,string>> books;
// pastikan sudah buat repo onlinenya
// git init .
// git branch -M main
// git add .
// git commit -m "nama terserah"
// git remote add origin namalink
// git push -u origin main




void signup(){
    cout << "Enter your username: " << endl;
    string name;
    cin >> name;
    cout << "Make a password: " << endl;
    string pass;
    cin >> pass;
    string filename = cap(name) + ".txt";
    if (exists(filename)){
        cout << "Username already exists" << endl;
    }
    else{
        ofstream f(filename);
        f << pass;
        cout << "Signup successful" << endl;
    }
}
bool login(){
    cout << "Enter your username: " << endl;
    string name;
    cin >> name;
    cout << "Make a password: " << endl;
    string pass;
    cin >> pass;
    string filename = cap(name) + ".txt";

    ifstream test(filename);
    string read;
    string admin = "admin";

    getline(test,read);
    if (exists(filename)){
        if (read == pass){
            cout << "Welcome" << endl;
            return true;
        }
        else if (read == pass && filename.find(cap(admin)) != string::npos){
            adm = true;
            return true;
        }
        else{
            cout << "Wrong password" << endl;
        }
    }
    else{
        cout << "Username does not exists" << endl;
    }
    return false;

}

void user_func(){
    cout << "1. Pinjam buku\n";
    cout << "2. Kembalikan buku\n";
    cout << "3. Logout\n";

}









void menu(){
    cout << "1. Signup" << endl;
    cout << "2. Login" << endl;
    cout << "Choice: " << endl;
    int choice;
    cin >> choice;
    if (choice == 1){
        signup();
    }
    else if (choice == 2){
        login();
        if (login()){
        }
    }
}









int main(){
    // while (true){
    //     menu();
    // }
    string mainString = "Hello, world!";
    string subString = "world";

    
    


}