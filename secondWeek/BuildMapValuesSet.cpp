#include <iostream>
#include <map>
#include <set>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, string> и возвращающую множество значений этого словаря:

    set<string> BuildMapValuesSet(const map<int, string>& m) {
  // ...
}

    Пример:
        Ввод:
            set<string> values = BuildMapValuesSet({
            {1, "odd"},
            {2, "even"},
            {3, "odd"},
            {4, "even"},
            {5, "odd"}
        });

            for (const string& value : values) {
              cout << value << endl;
            }

        Вывод:
            even
            odd
*/

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> result;
    for (auto kv : m) result.insert(kv.second);
    return result;
}

int main(int argc, const char** argv) {
    map<int, string> m = {{1, "asd"}, {2, "qwe"}, {3, "zxc"}, {4, "zxc"}};
    set<string> sett = BuildMapValuesSet(m);
    for (auto str : sett) cout << str << " ";
    return 0;
}