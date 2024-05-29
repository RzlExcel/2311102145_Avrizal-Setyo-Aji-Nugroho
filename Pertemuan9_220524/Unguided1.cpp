/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int num_nodes;

    // Input jumlah simpul (kota)
    cout << "Silakan masukan jumlah simpul: ";
    cin >> num_nodes;
    cin.ignore(); // Mengabaikan karakter newline setelah input integer

    vector<string> nodes(num_nodes);

    // Input nama simpul (kota)
    cout << "Silahkan Masukkan Nama Simpul\n";
    for (int i = 0; i < num_nodes; ++i)
    {
        cout << "Simpul " << i + 1 << ": ";
        getline(cin, nodes[i]);
    }

    // Inisialisasi matriks adjacency
    vector<vector<int>> adj_matrix(num_nodes, vector<int>(num_nodes, 0));

    // Input bobot antar simpul (kota)
    cout << "Silahkan masukkan bobot antar simpul\n";
    for (int i = 0; i < num_nodes; ++i)
    {
        for (int j = 0; j < num_nodes; ++j)
        {
            cout << nodes[i] << "-->" << nodes[j] << ": ";
            cin >> adj_matrix[i][j];
        }
    }

    // Menampilkan matriks adjacency
    cout << "\n";
    cout << setw(8) << "";
    for (int i = 0; i < num_nodes; ++i)
    {
        cout << setw(8) << nodes[i];
    }
    cout << endl;

    for (int i = 0; i < num_nodes; ++i)
    {
        cout << setw(8) << nodes[i];
        for (int j = 0; j < num_nodes; ++j)
        {
            cout << setw(8) << adj_matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
