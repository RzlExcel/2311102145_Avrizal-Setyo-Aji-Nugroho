# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
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
#include <iomanip>

using namespace std;
// Tipe Data Primitif
int main (){
    char op;
    float num1, num2;

    cout<< "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "enter two oprands: ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '+':
        cout << "Result: " << num1 + num2;
        break;
    case '-':
        cout << "Result: " << num1 - num2;
        break;
     case '*':
        cout << "Result: " << num1 * num2;
        break;
    case '/':
        if (num2 != 0){
            cout << "Result: "<< fixed << setprecision(2) << num1 / num2;
        } else{
            cout << "Error! Division by zero is not allowed.";
        }
        break;
    default:
    cout << "Error! Operator is not correct";
        break;
    }
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Guided 

### 2. Tipe data Abstrak

```C++
#include <stdio.h>
#include <string.h>
// Tipe data Abstrak
// Struct
struct Mahasiswa
{
char name[50];
char address[100];
int age;
};
int main()
{
   // Menggunakan Struct
struct Mahasiswa mhs1, mhs2;
// Mengisi nilai ke struct
strcpy(mhs1.name, "Dian");
strcpy(mhs1.address, "Mataram");
mhs1.age = 22;
strcpy(mhs2.name, "Bambang");
strcpy(mhs2.address, "Surabaya");
mhs2.age = 23;

// Mencetak isi dari struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name);
printf("Alamat: %s\n", mhs1.address);
printf("Umur: %d\n", mhs1.age);
printf ("\n");
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name);
printf("Alamat: %s\n", mhs2.address);
printf("Umur: %d\n", mhs2.age);
return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Guided 

### 3. Tipe data Koleksi

```C++
#include <iostream>
#include <array>
//Tipe data koleksi
using namespace std;
int main() {
// Deklarasi dan inisialisasi array
int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;

// Mencetak array dengan tab

cout << "Isi array pertama : " << nilai[0] << endl;
cout << "Isi array kedua : " << nilai[1] << endl;
cout << "Isi array ketiga : " << nilai[2] << endl;
cout << "Isi array keempat : " << nilai[3] << endl;
cout << "Isi array kelima : " << nilai[4] << endl;
return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

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
