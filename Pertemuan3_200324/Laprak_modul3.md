# <h1 align="center">Laporan Praktikum Modul Single And Double Linked List</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori belom selese




## Guided 

### 1. Single Linked List

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Node di depan
void insertDepan(int nilai) {
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Node di belakang
void insertBelakang(int nilai) {
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung jumlah Node dalam list
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

// Tambah Node di posisi tertentu
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;

        Node *bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node dari depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;

        if (head->next != NULL) {
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
            delete hapus;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node dari belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        Node *bantu = head;

        if (head != tail) {
            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
            delete hapus;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node dari posisi tertentu
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        Node *bantu = head;
        Node *bantu2 = NULL;
        Node *hapus = NULL;

        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }
            if (nomor == posisi) {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

// Ubah data Node di depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah data Node di belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah data Node di posisi tertentu
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            int nomor = 1;

            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }

            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus semua Node dalam list
void clearList() {
    Node *bantu = head;
    Node *hapus;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan isi list
void tampil() {
    Node *bantu = head;

    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();

    return 0;
}

```
Program di atas adalah aplikasi linked list dalam C++. Linked list adalah struktur data yang digunakan untuk menyimpan data secara otomatis dalam memori komputer. Dalam list yang terhubung, setiap elemen disebut sebagai "node", dan setiap node terdiri dari dua komponen utama: data dan pointer yang menunjuk ke node berikutnya dalam list. Program ini memungkinkan Anda menambah, menghapus, dan mengubah data pada daftar terkait, dan juga menampilkan isi daftar setelah setiap operasi dilakukan. Anda dapat, misalnya, menambahkan data ke depan atau belakang daftar terkait, menghapus data dari depan, belakang, atau dari posisi tertentu, dan mengubah data pada posisi tertentu. Hasil dari setiap operasi ditampilkan, sehingga pengguna dapat melihat bagaimana operasi tersebut berdampak pada daftar terkait.

## Guided 

### 2. Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void deleteAll() {
        Node* current = head;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }

    return 0;
}

```
Dalam bahasa pemrograman C++, program di atas mengimplementasikan struktur data Linked List Doubly. Jenis Linked List ini memiliki dua pointer untuk setiap node: pointer ke node sebelumnya (prev) dan pointer ke node selanjutnya (next). Melalui sebuah menu interaktif yang disediakan oleh program, pengguna dapat menambah, menghapus, mengubah, dan menampilkan data dalam Doubly Linked List. Mereka dapat melakukan hal-hal seperti menambah data baru, menghapus data, mengubah data, menghapus seluruh data, atau menampilkan isi dari Doubly Linked List. Semua operasi dapat dilakukan sesuai dengan pilihan user, dan hasilnya ditampilkan secara langsung.

## Unguided 

### 1. Soal mengenai Single Linked List 
### Buatlah program menu Single Linked List Non-Circular untuk
### menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
### a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.
### [Nama_anda] [Usia_anda]
### John 19
### Jane 20
### Michael 18
### Yusuke 19
### Akechi 20
### Hoshino 18
### Karin 18
### b. Hapus data Akechi
### c. Tambahkan data berikut diantara John dan Jane : Futaba 18
### d. Tambahkan data berikut diawal : Igor 20
### e. Ubah data Michael menjadi : Reyn 18
### f. Tampilkan seluruh data


```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
using namespace std;

// Node struct untuk merepresentasikan node dalam linked list
struct Node {
    string nama_145;
    int usia_145;
    Node* next;
};

// Kelas untuk mengelola linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Fungsi untuk menambahkan node di depan
    void insertFront(string nama_145, int usia_145) {
        Node* newNode = new Node;
        newNode->nama_145 = nama_145;
        newNode->usia_145 = usia_145;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan node di belakang
    void insertBack(string nama_145, int usia_145) {
        Node* newNode = new Node;
        newNode->nama_145 = nama_145;
        newNode->usia_145 = usia_145;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Fungsi untuk menambahkan node di tengah
    void insertMiddle(string nama_145, int usia_145, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih besar dari 0" << endl;
            return;
        }
        if (posisi == 1) {
            insertFront(nama_145, usia_145);
            return;
        }
        Node* newNode = new Node;
        newNode->nama_145 = nama_145;
        newNode->usia_145 = usia_145;
        Node* current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi terlalu besar" << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Fungsi untuk mencari node berdasarkan nama
    Node* search(string nama_145) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama_145 == nama_145) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Fungsi untuk menghapus node berdasarkan nama
    void remove(string nama_145) {
        if (head == nullptr) {
            return;
        }
        if (head->nama_145 == nama_145) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->nama_145 == nama_145) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Fungsi untuk menampilkan seluruh data
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->nama_145 << " " << current->usia_145 << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    // Input data pengguna
    string namaSaya145;
    int usiaSaya145;

    // Input data pengguna sendiri
    cout << "Masukkan nama Anda: ";
    getline(cin, namaSaya145);
    cout << "Masukkan usia Anda: ";
    cin >> usiaSaya145;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    // Masukkan data pengguna ke dalam linked list
    list.insertFront(namaSaya145, usiaSaya145);

    // Input data nama dan usia mahasiswa lain dari pengguna
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa lain: ";
    cin >> jumlahMahasiswa;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        string namaMahasiswa145;
        int usiaMahasiswa145;

        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, namaMahasiswa145);
        cout << "Masukkan usia mahasiswa ke-" << i+1 << ": ";
        cin >> usiaMahasiswa145;
        cin.ignore(); // Membersihkan newline dari buffer stdin

        list.insertBack(namaMahasiswa145, usiaMahasiswa145);
    }

    // Tampilkan seluruh data
    cout << "Data mahasiswa:" << endl;
    list.display();
    cout << endl;

    // Menu operasi
    while(true){
    int opsi;
    cout << "Menu Operasi:" << endl;
    cout << "1. Hapus data mahasiswa" << endl;
    cout << "2. Tambahkan data mahasiswa di depan" << endl;
    cout << "3. Tambahkan data mahasiswa di tengah" << endl;
    cout << "4. Tambahkan data mahasiswa di belakang" << endl;
    cout << "5. Tampilkan data" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih opsi : ";
    cin >> opsi;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    // Proses operasi sesuai dengan opsi yang dipilih
    switch (opsi) {
        case 1: {
            string namaHapus;
            cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
            getline(cin, namaHapus);
            list.remove(namaHapus);
            break;
        }
        case 2: {
            string namaTambahDepan;
            int usiaTambahDepan;
            cout << "Masukkan nama mahasiswa yang ingin ditambahkan di depan: ";
            getline(cin, namaTambahDepan);
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di depan: ";
            cin>> usiaTambahDepan;
            cin.ignore(); 
            // Membersihkan newline dari buffer stdin
            list.insertFront(namaTambahDepan, usiaTambahDepan);
            break;
        }
        case 3: {
            string namaTambahTengah;
            int usiaTambahTengah;
            int posisiTambahTengah;
            cout << "Masukkan nama mahasiswa yang ingin ditambahkan di tengah: ";
            getline(cin, namaTambahTengah);
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di tengah: ";
            cin >> usiaTambahTengah;
            cout << "Masukkan posisi untuk menambahkan mahasiswa di tengah: ";
            cin >> posisiTambahTengah;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.insertMiddle(namaTambahTengah, usiaTambahTengah, posisiTambahTengah);
            break;
        }
        case 4: {
            string namaTambahBelakang;
            int usiaTambahBelakang;
            cout << "Masukkan nama mahasiswa yang ingin ditambahkan di belakang: ";
            getline(cin, namaTambahBelakang);
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di belakang: ";
            cin >> usiaTambahBelakang;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.insertBack(namaTambahBelakang, usiaTambahBelakang);
            break;
        }
        case 5: {
            cout << "Data mahasiswa setelah operasi:" << endl;
            list.display();
            break;
        }
        case 6 : {
            cout<<"Anda telah keluar dari menu!"<<endl;
            exit(0);
        }
        default:
            cout << "Opsi tidak valid" << endl;
    
    }
    }

    return 0;

}
```
#### Output:
![Unguided1](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan3_200324/Unguided1md3pt1.png?raw=true)
![Unguided1](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan3_200324/Unguided1md3pt2.png?raw=true)
![Unguided1](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan3_200324/Unguided1md3pt3.png?raw=true)
![Unguided1](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan3_200324/Unguided1md3pt4.png?raw=true)

Program diatas adalah program yang menggunakan daftar terkait dalam bahasa C++ untuk mengelola data mahasiswa. Ini memungkinkan user memasukkan data, menambahkan data di depan, di tengah, dan di belakang, menghapus data berdasarkan nama, dan menampilkan seluruh data. Setelah data dimasukkan, user  dapat memilih beberapa operasi dari menu, dan program akan menjalankan operasi sesuai dengan pilihan user.
## Unguided 

### 2. Buat dan jelaskan progaram menggunakan fungsi map dan jelaskan perbedaan dari array map

```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
using namespace std;

// Deklarasi class Node
class Node {
public:
    string nama_produk145;
    int harga145;
    Node* prev;
    Node* next;

    Node(string nama, int hrg) : nama_produk145(nama), harga145(hrg), prev(nullptr), next(nullptr) {}
};

// Deklarasi class DoubleLinkedList
class DoubleLinkedList {
public:
    Node* head;

    DoubleLinkedList() : head(nullptr) {}

    // fungsi untuk menambahkan data
    void tambahData(string nama_produk145, int harga145) {
        Node* new_node = new Node(nama_produk145, harga145);
        if (!head) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
            new_node->prev = current;
        }
    }

    // fungsi untuk menghapus data produk yang dipilih
    void hapusData(string nama_produk145) {
        Node* current = head;
        while (current) {
            if (current->nama_produk145 == nama_produk145) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                if (current == head) {
                    head = current->next;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // fungsi untuk mengupdate data berdasarkan nama produk
    void updateData(string nama_produk145, string nama_baru, int harga_baru) {
        Node* current = head;
        while (current) {
            if (current->nama_produk145 == nama_produk145) {
                current->nama_produk145 = nama_baru;
                current->harga145 = harga_baru;
                return;
            }
            current = current->next;
        }
    }

    // fungsi untuk menambah data di urutan tertentu
    void tambahDataUrutanTertentu(string nama_produk145, int harga145, string nama_setelah) {
        Node* new_node = new Node(nama_produk145, harga145);
        Node* current = head;
        while (current) {
            if (current->nama_produk145 == nama_setelah) {
                new_node->next = current->next;
                if (current->next) {
                    current->next->prev = new_node;
                }
                current->next = new_node;
                new_node->prev = current;
                return;
            }
            current = current->next;
        }
    }
        // fungsi untuk menghapus data berdasarkan posisi
    void hapusDataTertentu(int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0" << endl;
            return;
        }

        Node* current = head;
        int counter = 1;

        while (current && counter < posisi) {
            current = current->next;
            counter++;
        }

        if (!current) {
            cout << "Posisi melebihi panjang list" << endl;
            return;
        }

        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        if (current == head) {
            head = current->next;
        }

        delete current;
    }


    // fungsi untuk menampilkan data
    void tampilkanData() {
        Node* current = head;
        int NoUrut = 1;
        cout << "Nama Produk\tHarga" << endl;
        while (current) {
            cout << NoUrut<< ".\t"<< current->nama_produk145 << "\t\t" << current->harga145 << endl;
            current = current->next;
            NoUrut++;
        }
    }
    // fungsi untuk menghapus semua data
    void hapusSemuaData() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

};

int main() {
    // Inisialisasi double linked list
    DoubleLinkedList dll;

    // data awal
    dll.tambahData("Originote", 60000);
    dll.tambahData("Somethinc", 150000);
    dll.tambahData("Skintific", 100000);
    dll.tambahData("Wardah", 50000);
    dll.tambahData("Hanasui", 30000);


    while (true) {
         // Menu
    cout << "Toko Skincare Purwokerto" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Tambah Data Urutan Tertentu" << endl;
    cout << "5. Hapus Data Urutan Tertentu" << endl;
    cout << "6. Hapus Seluruh Data" << endl;
    cout << "7. Tampilkan Data" << endl;
    cout << "8. Exit" << endl;
        int pilihan;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama_produk145;
                int harga145;
                cout << "Masukkan nama produk: ";
                cin >> nama_produk145;
                cout << "Masukkan harga: ";
                cin >> harga145;
                dll.tambahData(nama_produk145, harga145);
                break;
            }
            case 2: {
                string nama_produk145;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama_produk145;
                dll.hapusData(nama_produk145);
                break;
            }
            case 3: {
                string nama_produk145, nama_baru;
                int harga_baru;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> nama_produk145;
                cout << "Masukkan nama baru: ";
                cin >> nama_baru;
                cout << "Masukkan harga baru: ";
                cin >> harga_baru;
                dll.updateData(nama_produk145, nama_baru, harga_baru);
                break;
            }
            case 4: {
                string nama_produk145;
                int harga145;
                string nama_setelah;
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> nama_produk145;
                cout << "Masukkan harga: ";
                cin >> harga145;
                cout << "Masukkan nama produk setelahnya: ";
                cin >> nama_setelah;
                dll.tambahDataUrutanTertentu(nama_produk145, harga145, nama_setelah);
                break;
            }
            case 5: {
                int posisi;
                cout << "Masukkan posisi data yang ingin dihapus: ";
                cin >> posisi;
                dll.hapusDataTertentu(posisi);
                break;
            }
            case 6: {
                dll.hapusSemuaData();
                 cout << "Semua produk telah dihapus" << endl;
                break;
            }
            case 7: {
                dll.tampilkanData();
                break;
            }
            case 8:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}
```
#### Output:
![Unguided1](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/blob/main/Pertemuan3_200324/Unguided1md3pt1.png?raw=true)

Sebuah program dalam bahasa C++ yang disebutkan di atas menggunakan struktur data Doubly Linked List untuk menyimpan dan mengelola data produk untuk sebuah toko kosmetik. User dapat menambahkan, menghapus, mengupdate, menampilkan, dan menghapus semua data produk melalui program ini. Semua data produk terdiri dari nama produk dan harganya. User dapat memilih berbagai operasi yang ingin mereka lakukan dengan menggunakan menu yang tersedia. Misalnya, mereka dapat menambah data baru, menghapus data, mengupdate data, menambah data dalam urutan tertentu, menghapus data berdasarkan posisi, menampilkan seluruh data produk, atau menghapus semua data produk sekaligus. Dengan interaksi yang mudah dipahami, program ini memberikan fleksibilitas untuk mengelola data produk di toko skincare.
## Kesimpulan
Single linked list adalah daftar di mana setiap elemen hanya memiliki koneksi ke elemen berikutnya, memudahkan penambahan dan penghapusan di awal tetapi sulit untuk mengakses elemen secara terbalik. Di sisi lain, double linked list memiliki koneksi maju dan mundur, memungkinkan navigasi dua arah. Meskipun double linked list membutuhkan lebih banyak memori karena setiap elemen memiliki dua koneksi, ini memudahkan operasi seperti penghapusan atau penambahan di tengah list. Pilihan antara keduanya tergantung pada kebutuhan aplikasi, dengan single linked list lebih cocok untuk navigasi satu arah dan double linked list lebih sesuai untuk navigasi maju dan mundur.
## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
