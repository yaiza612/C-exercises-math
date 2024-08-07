#include <iostream>
using namespace std;

/* Primero defino cuatro funciones para realizar las diferentes conversiones*/
// conversion de celsius a fahrenheit
double conversion_c_f(double p) { 
    double a; 
    a = (p * 1.8) + 32 ;
    return a;
}
// conversion de celsius a kelvin
double conversion_c_k(double q) {
    double b; 
    b = q + 273.15 ;
    return b;
}
// conversion de fahrenheit a celsius
double conversion_f_c(double r) {
    double c; 
    c = (r / 1,8) - 32 ;
    return c;
}
//conversion de kelvin a celsius
double conversion_k_c(double s) {
    double d; 
    d = s - 273.15 ;
    return d;
}


/* Ahora el programa principal usa las funciones definidas 
con anterioridad para 
realizar la funcion pedida de convertir cualquier temperatura 
en cualquiera de las unidades C, F, K*/
int main () {
    // declaracion de variables
    double x;
    char y; 
    // pedir al usuario la temperatura
    std::cout << "Escriba la temperatura con sus unidades (C, F, K):\t"; 
    std::cin >> x >> y;
    switch (y)
    {
    case 'C':  // si la temperatura es celsius
        if (x < -273.15 ){ // primero comprobar que el valor es valido para celsius
            std::cout << "Esta temperatura es fisicamente imposible. \n";
            std::cout << "En Celsius la temperatura por debajo de -273.15 C no existe. ";
            std::cout << "Por favor intentelo de nuevo." ;
            break;
        }
        double fahrenheit_1;
        double kelvin_1;
        fahrenheit_1 = conversion_c_f(x); // realizar las conversiones
        kelvin_1 = conversion_c_k(x); 
        std::cout << x << " C, " << fahrenheit_1 << " F, " << kelvin_1 << " K"; // output
        break;
    case 'F': // si la temperatura es fahrenheit 
        if (x < -459.67){ // primero comprobar que el valor es valido para fahrenheit
            std::cout << "Esta temperatura es fisicamente imposible. \n";
            std::cout << "En Fahrenheit la temperatura por debajo de -459.67 F no existe. ";
            std::cout << "Por favor intentelo de nuevo.";
            break;
        }
        double celsius_1;
        double kelvin_2;
        celsius_1 = conversion_f_c(x); // realizar la conversiones
        kelvin_2 = conversion_c_k(celsius_1);
        std::cout << celsius_1 << " C, " << x << " F, " << kelvin_2 << " K"; // output
        break;
    case 'K': // si la temperatura es kelvin 
        if (x < 0){ // primero comprobar que el valor es valido para kelvin
            std::cout << "Esta temperatura es fisicamente imposible. \n";
            std::cout << "En Kelvin la temperatura por debajo de 0 K no existe. ";
            std::cout <<  "Por favor intentelo de nuevo.";
            break;
        }
        double celsius_2; 
        double fahrenheit_2;
        celsius_2 = conversion_k_c(x); // realizar la conversiones 
        fahrenheit_2 = conversion_c_f(celsius_2);
        std::cout << celsius_2 << " C, " << fahrenheit_2 << " F, " << x << " K"; //output
        break;
    default:
    /* Si el usuario no introdujo la temperatura en el formato correcto,
     ya sea porque no introdujo un numero, se le olvidaron las unidades
    o puso unidades incorrectas, 
    darle feedback al usuario para que use de nuevo el programa de forma correcta*/
        std::cout << "Error! La temperatura introducida,";
        std::cout << "no tiene el formato correcto (valor + unidades en C, F o K).\n";
        std::cout << "Un ejemplo de uso seria: 24.2 C. \n";
        std::cout << "Por favor, intentelo de nuevo.\n";
        break;
    }
    return 0;
}