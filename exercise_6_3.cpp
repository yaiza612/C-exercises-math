
#include <iostream>

int main (){
    
    int i = 42; 
    int k = i;
    int *p = &i;
    *p = 99;
    std::cout << "i = " << i
    << std::endl;
    return 0;
}

// *p modify the value of i