#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   В этой задаче вам нужно присваивать номера автобусным маршрутам.
        А именно, для каждого маршрута, заданного набором названий остановок, 
        нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.), 
        либо вернуть номер существующего маршрута, которому соответствует такой набор остановок.
        Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными (см. пример).

        Указание
        В C++ ключом словаря может быть не только число или строка, но и другой контейнер, например, vector.

        Формат ввода
        Сначала вводится количество запросов Q, затем Q описаний запросов.
        Каждый запрос представляет собой положительное количество остановок N, 
        за которым следуют разделённые пробелом N различных названий остановок соответствующего маршрута. 
        Названия остановок состоят лишь из латинских букв и символов подчёркивания.

        Формат вывода
        Выведите ответ на каждый запрос в отдельной строке.
        Если маршрут с данным набором остановок уже существует, 
        в ответ на соответствующий запрос выведите Already exists for i, 
        где i — номер маршрута с таким набором остановок. 
        В противном случае нужно выделить введённому набору остановок новый номер i 
        и вывести его в формате New bus i.

        Пример
            Ввод: 
                4
                2 Marushkino Kokoshkino
                1 Kokoshkino
                2 Marushkino Kokoshkino
                2 Kokoshkino Marushkino
            
            Вывод:
                New bus 1
                New bus 2
                Already exists for 1
                New bus 3
            
        Замечание
            Будьте внимательны при обновлении словаря: если одновременно в одном выражении вычислять размер словаря 
            и добавлять в него новый элемент, результат может отличаться от ожидаемого на единицу. 
            Чтобы этого избежать, используйте временную переменную.

            Например, вместо кода
                map<string, int> m;
                // ...
                m["two"] = m.size();
                // что нужно сделать раньше: вычислить size или добавить новый ключ?
            
            стоит написать такой код:
                map<string, int> m;
                // ...
                int new_value = m.size();
                m["two"] = new_value;
                // теперь всё однозначно: нужен размер до добавления элемента
*/


int main() {
    int q, numberOfStops, count = 1;
    string stop;
    vector<string> stopsToCheck;
    cin >> q;
    map<vector<string>, int> routeStops;
    for (int i = 0 ; i < q; i++) {
        cin >> numberOfStops;
        for (int j = 0; j < numberOfStops; j++) {
            cin >> stop;
            stopsToCheck.push_back(stop);
        }
        if (routeStops.count(stopsToCheck) == 0) {
            routeStops[stopsToCheck] = count;
            cout << "New bus "<< count << endl;
            count++;
        } else if (routeStops.count(stopsToCheck) == 1) {
            cout << "Already exists for " << routeStops[stopsToCheck] << endl;
        }
        stopsToCheck.clear();
    }
    return 0;
}