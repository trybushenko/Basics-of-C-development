#include <iostream>
#include <vector>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Определите тип Incognizable, для которого следующий код будет корректен:
        
        Code:
            int main() {
              Incognizable a;
              Incognizable b = {};
              Incognizable c = {0};
              Incognizable d = {0, 1};
              return 0;
            }
*/

struct Incognizable { int x, y; };


int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}