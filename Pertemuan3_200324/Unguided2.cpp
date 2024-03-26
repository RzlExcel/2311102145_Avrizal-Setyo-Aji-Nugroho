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