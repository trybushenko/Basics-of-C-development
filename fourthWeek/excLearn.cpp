#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <exception>    

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   this file is dedicated for learning how to work with exceptions, catch them and how they set 
*/

struct Date {
    int year;
    int month;
    int day;
};

void ensureNextSymbolAndSkip(stringstream& stream) {
    if (stream.peek() != '/') {
        stringstream ss;
        cout << "expected, but got: " << char(stream.peek()) << endl;
        throw runtime_error(ss.str());
    }
    stream.ignore(1);
}

Date ParseDate(const string& s) {
    stringstream stream(s);
    Date date;
    stream >> date.year;
    ensureNextSymbolAndSkip(stream);
    stream >> date.month;
    ensureNextSymbolAndSkip(stream);
    stream >> date.day;
    return date;
}

int main() {
    string date_str = "2017/01a25";
    try {
        Date date = ParseDate(date_str);
    } catch(exception& ex) {
        cout << "exception happened " << ex.what();
    }
    
    //cout << setw(2) << setfill('0') << date.day << '.' << date.month << '.' << date.year;
    return 0;
}   