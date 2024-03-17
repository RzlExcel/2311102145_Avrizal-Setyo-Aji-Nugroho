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
