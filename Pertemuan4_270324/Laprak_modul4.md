# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori




## Guided 

### 1. Linked List Non Circular blm

```C++
#include <iostream>
#include <iomanip>

using namespace std;
// Tipe Data Primitif
int main (){
    char op;
    float num1, num2;

    cout<< "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "enter two oprands: ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '+':
        cout << "Result: " << num1 + num2;
        break;
    case '-':
        cout << "Result: " << num1 - num2;
        break;
     case '*':
        cout << "Result: " << num1 * num2;
        break;
    case '/':
        if (num2 != 0){
            cout << "Result: "<< fixed << setprecision(2) << num1 / num2;
        } else{
            cout << "Error! Division by zero is not allowed.";
        }
        break;
    default:
    cout << "Error! Operator is not correct";
        break;
    }
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Guided 

### 2. Linked List Circular blm

```C++
#include <stdio.h>
#include <string.h>
// Tipe data Abstrak
// Struct
struct Mahasiswa
{
char name[50];
char address[100];
int age;
};
int main()
{
   // Menggunakan Struct
struct Mahasiswa mhs1, mhs2;
// Mengisi nilai ke struct
strcpy(mhs1.name, "Dian");
strcpy(mhs1.address, "Mataram");
mhs1.age = 22;
strcpy(mhs2.name, "Bambang");
strcpy(mhs2.address, "Surabaya");
mhs2.age = 23;

// Mencetak isi dari struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name);
printf("Alamat: %s\n", mhs1.address);
printf("Umur: %d\n", mhs1.age);
printf ("\n");
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name);
printf("Alamat: %s\n", mhs2.address);
printf("Umur: %d\n", mhs2.age);
return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.


## Unguided 

### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.

```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
using namespace std;

struct Node
{
    string nama; // Menyimpan Nama Mahasiswa
    int NIM;     // Menyimpan NIM mahasiswa
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
    // Fungsi untuk menambah data pertama dalam linked
    void insertFront(string nama, int NIM)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->NIM = NIM;
        newNode->next = head;
        head = newNode;
    }
    // Fungsi untuk menambah data pada data terakhir
    void insertBack(string nama, int NIM)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->NIM = NIM;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    // Fungsi menambah data pada posisi tengah
    void insertMiddle(string nama, int NIM, int posisi)
    {
        if (posisi <= 0)
        {
            cout << "Posisi harus lebih besar dari 0" << endl;
            return;
        }
        if (posisi == 1)
        {
            insertFront(nama, NIM);
            return;
        }
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->NIM = NIM;
        Node *current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Posisi terlalu besar" << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    Node *search(string nama)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->nama == nama)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    // Fungsi untuk menghapus data
    void remove(string nama)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->nama == nama)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->nama == nama)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }
    // Fungsi untuk menampilkan data
    void display()
    {
        Node *current = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        while (current != nullptr)
        {
            cout << current->nama << "\t" << current->NIM << endl;
            current = current->next;
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    Node *getFrontNode()
    {
        return head;
    }
};

int main()
{
    LinkedList list;

    while (true)
    {
        int opsi;
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi : ";
        cin >> opsi;
        cin.ignore();

        switch (opsi)
        {
        case 1:
        { // Menginputkan Nama dan NIM  baru ke depan dari linked list
            string nama;
            int NIM;
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            cout << "Masukkan NIM: ";
            cin >> NIM;
            cin.ignore(); // Bersihkan buffer masukan
            list.insertFront(nama, NIM);
            cout << "Data berhasil ditambahkan!" << endl;
            break;
        }
        case 2:
        { // Menginputkan  data baru ke belakang dari linked list
            string nama;
            int NIM;
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            cout << "Masukkan NIM: ";
            cin >> NIM;
            cin.ignore();
            list.insertBack(nama, NIM);
            cout << "Data berhasil ditambahkan!" << endl;
            break;
        }
        case 3:
        { // Menginputkan nama pada posisi tengah
            string nama;
            int NIM;
            int posisi;
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            cout << "Masukkan NIM: ";
            cin >> NIM;
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            cin.ignore();
            list.insertMiddle(nama, NIM, posisi);
            cout << "Data berhasil ditambahkan!" << endl;
            break;
        }
        case 4:
        { // Mengubah data pada baris pertama
            if (list.isEmpty())
            {
                cout << "List kosong, tidak ada yang bisa diubah." << endl;
                break;
            }
            string namaBaru;
            int NIMBaru;
            cout << "Masukkan Nama Baru untuk Depan: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru untuk Depan: ";
            cin >> NIMBaru;
            cin.ignore();
            Node *frontNode = list.getFrontNode();
            frontNode->nama = namaBaru;
            frontNode->NIM = NIMBaru;
            cout << "Data Depan berhasil diubah." << endl;
            break;
        }
        case 5:
        { // mengubah data pada baris terakhir
            if (list.isEmpty())
            {
                cout << "List kosong, tidak ada yang bisa diubah." << endl;
                break;
            }
            string namaBaru;
            int NIMBaru;
            cout << "Masukkan Nama Baru untuk Belakang: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru untuk Belakang: ";
            cin >> NIMBaru;
            cin.ignore();
            Node *current = list.getFrontNode();
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->nama = namaBaru;
            current->NIM = NIMBaru;
            cout << "Data Belakang berhasil diubah." << endl;
            break;
        }
        case 6:
        { // mengubah data pada posisi tengah yang ditentukan
            if (list.isEmpty())
            {
                cout << "List kosong, tidak ada yang bisa diubah." << endl;
                break;
            }
            int posisi;
            cout << "Masukkan posisi node yang ingin diubah: ";
            cin >> posisi;
            cin.ignore();
            if (posisi <= 0)
            {
                cout << "Posisi harus lebih besar dari 0" << endl;
                break;
            }
            Node *current = list.getFrontNode();
            for (int i = 1; i < posisi && current != nullptr; ++i)
            {
                current = current->next;
            }
            if (current == nullptr)
            {
                cout << "Posisi terlalu besar" << endl;
                break;
            }
            string namaBaru;
            int NIMBaru;
            cout << "Masukkan Nama Baru: ";
            getline(cin, namaBaru);
            cout << "Masukkan NIM Baru: ";
            cin >> NIMBaru;
            cin.ignore();
            current->nama = namaBaru;
            current->NIM = NIMBaru;
            cout << "Data pada posisi " << posisi << " berhasil diubah." << endl;
            break;
        }
        case 7:
        { // mengapus data yang ada didepan
            if (list.isEmpty())
            {
                cout << "List kosong, tidak ada yang bisa dihapus." << endl;
                break;
            }
            Node *temp = list.getFrontNode();
            list.remove(temp->nama);
            cout << "Data Depan berhasil dihapus." << endl;
            break;
        }
        case 8:
        { // menghapus data yang ada dibelakang
            if (list.isEmpty())
            {
                cout << "List kosong, tidak ada yang bisa dihapus." << endl;
                break;
            }
            Node *prev = nullptr;
            Node *current = list.getFrontNode();
            while (current->next != nullptr)
            {
                prev = current;
                current = current->next;
            }
            if (prev == nullptr)
            {
                list.remove(current->nama);
            }
            else
            {
                prev->next = nullptr;
                delete current;
            }
            cout << "Data Belakang berhasil dihapus." << endl;
            break;
        }
        case 9:
        { // menghapus data yang ada pada posisi tengah atau ditentukan
            if (list.isEmpty())
            {
                cout << "List kosong, tidak ada yang bisa dihapus." << endl;
                break;
            }
            int posisi;
            cout << "Masukkan posisi node yang ingin dihapus: ";
            cin >> posisi;
            cin.ignore();
            if (posisi <= 0)
            {
                cout << "Posisi harus lebih besar dari 0" << endl;
                break;
            }
            Node *prev = nullptr;
            Node *current = list.getFrontNode();
            for (int i = 1; i < posisi && current != nullptr; ++i)
            {
                prev = current;
                current = current->next;
            }
            if (current == nullptr)
            {
                cout << "Posisi terlalu besar" << endl;
                break;
            }
            if (prev == nullptr)
            {
                list.remove(current->nama);
            }
            else
            {
                prev->next = current->next;
                delete current;
            }
            cout << "Data pada posisi " << posisi << " berhasil dihapus." << endl;
            break;
        }
        case 10:
        { // menghapus semua data
            if (list.isEmpty())
            {
                cout << "List sudah kosong." << endl;
                break;
            }
            while (!list.isEmpty())
            {
                Node *temp = list.getFrontNode();
                list.remove(temp->nama);
            }
            cout << "Seluruh data dalam list berhasil dihapus." << endl;
            break;
        }
        case 11:
        { // menampilkan data
            list.display();
            break;
        }
        case 0:
        {
            cout << "Terima kasih, program selesai." << endl;
            exit(0);
        }
        default:
        {
            cout << "Opsi tidak valid." << endl;
            break;
        }
        }
    }

    return 0;
}

```
#### Output:
![Screenshot%20(52).png](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.



## Kesimpulan
linked list circular adalah jenis linked list di mana elemen terakhir menunjuk kembali ke elemen pertama, membentuk lingkaran tanpa titik akhir yang jelas, yang menghilangkan kebutuhan akan pointer nullptr. Linked list circular sering digunakan untuk keperluan tertentu seperti buffering dan pemrograman terdistribusi.
## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
