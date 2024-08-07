#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

int main()
{
  
    // File pointer
    std::fstream fin;
  
    // Open an existing file
    fin.open("diarioActividad.txt", std::ios::in);

  
    // Read the Data from the file
    // as String Vector
    std::vector<std::string> row;
    std::string line, word, temp;
  
    while (fin >> temp) {
  
        row.clear();
  
        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);
        std::cout << line;
        // used for breaking words
        std::stringstream s(line);
  
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ' ')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);

        }

  
    }

}

