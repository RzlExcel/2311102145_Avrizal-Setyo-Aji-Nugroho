/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
using namespace std;

// Node struct untuk merepresentasikan node dalam linked list
struct Node {
    string nama_149;
    int usia_149;
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
    void insertFront(string nama_149, int usia_149) {
        Node* newNode = new Node;
        newNode->nama_149 = nama_149;
        newNode->usia_149 = usia_149;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan node di belakang
    void insertBack(string nama_149, int usia_149) {
        Node* newNode = new Node;
        newNode->nama_149 = nama_149;
        newNode->usia_149 = usia_149;
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
    void insertMiddle(string nama_149, int usia_149, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih besar dari 0" << endl;
            return;
        }
        if (posisi == 1) {
            insertFront(nama_149, usia_149);
            return;
        }
        Node* newNode = new Node;
        newNode->nama_149 = nama_149;
        newNode->usia_149 = usia_149;
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
    Node* search(string nama_149) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama_149 == nama_149) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Fungsi untuk menghapus node berdasarkan nama
    void remove(string nama_149) {
        if (head == nullptr) {
            return;
        }
        if (head->nama_149 == nama_149) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->nama_149 == nama_149) {
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
            cout << current->nama_149 << " " << current->usia_149 << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    // Input data pengguna
    string namaSaya;
    int usiaSaya;

    // Input data pengguna sendiri
    cout << "Masukkan nama Anda: ";
    getline(cin, namaSaya);
    cout << "Masukkan usia Anda: ";
    cin >> usiaSaya;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    // Masukkan data pengguna ke dalam linked list
    list.insertFront(namaSaya, usiaSaya);

    // Input data nama dan usia mahasiswa lain dari pengguna
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa lain: ";
    cin >> jumlahMahasiswa;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        string namaMahasiswa;
        int usiaMahasiswa;

        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, namaMahasiswa);
        cout << "Masukkan usia mahasiswa ke-" << i+1 << ": ";
        cin >> usiaMahasiswa;
        cin.ignore(); // Membersihkan newline dari buffer stdin

        list.insertBack(namaMahasiswa, usiaMahasiswa);
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