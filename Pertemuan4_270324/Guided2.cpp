#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan
int isEmpty()
{
    return (head == NULL && tail == NULL);
}

// Buat Node Baru
Node *buatNode(string data)
{
    Node *baru = new Node;
    baru->data = data;
    baru->next = NULL;
    return baru;
}

// Tambah Depan
void insertDepan(string data)
{
    Node *baru = buatNode(data);

    if (isEmpty())
    {
        head = baru;
        tail = baru;
        tail->next = head;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    Node *baru = buatNode(data);

    if (isEmpty())
    {
        head = baru;
        tail = baru;
        tail->next = head;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
        return;
    }
    else if (posisi == 1)
    {
        insertDepan(data);
        return;
    }

    Node *baru = buatNode(data);
    Node *bantu = head;
    for (int i = 1; i < posisi - 1 && bantu != NULL; ++i)
    {
        bantu = bantu->next;
    }
    if (bantu == NULL)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    baru->next = bantu->next;
    bantu->next = baru;
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
        return;
    }

    Node *hapus = head;
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        tail->next = head;
    }
    delete hapus;
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
        return;
    }

    Node *hapus = head;
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        while (hapus->next != tail)
        {
            hapus = hapus->next;
        }
        tail = hapus;
        tail->next = head;
        hapus = hapus->next;
    }
    delete hapus;
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
        return;
    }
    else if (posisi == 1)
    {
        hapusDepan();
        return;
    }

    Node *bantu = head;
    for (int i = 1; i < posisi - 1 && bantu != NULL; ++i)
    {
        bantu = bantu->next;
    }
    if (bantu == NULL || bantu->next == NULL)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    Node *hapus = bantu->next;
    bantu->next = hapus->next;
    delete hapus;
}

// Hapus List
void clearList()
{
    if (isEmpty())
    {
        cout << "List sudah kosong!" << endl;
        return;
    }

    Node *hapus = head;
    while (hapus != NULL)
    {
        Node *temp = hapus;
        hapus = hapus->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
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
    clearList();
    return 0;
}
