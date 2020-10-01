#include <iostream>
#include <map>
#include <string>
#include <algorithm>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: Реализуйте справочник столиц стран.

    На вход программе поступают следующие запросы:

    CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, 
    либо добавление такой страны с такой столицей, если раньше её не было.
    RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
    ABOUT country — вывод столицы страны country.
    DUMP — вывод столиц всех стран.

    Формат ввода
        В первой строке содержится количество запросов Q, 
        в следующих Q строках — описания запросов. 
        Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.

    Формат вывода
        Выведите результат обработки каждого запроса:

    В ответ на запрос CHANGE_CAPITAL country new_capital выведите
    Introduce new country country with capital new_capital, если страны country раньше не существовало;
    Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
    Country country has changed its capital from old_capital to new_capital, 
    если страна country до текущего момента имела столицу old_capital, 
    название которой не совпадает с названием new_capital.
    В ответ на запрос RENAME old_country_name new_country_name выведите
    Incorrect rename, skip, если новое название страны совпадает со старым, 
    страна old_country_name не существует или страна new_country_name уже существует;
    Country old_country_name with capital capital has been renamed to new_country_name, 
    если запрос корректен и страна имеет столицу capital.
    В ответ на запрос ABOUT country выведите
    Country country doesn't exist, если страны с названием country не существует;
    Country country has capital capital, если страна country существует и имеет столицу capital.
    В ответ на запрос DUMP выведите
    There are no countries in the world, если пока не было добавлено ни одной страны;
    последовательность пар вида country/capital, описывающую столицы всех стран, 
    если в мире уже есть хотя бы одна страна. 
    При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом.

    Пример 1:
        Ввод:
            6
            CHANGE_CAPITAL RussianEmpire Petrograd
            RENAME RussianEmpire RussianRepublic
            ABOUT RussianRepublic
            RENAME RussianRepublic USSR
            CHANGE_CAPITAL USSR Moscow
            DUMP
        Вывод:
            Introduce new country RussianEmpire with capital Petrograd
            Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
            Country RussianRepublic has capital Petrograd
            Country RussianRepublic with capital Petrograd has been renamed to USSR
            Country USSR has changed its capital from Petrograd to Moscow
            USSR/Moscow
    
    Пример 2:
        Ввод:
            24
            RENAME FakeCountry FarFarAway
            ABOUT FarFarAway
            DUMP
            CHANGE_CAPITAL TsardomOfRussia Moscow
            CHANGE_CAPITAL TsardomOfRussia Moscow
            CHANGE_CAPITAL ColonialBrazil Salvador
            CHANGE_CAPITAL TsardomOfRussia SaintPetersburg
            RENAME TsardomOfRussia RussianEmpire
            CHANGE_CAPITAL RussianEmpire Moscow
            CHANGE_CAPITAL RussianEmpire SaintPetersburg
            CHANGE_CAPITAL ColonialBrazil RioDeJaneiro
            DUMP
            RENAME ColonialBrazil EmpireOfBrazil
            ABOUT RussianEmpire
            RENAME EmpireOfBrazil UnitedStatesOfBrazil
            CHANGE_CAPITAL RussianEmpire Petrograd
            RENAME RussianEmpire RussianRepublic
            RENAME RussianRepublic USSR
            CHANGE_CAPITAL USSR Moscow
            CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
            RENAME UnitedStatesOfBrazil FederativeRepublicOfBrazil
            ABOUT RussianEmpire
            DUMP
            RENAME USSR USSR

        Вывод:
            Incorrect rename, skip
            Country FarFarAway doesn't exist
            There are no countries in the world
            Introduce new country TsardomOfRussia with capital Moscow
            Country TsardomOfRussia hasn't changed its capital
            Introduce new country ColonialBrazil with capital Salvador
            Country TsardomOfRussia has changed its capital from Moscow to SaintPetersburg
            Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire
            Country RussianEmpire has changed its capital from SaintPetersburg to Moscow
            Country RussianEmpire has changed its capital from Moscow to SaintPetersburg
            Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro
            ColonialBrazil/RioDeJaneiro RussianEmpire/SaintPetersburg
            Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil
            Country RussianEmpire has capital SaintPetersburg
            Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil
            Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd
            Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
            Country RussianRepublic with capital Petrograd has been renamed to USSR
            Country USSR has changed its capital from Petrograd to Moscow
            Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia
            Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil
            Country RussianEmpire doesn't exist
            FederativeRepublicOfBrazil/Brasilia USSR/Moscow
            Incorrect rename, skip
    
    Пример 3:
        Ввод:
            10
            CHANGE_CAPITAL RussianEmpire Petrograd
            RENAME USSR RussianEmpire
            DUMP
            ABOUT USSR
            DUMP
            RENAME RussianEmpire RussianEmpire
            DUMP
            CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
            RENAME RussianEmpire UnitedStatesOfBrazil
            DUMP

        Вывод:
            Introduce new country RussianEmpire with capital Petrograd
            Incorrect rename, skip
            RussianEmpire/Petrograd
            Country USSR doesn't exist
            RussianEmpire/Petrograd
            Incorrect rename, skip
            RussianEmpire/Petrograd
            Introduce new country UnitedStatesOfBrazil with capital Brasilia
            Incorrect rename, skip
            RussianEmpire/Petrograd UnitedStatesOfBrazil/Brasilia
*/

void printMap(const map<string, string>& m) {
    for (auto kv: m) cout << kv.first << " : " << kv.second << endl;
}

int main() {
    int q;
    cin >> q;
    map<string, string> countryCapital;
    string condition, country;
    for (int i = 0; i < q; i++) {
        cin >> condition;
        if (condition == "CHANGE_CAPITAL") {
            string capital;
            cin >> country >> capital;
            if (countryCapital.count(country) == 1) {
                if (countryCapital.at(country) == capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
                }
                else if (countryCapital.at(country) != capital) {
                    cout << "Country " << country << " has changed its capital from " << countryCapital[country] << " to " <<  capital << endl;
                    countryCapital[country] = capital;
                }    
            }
            else if (countryCapital.count(country) == 0) {
                countryCapital[country] = capital;
                cout << "Introduce new country " << country << " with capital " << capital << endl; 
            }
        }
        else if (condition == "RENAME") {
            string new_country_name;
            string capital;
            cin >> country >> new_country_name;
            if (country == new_country_name || countryCapital.count(country) == 0 || countryCapital.count(new_country_name) == 1) {
                cout << "Incorrect rename, skip" << endl;
            }
            else {
                capital = countryCapital[country];
                cout << "Country " << country <<  " with capital " << capital  << " has been renamed to " << new_country_name << endl;
                countryCapital.erase(country);
                countryCapital[new_country_name] = capital;
            } 
        }
        else if (condition == "ABOUT") {
            cin >> country;
            if (countryCapital.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            }
            else if (countryCapital.count(country) == 1) {
                cout << "Country " << country << " has capital " << countryCapital[country] << endl;
            }
        }
        else if (condition == "DUMP") {
            if (countryCapital.size() == 0) cout << "There are no countries in the world" << endl;
            else {
                for (auto kv : countryCapital) cout << kv.first << "/" << kv.second << endl;
            }
        }
    }
    return 0;
}
