#include <iostream>
#include <cmath>
 /*
 На вход вашей программы в стандартном потоке ввода подаются действительные коэффициенты A, B и C уравнения Ax² + Bx + C = 0. 
 Выведите все его различные действительные корни в поток вывода в любом порядке, при этом разделяя корни пробелами. 
 Гарантируется, что хотя бы один из коэффициентов уравнения не равен нулю.
 */
using namespace std;

int main() {
    int a, b, c;
    double x1, x2;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) cout << " " << endl;
        else {
            x1 = -((double)c / b);  
            cout << x1 << endl;
        }
        return 0;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        cout << " " << endl;
        return 0;
        }
    else if (discriminant == 0) {
        x1 = (-b) / (2 * a);
        x2 = x1;
        cout << x1 << endl;
        return 0;
    }
    else {
        x1 = ((-b) - sqrt(discriminant)) / (2 * a);
        x2 = ((-b) + sqrt(discriminant)) / (2 * a);
        cout << x2 << " " << x1 << endl;
        return 0;
    }
    return 0;
}