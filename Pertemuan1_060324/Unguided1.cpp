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