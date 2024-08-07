#include <iostream>

int main (){
    double a = 1/3*3, b = 1.0/3.0*3.0, c = 2.93333333333333333;
    int ai = 1/3*3, bi = 1.0/3.0*3, ci=c;
    std::cout << "a = " << a << ", ai = " << ai
    << "\nb = " << b << ", bi = " << bi
    << "\nc = " << c << ", ci = " << ci
    << std::endl;
    return 0;
}