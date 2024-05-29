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
