#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   learning lesson on overloading operators
*/

struct Duration {
    int hour;
    int min;
    Duration(int h = 0, int m = 0) {
        int total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }
};

istream& operator>>(istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}//перегружаем оператор ввода по ссылке и изменем её

ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ":" << setw(2) << duration.min; 
    return stream;
} 
//оператор, который перегружается, должен возвращать поток, который принимал он первым аргументом(в данном случае оператор возвращает поток cout)

Duration operator+(const Duration& lhs, const Duration& rhs) {
    return Duration({lhs.hour + rhs.hour, lhs.min + rhs.min});
}//возвращаем новую структуру просуммировав часы и минуты

bool operator<(const Duration& lhs, const Duration& rhs) {
    if (lhs.hour == rhs.hour) return lhs.min < rhs.min;
    else return lhs.hour < rhs.hour;
}// если больше то возвращаем true, в ином случае false

void PrintVector(const vector<Duration>& durs) {
    for (const auto& d : durs) cout << d << " ";
    cout << endl;
}

int main(int argc, const char** argv) {
    stringstream dur_ss("02:50");//инициализируем поток 
    Duration dur1 {0, 0};//считываем данные с потока в переменную типа Duration
    dur_ss >> dur1;
    cout << dur1 << endl; // выводим на экран нашу переменную типа Duration

    //далее будет одинаковый вывод, но разными способами

    //cout << "hello, " << "world!";
    //operator<<(operator<<(cout, "hello"), " world!"); // учебный пример по работе с операторами(в комментариях выше есть пояснение этому)
    // cout << "hello, " << "world!"; == operator<<(operator<<(cout, "hello"), " world!"); 

    //stringstream dur_ss1("02:50"); // инициализируем новый поток строк
    Duration dur2 {0, 35}; // инициализируем новый интервал
    //dur_ss1 >> dur2; // вводим данные с потока в переменную
    cout << dur2 << endl; // выводим данные с переменной dur2
    // суммируем dur1 и dur2
    cout << dur1 + dur2 << endl;
    Duration dur3 = dur1 + dur2;
    //vector of durations
    vector<Duration> v {dur3, dur1, dur2};
    PrintVector(v);
    //sorting a vector
    sort(begin(v), end(v));
    //printing the vector
    PrintVector(v); 
    return 0;
}   