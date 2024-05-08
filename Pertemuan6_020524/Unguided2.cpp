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