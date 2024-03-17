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
