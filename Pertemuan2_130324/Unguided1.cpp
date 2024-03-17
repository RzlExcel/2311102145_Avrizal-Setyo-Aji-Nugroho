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
