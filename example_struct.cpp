#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct employee {
    int id;
    char department[25];
    float hours;
};

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    string inFilename, outFilename, buffer;
    struct employee emp;

    cout << "Please give me two file names" << endl;
    /* validate all input succeeds */
    if (!getline (cin, inFilename)) {
        cerr << "error: invalid input for input file.\n";
        return 1;
    }
    if (!getline (cin, outFilename)) {
        cerr << "error: invalid input for output file.\n";
        return 1;
    }

    /* open file in binary mode 'ios::binary' */
    inputFile.open (inFilename, ios::binary);

    /* valdiate all files open for reading/writing */
    if (!inputFile.is_open()) {
        perror (("error opening: " + inFilename).c_str());
        return 1;
    }
    outputFile.open (outFilename);
    if (!outputFile.is_open()) {
        perror (("error opening: " + outFilename).c_str());
        return 1;
    }

    /* while each read succeeds, write to output file */
    while (inputFile.read (reinterpret_cast<char*>(&emp), sizeof(emp)))
    {
        outputFile << "Id:\t" << emp.id << endl;
        outputFile << "Department:\t" << emp.department << endl;
        outputFile << "Hours:\t" << emp.hours << endl;
    }

    inputFile.close();  /* close files */
    outputFile.close();
    cout << emp.id;
    return 0;
}