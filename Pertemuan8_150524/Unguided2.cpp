/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

// Fungsi untuk memeriksa apakah sebuah karakter adalah vokal
bool Vokal_145(char c)
{
    // Mengubah karakter menjadi huruf kecil untuk memudahkan pemeriksaan
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Fungsi untuk menghitung banyaknya huruf vokal dan mencatat huruf vokal yang diinput
pair<int, map<char, int>> HitungVocal_145(const string &Kalimat)
{
    int Hitung = 0;
    map<char, int> VokalFound;
    for (char c : Kalimat)
    {
        if (Vokal_145(c))
        {
            Hitung++;
            VokalFound[tolower(c)]++;
        }
    }
    return make_pair(Hitung, VokalFound);
}

int main()
{
    string Kalimat;
    cout << "=========================================\n";
    cout << "  TEMUKAN HURUF VOKAL DALAM KALIMAT\n";
    cout << "=========================================\n";

    // Input dari pengguna
    cout << "Masukkan kalimat: ";
    getline(cin, Kalimat);

    // Menghitung banyaknya huruf vokal dan mencatat huruf vokal yang diinput
    pair<int, map<char, int>> result = HitungVocal_145(Kalimat);

    // Menampilkan hasil
    cout << "Jumlah huruf vokal dalam kalimat adalah: " << result.first << endl;
    cout << "Huruf vokal yang ditemukan dalam kalimat: ";
    for (const auto &pair : result.second)
    {
        cout << pair.first << " (" << pair.second << "), ";
    }
    cout << endl;

    return 0;
}
