#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Longitud (formato por defecto): " << 1.8333333333333 << " m. " << std::endl;
    std::cout << "Longitud: " << std::setw(5) << std::setprecision(3) 
    << 1.833333333333333 << " m. " << std::endl;
    std::cout << "Longitud: " << std::setprecision(2) << 1.83333333333 << " m. " << std::endl;
    std::cout << "Longitud: " << std::setw(10) << std::setfill('*') 
    << 1.83333333333333 << " m. " << std::endl;
    std::cout << "Longitud: " << std::scientific << std::setprecision(4)
    <<1.833333333333333 << " m. " << std::endl;
    return 0;
}
