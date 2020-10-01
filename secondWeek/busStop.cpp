#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>       

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:

    NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
    BUSES_FOR_STOP bus — вывести названия всех маршрутов автобуса, проходящих через остановку bus.
    STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
    ALL_BUSES — вывести список всех маршрутов с остановками.

    Формат ввода
    В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.

    Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.
    Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, 
    что маршрут bus отсутствует, количество остановок больше 0, 
    а после числа stop_count следует именно такое количество названий остановок, 
    причём все названия в каждом списке различны.

    Формат вывода
    Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:

    На запрос BUSES_FOR_STOP bus выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке, 
    в котором они создавались командами NEW_BUS. Если остановка bus не существует, выведите No bus.
    На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, 
    в котором они были заданы в соответствующей команде NEW_BUS. 
    Описание каждой остановки bus должно иметь вид Stop bus: bus1 bus2 ..., где bus1 bus2 ... — список автобусов, 
    проезжающих через остановку bus, в порядке, в котором они создавались командами NEW_BUS, за исключением исходного маршрута bus. 
    Если через остановку bus не проезжает ни один автобус, кроме bus, вместо списка автобусов для неё выведите no interchange. 
    Если маршрут bus не существует, выведите No bus.
    На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке. 
    Описание каждого маршрута bus должно иметь вид Bus bus: stop1 stop2 ..., где stop1 stop2 ... — список остановок автобуса bus в порядке, 
    в котором они были заданы в соответствующей команде NEW_BUS. Если автобусы отсутствуют, выведите No buses.

    Предупреждение
    Условие задачи выше содержит много важных деталей. Если вы не уверены в том, что не упустили ни одной, перечитайте условие ещё раз.

    Пример 1:
        Ввод:
            10
            ALL_BUSES
            BUSES_FOR_STOP Marushkino
            STOPS_FOR_BUS 32K
            NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
            NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
            BUSES_FOR_STOP Vnukovo
            NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
            NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
            STOPS_FOR_BUS 272
            ALL_BUSES
        
        Вывод:
            No buses
            No bus
            No bus
            32 32K
            Stop Vnukovo: 32 32K 950
            Stop Moskovsky: no interchange
            Stop Rumyantsevo: no interchange
            Stop Troparyovo: 950
            Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
            Bus 32: Tolstopaltsevo Marushkino Vnukovo
            Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
            Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo

        Input:
            9
            NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
            NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
            NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
            NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
            STOPS_FOR_BUS 272
            STOPS_FOR_BUS 950
            BUSES_FOR_STOP Marushkino
            BUSES_FOR_STOP Vnukovo
            BUSES_FOR_STOP Solntsevo

        Correct output:
            Stop Vnukovo: 32 32K 950
            Stop Moskovsky: no interchange
            Stop Rumyantsevo: no interchange
            Stop Troparyovo: 950
            Stop Kokoshkino: no interchange
            Stop Marushkino: 32 32K
            Stop Vnukovo: 32 32K 272
            Stop Peredelkino: 32K
            Stop Solntsevo: 32K
            Stop Troparyovo: 272
            32 32K 950
            32 32K 950 272
            32K 950

        My output:
            Stop Vnukovo: 32 32K 950 
            Stop Moskovsky: no interchange
            Stop Rumyantsevo: no interchange
            Stop Troparyovo: 950 
            Stop Kokoshkino: no interchange
            Stop Marushkino: 32 32K 
            Stop Vnukovo: 32 32K 272 
            Stop Peredelkino: 32K 
            Stop Solntsevo: 32K 
            Stop Troparyovo: 272 
            32 32K 950 
            32 32K 950 272 
            32K 950 
*/

/*
void printMap(const map<int, vector<string>>& busStopsMap) {
    for (auto kv: busStopsMap) {
        cout << kv.first << " : ";
        for (int i = 0; i < kv.second.size(); i++) {
            if (i == kv.second.size() - 1) cout << kv.second[i] << "." << endl;
            else cout << kv.second[i] << ", ";
        }
    }
}
*/

int main() {
    int q;
    cin >> q;
    map<string, vector<string>> busStopsMap;
    vector<string> sequenceOfBusesByAdding;
    string condition;
    for (int i = 0; i < q; i++) {
        cin >> condition;
        if (condition == "NEW_BUS") {
            string NumberOfTheBus;
            int numberOfStops;
            cin >> NumberOfTheBus >> numberOfStops;
            sequenceOfBusesByAdding.push_back(NumberOfTheBus);
            string bus;
            for (int i = 0; i < numberOfStops; i++) {
                cin >> bus;
                busStopsMap[NumberOfTheBus].push_back(bus);
            }
        }
        //printMap(busStopsMap);
        else if (condition == "BUSES_FOR_STOP") {
            int count = 0;
            string bus;
            cin >> bus;
            for (auto number: sequenceOfBusesByAdding) {
                for (auto stops: busStopsMap[number]) {
                    if (stops == bus) {
                        cout << number << " ";
                        count++;
                    }
                }
            }
            if (count == 0) cout << "No stop" << endl;
            else cout << endl; 
        }
        else if (condition == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            bool flag;
            if (busStopsMap.count(bus) == 0) cout << "No bus" << endl;
            else {
                for (auto stopOfTheBus: busStopsMap[bus]) {
                    cout << "Stop " << stopOfTheBus << ": ";
                    flag = false;
                    for (auto kv: sequenceOfBusesByAdding) {
                        if (kv == bus) continue;
                        else {
                            for (auto stopsOfTheBuses: busStopsMap[kv]) {
                                if (stopOfTheBus == stopsOfTheBuses) {
                                    cout << kv << " ";
                                    flag = true;
                                }
                            }
                        } 
                    }
                    if (flag == false) cout << "no interchange";
                    cout << endl;
                }
            }
        }   
        else if (condition == "ALL_BUSES") {
            if (busStopsMap.size() == 0) cout << "No buses" << endl;
            else {
                for (auto kv : busStopsMap) {
                    cout << "Bus " << kv.first << ": ";
                    for (auto stop: kv.second) {
                        cout << stop << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}