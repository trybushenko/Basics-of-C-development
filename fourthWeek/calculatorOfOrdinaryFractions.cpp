#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>



/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:   Итак, теперь у нас с вами есть полноценный тип для представления обыкновенных дробей: класс Rational 
        интегрирован в язык с помощью перегрузки операторов и не позволяет выполнять некорректные операции 
        за счёт выбрасывания исключений. Давайте на основе класса Rational создадим простой калькулятор для обыкновенных дробей.
        Вам надо написать программу, которая считывает из стандартного ввода одну строку 
        в формате ДРОБЬ_1 операция ДРОБЬ_2. ДРОБЬ_1 и ДРОБЬ_2 имеют формат X/Y, где X — целое, а Y — целое неотрицательное число. 
        операция — это один из символов '+', '-', '*', '/'.
        Если ДРОБЬ_1 или ДРОБЬ_2 является некорректной обыкновенной дробью, 
        ваша программа должна вывести в стандартный вывод сообщение "Invalid argument". 
        Если считанная операция — это деление на ноль, выведите в стандартный вывод сообщение "Division by zero". 
        В противном случае выведите результат операции.

        stdin	    stdout
        1/2 + 1/3	5/6
        1/2 + 5/0	Invalid argument
        4/5 / 0/8	Division by zero
*/

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
class Rational {
    public:
        Rational() {
            numerator = 0;
            denominator = 1;
        }
        Rational(int _numerator, int _denominator) {
            if (_denominator == 0) {
                throw invalid_argument("Invalid argument");
            }
            int gcd_ = gcd(abs(_numerator), abs(_denominator));
            if (gcd_ > 1) {
                _numerator = _numerator / gcd_;
                _denominator = _denominator / gcd_;
            } 
            if (_numerator < 0 && _denominator < 0) {
                _numerator = abs(_numerator);
                _denominator = abs(_denominator);
            }
            if (_numerator == 0) {
                _denominator = 1;
            }

            if (_numerator < 0 || _denominator < 0) {
                _numerator = -abs(_numerator);
                _denominator = abs(_denominator);
            }
            numerator = _numerator;
            denominator = _denominator;
        }

        int Numerator() const {
            return numerator;
        }
        int Denominator() const {
            return denominator;
        }
    private:
        int numerator, denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    if ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator())) return true;
    else return false;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int num, denom;
    denom = lhs.Denominator() * rhs.Denominator();
    num = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    return Rational(num, denom);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int num, denom;
    denom = lhs.Denominator() * rhs.Denominator();
    num = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    return Rational(num, denom);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int num = lhs.Numerator() * rhs.Numerator();
    int denom = lhs.Denominator() * rhs.Denominator();
    return Rational(num, denom);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int num = lhs.Numerator() * rhs.Denominator();
    int denom = lhs.Denominator() * rhs.Numerator();
    if (denom == 0) {
        throw domain_error("Division by zero");
    }
    return Rational(num, denom);
}

ostream& operator<<(ostream& stream,  const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    int num, denom;
    char slash;
    if (stream) {
        if (!(stream >> num)) return stream;
        stream >> slash;
        if (!(stream >> denom)) return stream;
        if (slash == '/') rational = Rational(num, denom);
    }
  return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    Rational tmp = lhs - rhs;
    return tmp.Numerator() < 0;
}

int main(int argc, const char** argv) {
    Rational r1, r2;
    string operation;
    try {
        cin >> r1 >> operation >> r2;
    } catch(const exception& ex) {
        cout << "Invalid argument";
        return 1;
    }
    try {
        if (operation == "+") cout << r1 + r2 ;
        else if (operation == "-") cout << r1 - r2;
        else if (operation == "*") cout << r1 * r2;
        else if (operation == "/") cout << r1 / r2; 
    } catch(const domain_error& de) {
        cout << "Division by zero";
        return 2;
    }
    return 0;
}