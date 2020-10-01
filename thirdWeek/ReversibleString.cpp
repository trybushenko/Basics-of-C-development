#include <iostream>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Реализуйте класс ReversibleString, 
        хранящий строку и поддерживающий методы Reverse для переворота строки 
        и ToString для получения строки.

        Пример:
            int main() {
              ReversibleString s("live");
              s.Reverse();
              cout << s.ToString() << endl;

              s.Reverse();
              const ReversibleString& s_ref = s;
              string tmp = s_ref.ToString();
              cout << tmp << endl;

              ReversibleString empty;
              cout << '"' << empty.ToString() << '"' << endl;

              return 0;
            }

        Вывод:
            evil
            live
            ""
*/

class ReversibleString {
    public:
        ReversibleString(const string& word1) {
            word = word1;
        }
        ReversibleString() {
            word = ""; 
        }
        void Reverse() {
            int n = word.length();
            for (int i = 0; i < n / 2; i++) {
                swap(word[i], word[n - i - 1]);
            }
        }
        string ToString() const {
            return word;
        }
    private:
        string word;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
    return 0;
}