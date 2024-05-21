# <h1 align="center">Laporan Praktikum Modul ALGORITMA SEARCHING</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori

Algoritma pencarian adalah serangkaian langkah terstruktur yang digunakan untuk menemukan item tertentu dalam kumpulan data. Algoritma ini memainkan peran penting dalam berbagai aplikasi, seperti mesin pencari, sistem basis data, dan kecerdasan buatan.

1. Sequential Search: Juga dikenal sebagai linear search, algoritma ini melakukan pencarian secara berurutan dari awal hingga akhir kumpulan data. Setiap elemen dicek satu per satu hingga nilai yang dicari ditemukan atau sampai akhir kumpulan data.

2. Binary Search: Algoritma ini bekerja pada kumpulan data yang sudah terurut. Binary search membagi kumpulan data menjadi dua bagian dan membandingkan nilai yang dicari dengan elemen tengah. Jika nilai tersebut lebih kecil dari elemen tengah, pencarian dilakukan pada setengah kiri kumpulan data, dan sebaliknya.

3. Interpolation Search: Algoritma ini mirip dengan binary search, tetapi digunakan pada kumpulan data yang terurut secara teratur. Interpolation search memprediksi lokasi nilai yang dicari berdasarkan distribusi nilai di kumpulan data, sehingga dapat mengurangi jumlah iterasi yang diperlukan.

4. Ternary Search: Seperti binary search, tetapi algoritma ini membagi kumpulan data menjadi tiga bagian. Kemudian, pencarian dilakukan pada salah satu dari tiga bagian tersebut berdasarkan hasil perbandingan dengan nilai yang dicari.


## Guided 

### 1. Sequential Search

```C++
#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }

    cout << "Program Sequential Search" << endl;
    cout << "data : {9,4,1,7,5,12,4,13,4,10}" << endl;

    if (ketemu)
    {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    }
    else
    {
        cout << "data tidak ditemukan" << endl;
    }

    return 0;
}
```
Kode di atas adalah implementasi dari algoritma Sequential Search yang mencari elemen `10` dalam array `data` yang terdiri dari 10 elemen. Program dimulai dengan mendefinisikan array `data` dan elemen yang akan dicari (`cari`). Sebuah loop `for` digunakan untuk memeriksa setiap elemen dalam array. Jika elemen yang dicari ditemukan, variabel `ketemu` diatur menjadi `true` dan loop berhenti. Setelah loop, program menampilkan pesan apakah elemen ditemukan atau tidak, serta indeks di mana elemen tersebut ditemukan jika ada. Output akhir memberikan informasi tentang keberadaan elemen `10` dalam array `data` dan posisinya jika ditemukan.
## Guided 

### 2. BinerySearch

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort()
{
    int temp, min, i, j;
    for (i = 0; i < 7; i++)
    {
        min = i;
        for (j = i + 1; j < 7; j++)
        {
            if (dataArray[j] < dataArray[min])
            {
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

void binerySearch()
{
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 0;
    while (b_flag && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (dataArray[tengah] == cari)
        {
            b_flag = true;
        }
        else if (dataArray[tengah] < cari)
        {
            akhir = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (b_flag)
    {
        cout << "\nData ditemukan pada indeks ke-" << tengah << endl;
    }
    else
    {
        cout << "\nData tidak ditemukan" << endl;
    }
}

int main()
{
    cout << "Binery Search" << endl;
    cout << "\ndata : ";

    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    cout << "masukkan data yang ingin dicari : ";
    cin >> cari;

    cout << "\nData diurutkan : ";
    selection_sort();

    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    binerySearch();
    _getche();
    return 0;
}
```
Kode di atas adalah implementasi program untuk mencari sebuah elemen dalam array menggunakan metode Binary Search setelah mengurutkannya dengan Selection Sort. Array `dataArray` berisi 7 elemen yang diurutkan menggunakan fungsi `selection_sort`, di mana elemen minimum ditemukan dan ditukar dengan elemen pada indeks saat ini. Setelah array diurutkan, fungsi `binerySearch` (dengan kesalahan penulisan "binarySearch") mencari elemen yang diinginkan (`cari`). Fungsi ini menggunakan metode pencarian biner dengan variabel `awal`, `akhir`, dan `tengah` untuk menentukan posisi elemen yang dicari. Program ini kemudian menampilkan hasil pencarian, apakah data ditemukan beserta indeksnya atau tidak ditemukan sama sekali. Input pengguna diambil untuk menentukan elemen yang dicari dan hasilnya ditampilkan setelah pengurutan dan pencarian selesai.


## Unguided 1

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
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

```
#### Output:
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/dd9e195c-10cb-426c-b029-b056e9fc4b44)


Kode di atas merupakan implementasi dalam C++ untuk mencari sebuah huruf dalam sebuah kalimat yang telah dimasukkan pengguna menggunakan algoritma Binary Search setelah huruf-huruf dalam kalimat diurutkan. Program ini meminta pengguna untuk memasukkan kalimat dan huruf yang ingin dicari. Selanjutnya, program mengubah kalimat menjadi daftar huruf, menghapus spasi, dan mengurutkannya menggunakan fungsi sort(). Setelah itu, dilakukan pencarian menggunakan Binary Search untuk mencari huruf yang diinginkan dalam daftar huruf yang telah diurutkan. Jika huruf tersebut ditemukan, program akan menampilkan indeksnya dalam daftar huruf yang diurutkan, jika tidak, program akan memberi tahu pengguna bahwa huruf tersebut tidak ditemukan dalam kalimat.
## Unguided 2

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
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

```
#### Output:
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/39768799-ad9a-43bd-99da-f39311ea0279)

Kode di atas adalah implementasi dalam C++ untuk menghitung jumlah dan mencatat huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna. Program ini menggunakan fungsi `Vokal_145` untuk memeriksa apakah sebuah karakter adalah huruf vokal, dan kemudian menggunakan fungsi `HitungVocal_145` untuk menghitung jumlah huruf vokal dan mencatat kemunculan masing-masing huruf vokal dalam kalimat. Setelah input kalimat dari pengguna, program akan menampilkan jumlah huruf vokal dalam kalimat serta huruf vokal yang ditemukan beserta jumlah kemunculannya.
## Unguided 

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencari berapa banyak angka 4 dalam data
int HitungAngkaEmpat_145(const vector<int> &data)
{
    int Hitung = 0;
    for (int num : data)
    {
        if (num == 4)
        {
            Hitung++;
        }
    }
    return Hitung;
}

int main()
{
    // Data yang diberikan
    vector<int> data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};

    // Menghitung berapa banyak angka 4 dalam data menggunakan Sequential Search
    int Hitung = HitungAngkaEmpat_145(data);

    // Menampilkan hasil
    cout << "Banyaknya angka 4 dalam data adalah: " << Hitung << endl;

    return 0;
}

```
#### Output:
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/c42eb151-e394-44b7-a171-77a28b762a31)

Kode di atas adalah implementasi dalam C++ untuk menghitung berapa banyak angka 4 dalam sebuah vektor yang telah diberikan. Program ini menggunakan fungsi `HitungAngkaEmpat_145` untuk melakukan iterasi melalui setiap elemen dalam vektor dan menghitung berapa kali angka 4 muncul. Setelah itu, program menampilkan hasil jumlah angka 4 yang ditemukan dalam vektor.
## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
