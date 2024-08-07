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
    std::cout << "El primer numero complejo introducido es: " << x.real();
    if (x.imag() >= 0) {
        std::cout << " + ";
    } else {
        std::cout << " - ";
    }
    std::cout << std::abs(x.imag()) << "i" << std::endl;

    std::cout << "El segundo numero complejo introducido es: " << y.real();
    if (y.imag() >= 0) {
        std::cout << " + ";
    } else {
        std::cout << " - ";
    }
    std::cout << std::abs(y.imag()) << "i" << std::endl;

    std::complex<double> sum = x + y;
    std::cout << "La suma de ambos numeros complejos es: " << sum.real();
    if (sum.imag() >= 0) {
        std::cout << " + ";
    } else {
        std::cout << " - ";
    }
    std::cout << std::abs(sum.imag()) << "i" << std::endl;

    std::complex<double> product = x * y;
    std::cout << "El producto de ambos numeros complejos es: " << product.real();
    if (product.imag() >= 0) {
        std::cout << " + ";
    } else {
        std::cout << " - ";
    }
    std::cout << std::abs(product.imag()) << "i" << std::endl;
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