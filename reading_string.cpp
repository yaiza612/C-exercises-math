#include <iostream>
#include <complex>
using namespace std;


/*int main(){
    double x;
    char y; 
    string x_text;
    string text = "sdgsd dfgdfgh ";
    /* std::cin >> text; 
    x_text = text.substr(0, text.find(" "));
    x = stod(x_text);
    return 0;} */



using namespace std;

int main()
{
    cout << "Hola! Este es un ejemplo en C++" << "\n" << "Por favor ingrese su nombre:" << "\n";
    //Volvemos a mostrar el mismo mensaje, pues para mostrar datos no hay problemas

   string nombre;//Seguimos usando string para almacenar el nombre
   //cin >> nombre; //Esta línea da problemas si se lee un valor con espacios
   // En su lugar, usamos getline, con el flujo de entrada de cin y lo asignamos as nombre
   getline(cin, nombre); //Esta línea no dará problemas con los espacios en el nombre

   cout << "Bienvenido al sistema " << nombre << ". Gracias por usar nuestra aplicación" << "\n";


   return 0;
}