// C++ code for returning 2D array
// from function using static keyword
#include <iostream>
using namespace std;
const int N = 2;
 
// structure of array
struct Struct_array {
    int arr[N][N];
};
 
// function for display array
void printArray(Struct_array var)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << var.arr[i][j] << " ";
        }
        cout << endl;
    }
}
 
// function to initialize and returning array
Struct_array getArray()
{
    Struct_array var;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            var.arr[i][j] = i + j;
        }
    }
    return var;
}

Struct_array sum_matrix(Struct_array p, Struct_array q){
    Struct_array var;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            var.arr[i][j] = p.arr[i][j] + q.arr[i][j];}}
    return var;
}

Struct_array product_matrix(Struct_array n, Struct_array m){
    Struct_array result_product;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
                        result_product.arr[i][j] = 0;
                        for (int k = 0; k < N; k++){
            result_product.arr[i][j] += n.arr[i][k] * m.arr[k][j];

            }
           
        }
        
    }
    return result_product;
}

// Driver code
int main()
{
    Struct_array p;
    p = {1,1,1,1};
    printArray(p);
    Struct_array q;
    q = getArray();
    printArray(q);
    Struct_array sum; 
    sum = sum_matrix(p, q);
    printArray(sum);
    Struct_array s;
    s = {3,3,2,3};
    Struct_array product;
    product = product_matrix(p,s);
    printArray(s);
    cout << s.arr[0][0];
    cout << s.arr[1][0];
    return 0;
}