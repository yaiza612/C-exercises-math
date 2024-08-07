#include <iostream>
#include <iomanip>

int main() {
    double uno = 1.0, dos = 1.414, tres = 1.732, cuatro = 2.0, cinco = 2.236;
    std::cout<< std::fixed << std::setprecision(3) << 
     "N \t Raiz cuadrada \n" <<
     "1 \t" << uno << "\n" <<
     "2 \t" << dos << "\n" <<
     "3 \t" << tres << "\n" <<
     "4 \t" << cuatro << "\n" <<
     "5 \t" << cinco << "\n" 
     << std::endl;
     return 0;
}