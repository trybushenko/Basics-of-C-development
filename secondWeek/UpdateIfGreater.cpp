#include <iostream>

using namespace std;

/*
Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента: 
first и second. Если first оказался больше second, Ваша функция должна записывать 
в second значение параметра first. При этом указанная функция не должна ничего возвращать, 
а изменение параметра second должно быть видно на вызывающей стороне.
                            Замечание
В данной задаче вам нужно самостоятельно выбрать типы для параметров функции UpdateIfGreater. 
Подумайте, какой из них обязан быть ссылкой, а какой может быть просто int. 
При этом учтите разные варианты вызова функции:

UpdateIfGreater(x, y);
UpdateIfGreater(5, y);
*/

void UpdateIfGreater(int first, int& second) {
    if (first > second) second = first;
}