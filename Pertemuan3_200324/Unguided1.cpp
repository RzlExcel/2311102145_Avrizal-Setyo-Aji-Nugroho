/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
using namespace std;

class Node {
public:
    string nama;
    int usia;
    Node* next;

    Node(string nama, int usia) {
        this->nama = nama;
        this->usia = usia;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void tambahDepan(string nama, int usia) {
        Node* newNode = new Node(nama, usia);
        newNode->next = head;
        head = newNode;
    }

    void tambahBelakang(string nama, int usia) {
        Node* newNode = new Node(nama, usia);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

    void tambahTengah(string nama, int usia, string namaSebelum) {
        Node* newNode = new Node(nama, usia);
        Node* current = head;
        while (current != nullptr) {
            if (current->nama == namaSebelum) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Data sebelumnya tidak ditemukan." << endl;
    }

    void hapusData(string nama) {
        Node* current = head;
        Node* prev = nullptr;
        if (current != nullptr && current->nama == nama) {
            head = current->next;
            delete current;
            return;
        }
        while (current != nullptr && current->nama != nama) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Data tidak ditemukan." << endl;
            return;
        }
        prev->next = current->next;
        delete current;
    }

    void ubahData(string namaLama, string namaBaru, int usiaBaru) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama == namaLama) {
                current->nama = namaBaru;
                current->usia = usiaBaru;
                return;
            }
            current = current->next;
        }
        cout << "Data tidak ditemukan." << endl;
    }

    void tampilkanData() {
        Node* current = head;
        cout << "Nama   Usia" << endl;
        while (current != nullptr) {
            cout << current->nama << " " << current->usia << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList linkedList;

    // Data pertama (nama dan usia Anda)
    string namaAnda;
    int usiaAnda;
    cout << "Masukkan nama Anda: ";
    cin >> namaAnda;
    cout << "Masukkan usia Anda: ";
    cin >> usiaAnda;
    linkedList.tambahDepan(namaAnda, usiaAnda);

    // a. Menambahkan data sesuai urutan
    linkedList.tambahBelakang("John", 19);
    linkedList.tambahBelakang("Jane", 20);
    linkedList.tambahBelakang("Michael", 18);
    linkedList.tambahBelakang("Yusuke", 19);
    linkedList.tambahBelakang("Akechi", 20);
    linkedList.tambahBelakang("Hoshino", 18);
    linkedList.tambahBelakang("Karin", 18);

    // b. Menghapus data Akechi
    linkedList.hapusData("Akechi");

    // c. Menambahkan data Futaba di antara John dan Jane
    linkedList.tambahTengah("Futaba", 18, "John");

    // d. Menambahkan data Igor di awal
    linkedList.tambahDepan("Igor", 20);

    // e. Mengubah data Michael menjadi Reyn
    linkedList.ubahData("Michael", "Reyn", 18);

    // f. Menampilkan seluruh data
    linkedList.tampilkanData();

    return 0;
}
