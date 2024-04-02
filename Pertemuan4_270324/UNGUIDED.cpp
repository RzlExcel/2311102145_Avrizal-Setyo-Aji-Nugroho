/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Deklarasi class Node untuk mepresentasikan  node dari linked list
class Node
{
public:
    string nama_145; // Menyimpan nama
    string nim_145;  // Menyimpan NIM Mahasiswa
    Node *next;

    Node(string nama_145, string nim_145)
    {
        this->nama_145 = nama_145;
        this->nim_145 = nim_145;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    // Konstruktor class linked list untuk inisialisasi head  menjadi NULL
    LinkedList()
    {
        head = nullptr;
    }
    // Fungsi untuk tambah data depan
    void tambahDepan(string nama_145, string nim_145)
    {
        Node *newNode = new Node(nama_145, nim_145);
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk tambah data belakang
    void tambahBelakang(string nama_145, string nim_145)
    {
        Node *newNode = new Node(nama_145, nim_145);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fungsi untuk tambah data tengah
    void tambahTengah(string nama_145, string nim_145, int posisi)
    {
        if (posisi < 1)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        Node *newNode = new Node(nama_145, nim_145);
        if (posisi == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < posisi - 1; ++i)
        {
            if (temp == nullptr)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // FUngsi untuk ubah data depan
    void ubahDepan(string nama_145, string nim_145)
    {
        if (head == nullptr)
        {
            cout << "List kosong" << endl;
            return;
        }
        head->nama_145 = nama_145;
        head->nim_145 = nim_145;
    }

    // Fungsi untuk ubah data belakang
    void ubahBelakang(string nama_145, string nim_145)
    {
        if (head == nullptr)
        {
            cout << "List kosong" << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->nama_145 = nama_145;
        temp->nim_145 = nim_145;
    }

    // Fungsi untuk ubah data tengah
    void ubahTengah(string nama_145, string nim_145, int posisi)
    {
        if (head == nullptr)
        {
            cout << "List kosong" << endl;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < posisi; ++i)
        {
            if (temp == nullptr)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        temp->nama_145 = nama_145;
        temp->nim_145 = nim_145;
    }

    // Fungsi untuk hapus data depan
    void hapusDepan()
    {
        if (head == nullptr)
        {
            cout << "List kosong" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Fungsi untuk hapus data belakang
    void hapusBelakang()
    {
        if (head == nullptr)
        {
            cout << "List kosong" << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Fungsi untuk hapus data tengah
    void hapusTengah(int posisi)
    {
        if (head == nullptr)
        {
            cout << "List kosong" << endl;
            return;
        }
        if (posisi < 1)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        if (posisi == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        for (int i = 1; i < posisi && curr != nullptr; ++i)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    // Fungsi untuk hapus semua data
    void hapusList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Fungsi untuk menampilkan semua data
    void tampilkan()
    {
        if (head == nullptr)
        {
            cout << "List kosong" << endl;
            return;
        }
        cout << setw(10) << left << "Nama" << setw(10) << left << "NIM" << endl;
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << setw(10) << left << temp->nama_145 << setw(10) << left << temp->nim_145 << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList linkedList;

    int pilihan_145, posisi; // variabel untuk menyimpan pilihan
    string nama_145, nim_145;

    while (true)
    {
        cout << "-------------------------------------------" << endl;
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "-------------------------------------------" << endl;
        cout << endl;
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
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan_145;

        switch (pilihan_145)
        {
        case 0:
            return 0;
        case 1:
            //  memanggil fungsi tambah data depan
            cout << "Masukkan Nama: ";
            cin >> nama_145;
            cout << "Masukkan NIM: ";
            cin >> nim_145;
            linkedList.tambahDepan(nama_145, nim_145);
            cout << "Data berhasil ditambahkan!" << endl;
            break;
        case 2:
            //  memanggil fungsi tambah data belakang
            cout << "Masukkan Nama: ";
            cin >> nama_145;
            cout << "Masukkan NIM: ";
            cin >> nim_145;
            linkedList.tambahBelakang(nama_145, nim_145);
            cout << "Data berhasil ditambahkan!" << endl;
            break;
        case 3:
            //  memanggil fungsi tambah data tengah
            cout << "Masukkan Nama: ";
            cin >> nama_145;
            cout << "Masukkan NIM: ";
            cin >> nim_145;
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            linkedList.tambahTengah(nama_145, nim_145, posisi);
            cout << "Data berhasil ditambahkan!" << endl;
            break;
        case 4:
            //  memanggil fungsi ubah data depan
            cout << "Masukkan Nama : ";
            cin >> nama_145;
            cout << "Masukkan NIM : ";
            cin >> nim_145;
            linkedList.ubahDepan(nama_145, nim_145);
            cout << "Data berhasil diperbarui!" << endl;
            break;
        case 5:
            //  memanggil fungsi ubah data belakang
            cout << "Masukkan Nama : ";
            cin >> nama_145;
            cout << "Masukkan NIM : ";
            cin >> nim_145;
            linkedList.ubahBelakang(nama_145, nim_145);
            cout << "Data berhasil diperbarui!" << endl;
            break;
        case 6:
            //  memanggil fungsi ubah data tengah
            cout << "Masukkan Nama : ";
            cin >> nama_145;
            cout << "Masukkan NIM : ";
            cin >> nim_145;
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            linkedList.ubahTengah(nama_145, nim_145, posisi);
            cout << "Data berhasil diperbarui!" << endl;
            break;
        case 7:
            //  memanggil fungsi hapus data depan
            linkedList.hapusDepan();
            cout << "Data berhasil dihapus\n";
            break;
        case 8:
            //  memanggil fungsi hapus data belakang
            linkedList.hapusBelakang();
            cout << "Data berhasil dihapus\n";
            break;
        case 9:
            //  memanggil fungsi hapus data tengah
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            linkedList.hapusTengah(posisi);
            cout << "Data berhasil dihapus\n";
            break;
        case 10:
            //  memanggil fungsi  hapus semua data list
            linkedList.hapusList();
            cout << "Semua data telah dihapus." << endl;
            break;
        case 11:
            // memanggil fungsi tampil data
            linkedList.tampilkan();
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}