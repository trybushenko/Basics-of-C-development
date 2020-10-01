#include <iostream>
#include <string>
#include <exception>


/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Напишите функцию EnsureEqual. 
        В случае, если строка left не равна строке right, 
        функция должна выбрасывать исключение runtime_error 
        с содержанием "<l> != <r>", где <l> и <r> - строки, 
        которые хранятся в переменных left и right соответственно. 
        Обратите внимание, что вокруг знака неравенства в строке, 
        которая помещается в исключение, должно быть ровно по одному пробелу.

        Если left == right, функция должна корректно завершаться.

        Пример кода: 
            int main() {
              try {
                EnsureEqual("C++ White", "C++ White");
                EnsureEqual("C++ White", "C++ Yellow");
              } catch (runtime_error& e) {
                cout << e.what() << endl;
              }
              return 0;
            }
        Вывод из примера:
            C++ White != C++ Yellow
*/

void EnsureEqual(const string& left, const string& right) {
    if (left != right) throw runtime_error(left +  " != " + right);
    else return;
}

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}