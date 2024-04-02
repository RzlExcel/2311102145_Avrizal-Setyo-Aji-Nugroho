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

``#include <iostream>
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

Kode di atas merupakan program Single Linked List Non-Circular dalam bahasa C++ yang mendemonstrasikan operasi dasar seperti menambah data di depan, belakang, dan tengah, mengubah data di depan, belakang, dan tengah, menghapus data di depan, belakang, dan tengah, serta menghapus seluruh data. Program ini juga memungkinkan user untuk menampilkan data yang ada di dalam list. Kode ini menggunakan struct Node untuk menyimpan data nama dan NIM mahasiswa, dan struct LinkedList untuk menampung seluruh node. Program ini menggunakan berbagai fungsi untuk melakukan operasi-operasi tersebut, seperti insertFront(), insertBack(), insertMiddle(), remove(), search(), dan display().


## Kesimpulan
linked list circular adalah jenis linked list di mana elemen terakhir menunjuk kembali ke elemen pertama, membentuk lingkaran tanpa titik akhir yang jelas, yang menghilangkan kebutuhan akan pointer nullptr. Linked list circular sering digunakan untuk keperluan tertentu seperti buffering dan pemrograman terdistribusi.
## Referensi
[1] GeeksforGeeks. (2023, November 14). Circular Linked List. Retrieved from https://www.geeksforgeeks.org/circular-linked-list/ <br>
[2] Modul Kuliah Struktur Data - Linked List - Universitas Esa Unggul: https://lms-paralel.esaunggul.ac.id/pluginfile.php?file=%2F86227%2Fmod_resource%2Fcontent%2F1%2FModul%20Struktur%20Data-Linked%20List.pdf
