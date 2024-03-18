# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori

Proses update


## Guided 

### 1. Tipe data primitif

```C++
#include <iostream>
using namespace std;

int main() {
    // Deklarasi array
    int arr[2][3][3];

    // Input elemen
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Guided 

### 2. Tipe data Abstrak

```C++
#include <iostream>

using namespace std;
int main() { 
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array : ";
    cin >> a;

    int array[a];
    cout << "Masukkan " << a << " 3angka : \n";
    
    for (i =0; i < a; i++){
        cout << "Array ke-" << (i) <<": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i= 0; i <a; i++){
        if (array[i] > maks){
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada ke-"<< lokasi << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.


## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas.Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    //Menentukan ukuran maksimumarray yang digunakan dalam program
    const int MXSize_145 = 100;

    int bilangan[MXSize_145];//Deklarasi untuk menyimpan elemen array
    int n;// variabel untuk menyimpan data array yang dimasukkan oleh User

    // memintan user meng inputkan data array
    cout << "Masukkan jumlah elemen data array: ";
    cin >> n;

    // meminta user menginputkan elemen-elemen array
    cout << "Masukkan data array: ";
    for (int i = 0; i < n; ++i) {
        cin >> bilangan[i];
    }

    // deklarasi array untuk menyimpan ganjil genap
    int bil_genap[MXSize_145];
    int bil_ganjil[MXSize_145];
    // variable untu menghitung jumlah bilangan ganjil genap
    int count_genap = 0, count_ganjil = 0;
    // memisahkan bilangan ganjil genap dari array
    for (int i = 0; i < n; ++i) {
        if (bilangan[i] % 2 == 0) {
            bil_genap[count_genap++] = bilangan[i];
        } else {
            bil_ganjil[count_ganjil++] = bilangan[i];
        }
    }
    // Menampilkan bilangan genap
    cout << "Nomor Genap: ";
    if (count_genap > 0) {
        for (int i = 0; i < count_genap; ++i) {
            cout << bil_genap[i];
            if (i != count_genap - 1) {
                cout << ", ";
            }
        }
    } else {
        cout << "Tidak ada";
    }
    cout << endl;
    // menampilkan bilangan ganjil
    cout << "Nomor Ganjil: ";
    if (count_ganjil > 0) {
        for (int i = 0; i < count_ganjil; ++i) {
            cout << bil_ganjil[i];
            if (i != count_ganjil - 1) {
                cout << ", ";
            }
        }
    } else {
        cout << "Tidak ada";
    }
    cout << endl;

    return 0;
}

```
#### Output:
![Unguided1](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan1_060324/OUTPUT%20unguided%201%20md1.png?raw=true)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
using namespace std;

int main() {
    //variable untuk menyimpan ukuran elemen array tiga dimensi
    int x_size145, y_size145, z_size145;

    // user menginputkan ukuran elemen array tiga dimensi
    cout << "Masukkan ukuran elemen array tiga dimensi (x y z): ";
    cin >> x_size145 >> y_size145 >> z_size145;

    // mendeklarasikan array dengan ukuran yang dimasukkan user
    int arr[x_size145][y_size145][z_size145];

    // loop untuk mengisi elemen array dengan data yang diinputkan user
    for (int x = 0; x < x_size145; x++) {
        for (int y = 0; y < y_size145; y++) {
            for (int z = 0; z < z_size145; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // loop untuk menampilkan elemen array berserta indeksnya
    for (int x = 0; x < x_size145; x++) {
        for (int y = 0; y < y_size145; y++) {
            for (int z = 0; z < z_size145; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    //loop untuk menampilkan elemen array dalam format tiga dimensi
    for (int x = 0; x < x_size145; x++) {
        for (int y = 0; y < y_size145; y++) {
            for (int z = 0; z < z_size145; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

```
#### Output:
![Unguided2](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan2_130324/Unguided2modul2pt1.png?raw=true)
![Unguided2](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan2_130324/Unguided2modul2pt2.png?raw=true)
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 3. Buat dan jelaskan progaram menggunakan fungsi map dan jelaskan perbedaan dari array map

```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
using namespace std;

int main() {
    
    //Menentukan ukuran maksimumarray yang digunakan dalam program
    const int MX_SIZE145 = 100;
    int arr[MX_SIZE145];// mendeklarasi array untuk menyimpan elemen array
    int n;//variable untuk menyimpan jumlah elemen array yang diinput user

    cout << "Masukkan jumlah elemen array: ";//user diminta menginputkan jumlah array
    cin >> n;

    cout << "Masukkan elemen array: ";//user menginputkan elemen array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int pilih;// variable menyimpan pilihan yang akan digunakan user
    do {
        cout << "\nMenu:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Cari nilai rata-rata\n";
        cout << "0. Keluar\n";
        cout << "Pilih operasi yang ingin dilakukan: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                // mencari nilai maksimum array
                int maksimum = arr[0];
                for (int i = 1; i < n; ++i) {
                    if (arr[i] > maksimum) {
                        maksimum = arr[i];
                    }
                }
                cout << "Nilai maksimum: " << maksimum << endl;
                break;
            }
            case 2: {
                // mencari nilai minimum array
                int minimum = arr[0];
                for (int i = 1; i < n; ++i) {
                    if (arr[i] < minimum) {
                        minimum = arr[i];
                    }
                }
                cout << "Nilai minimum: " << minimum << endl;
                break;
            }
            case 3: {
                // mencari nilai rata-rata array
                int total = 0;
                for (int i = 0; i < n; ++i) {
                    total += arr[i];
                }
                double rata_rata = static_cast<double>(total) / n;
                cout << "Nilai rata-rata: " << rata_rata << endl;
                break;
            }
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 0);

    return 0;
}

```
#### Output:
![Unguided1](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan2_130324/Unguided3modul2pt1.png?raw=true)
![Unguided1](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan2_130324/Unguided3modul2pt2.png?raw=true)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
