#include <iostream>
#include <iomanip>

using namespace std;
// Tipe Data Primitif
int main (){
    char op;
    float num1, num2;

    cout<< "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "enter two oprands: ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '+':
        cout << "Result: " << num1 + num2;
        break;
    case '-':
        cout << "Result: " << num1 - num2;
        break;
     case '*':
        cout << "Result: " << num1 * num2;
        break;
    case '/':
        if (num2 != 0){
            cout << "Result: "<< fixed << setprecision(2) << num1 / num2;
        } else{
            cout << "Error! Division by zero is not allowed.";
        }
        break;
    default:
    cout << "Error! Operator is not correct";
        break;
    }
    return 0;
}