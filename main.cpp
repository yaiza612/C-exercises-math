#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    string ms {"Hello World"}; //For writing a comment in the code you do this
    cout << ms;
}

/*you can write comments of multiple lines like this:
hola que tal? */