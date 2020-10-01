#include <iostream>
#include <fstream>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Часть 2
        Снова считайте все содержимое файла input.txt, 
        но на этот раз выведите его в файл output.txt. 
        Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки.

         Пример: 
            input.txt:
                Keep calm
                and
                learn C++

            output.txt:
                Keep calm
                and
                learn C++
                
*/

int main() {
    ifstream input("inputAndoutput/input.txt");
    ofstream output("inputAndoutput/output.txt");
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            output << line << endl;
        }
    }
    return 0;
}