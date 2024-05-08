# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori
Stack, juga disebut tumpukan, adalah struktur data yang menggunakan prinsip Last In First Out (LIFO). Artinya, elemen pertama yang dikeluarkan adalah yang terakhir yang dimasukkan ke dalam stack. Seringkali, Stack dianalogikan dengan tumpukan piring: piring pertama yang ditumpuk adalah piring terakhir yang diambil.

Operasi Inti dari Stack:

1. Push (Masukkan): Menambahkan elemen ke dalam tumpukan pada posisi paling atas atau ujung.<br>
2. Pop (Keluarkan): Menghapus elemen dari posisi paling atas atau ujung tumpukan.<br>
3. Top (Atas): Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa menghapusnya.<br>
4. IsEmpty (Kosong): Memeriksa apakah tumpukan kosong atau tidak.<br>
5. IsFull (Penuh):Memeriksaapakah tumpukanpenuhatau tidak (terutamapada implementasitumpukandengankapasitasterbatas).<br>
6. Size(Ukuran):Mengembalikanjumlahelemenyangadadalamtumpukan.<br>
7. Peek (Lihat):Melihat nilai atau elemenpadaposisi tertentudalamtumpukan tanpamenghapusnya.<br>
8. Clear (Hapus Semua): Mengosongkan ataumenghapus semua elemen dari tumpukan.<br>
9. Search(Cari):Mencarikeberadaanelementertentudalamtumpukan.<br>

Implementasi Stack:

Berbagai struktur data, seperti array, Linked list, dan Tree, dapat digunakan untuk mengimplementasikan stack. Array adalah implementasi yang paling umum.




## Guided 

### 1. Stack

```C++
#include <iostream>
using namespace std;
string arrayBuku[5];
int maksimal = 5, top = 0;
bool isFull()
{
    return (top == maksimal);
}
bool isEmpty()
{
    return (top == 0);
}
void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}
void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}
void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}
int countStack()
{
    return top;
}
void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}
int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");
    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}

```
Kode di atas mengimplementasikan struktur data stack menggunakan array dalam bahasa C++. Kode tersebut memiliki fungsi dasar seperti push untuk menambahkan data ke dalam stack, pop untuk menghapus data dari stack, dan peek untuk melihat data di posisi tertentu. Selain itu, kode tersebut memiliki fungsi tambahan seperti isFull, isEmpty, countStack, changeArrayBook, destroyArrayBook, dan cetakArrayBook. Program juga melakukan operasi dasar pada stack, seperti menambahkan beberapa data ke dalam stack, menghapus data dari stack, mengubah data pada posisi tertentu, serta menghapus seluruh data dari stack. Setelah operasi-operasi dilakukan, program mencetak status stack dan isi stack sesuai dengan operasi yang telah dilakukan.
## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.


```C++
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
```

#### Output:

![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/f43bee63-3e1d-49f0-95ee-381c2cfc3223)
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/61ddfc7f-772b-4d2e-9f56-0dbe39b00c74)



Kode di atas menggunakan struktur data stack dan queue untuk mengetahui apakah sebuah kalimat yang dimasukkan merupakan palindrom atau tidak. Program meminta pengguna untuk memasukkan sebuah kalimat, kemudian setiap karakter dari kalimat tersebut dimasukkan ke dalam stack dan queue, dan kemudian karakter-karakter tersebut dikeluarkan dari stack dan queue secara bergantian untuk membandingkannya. Jika urutan karakter yang dikeluarkan dari stack dan queue sama, maka kalimat tersebut merupakan palindrom; jika tidak, maka bukan palindrom. Hasil pemeriksaan akan ditampilkan kepada pengguna.



## Unguided 2
### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?
 



```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string kataTerbalik(string kata)
{
    stack<char> charStack;
    for (char c : kata)
    {
        charStack.push(c);
    }
    string kataTerbalik = "";
    while (!charStack.empty())
    {
        kataTerbalik += charStack.top();
        charStack.pop();
    }
    return kataTerbalik;
}
string KalimatTerbalik(string Kalimat)
{
    stack<string> kataStack;
    string kata = "";
    for (char c : Kalimat)
    {
        if (c == ' ')
        {
            kataStack.push(kata);
            kata = "";
        }
        else
        {
            kata += c;
        }
    }
    kataStack.push(kata);
    string KalimatTerbalik = "";
    while (!kataStack.empty())
    {
        KalimatTerbalik += kataTerbalik(kataStack.top()) + " ";
        kataStack.pop();
    }
    return KalimatTerbalik;
}
int main()
{
    string Kalimat;
    cout << "Masukkan Kalimat : ";
    getline(cin, Kalimat);
    cout << "Kalimat : " << Kalimat << endl;
    cout << "Kalimat Terbalik : " << KalimatTerbalik(Kalimat) << endl;
    return 0;
}
```
#### Output:
![image](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/37fdbdef-03c1-4a3d-b247-124f780d23b9)


Kode di atas adalah program yang membalikkan setiap kata dalam sebuah kalimat dengan menggunakan struktur data stack dari C++ STL. Program pertama-tama meminta pengguna memasukkan kalimat. Setelah menerima input, program memproses setiap karakter dalam kalimat. Ketika program menemukan spasi, dia memasukkan kata-kata yang telah dibuat ke dalam stack 'kataStack'. Setelah kata-kata dimasukkan ke dalam stack, program mengeluarkan kata-kata satu per satu dari stack dan menggunakan fungsi 'kataTerbalik' untuk membalikkan kata-kata tersebut, sehingga membentuk kalimat terbalik. Hasilnya, program mencetak kalimat asli ke layar dan mencetak kalimat terbalik.

## Kesimpulan
Meskipun menggunakan metode dan fitur yang berbeda, ketiga kode tersebut merupakan implementasi struktur data stack dalam bahasa C++. Sementara kode pertama dan kedua berfokus pada penggunaan stack dengan array dan melakukan operasi dasar seperti push, pop, dan peek, serta fungsi lainnya seperti isFull, isEmpty, countStack, changeArrayBook, destroyArrayBook, dan cetakArrayBook, kode ketiga membalikkan setiap kata dalam sebuah kalimat dengan menggunakan struktur data stack yang disediakan oleh C++ STL. Meskipun tujuan dan fokus penggunaan stack dalam masing-masing dari ketiga kode tersebut berbeda, inti dari penggunaan stack adalah untuk memanipulasi data dengan cara yang sesuai dengan kebutuhan program tertentu.


## Referensi
[1] Erkamim, E., Abdurrohim, I., Yuliyanti, S., Karim, R., Rahman, A., Admira, T. M. A., & Ridwan, A. (2024). Buku Ajar Algoritma dan Struktur Data. PT. Sonpedia Publishing Indonesia.
<br>
[2 ]Nugraha, M. (2021). Dasar Pemrograman Dengan C++ Materi Paling Dasar Untuk Menjadi Programmer Berbagai Platform. Deepublish.
