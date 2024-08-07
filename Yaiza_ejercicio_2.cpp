#include <iostream>
#include <complex>
using namespace std;

/* Definir constante. En este caso estamos trabajando con numeros complejos.
Esto significa que las matrices siempre seran de 2x2*/
const int N = 2;

// definir la estructura del array
struct Struct_array {
    double arr[N][N];
};

//crear funcion para imprimir complejo
void print_complex(double real, double imaginaria, string desc){
    std::cout << desc << real;
    if (imaginaria >= 0) {
        std::cout << " + ";
    } else {
        std::cout << " - ";
    }
    std::cout << std::abs(imaginaria) << "i" << std::endl;
}

// crear funcion para imprimir matriz
void print_matrix(Struct_array array, double real, double imaginaria){
    if (imaginaria >= 0){
    cout << "\t--Matrix de " << real << "+" << imaginaria << "i--\n";
    }
    else{cout << "\t--Matrix de " << real << imaginaria << "i--\n";
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout<<"\t"<<array.arr[i][j] <<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

// crear funcion para sumar las dos matrices
Struct_array sum_matrix(Struct_array p, Struct_array q){
    Struct_array result_sum;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result_sum.arr[i][j] = p.arr[i][j] + q.arr[i][j];
        }
    }
    return result_sum;
}

// crear funcion para multiplicar las dos matrices
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

int main () {
    std::cin.exceptions(std::ios_base::failbit);
    // declaracion de variables
    double a, b, c, d; /*vease que se piden dos doubles por cada numero
    complejo por ser mas intuitivo que pedir el complejo con su formato correcto
    (entre parentesis y separando parte real e imaginaria con una coma)*/ 
    try{ // comprobar que el usuario introduce correctamente los numeros complejos
    std::cout << "Introduzca el primer numero complejo (valor real + valor imaginario):\t"; 
    std::cin >> a >> b;
    std::cout << "Introduzca el segundo numero complejo (valor real + valor imaginario):\t";  
    std::cin >> c >> d;
    } // si no lo hace, lanzar error y finalizar
    catch(std::ios_base::failure &error){
        std::cout << "Error! El numero complejo no tiene el formato correcto\n";
        std::cout << "Ejemplo de entrada: 2.0 4.55 \n";
        std::cout << "Intentelo de nuevo.";
        throw;
    }
    std::complex<double> x(a,b), y(c,d); // ahora declarar los complejos
    // Hacer las operaciones y escribir el resultado en consola
    print_complex(x.real(), x.imag(), "El primer numero complejo introducido es: ");
    print_complex(y.real(), y.imag(), "El segundo numero complejo introducido es: " );
    std::complex<double> sum = x + y;
    print_complex(sum.real(), sum.imag(), "La suma de ambos numeros complejos es: " );
    std::complex<double> product = x * y;
    print_complex(product.real(), product.imag()
    , "El producto de ambos numeros complejos es: " );
    // Declarar matrices por cada uno de los numeros complejos
    Struct_array matrix_1 = {real(x), -imag(x), imag(x), real(x)};
    Struct_array matrix_2 = {real(y), -imag(y), imag(y), real(y)};
    // Realizar las operaciones con las matrices y escribit el resultado en consola
    Struct_array suma = sum_matrix(matrix_1, matrix_2);
    Struct_array producto = product_matrix(matrix_1, matrix_2);
    std::cout << "La suma y el producto de dos numeros complejos puede calcularse sumando";
    std::cout << "y multiplicando sus respectivas matrices\n";
    std::cout << "La matriz correspondiente al primer numero complejo es:\n";
    print_matrix(matrix_1, real(x), imag(x));
    std::cout << "La matriz correspondiente al segundo numero complejo es:\n";
    print_matrix(matrix_2, real(y), imag(y));
    std::cout << "La matriz resultado de esta suma es:\n";
    print_matrix(suma, suma.arr[0][0], suma.arr[1][0]);
    std::cout << "La matriz resultado del producto es:\n";
    print_matrix(producto, producto.arr[0][0], producto.arr[1][0]);
  return 0;
}
