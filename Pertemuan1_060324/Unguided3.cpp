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
