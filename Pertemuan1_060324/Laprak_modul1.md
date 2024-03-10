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
Kode di atas adalah program sederhana dalam bahasa C++ yang meminta pengguna memasukkan operator(+,-,*,/) dan dua operand. Program kemudian menggunakan struktur switch case untuk mengevaluasi operator tersebut dan melakukan operasi aritmatika yang sesuai. Dan program pembagian memeriksa agar operand kedua tidak nol untuk menghindari kesalahan pembagian. Setelah melakukan operasi aritmatika hasil akan ditampilkan oleh cout. Jika program tidak valid maka program akan mengirim pesan kesalahan  

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
Kode di atas menggunakan tipe data absrak dalam bentuk struct untuk memprensentasikan informasi mahasiswa. Dua variable struct 'mhs1' dan 'mhs2' dibuat untuk menyimpan data mahasiswa. Nilai-nilai tersebut diisi dengan fungsi 'strcpy' dan kemudian dicetak menggunakan 'printf'.

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
Kode di atas menunjukan tipe data koleksi, khususnya array. Dalam program ini, array 'nilai' yang terdiri dari 5 elemen bertipe int(integer) dideklarasikan dan di isi dengan nilai tertentu. Kemudian Dicetak menggunakan 'cout'.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas.Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
using namespace std;
//fungsi menghitung luas segitiga
float luassegitiga145(float alas, float tinggi){
    return 0.5*alas*tinggi;
}
//fungsi mencari keliling segitiga
float kelsegitiga145(float sisi1, float sisi2, float sisi3){
    return sisi1+sisi2+sisi3;
}

int main() {
    float sisi1,sisi2,sisi3;// variable untuk menyimpan sisi segitiga
    // menginputkan angka
    cout <<"Masukkan panjang sisi 1 : ";
    cin >> sisi1;
    cout <<"Masukkan panjang sisi 2 : ";
    cin >> sisi2;
    cout <<"Masukkan panjang sisi 3 : ";
    cin >> sisi3;
    //menghitung dan menampilkan luas dan keliling segitiga
    float Luas145 = luassegitiga145(sisi1,sisi2);
    cout << "Luas segitiga : " << Luas145 << endl;
    float kel145 = kelsegitiga145(sisi1,sisi2,sisi3);
    cout << "keliling segitiga : " << kel145 << endl;

    return 0;
}
```
#### Output:
![Unguided1](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan1_060324/OUTPUT%20unguided%201%20md1.png?raw=true)

Kode di atas adalah program yang menggunakan tipe data primitif 'float' dengan 2 fungsi.fungsi pertama adalah mengitung luas segitiga dan fungsi kedua adalah menghitung keliling segitiga

## Unguided 

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

```C++
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
```
#### Output:
![Unguided2](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan1_060324/OUTPUT%20unguided%202%20md1.png?raw=true)

Kode di atas digunakan untuk mendefisinikan struct 'Character145' yang mempresentasikan atribut seperti nama, level, healt point, attach, crit rate, dan crit damage. Selain itu program mendefisinikan class 'Build145' yang menggunakn 'tampilkaninfo()' untuk menamp-ilkan informasi karakter yang diberikan. Dalam fungsi 'main()',objek 'karakter' dari class 'Build145' dibuat, dan sebuah objek 'Info1' dari struct 'Character145' diinisialisasi dengan nilai-nilai yang sesuai dengan karakter bernama "Yoimiya". Kemuadian 'tampilkaninfo()' dipanggil untuk menampilkan informasi karakter "Yoimiya".

## Unguided 

### 3. Buat dan jelaskan progaram menggunakan fungsi map dan jelaskan perbedaan dari array map

```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <map>
using namespace std;


int main() {
    // deklarasi map dengan string dan int
    map<string, int> Stokbarang145;
    Stokbarang145["celana"]=110;
    Stokbarang145["jaket"]=80;
    Stokbarang145["kaos kaki"]=100;
    Stokbarang145["kemeja"]=150;
    Stokbarang145["sepatu"]=100;
    Stokbarang145["topi"]=50;

    cout <<"Stok barang di toko sheesh"<< endl;
    // looping dan menampilkan elemen map
    int i = 1;
    for (const auto& pair : Stokbarang145) {
        cout << i << " " << pair.first << ": " << pair.second << endl;
        i++;
    }
    return 0;
}

```
#### Output:
![Unguided3](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan1_060324/OUTPUT%20unguided%203%20md1.png?raw=true)

Kode di atas mendemostrasikan tipe data koleksi 'map',yang digunakan untuk menyimpan pasangan kunci nilai. Map 'Stokbarang145' dideklarasikan dengan tipe data string sebangai kunci dan integer sebagai nilai. Kemudian diloop menggunakan 'for' dan hasilnya adalah daftar stok barang yang diurut berdasarkan nama dengan nomor urut yang ditampilkan.

## Kesimpulan
Tipe data adalah komponen penting untuk menyimpan infomasi dalam C++, yang memungkinkan program untuk bekerja dengan nilai numerik, karakter, dan keadaan logis. Tipe data C++ memberikan fleksibilitas untuk menyimpan dan mengelola data dalam program dengan efisien.
## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
