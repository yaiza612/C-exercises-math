# include <iostream> 

int main () {
    double blocks [] = {10, 20, 30, 40};
    std::cout << *blocks << ", " << * (blocks+2)
    << ", " << *blocks+2 << std::endl;

    double *ptr = blocks;
    std::cout << *ptr << ", " << *ptr+1 << ", "
    << * (ptr+1) << std::endl;
    return 0;
}