#include <iostream>
#include <vector>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: У каждого из нас есть повторяющиеся ежемесячные дела, 
каждое из которых нужно выполнять в конкретный день каждого месяца: оплата счетов за электричество, абонентская плата за связь и пр. 
Вам нужно реализовать работу со списком таких дел на месяц, а именно, реализовать набор следующих операций:
ADD i s - Назначить дело с названием s на день i текущего месяца.
DUMP i - Вывести все дела, запланированные на день i текущего месяца.
NEXT - Перейти к списку дел на новый месяц. 
При выполнении данной команды вместо текущего (старого) списка дел на текущий месяц создаётся 
и становится активным (новый) список дел на следующий месяц: все дела со старого списка дел копируются в новый список. 
После выполнения данной команды новый список дел и следующий месяц становятся текущими, 
а работа со старым списком дел прекращается. При переходе к новому месяцу необходимо обратить внимание на разное количество дней в месяцах:
если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни необходимо оставить пустыми (не содержащими дел);
если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних» дней необходимо переместить на последний день следующего месяца.

Замечания
Историю списков дел хранить не требуется, работа ведется только с текущим списком дел текущего месяца. 
Более того, при создании списка дел на следующий месяц, он «перетирает» предыдущий список.
Обратите внимание, что количество команд NEXT в общей последовательности команд при работе со списком дел может превышать 11.
Начальным текущим месяцем считается январь.
Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.

Формат ввода
Сначала число операций Q, затем описания операций.
Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания. 
Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца.

Формат вывода
Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день, 
а затем их названия, разделяя их пробелом. Порядок вывода дел в рамках каждой операции значения не имеет.

Пример:
Ввод:
    12
    ADD 5 Salary
    ADD 31 Walk
    ADD 30 WalkPreparations
    NEXT
    DUMP 5
    DUMP 28
    NEXT
    DUMP 31
    DUMP 30
    DUMP 28
    ADD 28 Payment
    DUMP 28

Вывод:
    1 Salary
    2 WalkPreparations Walk
    0
    0
    2 WalkPreparations Walk
    3 WalkPreparations Walk Payment

Ввод:
    5
    ADD 31 Jan_31
    ADD 30 Jan_30
    ADD 29 Jan_29
    NEXT
    DUMP 28
Вывод: 
    3 Jan_31 Jan_30 Jan_29

*/


void add(vector<vector<string>>& affairs, int index, string task) {
    affairs[index - 1].push_back(task);
}


void dump(vector<vector<string>> affairs, int index) {
    int quantity = affairs[index - 1].size();
    cout << quantity << " ";
    for (auto str: affairs[index - 1]) cout << str << " ";
    cout << '\n'; 
}


void printVector(vector<string> affairs) {
    for (int i = 0; i < affairs.size(); i++) cout << affairs[i] << "< this was iteration number " << i << endl;
}

     
int main() {
    int q;
    cin >> q;
    vector<int> numberOfDays{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentMonth = 0;
    vector<vector<string>> affairs(numberOfDays[currentMonth]);
    string condition;
    for (int i = 0; i < q; i++) {
        cin >> condition;
        if (currentMonth > 11) currentMonth = 0;
        if (condition == "ADD") {
            string task;
            int index;
            cin >> index >> task;
            add(affairs, index, task);
        }
        else if (condition == "DUMP") {
            int index;
            cin >> index;
            dump(affairs, index);
        }
        else if (condition == "NEXT") {
            if (numberOfDays[currentMonth % 12] > numberOfDays[(currentMonth + 1) % 12]) {
                for (int i = numberOfDays[(currentMonth + 1)% 12]; i < affairs.size(); ++i) {
                    affairs[numberOfDays[(currentMonth + 1) % 12] - 1].insert(end(affairs[numberOfDays[(currentMonth + 1) % 12] - 1]), begin(affairs[i]), end(affairs[i]));
                }
            }
            affairs.resize(numberOfDays[++currentMonth % 12]);
        }
    }
    return 0;
}
