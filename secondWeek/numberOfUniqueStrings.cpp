#include <iostream>
#include <string>
#include <set>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: 
    Дан набор строк. Найдите количество уникальных строк в этом наборе.

    Формат ввода
    Сначала вводится количество строк N, 
    затем — сами N строк, разделённые символом перевода строки. 
    Все строки состоят лишь из латинских букв, цифр и символов подчёркивания.

    Формат вывода
    Выведите единственное целое число — количество уникальных строк в данном наборе.

    Пример
        Ввод:
            6
            first
            second
            first
            third
            second
            second
        
        Вывод:
            3
*/

int main() {
    int n;
    cin >> n;
    set<string> uniqueWords;
    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        uniqueWords.insert(word);
    } 
    cout << uniqueWords.size() << endl;
    return 0;
}