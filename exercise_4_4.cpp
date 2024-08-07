#include <iostream>

int main (){
    int *p1;
    int v1 = 10;
    p1 = &v1;
    *p1 = 42;
    std::cout << v1 << "\t" << *p1 << std::endl; 
    return 0;

}