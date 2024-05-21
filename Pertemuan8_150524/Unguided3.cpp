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
