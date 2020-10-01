#include <iostream>
#include <vector>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. 
Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.

Гарантируется, что среднее арифметическое значений температуры является целым числом.

Формат ввода:
Вводится число N, затем N неотрицательных целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.

Формат вывода:
Первое число K — количество дней, значение температуры в которых выше среднего арифметического. Затем K целых чисел — номера этих дней.

Пример:

Ввод
5
7 6 3 0 9

Вывод:
3
0 1 4

*/

int main(int argc, const char** argv) {
    int n;
    cin >> n;
    int summary_temperature = 0;
    vector<unsigned int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        summary_temperature += v[i];
    }
    double average_temperature = static_cast<double>(summary_temperature) / v.size();
    int count = 0;
    for (auto temp: v) {
        if (temp > average_temperature) count++;
    }
    cout << "\n" << count << endl;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > average_temperature) cout << i << " ";
    }
    
    return 0;
}