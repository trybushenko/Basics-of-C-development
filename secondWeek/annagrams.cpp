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
task: Слова называются анаграммами друг друга, если одно из них можно получить перестановкой букв в другом. 
    Например, слово «eat» можно получить перестановкой букв слова «tea», 
    поэтому эти слова являются анаграммами друг друга. Даны пары слов, 
    проверьте для каждой из них, являются ли слова этой пары анаграммами друг друга.

    Указание
    Один из способов проверки того, являются ли слова анаграммами друг друга, 
    заключается в следующем. Для каждого слова с помощью словаря подсчитаем, 
    сколько раз в нём встречается каждая буква. Е
    сли для обоих слов эти словари равны (а это проверяется с помощью обычного оператора ==), 
    то слова являются анаграммами друг друга, в противном случае не являются.

    При этом построение такого словаря по слову удобно вынести в отдельную функцию BuildCharCounters.

    Формат ввода
    Сначала дано число пар слов N, 
    затем в N строках содержатся пары слов, 
    которые необходимо проверить. 
    Гарантируется, что все слова состоят лишь из строчных латинских букв.

    Формат вывода
    Выведите N строк: для каждой введённой пары слов YES, 
    если эти слова являются анаграммами, и NO в противном случае.

    Ввод: 
        3
        eat tea
        find search
        master stream

    Вывод:
        YES
        NO
        YES
*/

void BuildCharCounters(const string& word1,const string& word2) {
    if (word1.length() != word2.length()) {
        cout << "NO" << endl;
        return;
    }
    map<char, int> mapWord1, mapWord2;
    for (auto ch: word1) mapWord1[ch] = count(word1.begin(), word1.end(), ch);
    for (auto ch: word2) mapWord2[ch] = count(word2.begin(), word2.end(), ch);
    for (auto w1: mapWord1) {
        if (mapWord2[w1.first] != w1.second) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string word1, word2;
        cin >> word1 >> word2;
        BuildCharCounters(word1, word2);
    }
    return 0;
}
