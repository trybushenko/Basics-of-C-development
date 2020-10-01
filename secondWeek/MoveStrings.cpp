#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination, 
и дописывает все строки из первого вектора в конец второго. 
После выполнения функции вектор source должен оказаться пустым.
*/

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto str: source) {
        destination.push_back(str);
    }
    source.clear();
}

