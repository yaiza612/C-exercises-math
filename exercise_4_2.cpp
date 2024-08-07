#include <iostream>

int x, y;

int main() {
    x=10;
    std::cout << x << std::endl;
    int x;
    x=20;
    std::cout << x << std::endl;
    y= ::x;
    std::cout << y << std::endl;
    return 0;
}