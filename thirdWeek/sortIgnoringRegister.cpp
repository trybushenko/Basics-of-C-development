#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:           Условие:
    В стандартном потоке дана одна строка, 
    состоящая из числа N и следующих за ним N строк S. 
    Между собой число и строки разделены пробелом.

    Отсортируйте строки S в лексикографическом порядке по возрастанию, 
    игнорируя регистр букв, и выведите их в стандартный поток вывода.

    Ограничения
    0 <= N <= 1000
    1 <= |S| <= 15
    Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]

    Примеры:
        stdin	       stdout
        2 q A	       A q
        3 a C b	       a b C
*/

int main() {
    int n;
    cin >> n;
    vector<string> stringVector;
    string letter;
    for (int i = 0; i < n; i++) {
        cin >> letter;
        stringVector.push_back(letter);
    }
    sort(begin(stringVector), end(stringVector), [](string i, string j){
		for(int c = 0; c < i.size(); ++c) i[c] = tolower(i[c]);
        for(int c = 0; c < j.size(); ++c)j[c] = tolower(j[c]);
			return (i<j);
		});
    for (const auto& let : stringVector) cout << let << " ";
}