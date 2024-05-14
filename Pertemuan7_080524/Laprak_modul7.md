# <h1 align="center">Laporan Praktikum Modul QUEUE</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori




## Guided 

### 1. QUEUE

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan
bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}
int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}
void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
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
Kode di atas merupakan implementasi sederhana dari struktur data antrian (queue). Program ini memiliki fungsi dasar seperti enqueue (menambah elemen), dequeue (menghapus elemen), clearQueue (menghapus semua elemen), isEmpty (mengecek apakah antrian kosong atau penuh), countQueue (menghitung jumlah elemen dalam antrian), dan viewQueue (menampilkan elemen dalam antrian). Dengan menambah, menghapus, dan membersihkan antrian, operasi-operasi tersebut diuji dalam fungsi utama.



## Unguided 1
## Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list


```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

// Class Queue menggunakan linked list
class Queue
{
private:
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = nullptr;
        back = nullptr;
    }

    // Fungsi untuk mengecek apakah queue kosong
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Fungsi untuk menambahkan data ke dalam queue
    void enqueue(string data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }

    // Fungsi untuk menghapus data dari queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    // Fungsi untuk melihat data yang ada di queue
    void viewQueue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
            return;
        }
        cout << "Data antrian teller:" << endl;
        Node *current = front;
        int position = 1;
        while (current != nullptr)
        {
            cout << position << ". " << current->data << endl;
            current = current->next;
            position++;
        }
    }

    // Fungsi untuk menghitung jumlah data di queue
    int countQueue()
    {
        int count = 0;
        Node *current = front;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi untuk membersihkan queue
    void clearQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    Queue queue; // Membuat objek queue

    queue.enqueue("Andi");
    queue.enqueue("Maya");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.dequeue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/76481400-569f-41f1-b970-f4b01dcc0f62)


Kode di atas menunjukkan penggunaan linked list dalam bahasa C++ untuk menjalankan struktur data antrian (queue). Setiap elemen dalam antrian diwakili sebagai simpul (node) yang terhubung satu sama lain. Kelas antrian memiliki fungsi dasar seperti menambah atau menghapus elemen; menampilkan antrian (menampilkan elemen dalam antrian); menghitung antrian (menghitung jumlah elemen dalam antrian); dan clearQueue (menghapus semua elemen dalam antrian). Beberapa operasi seperti penambahan, penghapusan, dan pembersihan antrian dilakukan untuk memeriksa fungsi main function.

## Unguided 2
## Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa



```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
using namespace std;

struct MahasiswaNode
{
    string nama;
    string nim;
    MahasiswaNode *next;
};

// Class Queue menggunakan linked list untuk Mahasiswa
class MahasiswaQueue
{
private:
    MahasiswaNode *front;
    MahasiswaNode *back;

public:
    MahasiswaQueue()
    {
        front = nullptr;
        back = nullptr;
    }

    // Fungsi untuk mengecek apakah queue kosong
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Fungsi untuk menambahkan data Mahasiswa ke dalam queue
    void enqueue(string nama, string nim)
    {
        MahasiswaNode *newNode = new MahasiswaNode();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }

    // Fungsi untuk menghapus data Mahasiswa dari queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
            return;
        }
        MahasiswaNode *temp = front;
        front = front->next;
        delete temp;
    }

    // Fungsi untuk melihat data Mahasiswa yang ada di queue
    void viewQueue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
            return;
        }
        cout << "Data antrian mahasiswa:" << endl;
        MahasiswaNode *current = front;
        int position = 1;
        while (current != nullptr)
        {
            cout << position << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            position++;
        }
    }

    // Fungsi untuk menghitung jumlah data Mahasiswa di queue
    int countQueue()
    {
        int count = 0;
        MahasiswaNode *current = front;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi untuk membersihkan queue
    void clearQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    MahasiswaQueue queue;

    char tambahLagi;
    do
    {
        string nama, nim;
        cout << "Masukkan nama mahasiswa: ";
        getline(cin, nama);
        cout << "Masukkan NIM mahasiswa: ";
        getline(cin, nim);
        queue.enqueue(nama, nim);

        cout << "Apakah ingin menambahkan mahasiswa lagi? (y/n): ";
        cin >> tambahLagi;
        cin.ignore();
    } while (tambahLagi == 'y' || tambahLagi == 'Y');

    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}

```
#### Output:
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/4966deda-191e-4d7e-bce7-bae0f88e28e7)


Kode di atas menjalankan struktur data antrian (queue) menggunakan daftar terhubung untuk menampilkan data Mahasiswa dalam bahasa C++. Program meminta pengguna memasukkan nama dan NIM Mahasiswa secara berulang hingga mereka tidak ingin menambahkan lagi. Setelah semua data Mahasiswa dimasukkan ke dalam antrian, program akan menampilkan daftar Mahasiswa bersama dengan jumlah Mahasiswa yang ada dalam antrian. Struktur data ini memungkinkan penambahan dan penghapusan data Mahasiswa dengan urutan first-in-first-out (FIFO).

## Kesimpulan
Dalam pemrograman komputer, queue adalah struktur data yang penting yang memungkinkan penyimpanan dan penarikan elemen dalam urutan tertentu, yaitu first-in-first-out (FIFO). Dalam antrian, elemen baru dapat ditambahkan ke ujung belakangnya, dan elemen yang sudah ada dapat diproses dan dihapus dari ujung depannya. Dengan demikian, antrian sangat berguna untuk berbagai tujuan, termasuk penjadwalan tugas, pengelolaan tugas antrian, dan pengiriman pesan antarproses. Implementasi antrian dapat dilakukan dengan berbagai struktur data dasar, seperti array atau daftar terkait. Antrian memiliki fungsi dasar seperti enqueue (menambah elemen), dequeue (menghapus elemen), isEmpty (mengecek apakah antrian kosong atau penuh), viewQueue (melihat elemen dalam antrian), countQueue (menghitung jumlah elemen dalam antrian), dan clearQueue (menghapus semua elemen dalam antrian).
## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
