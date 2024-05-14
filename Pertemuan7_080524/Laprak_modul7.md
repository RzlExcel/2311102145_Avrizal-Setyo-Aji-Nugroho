# <h1 align="center">Laporan Praktikum Modul QUEUE</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori

Queue atau antrian adalah struktur data abstrak yang digunakan untuk menyimpan sekumpulan data dengan cara First In First Out (FIFO). Artinya, elemen yang pertama kali masuk ke dalam antrian adalah elemen yang pertama kali dikeluarkan.

Queue sering diibaratkan seperti antrian di kehidupan nyata, di mana orang yang datang pertama kali dilayani terlebih dahulu. Hal ini berbeda dengan struktur data lain seperti stack yang menggunakan prinsip Last In First Out (LIFO).

Operasi Dasar Queue

Ada beberapa operasi dasar yang dapat dilakukan pada queue:

1. Enqueue: Menambahkan elemen baru ke dalam queue, biasanya dilakukan di ujung belakang (rear) queue.
2. Dequeue: Menghapus elemen pertama dari queue, biasanya dilakukan di ujung depan (front) queue.
3. Front: Mendapatkan elemen pertama dari queue tanpa menghapusnya.
4. IsEmpty: Memeriksa apakah queue kosong.
5. IsFull: Memeriksa apakah queue penuh (untuk implementasi menggunakan array).
6. Count: Menghitung jumlah elemen dalam queue.
7. Clear: Menghapus semua elemen dari queue.

Queue dapat diimplementasikan dengan menggunakan berbagai struktur data, seperti array, linked list, dan circular array.

1. Implementasi dengan Array: Sederhana, tetapi memiliki keterbatasan ukuran.
2. Implementasi dengan Linked List: Lebih fleksibel dalam ukuran, tetapi lebih kompleks.
3. Implementasi dengan Circular Array: Menggabungkan kelebihan array dan linked list.



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
