# <h1 align="center">Laporan Praktikum Modul ALGORITMA SEARCHING</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori

Tipe data adalah klasifikasi value suatu variabel yang membantu operasi komputer untuk mengenali nilai data tanpa menghasilkan output error. Pada dasarnya, komputer hanya memahami bahasa biner (binary language) yaitu 1 dan 0. Agar komputer melakukan operasi yang lebih kompleks, perlu adanya tipe data yang bisa dipahami bahasa komputer atau bahasa pemrograman.

1. Tipe data Primitif
   Tipe data primitif adalah tipe data dasar yang banyak digunakan bahasa pemrogaman contohnya:
   <div>a.int(Integer)<div>
   b.float <div>
   c.char <div>
   d.boolean <div>
   e.double <div>
2. Tipe data abstrak
   tipe data abstrak atau lebih dikenal dengan istilah ADT(Abstract Data Types) adalah tipe        data yang bergantung dengan tipe data dan serangkaian operasi yang dilakukan sesuai dengan      input dan output pada software.
3. Tipe data koleksi(collection)
   adalah tipe data dengan jumlah data yang dinamis. misalkan tipe data integer, yang terdiri dari banyak variabel. kemuan variabel tersebut disimpan dalan suatu tempat. Dalam bahasa c++ disebut dengan array, vektor, dan map.


## Guided 

### 1. Tipe data primitif

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

### 2. Tipe data Abstrak

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


## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas.Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
```
#### Output:
![Screenshot%20(52).png](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 3. Buat dan jelaskan progaram menggunakan fungsi map dan jelaskan perbedaan dari array map

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
