#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

/*
developer: Artem Trybushenko
language: cpp
*/

using namespace std;

/*
task:	В этой задаче вам надо разработать класс Matrix для представления целочисленной матрицы.
		Более подробно, класс Matrix должен иметь:
			-конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
			-конструктор от двух целочисленных параметров: num_rows и num_cols, — которые задают количество строк
			 и столбцов матрицы соответственно
			-метод Reset, принимающий два целочисленных параметра,
			 которые задают новое количество строк и столбцов матрицы соответственно;
			 метод Reset меняет размеры матрицы на заданные и обнуляет все её элементы
			-константный метод At, который принимает номер строки и номер столбца (именно в этом порядке;
			 нумерация строк и столбцов начинается с нуля) и возвращает значение в соответствущей ячейке матрицы
			-неконстантный метод At с такими же параметрами, но возвращающий ссылку
			 на значение в соответствущей ячейке матрицы
			-константные методы GetNumRows и GetNumColumns,
			 которые возвращают количество строк и столбцов матрицы соответственно

		Если количество строк или количество столбцов, переданное в конструктор класса Matrix или метод Reset,
		оказалось отрицательным, то должно быть выброшено стандартное исключение out_of_range.

		Это же исключение должен бросать метод At, если переданная в него ячейка выходит за границы матрицы.

		Кроме того, для класса Matrix должны быть определены следующие операторы:
			-оператор ввода из потока istream; формат ввода простой — сначала задаётся количество строк
			 и столбцов (именно в этом порядке), а затем все элементы матрицы:
			 сначала элемент первой строки и первого столбца,
			 затем элемент первой строки и второго столбца и так далее
			-оператор вывода в поток ostream;
			 он должен выводить матрицу в том же формате,
			 в каком её читает оператор ввода, — в первой строке количество строк и столбцов,
			 во второй — элементы первой строки, в третьей — элементы второй строки и т.д.
			-оператор проверки на равенство (==): он должен возвращать true,
			 если сравниваемые матрицы имеют одинаковый размер и все их соответствующие элементы равны между собой,
			 в противном случае он должен возвращать false.
			-оператор сложения: он должен принимать две матрицы и возвращать новую матрицу,
			которая является их суммой; если переданные матрицы имеют разные размеры этот оператор
			должен выбрасывать стандартное исключение invalid_argument.

		Вам дана заготовка решения, а также пример ввода и вывода. Когда вы реализуете класс Matrix,
		вы можете использовать этот пример, чтобы убедиться, что ваш код работает правильно.

		Важно! Пример не проверяет выполнение всех требований, приведённых в условии.

		Примечание
		Матрицы с нулём строк или нулём столбцов считаются пустыми.
		Любые две пустые матрицы равны. Сумма двух пустых матриц также является пустой матрицей.

		Пример:
			Ввод:
				3 5
				6 4 -1 9 8
				12 1 2 9 -5
				-4 0 12 8 6

				3 5
				5 1 0 -8 23
				14 5 -6 6 9
				8 0 5 4 1
			Вывод:
				3 5
				11 5 -1 1 31
				26 6 -4 15 4
				4 0 17 12 7
*/

class Matrix {
	public:
		Matrix() {
			rows = 0;
			columns = 0;
			Reset(rows, columns);
		}

		Matrix(int num_rows, int num_cols) {
			if (num_rows < 0 || num_cols < 0) {
				throw out_of_range("Number of columns or number of rows is less than 0");
			}
			else if (num_cols == 0 || num_rows == 0) {
				columns = 0;
				rows = 0;
			}
			else {
				rows = num_rows;
				columns = num_cols;
				Reset(rows, num_cols);
			}
		}

		void Reset(const int& num_rows, const int& num_cols) {
			if (num_rows < 0 || num_cols < 0) {
				throw out_of_range("Number of columns or number of rows is less than 0");
			}
			else if (num_cols == 0 || num_rows == 0) {
				columns = 0;
				rows = 0;
			}
			else {
				matrix.resize(num_rows);
				for (auto& row : matrix) {
					row.resize(num_cols);
					for (auto& col : row) {
						col = 0;
					}
				}
				columns = num_cols;
				rows = num_rows;}

		}
		int At(const int& row, const int& col) const {
			if (row >= rows || row < 0 || col >= columns || col < 0) throw out_of_range("Given numbers are out of range");
			return matrix.at(row).at(col);
		}

		int& At(const int& row, const int& col) {
			if (row >= rows || row < 0 || col >= columns || col < 0) throw out_of_range("Given numbers are out of range");
			return matrix.at(row).at(col);
		}

		int GetNumRows() const {
			return rows;
		}

		int GetNumColumns() const {
			return columns;
		}
	private:
		int rows, columns;
		vector<vector<int>> matrix;
};

istream& operator>>(istream& stream, Matrix& matrix) {
	int rows, cols;
	stream >> rows >> cols;
	matrix.Reset(rows, cols);
	for (int row = 0; row < matrix.GetNumRows(); ++row) {
		for (int col = 0; col < matrix.GetNumColumns(); ++col) {
			stream >> matrix.At(row, col);
		}
	}
	return stream;
}

ostream& operator<<(ostream& stream, const Matrix& matrix) {
	stream << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << endl;
	for (int row = 0; row < matrix.GetNumRows(); ++row) {
		for (int col = 0; col < matrix.GetNumColumns(); ++col) {
			stream << matrix.At(row, col) << ' ';
		}
		stream << endl;
	}
	return stream;
}
Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	Matrix resultMatrix;
	if (lhs.GetNumColumns() != rhs.GetNumColumns()) throw invalid_argument("Mismatch number of columns");
	else if (lhs.GetNumRows() != rhs.GetNumRows()) throw invalid_argument("Mismatch number of rows");
	else {
		resultMatrix.Reset(lhs.GetNumRows(), lhs.GetNumColumns());
		for (int row = 0; row < lhs.GetNumRows(); ++row) {
			for (int col = 0; col < lhs.GetNumColumns(); ++col) {
				resultMatrix.At(row, col) = lhs.At(row, col) + rhs.At(row, col);
			}
		}
	}
	return resultMatrix;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumColumns() != rhs.GetNumColumns() || lhs.GetNumRows() != rhs.GetNumRows()) return false;
	if (lhs.GetNumColumns() == 0 || rhs.GetNumRows() == 0) return true;
	for (int row = 0; row < lhs.GetNumRows(); ++row) {
		for (int col = 0; col < lhs.GetNumColumns(); ++col) {
			if (lhs.At(row, col) != rhs.At(row, col)) return false;
		}
	}
	return true;
}
/*
int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << (one + two) << endl;
	return 0;
}
*/


