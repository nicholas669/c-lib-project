#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>> anag;
vector<string> name;

void game(){
    cout << "Mau berapa banyak kata yang di anagram?: \n";
    int choice;
    cin >> choice;
    for (int i = 0;i < choice;i++){
        cout<< "Masukkan kata ke " << i+1 << " : \n";
        string word;
        cin >> word;
        string ori = word;
        auto start = word.begin();
        auto last = word.end();
        sort(start,last);
        anag[word].push_back(ori);
        name.push_back(word);
    }

}
int main(){
    game();
    for (const auto& pair : anag) {
        cout << "Anagram group for: " << pair.first << "\n";
        for (const string& word : pair.second) {
            cout << word << " ,";
        }
        cout << "\n";
    } 
}

