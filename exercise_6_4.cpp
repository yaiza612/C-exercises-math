#include <iostream>

int main() {
    int x =-5, y = 8;
    bool b1 = ! (y < 3) || y > 7 ;
    bool b2 = (x + 1) > 2 || (x + 1) < -3;
    bool b3 = x + 1 > 2 || x + 1 < -3;
    bool b4 = !( y == 0);
    bool b5 = x < 0 && x/y > 1; 
    std::cout << std::boolalpha
    << "b1 = " << b1 << ", " 
    << "b2 = " << b2 << ", " 
    << "b3 = " << b3 << ", " 
    << "b4 = " << b4 << ", " 
    << "b5 = " << b5 << std::endl;
    return 0; 
}