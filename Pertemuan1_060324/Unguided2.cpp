/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <string>
using namespace std;

// Definisi struct untuk merepresentasikan karakter
struct Character145 {
    string Nama;
    string Level;
    int HP;
    int attack;
    string Critrate;
    string Critdamage;
};

// Definisi class untuk menampilkan informasi karakter
class Build145 {
public:
    void tampilkanInfo(Character145 Info) {
        cout << "Nama character : " << Info.Nama << endl;
        cout << "Level : " << Info.Level << endl;
        cout << "Healt Point : " << Info.HP << endl;
        cout << "Attack : " << Info.attack << endl;
        cout << "Crit rate : " << Info.Critrate << endl;
        cout << "Crit damage : " << Info.Critdamage << endl;
    }
};

int main() {
    // Deklarasi build145
    Build145 karakter;
    // Deklarasi character145
    Character145 Info1 = {"Yoimiya", "90/90", 18573, 2246, "75,9%", "210,2%"};
    // Deklarasi class dan struct
    karakter.tampilkanInfo(Info1);

    return 0;
}