#include <iostream>
using namespace std;

// Deklarasi class Node
class Node {
public:
    string nama_produk;
    int harga;
    Node* prev;
    Node* next;

    // Konstruktor
    Node(string nama, int hrg) : nama_produk(nama), harga(hrg), prev(nullptr), next(nullptr) {}
};

// Deklarasi class DoubleLinkedList
class DoubleLinkedList {
public:
    Node* head;

    // Konstruktor
    DoubleLinkedList() : head(nullptr) {}

    // Method untuk menambah data di akhir
    void tambahData(string nama_produk, int harga) {
        Node* new_node = new Node(nama_produk, harga);
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

    // Method untuk menghapus data berdasarkan nama produk
    void hapusData(string nama_produk) {
        Node* current = head;
        while (current) {
            if (current->nama_produk == nama_produk) {
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

    // Method untuk mengupdate data berdasarkan nama produk
    void updateData(string nama_produk, string nama_baru, int harga_baru) {
        Node* current = head;
        while (current) {
            if (current->nama_produk == nama_produk) {
                current->nama_produk = nama_baru;
                current->harga = harga_baru;
                return;
            }
            current = current->next;
        }
    }

    // Method untuk menambah data di urutan tertentu
    void tambahDataUrutanTertentu(string nama_produk, int harga, string nama_setelah) {
        Node* new_node = new Node(nama_produk, harga);
        Node* current = head;
        while (current) {
            if (current->nama_produk == nama_setelah) {
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

    // Method untuk menampilkan data
    void tampilkanData() {
        Node* current = head;
        cout << "Nama Produk\tHarga" << endl;
        while (current) {
            cout << current->nama_produk << "\t\t" << current->harga << endl;
            current = current->next;
        }
    }
};

int main() {
    // Inisialisasi double linked list
    DoubleLinkedList dll;

    // Tambahkan data awal
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
                string nama_produk;
                int harga;
                cout << "Masukkan nama produk: ";
                cin >> nama_produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                dll.tambahData(nama_produk, harga);
                break;
            }
            case 2: {
                string nama_produk;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama_produk;
                dll.hapusData(nama_produk);
                break;
            }
            case 3: {
                string nama_produk, nama_baru;
                int harga_baru;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> nama_produk;
                cout << "Masukkan nama baru: ";
                cin >> nama_baru;
                cout << "Masukkan harga baru: ";
                cin >> harga_baru;
                dll.updateData(nama_produk, nama_baru, harga_baru);
                break;
            }
            case 4: {
                string nama_produk;
                int harga;
                string nama_setelah;
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> nama_produk;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan nama produk setelahnya: ";
                cin >> nama_setelah;
                dll.tambahDataUrutanTertentu(nama_produk, harga, nama_setelah);
                break;
            }
            case 5: {
                // Untuk kasus ini, karena tidak disebutkan dalam deskripsi, saya akan membiarkannya kosong
                cout << "Menu belum diimplementasikan" << endl;
                break;
            }
            case 6: {
                // Untuk kasus ini, karena tidak disebutkan dalam deskripsi, saya akan membiarkannya kosong
                cout << "Menu belum diimplementasikan" << endl;
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
