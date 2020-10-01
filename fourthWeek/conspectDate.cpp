#include <iostream>
#include <string>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   this file is dedicated for learning how to work with 
        explicit constructors, structures etc took from the lecture in C++ software engineering
*/

struct Day {
    int value;
    explicit Day(int new_value) {
        value = new_value;
    }
};

struct Month {
    int value;
    explicit Month(int new_value) {
        value = new_value;
    }
};

struct Year {
    int value;
    explicit Year(int new_value) {
        value = new_value;
    }
};


struct Date {
    int day, month, year;
    Date (Day new_day, Month new_month, Year new_year) {
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;
    }
};

void printDate (const Date& date) {
    cout << date.day << "." << date.month << "." << date.year;
}

int main() {
    Date date = {Day(1), Month(1), Year(2017)};
    printDate(date);
    return 0;
}