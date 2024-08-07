#include <iostream>
using namespace std;

//Funtion
double suma (double, double) ;

double x, y;

int main () {
    double result; 
    cout << "Introduce the first number for the sum \n";
    cin >> x;
    cout << "Introduce the second number for the sum \n";
    cin >> y;
    result = suma(x, y);
    cout << "El resultado es: \n";
    cout << result;
    return 0;
}

double suma(double x1, double y1) {
    double result;
    result = x1 + y1;
    return result;
}