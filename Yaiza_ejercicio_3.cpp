#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//Definir las constantes globales 
const string filename = "diarioActividad.txt";
const string prefijo = "M"; 

// Crear variables para obtener los diferentes datos del fichero
string id;
string inicio;
string final;
string tipo;

/*Quiero trabajar con un diccionario (mapa) de estructuras, para ello
primero debo de definir la estructura que usaré*/
struct maquina{
    int id; // el id sera un numero entero para poder usarlo luego para sortear por orden
    int auto_n;
    int manual_n;
    int error_n;
    int tiempo_auto; 
};


struct comparador {
    bool operator()(const pair<string, maquina>& x, const pair<string, maquina>& y) const {
        return x.second.id < y.second.id;
    }
}; //gracias a esta función podremos ordenar por id

// Definir una función para calcular la duración:
int calcular_duracion(string tiempo_1, string tiempo_2){ 
    tm t_1{}, t_2{};

    istringstream stream_1(tiempo_1);
    istringstream stream_2(tiempo_2);

    stream_1>> get_time(&t_1, "%H:%M");
    stream_2 >> get_time(&t_2, "%H:%M");

    auto empieza = chrono::hours(t_1.tm_hour) + chrono::minutes(t_1.tm_min);
    auto acaba = chrono::hours(t_2.tm_hour) + chrono::minutes(t_2.tm_min);

    int duracion = (acaba - empieza).count();  

    return duracion;
}

int main(){
    /*Leemos el archivo y utilizamos una condicion para comprobar que el fichero 
    puede ser leido y en caso de no ser asi devolver el error*/
    ifstream input;

    input.open(filename);

    if(!input.is_open()){
        cout << "Error, no es posible leer el fichero " << filename << std::endl;
        return 1;
    }

    map<string, maquina> maquinas; //Crear el mapa de estructuras
    int count = 0; 
    /* definir constante para comprobar que el codigo funciona
     sobre todas las lineas del archivo*/
    while(input>>id>>inicio>>final>>tipo){ //loop para leer linea por linea 
        
        struct maquina m = maquinas[id]; //declarar la estructura en el mapa
        
        input.get();
        
        string numero; 
        numero = id.substr(prefijo.length());
        m.id = stoi(numero); // obtener el id en forma de entero
        
        /*Condiciones para obtener la duracion en auto 
        y el numero total en auto, manual y error*/
        if (tipo == "AUTO"){ 
            m.tiempo_auto += calcular_duracion(inicio, final);
            m.auto_n += 1;
        }
        else if (tipo == "MANUAL"){
            m.manual_n +=1;
        }
        else if (tipo == "ERROR") { m.error_n +=1;
        }

       maquinas[id] = m; //introducir la estructura en el diccionario (mapa)

       count++;

       if(!input){ // comprobar que no ha habido errores en la lectura
            break;
        }
       

    }

    cout << "Numero de lineas leidas en el fichero " << count << endl;
    // para sortear el diccionario creamos un vector
    vector<pair<string, maquina>> v(maquinas.begin(), maquinas.end()); 
    // utilizar el comparador de estructuras para ordenar por id
    sort(v.begin(), v.end(), comparador()); 
    size_t size = v.size();
    cout << "Numero de maquinas: " << size << endl; 
    // Imprimir en consola toda la informacion obtenida
    for (const auto& key : v) {
        cout << "Nombre: " << key.first << ", id: " << key.second.id
                  << ", total en auto: " << key.second.auto_n  << ", total en manual: " 
                  << key.second.manual_n << ", total en error " << key.second.error_n
                  << ", tiempo en auto: " << key.second.tiempo_auto 
                  << " min" << endl;
    }

    input.close(); // cerrar el archivo
    return 0;
}