#include <iostream>
#include <string>   
#include <vector>
#include <algorithm>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Реализуйте класс, поддерживающий набор строк в отсортированном порядке. 
        Класс должен содержать два публичных метода:
        class SortedStrings {
            public:
              void AddString(const string& s) {
                // добавить строку s в набор
              }
              vector<string> GetSortedStrings() {
                // получить набор из всех добавленных строк в отсортированном порядке
              }
            private:
              // приватные поля
        };
        Пример:
            Код:
                void PrintSortedStrings(SortedStrings& strings) {
                    for (const string& s : strings.GetSortedStrings()) {
                        cout << s << " ";
                    }
                    cout << endl;
                    }


                int main() {
                    SortedStrings strings;

                    strings.AddString("first");
                    strings.AddString("third");
                    strings.AddString("second");

                    PrintSortedStrings(strings);

                    strings.AddString("second");

                    PrintSortedStrings(strings);

                    return 0;
                }

*/

class SortedStrings {
public:
    void AddString(const string& s) {
        sortString.push_back(s);
    }
    vector<string> GetSortedStrings() {
      sort(sortString.begin(), sortString.end());
      return sortString;
    }
    private:
        vector<string> sortString;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}
/*
int main() {
    SortedStrings strings;
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);
    strings.AddString("second");
    PrintSortedStrings(strings);
    return 0;
}
*/