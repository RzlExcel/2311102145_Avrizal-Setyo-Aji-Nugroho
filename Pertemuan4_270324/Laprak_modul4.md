# <h1 align="center">Laporan Praktikum Modul 
# <p align="center">LINKED LIST CIRCULAR DAN NON CIRCULAR
</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori

Linked List Circular (LLC) adalah jenis Linked List yang memiliki pointer next yang menunjuk pada dirinya sendiri, sehingga berputar. Setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya dan juga memiliki field yang berisi data. Pada akhir linked list, node terakhir akan menunjuk ke node terdepan sehingga linked list tersebut berputar. Node terakhir akan menunjuk lagi ke head.
Linked List Non Circular (SLLNC) adalah jenis Linked List yang pointer next pada node terakhir akan menunjuk ke NULL. Pada node terakhir/ekor yang semula menunjuk ke NULL, akan diganti menjadi pointer ke head.
# Linked List Non-Circular:

Kelebihan:

-Lebih mudah diimplementasikan.<br>
-Lebih hemat memori.<br>
<br>Kekurangan:<br>

-Pencarian data kurang efisien.<br>
-Penghapusan node di awal rumit.<br>
# Linked List Circular:<br>

Kelebihan:<br>

-Pencarian data lebih efisien.<br>
-Penghapusan node di awal mudah.<br>
<br>Kekurangan:<br>

-Lebih rumit diimplementasikan.<br>
-Membutuhkan memori lebih banyak.<br>


## Guided 

### 1. Linked List Non Circular 
```C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
        }

        nomor++;
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
        }
        else
        {
            delete hapus;
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        else
        {
            delete hapus;
            head = tail = NULL;
        }
    }

    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == 0)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Program diatas adalah implementasi dari struktur data linked list non-circular menggunakan bahasa pemrograman C++. Dalam program ini, kita dapat melakukan berbagai operasi seperti menambahkan elemen di depan atau belakang, menghapus elemen dari depan, belakang, atau tengah, serta mengubah nilai dari elemen-elemen tertentu dalam linked list. Setiap operasi ini diimplementasikan melalui fungsi-fungsi yang telah didefinisikan sebelumnya. Pada bagian main() program, dilakukan serangkaian operasi tersebut untuk menguji fungsi-fungsi tersebut, dengan menambahkan, menghapus, dan mengubah elemen-elemen dalam linked list serta menampilkan hasilnya.
## Guided 

### 2. Linked List Circular 
```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Program diatas adalah implementasi dari struktur data linked list circular menggunakan bahasa pemrograman C++. Dalam program ini, kita dapat melakukan berbagai operasi seperti menambahkan elemen di depan atau belakang, menghapus elemen dari depan, belakang, atau tengah, serta mengubah nilai dari elemen-elemen tertentu dalam linked list. Setiap operasi ini diimplementasikan melalui fungsi-fungsi yang telah didefinisikan sebelumnya. Pada bagian main() program, dilakukan serangkaian operasi tersebut untuk menguji fungsi-fungsi tersebut, dengan menambahkan, menghapus, dan mengubah elemen-elemen dalam linked list serta menampilkan hasilnya.

## Unguided 

### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.
![Screenshot 2024-04-02 204643](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/88789fe5-7ba2-4bda-a8dc-d39a7e8a3097)
![Screenshot 2024-04-02 204707](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/ad6cd9a7-efe3-4a66-aca1-641e8e28ecbd)
![Screenshot 2024-04-02 204719](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/b75433d1-40a2-4f81-94e9-d17579562cd6)




```C++
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

```
#### Output:
![Screenshot 2024-04-02 224545](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/5f7fbb33-929d-4af6-a0ab-243ce5e58dca)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/0f19562d-3a73-4f9f-b8ce-864c565083ae)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/3da94875-e5ee-4b96-9646-5da52dbe786e)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/446abbe7-8b55-44a1-ad44-dcab423ad268)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/a53fab6a-70cc-4f10-9c29-f30f4cf997d7)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/0844095b-7403-4b19-8253-ceadab7ceb35)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/69b95f88-638d-423e-8634-92324c5dc496)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/0de6bef0-8ea2-4e18-8818-8790f8f75c04)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/0e523ac6-68f4-4902-afec-3471b266b9cc)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/fb706b55-f2cb-4ddf-bcf3-275de788c4e9)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/bfad3533-57d1-42ca-bc2a-66c542f2ffda)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/849a7b7c-6936-429e-8351-055042a217f5)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/a3ad2055-9690-49f7-8fc9-fb1deb1cfde8)


Kode di atas merupakan program Single Linked List Non-Circular dalam bahasa C++ yang mendemonstrasikan operasi dasar seperti menambah data di depan, belakang, dan tengah, mengubah data di depan, belakang, dan tengah, menghapus data di depan, belakang, dan tengah, serta menghapus seluruh data. Program ini juga memungkinkan user untuk menampilkan data yang ada di dalam list. Kode ini menggunakan struct Node untuk menyimpan data nama dan NIM mahasiswa, dan struct LinkedList untuk menampung seluruh node. Program ini menggunakan berbagai fungsi untuk melakukan operasi-operasi tersebut, seperti insertFront(), insertBack(), insertMiddle(), remove(), search(), dan display().


## Kesimpulan
linked list circular adalah jenis linked list di mana elemen terakhir menunjuk kembali ke elemen pertama, membentuk lingkaran tanpa titik akhir yang jelas, yang menghilangkan kebutuhan akan pointer nullptr. Linked list circular sering digunakan untuk keperluan tertentu seperti buffering dan pemrograman terdistribusi.
## Referensi
[1] GeeksforGeeks. (2023, November 14). Circular Linked List. Retrieved from https://www.geeksforgeeks.org/circular-linked-list/ <br>
[2] Modul Kuliah Struktur Data - Linked List - Universitas Esa Unggul: https://lms-paralel.esaunggul.ac.id/pluginfile.php?file=%2F86227%2Fmod_resource%2Fcontent%2F1%2FModul%20Struktur%20Data-Linked%20List.pdf
