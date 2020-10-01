#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   <fstream> - библиотека для работы с вводом и выводом
        <ifstream> - библиотека для работы с вводом
        <ofstream> - библиотека для работы с выводом
        flag for ofstream ios::app means appending string to already existing file.
        ofstream output(path, ios::app) appends to the end of the file next lines of the code
        getline(ifstream input(path), string variable, EOF) to read a line and write down to the variable with type string or read till the end of line 
        <iomanip> - library for working with manipulators of input 
        cout << fixed(instead of 1e-3 outs 0.003) << setprecision(2);fixed - (<iomanip> library) means to output next all values with standard view, 
        setprecision(2)(<iomanip> library) - output first 2 values after comma 
        cout << setw(n) << variable << ' '; (reserving n columns for a variable to output)
        cout << setfill('.'); - fullfill all blank lines with dots
        cout << left; - do it starting from the right and ending at the left of the line;
*/

/*function to read information from the file
void ReadAll(const string& path) {
    ifstream input(path);
    if (input) {
        string line;
        while (getline(input, line)) {
            cout << line << endl;
        }
    }
}
string path = "output.txt";
ofstream output(path)
output << "hello " << endl; // "hello "

ofstream output(path, ios::app);
output << " world" << endl; // "hello
                                 world"
*/

void Print(const vector<string>& names, const vector<double>& values, int width) {
    for (const auto& n : names) {
        cout << setw(width) << n << ' ';
    } 
    cout << endl;
    cout << fixed << setprecision(2);
    for (const auto& b: values) {
        cout << setw(width) << b << ' '; 
    }
}

int main() {
    vector<string> names = {"a", "b", "c"};
    vector<double> values = {5, 0.01, 0.000005};
    cout << setfill('.');
    //cout << left;
    Print(names, values, 10);
    
    return 0;
}