#include <iostream>
#include "externsC.h"
#include "sum.cpp"
using namespace std;

double x, y;

int main() {
    double result;
    cout << "Introduce the first sum";
    cin >> x;
    cout << "Introduce the second sum";
    cin >> y;
    result = sum(x, y);
    cout << "El resultado es: \n";
    cout << result;
    return 0;
}