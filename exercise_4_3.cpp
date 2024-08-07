#include <iostream>

int x1, x2, x3; 

int main (){
    x1 = 1; 
    {//Inicio del bloque
    std::cout << x1 << "\t";
    int x1 = 4; 
    std::cout << x1 << "\t";{
        //inicio de segundo bloque
        x2 = x1;
        std::cout << x2 << "\t";
        std::cout << ::x1 << "\t";
    }}
    std::cout << x1 << std::endl;
    return 0;
}