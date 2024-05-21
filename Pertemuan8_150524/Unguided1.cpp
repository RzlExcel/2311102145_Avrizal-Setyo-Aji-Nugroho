/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk melakukan binary search
int binarySearch(const vector<char> &arr, char x)
{
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return -1;
}

int main()
{
    string Kalimat_145;
    char MencariHuruf;

    // Input dari pengguna
    cout << "Masukkan kalimat: ";
    getline(cin, Kalimat_145);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> MencariHuruf;

    // Menghapus spasi dan mengubah kalimat menjadi daftar huruf
    vector<char> ListHuruf;
    for (char c : Kalimat_145)
    {
        if (c != ' ')
        {
            ListHuruf.push_back(c);
        }
    }

    // Mengurutkan daftar huruf
    sort(ListHuruf.begin(), ListHuruf.end());
    cout << "Huruf-huruf yang diurutkan: ";
    for (char c : ListHuruf)
    {
        cout << c << ' ';
    }
    cout << endl;

    // Menggunakan Binary Search untuk mencari karakter
    int result = binarySearch(ListHuruf, MencariHuruf);

    if (result != -1)
    {
        cout << "Karakter \"" << MencariHuruf << "\" ditemukan pada indeks " << result << " dalam array terurut." << endl;
    }
    else
    {
        cout << "Karakter \"" << MencariHuruf << "\" tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}
