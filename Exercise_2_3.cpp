#include <iostream>
#include <iomanip>

int main() {
    std::cout<< std::fixed << std::setprecision(3) << 
     "N \t\t Raiz cuadrada \n" <<
     "1 \t\t" << 1.0000 << "\n" <<
     "2 \t\t" << 1.414 << "\n" <<
     "3 \t\t" << 1.732 << "\n" <<
     "4 \t\t" << 2.000 << "\n" <<
     "5 \t\t" << 2.2360 << "\n" 
     << std::endl;
     return 0;
}