#include <iostream>
#include <vector>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда. 
Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.

Реализуйте обработку следующих операций над очередью:

WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
QUIET i: пометить i-го человека как успокоившегося;
COME k: добавить k спокойных человек в конец очереди;
COME -k: убрать k человек из конца очереди;
WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
Изначально очередь пуста.

Формат ввода
Количество операций Q, затем описания операций.
Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.
Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.

Формат вывода
Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокоящихся людей в очереди.

Пример: 
    Ввод:
    8
    COME 5
    WORRY 1
    WORRY 4
    COME -2
    WORRY_COUNT
    COME 3
    WORRY 3
    WORRY_COUNT

    Вывод:
    1
    2
    
*/
int worryCount(vector<bool>& queue) {
    int worryCount = 0; 
    for (auto i: queue) {
        if (i == true) worryCount++;
    }
    return worryCount;
}


void worry(vector<bool>& queue, int index) {
    queue[index] = true;
}

void quiet(vector<bool>& queue, int index) {
    queue[index] = false;
}
void come(vector<bool>& queue, int index) {
    int len = queue.size();
    if (index < 0) {
        queue.resize(len + index);
        
    }
    else {
        for (int i = 0; i < index; i++) {
            queue.push_back(false);
        }
    }  
}

void printVector(vector<bool>& v) {
    for (auto i: v) cout << i << " ";
    cout << endl;
}

int main(int argc, const char** argv) {
    int q;
    cin >> q;
    vector<bool> queue;
    string condition, stringIndex;
    int index;
    for (int i = 0; i < q; i++) {
        cin >> condition;
        if (condition == "COME") {
            cin >> stringIndex;
            come(queue, atoi(stringIndex.c_str()));
        }
        else if (condition == "WORRY") {
            cin >> stringIndex;
            worry(queue, atoi(stringIndex.c_str()));
        }
        else if (condition == "WORRY_COUNT") {
            cout << worryCount(queue) << endl;
        }
        else if (condition == "QUIET") {
            cin >> stringIndex;
            quiet(queue, atoi(stringIndex.c_str()));
        }
        //printVector(queue);
    }
    return 0;
}   
