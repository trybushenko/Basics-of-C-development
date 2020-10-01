#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;


/*
Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.
*/

void Reverse(vector<int>& v) {
    //assigning starting size of vector v to a variable len
    int len = v.size();
    //timing
    auto start = steady_clock::now();
    for (int i = len - 1; i >= 0; i--) {
        v.push_back(v[i]); 
    }
    auto finish = steady_clock::now();
    //getting the result
    cout << "loop worked " 
    << duration_cast<milliseconds> (finish - start).count() 
    << "ms" << endl;
    //timing
    start = steady_clock::now();
    v.erase(v.begin(), v.begin() + len);
    finish = steady_clock::now();
    //getting the result
    cout << "erasing worked for " 
    << duration_cast<milliseconds>(finish - start).count()
    << "ms" << endl;
}
