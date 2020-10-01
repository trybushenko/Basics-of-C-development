#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Условие
        В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел. 
        Первым числом идёт само число N. 
        Далее следуют ещё N чисел, обозначим их за массив A. 
        Между собой числа разделены пробелом.

        Отсортируйте массив А по модулю и выведите его в стандартный поток.

        Ограничения
            0 <= N <= 1000
            -1000000 <= A[i] <= 1000000

        Примеры
            stdin	    stdout
            2 -4 3	    3 -4
            3 1 -3 2  	1 2 -3
        Подсказка
        функция sort дополнительно принимает третий аргумент. Изучите его подробнее по ссылке.
*/

int main(int argc, const char** argv) {
    int n, q;
    cin >> n;
    vector<int> vectorToSort;
    for (int i = 0; i < n; i++) {
        cin >> q;
        vectorToSort.push_back(q);
    }
    sort(begin(vectorToSort), end(vectorToSort), [](int i, int j){
        return abs(i)<abs(j);
    });
    for (auto str : vectorToSort) cout << str << ' ';
    return 0;
}