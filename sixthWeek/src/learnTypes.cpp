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
	/*
	* int x = 2'000'000'000'000;
	*unsigned int y = x;
	*cout << y << endl; // outputs 2'000'000'000'000 instead of number less than 0 cout << (-1 < 1//u) << endl; - error
	*
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

	/*
	 * enum class - класс для перечисления элементов
	 * Пример:
	 * enum class RequestType {
	 * 	ADD;
	 * 	REMOVE;
	 * 	NEGATE;
	 * };
	 * а дальше нужно использовать RequestType::ADD, то есть мы используем scope RequestType
	 * для использования переменной ADD
	 */

	/*
	 * switch(variable for comparing) {
	 * case  value1:
	 * 		//action
	 * case value2:
	 * 		//action
	 * case value3: {
	 * 		boolean bool = true; if we initialize and declare a variable we have to put curly braces
	 *
	 * 		}
	 * 	default: an analog of else statement
	 * 		//action
	 * }
	 */

	/*
	 * enum class RequestType {
	 * 	 ADD = 0;
	 * 	 REMOVE = 1;
	 * 	 NEGATE = 2;
	 * 	} так все enum значения кодируются целыми числами и в случае чего мы можем преобразовать
	 * 	их в целые числа с помощью static_cast<i	nt>(enum variable)
	 */
	int32_t x = 10;
	uint64_t y = 15;
	auto p = x & y;
	cout << p << endl;
	int32_t q = 1u;
	cout << q << endl;
	return 0;
}

