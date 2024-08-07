#include <iostream>
using namespace std;


int main () {
    int x, y; 
    cout << "Introduce dos enteros: \t";
    cin >> x >> y;
    cout << "---------------------------------------\n";
    cout << "Los numeros enteros introducidos son: \n";
    cout << x << " y " << y << "\n";
    cout << "Suma: " << x + y << "\n";
    cout << "Resta: " << x - y << "\n";
    cout << "Division entera: " << x / y << "\n";
    cout << "Modulo: " << (x & y) << "\n";
    cout << "Division: " << (double)x / y << "\n";
    cout << "----------------------------------------";
    return 0;
}

