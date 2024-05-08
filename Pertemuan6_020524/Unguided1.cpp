#include <iostream>
#include <string>

using namespace std;

class stack
{
private:
    struct Node
    {
        char data;
        Node *next;
    };
    Node *top;

public:
    stack() { top = NULL; }
    void push(char x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }
    char pop()
    {
        if (top == NULL)
        {
            cout << "Stack Kosong" << endl;
            exit(1);
        }
        char x = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return x;
    }
    bool kosong()
    {
        return top == NULL;
    }
};

class Queue
{
private:
    struct Node
    {
        char data;
        Node *next;
    };
    Node *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(char x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (front == NULL)
            front = rear = temp;
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    char dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue Kosong" << endl;
            exit(1);
        }
        char x = front->data;
        Node *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
        return x;
    }
    bool kosong()
    {
        return front == NULL;
    }
};

int main()
{
    stack s;
    Queue q;
    string str;
    cout << "Masukkan kalimat : " << endl;
    cin >> str;
    for (int i = 0; i < str.length();
         i++)
    {
        s.push(str[i]);
        q.enqueue(str[i]);
    }
    bool Palindrom = true;
    for (int i = 0; i < str.length();
         i++)
    {
        if (s.pop() != q.dequeue())
        {
            Palindrom = false;
            break;
        }
    }
    if (Palindrom)
        cout << "Kalimat Tersebut adalah Palindrom" << endl;
    else
        cout << "Kalimat Tersebut bukan Palindrom" << endl;
    return 0;
}