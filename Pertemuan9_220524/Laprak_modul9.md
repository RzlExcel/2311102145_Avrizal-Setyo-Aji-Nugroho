# <h1 align="center">Laporan Praktikum Modul GRAPH DAN TREE</h1>
<p align="center">Avrizal Setyo Aji Nugroho</p>
<p align="center">2311102145</p>

## Dasar Teori

Dalam ilmu komputer, graf dan pohon adalah struktur data penting yang digunakan untuk menunjukkan data dan hubungannya. Graf terdiri dari simpul (nodes) dan sisi (edges). Simpul-sisi ini menghubungkan satu sama lain, sehingga graf dapat bersifat terarah (directed) atau tak terarah (undirected). Dalam banyak aplikasi, seperti representasi peta, jaringan komputer, dan jaringan sosial, graf berarah memiliki setiap sisi yang menunjukkan arah dari simpul ke simpul. Untuk menemukan jalur atau siklus di dalam graf, algoritma seperti Breadth-First Search (BFS) dan Depth-First Search (DFS) digunakan.

Pohon adalah jenis graf yang terhubung sepenuhnya dan tidak memiliki siklus. Dalam pohon, satu simpul disebut akar (root), dan setiap simpul memiliki satu induk (parent), kecuali akar yang tidak memiliki induk. Pohon keputusan, struktur organisasi, dan sistem file adalah beberapa struktur hierarki yang diwakili oleh pohon. Pohon biner adalah pohon dengan paling banyak dua anak di setiap simpul. Salah satu cara untuk mengunjungi semua simpul dalam pohon adalah dengan melewati pohon, seperti pre-order, in-order, dan post-order. Salah satu jenis pohon biner yang digunakan untuk mencari data dengan cepat adalah pohon pencarian biner. Pohon sangat baik untuk pencarian, penyisipan, dan penghapusan karena struktur dan sifatnya.


## Guided 

### 1. Program Graph

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekai", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}};

void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << " )";
            }
        }
        cout << endl;
    }
}

int main()
{
    tampilGraph();
    return 0;
}
```
Kode di atas adalah program C++ yang menggunakan matriks adjacency yang sudah didefinisikan sebelumnya untuk menampilkan representasi graf berbobot. Array yang digunakan adalah "simpul", yang mengandung nama simpul (kota), dan "busur", yang merupakan matriks adjacency berukuran 7 x 7 untuk menunjukkan bobot antara simpul. Untuk mencetak graf ke layar, fungsi "tampilGraph" digunakan. Fungsi ini melakukan iterasi melalui setiap baris dalam matriks adjacency dan menampilkan nama simpul awal, diikuti dengan daftar simpul tujuan yang terhubung, asalkan bobotnya tidak nol. Untuk menampilkan graf, fungsi "main" hanya menghubungi fungsi "tampilGraph". Untuk input/output, program ini menggunakan library iostream dan iomanip untuk mengatur format output secara menyeluruh.
## Guided 

### 2. Program Tree

```C++
#include <iostream>

using namespace std;

// Program Binary Tree

// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

// Inisialisasi
void init()
{
    root = NULL;
}

// Cek Node
int isEmpty()
{
    if (root == NULL)
        return 1; // true
    else
        return 0; // false
}

void buatNode(char data)
{
    if (isEmpty() == 1)
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\n Pohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kiri ada atau tidak
        if (node->left != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}
// Tambah Kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (root == NULL)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kanan ada atau tidak
        if (node->right != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}
// Ubah Data Tree
void update(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
// Lihat Isi Data Tree
void retrieve(Pohon *node)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
// Cari Data Tree
void find(Pohon *node)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus Tree
void clear()
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void charateristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}
int main()
{
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);

    retrieve(nodeC);

    find(nodeC);

    cout << "\n"
         << endl;
    charateristic();

    cout << "\n PreOrder :" << endl;
    preOrder(root);

    cout << "\n"
         << endl;
    cout << " InOrder :" << endl;
    inOrder(root);

    cout << "\n"
         << endl;
    cout << " PostOrder :" << endl;
    postOrder(root);
}
```
Kode di atas adalah program C++ untuk manipulasi pohon biner yang mencakup operasi dasar seperti pembuatan, penambahan, pengubahan, dan penghapusan node, serta traversal dan penghitungan karakteristik pohon. Program ini menginisialisasi pohon biner dengan `init()`, memeriksa kekosongan dengan `isEmpty()`, dan membuat node baru dengan `buatNode()`. Fungsi `insertLeft()` dan `insertRight()` menambah anak kiri dan kanan pada node tertentu, sementara `update()` mengubah data node, dan `retrieve()` serta `find()` menampilkan data node. Program juga mendukung traversal pre-order, in-order, dan post-order dengan fungsi `preOrder()`, `inOrder()`, dan `postOrder()`. Penghapusan pohon dilakukan dengan `deleteTree()` dan `clear()`, sedangkan fungsi `size()` dan `height()` menghitung ukuran dan tinggi pohon, yang digunakan dalam `characteristic()` untuk menampilkan karakteristik pohon. Program diakhiri dengan `main()`, yang mendemonstrasikan berbagai operasi ini pada pohon contoh.


## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya. Output Program
![Screenshot 2024-05-28 230451](https://github.com/RzlExcel/2311102145_Avrizal-Setyo-Aji-Nugroho/assets/151628376/c2c5f07a-bef3-40e5-a200-bd2dd22ed52b)


```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int num_nodes;

    // Input jumlah simpul (kota)
    cout << "Silakan masukan jumlah simpul: ";
    cin >> num_nodes;
    cin.ignore(); // Mengabaikan karakter newline setelah input integer

    vector<string> nodes(num_nodes);

    // Input nama simpul (kota)
    cout << "Silahkan Masukkan Nama Simpul\n";
    for (int i = 0; i < num_nodes; ++i)
    {
        cout << "Simpul " << i + 1 << ": ";
        getline(cin, nodes[i]);
    }

    // Inisialisasi matriks adjacency
    vector<vector<int>> adj_matrix(num_nodes, vector<int>(num_nodes, 0));

    // Input bobot antar simpul (kota)
    cout << "Silahkan masukkan bobot antar simpul\n";
    for (int i = 0; i < num_nodes; ++i)
    {
        for (int j = 0; j < num_nodes; ++j)
        {
            cout << nodes[i] << "-->" << nodes[j] << ": ";
            cin >> adj_matrix[i][j];
        }
    }

    // Menampilkan matriks adjacency
    cout << "\n";
    cout << setw(8) << "";
    for (int i = 0; i < num_nodes; ++i)
    {
        cout << setw(8) << nodes[i];
    }
    cout << endl;

    for (int i = 0; i < num_nodes; ++i)
    {
        cout << setw(8) << nodes[i];
        for (int j = 0; j < num_nodes; ++j)
        {
            cout << setw(8) << adj_matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}

```
#### Output:
![Screenshot%20(52).png](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas merupakan program C++ untuk menginput dan menampilkan matriks adjacency yang merepresentasikan graf berbobot (weighted graph) antara beberapa simpul (nodes), yang dalam konteks ini adalah kota-kota. Pertama, program meminta pengguna untuk memasukkan jumlah simpul dan namanya. Kemudian, program menginisialisasi matriks adjacency dengan ukuran yang sesuai dengan jumlah simpul, yang diisi dengan bobot antar simpul yang dimasukkan oleh pengguna. Terakhir, program menampilkan matriks adjacency yang sudah terbentuk dalam format tabel, di mana baris dan kolom diberi label nama simpul untuk memudahkan pembacaannya. Program ini menggunakan library C++ standar seperti iostream untuk input dan output, vector untuk menyimpan data secara dinamis, string untuk mengatur nama simpul, dan iomanip untuk memformat output dengan benar.

## Unguided 

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
/*
    Avrizal Setyo Aji Nugroho
    2311102145
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

// Inisialisasi
void init()
{
    root = NULL;
}

// Cek Node
int isEmpty()
{
    return root == NULL;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Tambah Kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Ubah Data Tree
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nData node: " << node->data << endl;
        }
    }
}

// Cari Data Tree
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;
            if (!node->parent)
            {
                cout << "Parent: (tidak punya parent)" << endl;
            }
            else
            {
                cout << "Parent: " << node->parent->data << endl;
            }
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
            {
                cout << "Sibling: " << node->parent->left->data << endl;
            }
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
            {
                cout << "Sibling: " << node->parent->right->data << endl;
            }
            else
            {
                cout << "Sibling: (tidak punya sibling)" << endl;
            }
            if (!node->left)
            {
                cout << "Child Kiri: (tidak punya Child kiri)" << endl;
            }
            else
            {
                cout << "Child Kiri: " << node->left->data << endl;
            }
            if (!node->right)
            {
                cout << "Child Kanan: (tidak punya Child kanan)" << endl;
            }
            else
            {
                cout << "Child Kanan: " << node->right->data << endl;
            }
        }
    }
}

// Tampilkan Child dan Descendant dari Node
void displayChildren(Pohon *node)
{
    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    if (node->left)
    {
        cout << "Child Kiri: " << node->left->data << endl;
    }
    else
    {
        cout << "Child Kiri: (tidak punya Child kiri)" << endl;
    }
    if (node->right)
    {
        cout << "Child Kanan: " << node->right->data << endl;
    }
    else
    {
        cout << "Child Kanan: (tidak punya Child kanan)" << endl;
    }
}

void displayDescendants(Pohon *node)
{
    if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "Descendants of node " << node->data << ": ";
    cout << endl;
}

// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// inOrder
void inOrder(Pohon *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

// postOrder
void postOrder(Pohon *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (node != NULL)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    if (node == root)
    {
        root = NULL;
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (node != NULL)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (root != NULL)
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
    else
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
}

// Cek Size Tree
int size(Pohon *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + size(node->left) + size(node->right);
    }
}

// Cek Height Level Tree
int height(Pohon *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        return max(heightKiri, heightKanan) + 1;
    }
}

// Karakteristik Tree
void characteristic()
{
    cout << "\nSize Tree: " << size(root) << endl;
    cout << "Height Tree: " << height(root) << endl;
    cout << "Average Node of Tree: " << static_cast<double>(size(root)) / height(root) << endl;
}

Pohon *findNode(Pohon *node, char data)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->data == data)
    {
        return node;
    }
    Pohon *foundNode = findNode(node->left, data);
    if (foundNode == NULL)
    {
        foundNode = findNode(node->right, data);
    }
    return foundNode;
}

void menu()
{
    int choice;
    char data, parentData;
    Pohon *node, *parentNode;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Buat Node\n";
        cout << "2. Tambah Kiri\n";
        cout << "3. Tambah Kanan\n";
        cout << "4. Ubah Data Node\n";
        cout << "5. Lihat Isi Node\n";
        cout << "6. Cari Node\n";
        cout << "7. Tampilkan Child\n";
        cout << "8. Tampilkan Descendants\n";
        cout << "9. Hapus SubTree\n";
        cout << "10. Hapus Tree\n";
        cout << "11. Tampilkan Karakteristik Tree\n";
        cout << "12. PreOrder Traversal\n";
        cout << "13. InOrder Traversal\n";
        cout << "14. PostOrder Traversal\n";
        cout << "15. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan data untuk root: ";
            cin >> data;
            buatNode(data);
            break;
        case 2:
            cout << "Masukkan data untuk node baru: ";
            cin >> data;
            cout << "Masukkan data parent: ";
            cin >> parentData;
            parentNode = findNode(root, parentData);
            if (parentNode != NULL)
            {
                insertLeft(data, parentNode);
            }
            else
            {
                cout << "Parent tidak ditemukan!" << endl;
            }
            break;
        case 3:
            cout << "Masukkan data untuk node baru: ";
            cin >> data;
            cout << "Masukkan data parent: ";
            cin >> parentData;
            parentNode = findNode(root, parentData);
            if (parentNode != NULL)
            {
                insertRight(data, parentNode);
            }
            else
            {
                cout << "Parent tidak ditemukan!" << endl;
            }
            break;
        case 4:
            cout << "Masukkan data node yang ingin diubah: ";
            cin >> parentData;
            cout << "Masukkan data baru: ";
            cin >> data;
            parentNode = findNode(root, parentData);
            if (parentNode != NULL)
            {
                update(data, parentNode);
            }
            else
            {
                cout << "Node tidak ditemukan!" << endl;
            }
            break;
        case 5:
            cout << "Masukkan data node yang ingin dilihat: ";
            cin >> data;
            node = findNode(root, data);
            retrieve(node);
            break;
        case 6:
            cout << "Masukkan data node yang ingin dicari: ";
            cin >> data;
            node = findNode(root, data);
            find(node);
            break;
        case 7:
            cout << "Masukkan data node yang ingin dilihat child-nya: ";
            cin >> data;
            node = findNode(root, data);
            displayChildren(node);
            break;
        case 8:
            cout << "Masukkan data node yang ingin dilihat descendant-nya: ";
            cin >> data;
            node = findNode(root, data);
            displayDescendants(node);
            break;
        case 9:
            cout << "Masukkan data node yang ingin dihapus subtree-nya: ";
            cin >> data;
            node = findNode(root, data);
            deleteSub(node);
            break;
        case 10:
            clear();
            break;
        case 11:
            characteristic();
            break;
        case 12:
            cout << "PreOrder Traversal: ";
            preOrder(root);
            cout << endl;
            break;
        case 13:
            cout << "InOrder Traversal: ";
            inOrder(root);
            cout << endl;
            break;
        case 14:
            cout << "PostOrder Traversal: ";
            postOrder(root);
            cout << endl;
            break;
        case 15:
            cout << "Keluar..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    } while (choice != 15);
}

int main()
{
    init();
    menu();
    return 0;
}

```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas adalah program C++ modifikasi untuk manipulasi pohon biner pada guided tree(guided2) yang menyediakan berbagai operasi dasar pada pohon biner melalui menu interaktif. Program ini menggunakan struktur `Pohon` untuk merepresentasikan node dalam pohon biner, yang mencakup data, child kiri, child kanan, dan parent. Fungsi-fungsi seperti `buatNode`, `insertLeft`, `insertRight`, `update`, `retrieve`, `find`, `displayChildren`, `displayDescendants`, `deleteSub`, `clear`, `size`, dan `height` mengizinkan pengguna untuk membuat node, menambah node kiri atau kanan, memperbarui data node, menampilkan data node, mencari node, menampilkan child dan descendant, menghapus subtree atau seluruh pohon, serta menghitung ukuran dan tinggi pohon. Selain itu, program ini mendukung traversal pohon dalam tiga cara: preOrder, inOrder, dan postOrder. Semua fungsi tersebut diakses melalui fungsi `menu` yang menampilkan pilihan menu kepada pengguna dan memanggil fungsi yang sesuai berdasarkan input pengguna. Program ini memulai dengan menginisialisasi pohon menggunakan fungsi `init` dan kemudian memanggil fungsi `menu` dari fungsi `main`.


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
