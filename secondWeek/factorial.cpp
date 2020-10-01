#include <iostream>

using namespace std;

/*
Напишите функцию, которая
    -называется Factorial
    -возвращает int
    -принимает int и возвращает факториал своего аргумента. 
    Гарантируется, что аргумент функции по модулю не превышает 10. 
    Для отрицательных аргументов функция должна возвращать 1.
*/

int Factorial(int x) {
    int result = 1;
    if (x == 0 || x == 1 || x < 0) return 1;
    else {
        for (int i = 1; i < x + 1; i++)
        {
            result *= i;
        }
        return result;
    }
}
