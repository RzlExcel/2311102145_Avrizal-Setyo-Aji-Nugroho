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
