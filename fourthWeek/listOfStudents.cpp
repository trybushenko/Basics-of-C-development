#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения. 
        Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля.

        Формат ввода:
            Первая строка содержит одно целое число N от 0 до 10000 — число студентов.
            Далее идут N строк, каждая из которых содержит две строки длиной от 1 до 15 символов — имя и фамилию очередного студента, 
            и три целых числа от 0 до 1000000000 — день, месяц и год рождения.
            Следующая строка содержит одно целое число M от 0 до 10000 — число запросов.
            Следующие M строк содержат строку длиной от 1 до 15 символов — запрос, 
            и целое число от 0 до 1000000000 — номер студента (нумерация начинается с 1).
        Формат вывода:
            Для запроса вида name K, где K от 1 до N, выведите через пробел имя и фамилию K-го студента.
            Для запроса вида date K, где K от 1 до N, выведите через точку день, месяц и год рождения K-го студента.
            Для остальных запросов выведите bad request.
        
        Пример ввода:
            3
            Ivan Ivanov 1 1 1901
            Petr Petrox 2 2 1902
            Alexander Sidorov 3 3 1903
            3
            name 1
            date 3
            mark 5

        Пример вывода:
            Ivan Ivanov
            3.3.1903
            bad request
*/

struct Student { 
    string name;
    string surname;
    int day; 
    int month; 
    int year;
};

int main() {
    string name, surname, condition;
    int day, month, year, n, quantityOfAsks, index;
    cin >> n;
    vector<Student> students;
    for (int i = 0; i < n; i++) {
        cin >> name >> surname >> day >> month >> year;
        students.push_back({name, surname, day, month, year});
    }
    cin >> quantityOfAsks;
    int len = students.size();
    for (int i = 0; i < quantityOfAsks; i++) {
        cin >> condition >> index;
        index--;
        if (index > len || index < 0) cout << "bad request" << endl;
        else {
            Student student = students[index];
            if (condition == "name") cout << student.name << ' ' << student.surname << endl; 
            else if (condition == "date") cout << student.day << '.' << student.month << '.' << student.year << endl;
            else cout << "bad request" << endl;
        }
    }
    
    return 0;
}   