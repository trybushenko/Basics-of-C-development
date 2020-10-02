#include <iostream>
#include <limits>
#include <vector>
/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task: 	learning task for learning types of integers
*/

int main(int argc, const char** argv) {
	cout << "size_t : " <<numeric_limits<size_t>::max()
		 << "\nunsigned int : " << numeric_limits<unsigned int>::max()
		 << "\nminimal value int8_t : " << numeric_limits<int8_t> :: min()
		 << "\nmaximal value int8_t : " << numeric_limits<int8_t> :: max()
		 << "\nminimal value int16_t : " << numeric_limits<int16_t> :: min()
		 << "\nmaximal value int16_t : " << numeric_limits<int16_t> :: max()
		 << "\nminimal value int32_t : " << numeric_limits<int32_t> :: min()
		 << "\nmaximal value int32_t : " << numeric_limits<int32_t> :: max()
		 << "\nminimal value int64_t : " << numeric_limits<int64_t> :: min()
		 << "\nmaximal value int64_t : " << numeric_limits<int64_t> :: max() << endl;
	/*int x = 2'000'000'000'000;
	unsigned int y = x;
	cout << y << endl; // outputs 2'000'000'000'000 instead of number less than 0
	cout << (-1 < 1u) << endl; - error
	*/
	vector<int> z = {1, 5, 6};
	for (int i = 0; i < static_cast<int>(z.size()); i++) {
		cout << i << ' ' << z[i] << endl;
	}
	//for (size_t i = z.size() - 1; i >= 0; --i {cout << z[i]} // it crashes because z can be empty
	for (int k = z.size(); k > 0; --k) {
		size_t i = k - 1;
		cout << z[i] << endl;
	}
	/*
	 * во время деления двух целых чисел разного типа, число которое получилось будет приводится
	 * к большему типу, то есть (int / size_t = size_t) || (int8_t / uint32_t = uint32_t).
	 * максимальное значение целочисленного типа + 1 = минимальное значение этого же типа
	 * static_cast<type> (integer) - приведение числа одного типа к другому
	 * */
	return 0;
}
