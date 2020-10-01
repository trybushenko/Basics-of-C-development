#include <iostream>
/*
В стандартном потоке даны три строки, разделённые пробелом. 
Каждая строка состоит из строчных латинских букв и имеет длину не более 30 символов. 
Выведите в стандартный вывод лексикографически минимальную из них.
*/

using namespace std;

int main(int argc, const char** argv) {
    int a, b;
    cin >> a >> b;
    if (b == 0) {
        cout << "Impossible";
        return 0;
    }
    double div = a / b;
    cout << div;  
    return 0;
}