#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   В этой задаче вам нужно присваивать номера автобусным маршрутам.
        А именно, для каждого маршрута, заданного множеством названий остановок, 
        нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.), 
        либо вернуть номер существующего маршрута, которому соответствует такое множество остановок.

        В отличие от задачи «Автобусные остановки — 2», наборы остановок, 
        которые можно получить друг из друга перестановкой элементов или 
        добавлением/удалением повторяющихся, следует считать одинаковыми.

        Формат ввода
        Сначала вводится количество запросов Q, затем Q описаний запросов.

        Каждый запрос представляет собой положительное количество остановок N, 
        за которым следуют разделённые пробелом N названий остановок соответствующего маршрута (не обязательно различных). 
        Названия остановок состоят лишь из латинских букв и символов подчёркивания.

        Формат вывода
        Выведите ответ на каждый запрос в отдельной строке.

        Если маршрут с данным набором остановок уже существует, 
        в ответ на соответствующий запрос выведите Already exists for i, где i — номер маршрута с таким набором остановок. 
        В противном случае нужно выделить введённому набору остановок новый номер i и вывести его в формате New bus i.

        Пример:
            Ввод:
                5
                2 Marushkino Kokoshkino
                1 Kokoshkino
                2 Marushkino Kokoshkino
                2 Kokoshkino Marushkino
                2 Kokoshkino Kokoshkino
             
            Вывод:
                New bus 1
                New bus 2
                Already exists for 1
                Already exists for 1
                Already exists for 2
        
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
    int q, n;
    cin >> q;  
    int count = 0;
    string stop;
    map<set<string>, int> routeStops;
    set<string> stops;
    for (int i = 0; i < q; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> stop;
            stops.insert(stop);
        }
        if (routeStops.count(stops)) {
            cout << "Already exists for " << routeStops[stops] << endl;
        } else {
            routeStops[stops] = ++count;
            cout << "New bus " << count << endl;
        }
        stops.clear();
    }
    
    return 0;
}