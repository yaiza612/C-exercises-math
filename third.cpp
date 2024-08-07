#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

const std::string filename = "diarioActividad.txt";

struct maquinas{
    char id;
    char inicio;
    char final;
    char tipo;
};

int main() {
    std::ifstream fich_in(filename.c_str(), std::ios::in);
    if (!fich_in) {
        std::cout << "Error, no es posible leer el fichero " << filename << std::endl;
        return 1;
    }
    /*int numLines = 0;
    std::string unused;
    while ( std::getline(fich_in, unused) ){
        ++numLines;};
    std::cout << numLines;
    maquinas arr[numLines];*/
    std::vector<std::string> fila;
    std::string line, word, temp;
    while (fich_in >> temp) {
  
        fila.clear();
  
        // read an entire row and
        // store it in a string variable 'line'
        getline(fich_in, line);
        std::cout << line + '\n';
        // used for breaking words
        std::stringstream s(line);
        //std::cout << line + '\n';
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ' ')) {
  
            // add all the column data
            // of a row to a vector
            fila.push_back(word);
        }
    
        std::cout << fila[1];

    }
}