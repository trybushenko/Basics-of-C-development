#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Напишите функцию, которая:
    -называется IsPalindrom
    -возвращает bool
    -принимает параметр типа string и возвращает, является ли переданная строка палиндромом
    Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево. 
    Пустая строка является палиндромом.
*/

bool IsPalindrom(string str) {
    if (str == "") return true;
    else if (str.size() == 1) return true;
    else {
        vector<char> straightReading, reverseReading;
        for (int i = 0; i < str.size(); i++)
        {   if (str[i] == ' ') continue;
            straightReading.push_back(str[i]);
        }
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] == ' ') continue;
            reverseReading.push_back(str[i]);
        }
        for (int i = 0; i < straightReading.size(); i++)
        {
            if (straightReading[i] != reverseReading[i]) return false;
        }
        return true;
        /*
        Alternative and faster way to write the previos code 
        int len = str.size();
        for (int i = 0; i < len/2; i++)
        {
            if (str[i] != str[len-i-1]) return false;
        }
         return true;
        */
        }
}