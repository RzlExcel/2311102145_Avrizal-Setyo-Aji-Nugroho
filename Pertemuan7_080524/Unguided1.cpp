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