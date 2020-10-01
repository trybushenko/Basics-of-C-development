#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Напишите функцию, которая
    -называется PalindromFilter
    -возвращает vector<string>
    -принимает vector<string> words и int minLength и возвращает все строки из вектора words, 
    которые являются палиндромами и имеют длину не меньше minLength
***Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.***
*/
bool IsPalindrom(string str) {
    if (str == "") return true;
    else if (str.size() == 1) return true;
    else {
        int len = str.size();
        for (int i = 0; i < len/2; i++)
        {
            if (str[i] != str[len-i-1]) return false;
        }
         return true;
    }
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> filtered;
    for (auto word: words)
    {
        if (word.size() < minLength) continue;
        else {
            bool flag = false;
            flag = IsPalindrom(word);
            if (flag == true) filtered.push_back(word);
        }
    }
    return filtered;
}


int main() {
    vector<string> palindromArray{"weew", "bro", "code"};
    vector<string> filteredVector = PalindromFilter(palindromArray, 2);
    for (auto s: filteredVector) cout << s << " ";
    return 0;
}