#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// definir las constantes globales
const bool MODO_DEBUG = true;
const int N = 10;

// crear estructura para recoger los estados y el numero entre 0 y 1
struct Tabla_de_estados 
{
    int estado_S_1;
    int random_numero;
    int estado_S_2;
};
// crear array de estructuras con los datos de los estados y sus transiciones
static const Tabla_de_estados t[]=
{
    { 0, 0, 2},
    { 0, 1, 1},
    { 1, 0, 1},
    { 1, 1, 4},
    { 2, 0, 5},
    { 2, 1, 3},
    { 3, 0, 6},
    { 3, 1, 7},
    { 4, 0, 5},
    { 4, 1, 7},
    { 5, 0, 5},
    { 5, 1, 1},
    { 6, 0, 6},
    { 6, 1, 7},
    { 7, 0, 7},
    { 7, 1, 7},
};

// crear estructura de los datos que queremos imprimir en consola
struct informe{
    int n_transicion;
    int replicas = 0;
};

// crear funcion para calcular el index al que ir y hacer el codigo más rápido y eficiente
int index(int a, int b){
    int result = a*2 + b;
    return result;
}


// crear función para comparar y sortear por numero de transiciones
struct comparador {
    bool operator()(const pair<string, informe>& x, const pair<string, informe>& y) const {
        return x.second.n_transicion< y.second.n_transicion;
    }
};

int main(){
    if (MODO_DEBUG){cout << "Evolucion del automata en " << N << " replicas" << endl;} 
    /* Las condiciones 
    ayudaran a imprimir en caso de de estar en modo debug TRUE*/
    // Definir las distintas variables:
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_real_distribution<double> dis(0.0, 1.0); 
    int T[N]; 
    map<string, informe> informes; 
    // loop para realizar N veces el experimento
    for(int i= 0; i< N; i++){ 
        int estado = 0; 
        int transicion = 0;
        if (MODO_DEBUG){cout << "S" << estado;}

        
        while(estado != 7){ // loop para realizar el experimento
            double random = dis(gen);
            int number = round(random); // definir numero pseudorandom entre 0 y 1
            int n = index(estado, number); // calcular el index del array
            estado = t[n].estado_S_2; // update el estado
            transicion += 1; // recoger numero de transiciones
            if (MODO_DEBUG){cout << ", " << number << ", " << "S" << estado;} 

    
        
        }
        T[i] = transicion; // recoger transiciones en array
        if (MODO_DEBUG){cout << endl;} 
    
    }

    if (MODO_DEBUG){cout << "\n" << "Contenido del vector T:" << endl;}
    for (int t: T){ 
        struct informe z = informes[to_string(t)];
        z.n_transicion = t; 
        z.replicas += 1; // popular las estructuras del diccionario
        informes[to_string(t)] = z; // popular el diccionario
        if (MODO_DEBUG){cout << t << " ";}
    }
    if (MODO_DEBUG){cout << "\n\n";}
    cout << "Informe sobre el numero de transiciones:" << endl;
    vector<pair<string, informe>> v(informes.begin(), informes.end()); 
    /*crear vector para sortear 
    por numero de transiciones*/ 
    sort(v.begin(), v.end(), comparador()); 
    for (const auto& key : v) { // imprimir en consola los datos recogidos.
        cout << key.second.n_transicion << " transiciones en " 
             << key.second.replicas << " replicas" << endl; 
    }

    return 0;
}
