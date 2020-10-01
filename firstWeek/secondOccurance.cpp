#include <iostream>
#include <string>

using namespace std;

/*
Дана строка. Найдите в этой строке второе вхождение буквы f 
и выведите индекс этого вхождения. 
Если буква f в данной строке встречается только один раз, 
выведите число -1, а если не встречается ни разу, 
выведите число -2. Индексы нумеруются с нуля.
*/

int main() {
    string word;
    char neededLetter = 'f';
    cin >> word;
    int counter = 0;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == neededLetter) {
            counter++;
            if (counter == 1) continue;
            else {
                cout << i;
                return 0;
            }
        }
    }
    if (counter == 1) cout << -1;
    else if (counter == 0) cout << -2;
    return 0;
}