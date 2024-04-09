# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori

Hash Table adalah data structure yang digunakan untuk mengorganisasi data dengan efisiensi tinggi. Hash Table menggunakan fungsi hash untuk menghasilkan key yang unik dan memastikan bahwa setiap key hanya tersedia satu kali. Jika key yang sama ditemukan, akan terjadi kolisi, yang akan menyebabkan waktu akses lebih lama. Jika fungsi hash yang digunakan adalah baik, kemungkinan kolisi dapat menjadi kecil atau tidak terjadi. Hash Table dapat dibuat dengan beberapa desain, termasuk separate chaining, linear probing, dan quadratic probing : <br><br>
-Separate chaining menggunakan list untuk menyimpan data yang memiliki key yang sama<br>
-linear probing menggunakan algoritma probing untuk mencari lokasi yang tersedia untuk menyimpan data <br>
-quadratic probing menggunakan algoritma probing yang berbeda <br><br>
Hash Table dapat digunakan dalam berbagai aplikasi, mulai dari sistem operasi, database, hingga aplikasi web. Hash Table memiliki beberapa variasi, termasuk open addressing dan closed addressing. <br>
-Open addressing menggunakan algoritma hash untuk mencari lokasi yang tersedia untuk menyimpan data<br> 
-sedangkan closed addressing menggunakan algoritma hash untuk mencari lokasi yang tidak tersedia untuk menyimpan data. 


## Guided 

### 1. Hash Table

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value),
                               next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Guided 

### 2. Hash Table

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode
{
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name,
                                               phone_number));
    }
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it !=
                                                table[hash_val].end();
             it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl
         << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.



## Unguided 

 
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/cabe2547-3be2-4224-a835-d5d8578b2ff1)



```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Struktur data untuk setiap node
struct Node
{
    string NIM;
    string nama;
    int nilai;
    Node *next;
    Node(string NIM, string nama, int nilai) : NIM(NIM), nama(nama), nilai(nilai), next(nullptr) {}
};

// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }

    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Fungsi hash sederhana
    int hash_func(string NIM)
    {
        int sum = 0;
        for (char c : NIM)
        {
            sum += c;
        }
        return sum % MAX_SIZE;
    }

    // Fungsi Menginputkan data
    void insert(string NIM, string nama, int nilai)
    {
        int index = hash_func(NIM);
        Node *newNode = new Node(NIM, nama, nilai);
        if (table[index] == nullptr)
        {
            table[index] = newNode;
        }
        else
        {
            Node *current = table[index];
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Fungsi untuk menghapus data
    void remove(string NIM)
    {
        int index = hash_func(NIM);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Data Ra ene NIM: " << NIM << endl;
    }

    // Fungsi mencari  data berdasarkan NIM
    void searchByNIM(string NIM)
    {
        int index = hash_func(NIM);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                cout << "Data ditemukan - NIM: " << current->NIM << ", Nama: " << current->nama << ", Nilai: " << current->nilai << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data Ra ene NIM: " << NIM << endl;
    }

    // Fungsi mencari data  berdasarkan nilai
    void searchByRange()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                if (current->nilai >= 80 && current->nilai <= 90)
                {
                    cout << "NIM: " << current->NIM << ", Nama: " << current->nama << ", Nilai: " << current->nilai << endl;
                }
                current = current->next;
            }
        }
    }

    // Menampilkan semua data mahasiswa
    void displayAllData()
    {
        cout << "Data Mahasiswa:\n";
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << "NIM: " << current->NIM << ", Nama: " << current->nama << ", Nilai: " << current->nilai << endl;
                current = current->next;
            }
        }
    }

    // Menampilkan menu pilihan
    void displayMenu()
    {
        cout << "Menu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cari berdasarkan NIM\n";
        cout << "4. Cari berdasarkan rentang nilai (80-90)\n";
        cout << "5. Tampilkan data mahasiswa\n";
        cout << "6. Keluar\n";
    }
};

int main()
{
    HashTable hashTable;

    int choice;
    string NIM, nama;
    int nilai;

    do
    {
        hashTable.displayMenu();
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Inputkan NIM: ";
            cin >> NIM;
            cout << "Inputkan Nama: ";
            cin >> nama;
            cout << "Inputkan Nilai: ";
            cin >> nilai;
            hashTable.insert(NIM, nama, nilai);
            break;
        case 2:
            cout << "Inputkan NIM yang ingin dihapus: ";
            cin >> NIM;
            hashTable.remove(NIM);
            break;
        case 3:
            cout << "Inputkan NIM yang ingin dicari: ";
            cin >> NIM;
            hashTable.searchByNIM(NIM);
            break;
        case 4:
            cout << "Data dengan nilai antara 80-90:\n";
            hashTable.searchByRange();
            break;
        case 5:
            hashTable.displayAllData();
            break;
        case 6:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Tidak Valid, yang bener aje rugi dong.\n";
        }
    } while (choice != 6);

    return 0;
}
```
#### Output:
![Screenshot%20(52).png](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
